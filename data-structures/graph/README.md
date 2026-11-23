# GRAPH

## Basic Concept

- 连通图：从任意一个节点出发都能到达其余任意节点
- 非连通图：至少有一个顶点到不了
- 有权图：给边添加权重变量
- 邻接：两个顶点之间存在边相连的时候就叫做邻接
- 路径：从顶点A到顶点B经过的边构成的序列被称为A到B的路径
- 邻接矩阵：使用一个 n * n大小的矩阵来表示图，每一行每一列代表一个顶点，矩阵元素代表边，用1和0来表示两个顶点之间是否存在边
- 邻接表：使用 n 个链表来表示图，链表节点是顶点，第i个链表对应顶点i，存储的节点代表与顶点i邻接的顶点

## Basic Operation

### 用邻接矩阵来表示无向图

```cpp
Class GraphAdjMat{
    vector<int> vertices;       //顶点列表，索引代表顶点，元素代表顶点值
    vector<vector<int>> adjMat; //邻接矩阵，行列索引代表顶点

    public:
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges){
        //添加顶点
        for(int val : vertices){
            addVertes(val);
        }

        //添加边
        for(const vector<int> &edge : edges){
            addEdge(edge[0],edge[1]);
        }
    }

    //获取顶点数量
    int size(){
        return vertices.size();
    }

    //添加顶点
    void addVertex(int val){
        int n = vertices.size();//先用n记录之前的顶点数

        vertices.push_back(val);

        //给邻接矩阵分别添加一行和一列
        adjMat.emplace_back(vector<int>(n,0));
        for(vector<int> &row : adjMat){
            row.push_back(0);
        }
    }

    //删除顶点
    void removeVertex(int index){
        if(index >= size()){
            throw out_of_range("定点不存在");
        }

        //分别删除定点列表中的节点和邻接矩阵里的行
        vertices.erase(vertices.begin() + index);
        adjMat.erase(adjMat.begin() + index);
        
        //删除邻接矩阵里的列
        for(vector<int> &row : adjMat){
            row.erase(row.begin() + index);
        }
    }

    //添加边
    void addEdge(int u, int v){
        if(u < 0 || v  < 0 || u >= size() || v >= size() || u == v){
            throw out_of_range("定点不存在");
        }
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    //删除边
    void removeEdge(int u,int v){
        if(u < 0 || v  < 0 || u >= size() || v >= size() || u == v){
            throw out_of_range("定点不存在");
        }
        adjMat[u][v] = 0;
        adjMat[v][u] = 0;
    }
}

```

### 用邻接表来实现图

```cpp
Class GraphAdjList{
    public:
        //key:顶点，value：该顶点的所有邻接顶点
        unordered_map<Vertex *,vector<Vertex *>> adjList;

        //在vector容器中删除删除指定节点
        void remove(vector<Vertex *> &vec, Vertex *vet){
            for(int i = 0; i < vec.size(); ++i){
                if(vec[i] == vet){
                    vec.erase(vec.begin() + i);
                    break;
                }
            }
        }

        //构造函数
        GraphAdjList(const vector<vector<Vertex *>> &edges){
            for(const vector<Vertex *> &edge : edges){
                addVertex(edge[0]);
                addVertex(edge[1]);
                addEdge(edge[0],edge[1]);
            }
        }

        //获得顶点数量
        int size(){
            return adjList.size();
        }

        void addEdge(Vertex *v1, Vertex *v2){
            if(!adjList.count(v1) || !adjList.count(v2) || v1 == v2){
                throw out_of_range("顶点不存在");
            }
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }

        //删除边
        void removeEdge(Vertex *v1, Vertex *v2){
            if(!adjList.count(v1) || !adjList.count(v2) || v1 == v2){
                throw out_of_range("顶点不存在");
            }
            remove(adjList[v1], v2);
            remove(adjList[v2], v1);
        }

        //添加顶点
        void addVertex(Vertex *v){
            if(adjList.count(v)){
                return;
            }

            adjList[v] = vector<Vertex *>();
        }

        //删除顶点
        void removeVertex(Vertex *v){
            if(!adjList.count(v)){
                throw invalid_argument("顶点不存在");
            }

            //删除邻接表中的链表
            adjList.erase(v);

            //遍历其他顶点的链表，删除所有包含v的边
            for(auto adj : adjList){
                remove(adj.second,v);
            }
        }
}
```

## Traversal

### BFS

广度优先遍历：从某个顶点出发，始终优先访问距离最近的顶点，并且一层层向外扩张。这种方式跟队列的进出方式一致，因此常用队列来实现。

为了防止重复遍历顶点，我们还需要借助一个哈希集合 `visited` 来记录哪些顶点已经被访问

```cpp

//使用邻接表来表示图，方便获得指定顶点的所有邻接顶点
vector<Vertex *> graphBFS(GraphAdjList &graph, Vertex *startVet){
    //顶点遍历序列
    vector<Vertex *> res;
    //哈希集合，记录访问过的点
    unordered_set<Vertex *> visited = {startVet};
    queue<Vertex *> que;
    que.push(startVet);
    //以startVet为起点，循环访问所有的顶点
    while(!que.empty()){
        Vertex *v = que.front();
        que.pop();
        res.push_back(v);
        for(auto adjVet : graph.adjList[v]){
            if(visited.count(adjVet)) continue;
            que.push(adjVet);
            visited.emplace(adjVet);
        }
    }
    return res;
}
```


### DFS

深度优先遍历是优先走到底，无路可走再回头的遍历方式，以此类推，直到所有顶点遍历完成。这种思想与递归一致，因而常用递归实现

```cpp
//dfs辅助函数
void dfs(GraphAdjList &graph, unordered_set<Vertex *> &visited, vector<Vertex *> &res, Vertex *vet){
    res.push_back(vet);
    visited.emplace(vet);

    for(Vertex *adjVet : graph.adjList[vet]){
        if(visited.count(adjVet)) continue;

        dfs(graph,visited,res,adjVet);
    }
}

//深度优先遍历
//依旧使用邻接表来表示图
vector<Vertex *> graphDFS(GraphAdjList &graph, Vertex *startVet){
    //顶点遍历序列
    vector<Vertex *> res;
    unordered_set<Vertex *> visited;
    dfs(graph,visited,res,startVet);
    return res;
}
```

