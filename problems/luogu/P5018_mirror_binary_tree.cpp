/*
P5018:对称二叉树

idea:
本题要求输出最大对称二叉子树的节点数
给我们的输入是节点数 n ,节点权值，以及每个节点的左右子节点编号，不存在记为-1
我们分别用val，lc，rc三个数组来记录某节点的权值，左右子节点编号
相当于完成了建树动作
下面就开始寻找最大对称二叉子树
对于一棵子树，我们可以用递归统计它的左右子树的节点数并判断节点数是否相等，不相等一定不对称
相等再判断是否对称，如果对称再与 `ans`比较，从而得到最大节点数
而判断是否对称就存在几种分类讨论的情况：
1.左右节点均不存在，这棵子树一定对称
2.左节点或者右节点有一个不存在，这棵子树一定不对称
3.左右节点都存在但是权值不相等，也不对称
4.左右节点存在且权值相等，这时候就需要继续判断子树是否对称，也就该我们的递归登场
  而如何使用递归呢，因为最左边的节点要和最右边的节点对应，并且中间两个节点对应，所以应该是lc[a]与rc[b]跟rc[a]，lc[b]两两作为参数调用mirror递归

时间复杂度O(n log n);
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> val;//v[i]表示节点i的权值
vector<int> lc; //lc[i]表示节点i的左子节点的编号
vector<int> rc; //rc[i]表示节点i的右子节点的编号
int ans = 0;

bool mirror(int a, int b){
    if(a == -1 && b == -1) return true;
    else if(a == -1 && b != -1) return false;
    else if(a != -1 && b == -1) return false;
    else if(a != -1 && b != -1 && val[a] != val[b]) return false;
    
    return (mirror(lc[a],rc[b]) && mirror(lc[b], rc[a]));
    
}
int dfs(int u){
    if(u == -1) return 0;
    int L = dfs(lc[u]);
    int R = dfs(rc[u]);

    int nodeNum = L + R + 1;
    if(L == R && mirror(lc[u],rc[u])){
        ans = max(ans,nodeNum);
    }
    return nodeNum;
}

int main(){
    int n;
    cin >> n;
    val.resize(n+1);
    lc.resize(n+1);
    rc.resize(n+1);
    
    for(int i = 1; i<=n; ++i){
        cin >> val[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> lc[i] >> rc[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}