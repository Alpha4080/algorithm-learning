/*
 * 
 * idea:
 * 队列的特点是先进先出，
 * 可以方便的把队首元素移到队尾，
 * 因此可以很好的模拟循环报数，
 * 这题只需要把所有人压进队列，
 * 1-m-1此循环的时候把队首元素移到队尾，
 * m的时候将队首元素弹出即可
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        for (int i = 1; i < m; ++i)
        {
            q.pop();
            q.push(q.front());
        }
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}