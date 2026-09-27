/*
 * 
 * idea:
 * 此题简单，
 * 直接使用queue的成员函数即可实现。
 * 
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (op == 2)
        {
            if (q.empty())
            {
                cout << "ERR_CANNOT_POP\n";
            }
            else
            {
                q.pop();
            }
        }
        else if (op == 3)
        {
            if (q.empty())
            {
                cout << "ERR_CANNOT_QUERY\n";
            }
            else
            {
                cout << q.front() << endl;
            }
        }
        else if (op == 4)
        {
            cout << q.size() << endl;
        }
    }
    return 0;
}