/*
 *
 * P1030求前序排列
 *
 *
 * 本题关键是抓住后序序列的最后一个节点，恰好是前序序列的第一个节点，
 * 根据中序和后序遍历划分子树，直接输出先序遍历，不需要显式建树。
 *
 * 1.后序区间的最后一个字符是当前根节点，先输出它
 * 2.在中序区间中找到根的位置。根左边属于左子树，右边属于右子树。
 * 3.根据中序划分得到左子树节点数 k。后序区间中，前 k 个字符属于左子树，剩余部分去掉末尾的根后属于右子树。
 * 4.先递归处理左子树，再处理右子树，形成“根 → 左 → 右”的先序输出。
 * 5.当前区间为空时返回。
 * 
 * 时间复杂度O(n^2)
 */

#include <bits/stdc++.h>
using namespace std;
int pos[256];
string ins, ps;
void preOrder(int inL, int postL, int len)
{ // 中序起点，后序起点，节点数
    if (len == 0)
        return;

    char head = ps[postL + len - 1];
    cout << head;

    int hp = pos[(unsigned char)head];
    int leftLen = hp - inL;
    preOrder(inL, postL, leftLen);
    preOrder(hp + 1, postL + leftLen, len - leftLen - 1);
}
int main()
{
    cin >> ins >> ps;
    for (int i = 0; i < ins.size(); ++i)
    {
        pos[(unsigned char)ins[i]] = i;
    }
    preOrder(0, 0, ins.size());
    return 0;
}