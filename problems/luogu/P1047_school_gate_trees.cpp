/*
 * P1047 校门外的树
 * Topic: Array / Simulation
 * 
 * Idea:
 * 用数组读取每一个位置是否有树。
 * 每读入一个区间[s,e],
 * 将区间中的树标记为不存在
 * 
 * Time: O(L + 区间总长度)
 * Space: O(L)
 * 
 * Mistake:
 * 第一次写成 vector<int> trees(L),
 * 但位置是 0~L，一共  L+1 个位置，因此会越界。
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, m;
    cin >> l >> m;
    vector<int> trees(l+1);
    for (int i = 0; i <= l; ++i)
    {
        trees[i] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        int start, end;
        cin >> start >> end;
        for (int j = start; j <= end; ++j)
        {
            trees[j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= l; ++i)
    {
        if (trees[i] == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}