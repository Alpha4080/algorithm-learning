/* 
 * B3631 单向链表
 * 
 * Topic:Array / Linked-List
 * 
 * Idea:
 * 此题虽名为单向链表，
 * 但实则用链表实现代码复杂，
 * 并且此题题目已知每个节点的值不同且范围较小
 * 因此考虑开一个足够大的数组 nxt[1000001]并初始化为0，
 * nxt[x]代表值x的节点的下一个节点。
 * 
 * Mistake：
 * 我刚开始尝试用结构体创建链表，
 * 再分别写题目要求的三个操作函数，
 * 但是发现情况复杂， 
 * 问了gpt之后得到此新想法。
 */

#include <bits/stdc++.h>
using namespace std;
vector<int> nxt(1000001, 0);

int main()
{
    int p;
    cin >> p;
    for (int i = 0; i < p; ++i)
    {
        int first, x, y;
        cin >> first;
        if (first == 1)
        {
            cin >> x >> y;
            nxt[y] = nxt[x];
            nxt[x] = y;
        }
        else if (first == 2)
        {
            cin >> x;
            cout << nxt[x] << '\n';
        }
        else if (first == 3)
        {
            cin >> x;
            nxt[x] = nxt[nxt[x]];
        }
    }
    return 0;
}