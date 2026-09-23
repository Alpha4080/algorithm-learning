/* 
 * 
 * P1160
 * 
 * idea:
 * 此题与 B3631 相似，
 * 数据均只出现一次并且范围较小，
 * 只不过这道题的插入操作可能在节点左边也可能在右边，
 * 因此用nxt，pre动态数组分别表示节点后一个和前一个节点，
 * 用数组removed表示某位同学被去掉了.
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;

    vector<int> nxt(n + 1, 0);
    vector<int> pre(n + 1, 0);
    vector<bool> removed(n + 1, false);
    for (int i = 2; i <= n; ++i)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0)
        {
            if (pre[k] != 0)
            {
                nxt[pre[k]] = i;
            }
            nxt[i] = k;
            pre[i] = pre[k];
            pre[k] = i;
        }
        if (p == 1)
        {
            if (nxt[k] != 0)
                pre[nxt[k]] = i;
            nxt[i] = nxt[k];
            pre[i] = k;
            nxt[k] = i;
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        if (removed[x] == true)
            continue;
        pre[nxt[x]] = pre[x];
        nxt[pre[x]] = nxt[x];
        removed[x] = true;
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (pre[i] == 0 && !removed[i])
        {
            cur = i;
            break;
        }
    }
    while (cur != 0)
    {
        cout << cur << " ";
        cur = nxt[cur];
    }
    return 0;
}