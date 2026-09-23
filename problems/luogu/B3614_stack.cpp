/*
 *
 * B3614
 *
 * idea:
 * 直接用栈的各个操作即可，
 * 只不过需要注意数据范围较大，
 * 因而应该用unsigned long long而不是int
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        stack<unsigned long long> st;
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            string op;
            cin >> op;
            if (op == "push")
            {
                unsigned long long x;
                cin >> x;
                st.push(x);
            }
            else if (op == "pop")
            {
                if (st.empty())
                {
                    cout << "Empty\n";
                }
                else
                {
                    st.pop();
                }
            }
            else if (op == "query")
            {
                if (st.empty())
                {
                    cout << "Anguei!\n";
                }
                else
                {
                    cout << st.top() << endl;
                }
            }
            else if (op == "size")
            {
                cout << st.size() << endl;
            }
        }
    }
    return 0;
}