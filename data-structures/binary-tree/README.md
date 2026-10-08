# Tree

## 1.What is binary-tree

二叉树是非线性(树形)数据结构，每个节点最多有两个子节点，叫做左子节点和右子节点。

二叉树节点结构体：
```cpp

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *Right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};

```
### Basic Concept

- 1.根节点(root node)：最上面的节点
- 2.叶节点(leaf node)：没有子节点的节点
- 3.父节点(子节点)：某节点直接相连的上(下)边的那个节点
- 4.边(edge)：连接两个节点的线段，即节点引用(指针)。
- 5.节点的度(degree)：节点的子节点数量
- 6.高度(height)：树的最大层数
- 7.节点的深度(depth)：从根节点到该节点经过的边的数量。

注：不同题目对depth和height的定义可能相差1

## 2.Basic Operation

### initialization

```cpp

// 初始化节点
TreeNode* n1 = new TreeNode(1);
TreeNode* n2 = new TreeNode(2);
TreeNode* n3 = new TreeNode(3);

//构建节点之间的引用
n1->left = n2;
n1->right = n3;

```

### insert or delete node

```cpp

TreeNode* P = new TreeNode(0);
//在 'n1->n2' 中间插入节点P
n1->left = P;
P->left = n2;

//删除节点P
n1->left = n2;
delete P;

```

## 3.Classification

- 完全二叉树：仅允许最底层的节点不完全填满，并且最底层的节点必须从左往右依次连续填充。
- 完美二叉树：所有层的节点都被完全填满。
- 完满二叉树：除了叶节点之外，所有节点都有两个子节点。
- 平衡二叉树：任意节点的左子树和右子树的高度差绝对值不能超过1.

## 4.Traversal

### 层序遍历

从顶部到底部逐层遍历二叉树，并且在每一层按照从左到右的顺序访问节点。本质属于广度优先搜索(breadth-first search,BFS)。

#### 代码实现

BFS通常借助队列实现，因为队列先进先出，而BFS逐层推进，背后的思想一致
```cpp

vector<int> levelOrder(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);

    vector<int> v;
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();

        v.push_back(node->val);

        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
    }
    return v;
}

```

### 前序、中序、后序遍历

这仨个都属于深度优先遍历(depth-first traversal)，也称深度优先搜索(depth-first search,DFS),体现了一种“先走到尽头，再回溯继续”的遍历方式

#### 代码实现

```cpp

//前序遍历：根->左->右
void preOrder(TreeNode *root){
    if(root == nullptr) return;
    v.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

//中序遍历：左->根->右
void inOrder(TreeNode *root){
    if(root == nullptr) return;
    inOrder(root->left);
    v.push_back(root->val);
    inOrder(root->right);
}

//后序遍历：左->右->根
void postOrder(TreeNode *root){
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    v.push_back(root->val);
}

```

## 5.Array Representation

利用层序遍历的特点可以得出在数组中父节点索引和子节点索引之间的映射关系：某节点索引为i，则该节点的左子节点索引为2i+1，右子节点索引为2i+2。

但在任意二叉树中，中间层通常存在许多 `None`，因此我们需要考虑在层序遍历序列中显式的写出所有 `None`，即：
```cpp

vector<int> tree = {1,2,3,INT_MAX,6,7,8,9,INT_MAX,INT_MAX,12,INT_MAX,INT_MAX,15};

```

完美二叉树非常适合用数组来表示，因为它只有最底层的右侧才会出现`None`，即层序遍历序列的末尾，因此不用处理。

### 代码实现

```cpp

class ArrayBinaryTree{
public:
    //构造
    ArrayBinaryTree(vector<int> arr){
        tree = arr;
    }

    //列表容量
    int size(){
        return tree.size();
    }

    //获取索引为 i 节点的值
    int val(int i){
        //索引越界，返回 INT_MAX,表示空位
        if(i < 0 || i >= size()) return INT_MAX;
        return tree[i];
    }

    //获取索引为i节点的左子节点的索引
    int left(int i){
        return i*2+1;
    }

    //右
    int right(int i){
        return 2*i+2;
    }

    //父节点
    int parent(int i){
        return (i-1)/2;
    }

    //层序遍历
    vector<int> levelOrder(){
        vector<int> res;
        for(int i = 0;i < size(); ++i){
            if(val(i) != INT_MAX) res.push_back(val(i));
        }
        return res;
    }

    //前序遍历
    vector<int> preOrder(){
        vector<int> res;
        dfs(0,"pre",res);
        return res;
    }

    //中序遍历
    vector<int> inOrder(){
        vector<int> res;
        dfs(0,"in",res);
        return res;
    }
    //后序遍历
    vector<int> postOrder(){
        vector<int> res;
        dfs(0,"post",res);
        return res;
    }

private:
    vector<int> tree;

    //dfs
    void dfs(int i, string order, vector<int> &res){
        //若为空位，直接返回
        if(val(i) == INT_MAX) return;
        //前序遍历
        if(order == "pre") res.push_back(val(i));
        dfs(left(i),"pre",res);
        //中序遍历
        if(order == "in") res.push_back(val(i));
        dfs(right(i),"in",res);
        //后序遍历
        if(order == "post") res.push_back(val(i));
    }
};

```

### 优点与局限性

优点：

- 数组存储在连续的内存空间中，对缓存友好，访问与遍历速度快。
- 不需要存储指针，节省空间。
- 允许随机访问节点。

缺点：
- 数组内存连续，不适合存储数据量过大的树。
- 增删节点需要通过数组插入与删除操作实现，效率低。
- 二叉树中存在大量`None`时，空间利用率低。


## 6.Binary Search Tree

二叉搜索树满足：

- 对于根节点，左子树中所有节点的值 < 根节点的值 < 右子树中所有节点的值。
- 任意节点的左、右子树也是二叉搜索树，同样满足上述条件。

### 二叉搜索树的操作

先将二叉搜索树封装成一个类 `BinarySearchTree`，声明一个成员变量 `root`，指向树的根节点。

#### 1.查找节点

目标节点值 `num`，声明一个节点 `cur`，从 `root` 出发循环比较`cur.val`和`num`之间的大小关系。

- 如果`cur.val` < `num`，说明目标节点在 `cur`的右子树中，执行`cur = cur.right`
- 如果`cur.val` > `num`，说明目标节点在 `cur`的左子树中，执行`cur = cur.left`
- 如果`cur.val` = `num`，说明找到目标节点，跳出循环并返回该节点


二叉搜索树与二分查找工作原理一致，每轮排除一半情况，循环次数最多是二叉树的高度，二叉树平衡时，使用O(log n)，时间

```cpp

TreeNode *search(int num){
    TreeNode *cur = root;
    while(cut != nullptr){
        if(cur->val < num){
            cur = cur->left;
        }else if(cur->val > num){
            cur = cur->right;
        }else break;
    }
    return cur;
}

```

#### 2.插入节点

1.查找插入位置：从根节点出发，较小走左，较大走右，直到找到第一个空子节点的位置跳出循环。
2.在该位置插入节点。

注：
- 二叉搜索树中不允许存在重复节点，如果待查节点在树中已经存在，则不执行插入直接返回。
- 为了实现插入节点，需要用一个 `pre` 保存上一轮循环的节点。这样当cur指向 `nullptr` 的时候，可以获得它的父节点，从而完成插入操作。

```cpp

void insert(int num){
    //若树为空，则初始化根节点
    if(root == nullptr){
        root = new TreeNode(num);
        return;
    }
    TreeNode *cur = root, *pre = nullptr;
    //循环查找，越过空子节点后跳出
    while(cur != nullptr){
        //找到重复节点，直接返回
        if(cur->val == num){
            return;
        }
        pre = cur;
        //插入位置在 cur 的右子树中
        if(cur->val < num){
            cur = cur->right;
        }
        //插入位置在 cur 的左子树中
        else{
            cur = cur->left;
        }
    }
    TreeNode *node = new TreeNode(num);
    if(pre->val < num){
        pre->right = node;
    }else{
        pre->left = node;
    }
}

```

BST 的查找、插入和删除时间复杂度为 `O(h)`，
其中 `h` 为树高。

- 当树较平衡时，`h = O(log n)`，因此复杂度为 `O(log n)`。
- 当 BST 退化为链表时，`h = O(n)`，最坏复杂度为 `O(n)`。

#### 3.删除节点

删除节点分三种情况：

1. 无子节点：直接删除。
2. 一个子节点：让该子节点代替被删除节点。
3. 两个子节点：
   - 找右子树中的最小节点，即中序后继。
   - 删除该后继节点。
   - 用后继节点的值覆盖当前节点。

右子树最小节点的寻找方式：

```cpp
TreeNode* tmp = cur->right;

while (tmp->left != nullptr) {
    tmp = tmp->left;
}
```

> 一个 BTS 有两个子节点时，我们不是直接把节点“拔掉”，而是找一个最接近它、又不会把BST顺序破坏的节点来代替它：右子树最小值就是一个天然选择。

### 中序遍历有序

中序遍历是：左->根->右，二叉搜索树又有“左子节点＜根节点＜右子节点”，因此二叉搜索树中进行中序遍历得到的序列正好是升序的。


## 7.AVL Tree

AVL Tree是一种自平衡二叉搜索树。

它在 BST 的基础上限制任意节点左右子树高度差不能超过 1，
从而避免 BST 退化成链表。


### Balance factor

平衡因子 BF = leftHeight - rightHeight;

AVL 节点满足：

- BF = -1
- BF = 0
- BF = 1

如果绝对值大于1，就会发生失衡。

### Rotation

#### LL

左 -> 左

右旋。

#### RR

右 ->右 

左旋。

#### LR

左 -> 右

先左旋孩子，再右旋当前节点

#### RL

右 -> 左

先右旋孩子，再左旋当前节点

注：

- LR和RL两种情况，其实就是先掰成LL和RR，再进行右旋/左旋。

### Insert

- 1.按照普通 BST 插入。
- 2.更新节点高度。
- 3.检查平衡因子
- 4.如果失衡，则进行旋转

### Complexity

查找：O(log n)

插入：O(log n)

删除：O(log n)

AVL 通过保持树高为 O(log n)，
避免普通 BST 最坏退化为 O(n)。