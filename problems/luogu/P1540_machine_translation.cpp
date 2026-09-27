/*
 *
 * idea:
 * 用两个数据结构组合解决这个问题。
 * 题目中可以看出关键在于内存中的单词有先进先出的特点，
 * 这就说明适合用队列，
 * 然后每个单词还有一个对应的非负数且非负数的范围很小，
 * 用一个inMemory数组去标记每个单词在不在队列里，
 * 时间复杂度是O(1),
 * 整体时间复杂度是O(n)。
 *
 */ 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    bool inMemory[1001] = {};

    int m, n;
    cin >> m >> n;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (!inMemory[x])
        {
            if (q.size() == m)
            {
                inMemory[q.front()] = false;
                q.pop();
            }
            q.push(x);
            inMemory[x] = true;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}