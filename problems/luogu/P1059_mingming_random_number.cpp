/*
 * P1059 明明的随机数
 * Topic: Array / STL
 * 
 * Idea:
 * 本题数据范围较小，
 * 因此直接创建一个 bool 类型的 exist[1001],
 * 数 x 出现，就将 exist[x] 设置为 true，
 * 此操作天然去重，
 * 
 * Time: O()
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool exist[1001] = {};

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        exist[x] = true;
    }

    int cnt = 0;
    for (int i = 0; i <= 1000; ++i)
    {
        if (exist[i])
        {
            ++cnt;
        }
    }

    cout << cnt << '\n';

    for (int i = 0; i <= 1000; ++i)
    {
        if (exist[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}