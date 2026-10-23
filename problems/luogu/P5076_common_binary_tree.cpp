/*
 * P5076：普通二叉树（简化版）
 *
 * idea：使用结构体数组维护二叉搜索树，利用“左子树的值 < 当前节点值 < 右子树的值”进行查找，不需要实际做中序遍历。
 *
 * op1:统计小于 x 的节点数，最后加 1。当前值 < x 时，将左子树大小与当前节点一起计入，再往右走；否则往左走。
 * op2:设左子树大小为 s。k <= s 去左边；k == s + 1 返回当前值；否则去右边，并令 k -= s + 1。
 * op3:当前值 < x 时记录候选，再往右找更大的；否则往左走。
 * op4:当前值 > x 时记录候选，再往左找更小的；否则往右走。
 * op5:沿大小关系寻找空位置，连接新节点。新节点 siz = 1，沿途祖先的 siz 都加 1。
 *
 * 最坏时间复杂度O(q^2)，q是节点数
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;//节点的数值
    int l, r;//左右子节点编号
    int siz;//子树大小，包括本身
} tree[10001];
int root = 0, tot = 0;

int op1(int x)
{
    int cnt = 0;
    int cur = root;
    while (cur != 0)
    {
        if (x > tree[cur].val)
        {
            cnt += tree[tree[cur].l].siz + 1;
            cur = tree[cur].r;
        }
        else if (x < tree[cur].val)
        {
            cur = tree[cur].l;
        }
        else
        {
            cnt += tree[tree[cur].l].siz;
            break;
        }
    }
    return cnt + 1;
}

int op2(int x)
{
    int cur = root;
    while (1)
    {
        if (tree[tree[cur].l].siz + 1 < x)
        {
            x -= tree[tree[cur].l].siz + 1;
            cur = tree[cur].r;
        }
        else if (tree[tree[cur].l].siz >= x)
        {
            cur = tree[cur].l;
        }
        else
        {
            return tree[cur].val;
        }
    }

    return 0;
}

int op3(int x)
{
    int cur = root;
    int ans = -2147483647;

    while (cur != 0)
    {
        if (tree[cur].val < x)
        {
            ans = tree[cur].val;
            cur = tree[cur].r;
        }
        else
        {
            cur = tree[cur].l;
        }
    }
    return ans;
}

int op4(int x)
{
    int cur = root;
    int ans = 2147483647;

    while (cur != 0)
    {
        if (tree[cur].val > x)
        {
            ans = tree[cur].val;
            cur = tree[cur].l;
        }
        else
        {
            cur = tree[cur].r;
        }
    }
    return ans;
}
void op5(int x)
{
    int p = ++tot;
    tree[p].val = x;
    tree[p].siz = 1;
    if (root == 0)
    {
        root = p;
        return;
    }
    int cur = root;
    int pre = 0;

    while (cur != 0)
    {
        pre = cur;
        tree[cur].siz++;
        if (x > tree[cur].val)
        {
            cur = tree[cur].r;
        }
        else if (x < tree[cur].val)
        {
            cur = tree[cur].l;
        }
    }
    if (x > tree[pre].val)
        tree[pre].r = p;
    else
        tree[pre].l = p;
}
int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
            cout << op1(x) << '\n';
        else if (op == 2)
            cout << op2(x) << '\n';
        else if (op == 3)
            cout << op3(x) << '\n';
        else if (op == 4)
            cout << op4(x) << '\n';
        else
            op5(x);
    }
    return 0;
}