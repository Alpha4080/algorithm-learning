 /*
 * 
 * idea:
 * 这题主要是用栈去保存数据，
 * 因为题目中说的后置表达式是最后两个数配上最先遇到的运算符进行运算，
 * 得到的结果再存回去，
 * 碰到运算符再算，
 * 这种先入后出的特点正好是栈的特点，
 * 因此使用栈来解决这一题是十分合理的。
 * 需要注意的点还有正确处理数据并将其存到栈里，
 * 用char去读数字要减去'0'才是真正的读到的数字，
 * 还有就是栈顶下边的那个元素才是运算符左侧的数
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