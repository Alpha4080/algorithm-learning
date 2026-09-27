 /*
 * 
 * idea:
 * 本题属于栈的经典应用场景，
 * 括号匹配，
 * 用一个栈st去把左括号压进去，
 * 遇到右括号就弹出一个左括号与之对应，
 * 如果遇到右括号但是栈里没有左括号也就是st.empty()为真的时候就直接输出NO并返回即可
 * 遍历结束后检查栈是否为空，如果是那么就满足条件，不是就输出NO
 * 
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c = 'A';
    stack<char> st;
    while (cin >> c && c != '@')
    {

        if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            if (st.empty())
            {
                cout << "NO";
                return 0;
            }
            else
            {
                st.pop();
            }
        }
        else
            continue;
    }
    cout << (st.empty() ? "YES" : "NO");
    return 0;
}