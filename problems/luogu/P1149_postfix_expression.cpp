 /*
 * 
 * idea:
 * 
 * 
 * 
 * 
 * 
 * 
 *  
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    stack<int> st;

    while (cin >> c && c != '@')
    {
        if (c >= '0' && c <= '9')
        {
            int num = c - '0';
            while (cin >> c && c != '.')
            {
                num = num * 10 + c - '0';
            }
            st.push(num);
            continue;
        }
        int rhs = st.top();
        st.pop();

        int lhs = st.top();
        st.pop();

        if(c == '+')
            st.push(lhs + rhs);
        else if(c == '-')
            st.push(lhs - rhs);
        else if(c == '*')
            st.push(lhs * rhs);
        else if(c == '/')
            st.push(lhs / rhs);
    }

    cout << st.top();

    return 0;
}