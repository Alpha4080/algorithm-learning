/*
 *
 * P1087 FBI树
 *
 * 本题通过用区间 [l,r] 表示一个树节点对应的子串，通过递归完成后序遍历，不需要显式建树。
 * 1.当 l == r 时，当前节点是叶子：字符为 0 输出 B，为 1 输出 I。
 * 2.否则将区间从中间分成两半，先递归处理左半段，再处理右半段。
 * 3.扫描当前区间，判断类型：全 0 输出 B，全 1 输出 I，同时包含两者则输出 F。
 *
 * 输出顺序是“左子树 → 右子树 → 当前节点”，符合后序遍历。
 *
 *
 * 设字符串长度为 L = 2^n。
 * 时间复杂度：O(L log L)
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

string s;
void dfs(int l, int r)
{
    if (l == r)
    {
        if (s[l] == '1')
            cout << "I";
        else
            cout << "B";
        return;
    }
    int mid = (l + r) / 2;
    dfs(l, mid);
    dfs(mid + 1, r);

    bool one = false, zero = false;
    for (int i = l; i <= r; ++i)
    {
        if (s[i] == '1')
            one = true;
        if (s[i] == '0')
            zero = true;
    }
    if (one == true && zero == true)
        cout << "F";
    else if (one == false && zero == true)
        cout << "B";
    else if (one == true && zero == false)
        cout << "I";
}
int main()
{
    int n;
    cin >> n >> s;
    dfs(0, s.size() - 1);
    return 0;
}