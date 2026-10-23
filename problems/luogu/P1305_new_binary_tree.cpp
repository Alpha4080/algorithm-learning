/*
 * 
 * P1305新二叉树
 * 
 * 本题仅需注意一下节点值为字母，访问数组时，下标记得减去'a'即可
 * 
 */

#include <bits/stdc++.h>
using namespace std;

char lc[26], rc[26];

void dfs(char root)
{
    if (root == '*')
        return;
    cout << root;
    dfs(lc[root - 'a']);
    dfs(rc[root - 'a']);
}

int main()
{
    int n;
    cin >> n;
    char u, l, r;
    char root;
    for (int i = 0; i < n; ++i)
    {
        cin >> u >> l >> r;
        if (i == 0)
            root = u;
        lc[u - 'a'] = l;
        rc[u - 'a'] = r;
    }
    dfs(root);
    return 0;
}