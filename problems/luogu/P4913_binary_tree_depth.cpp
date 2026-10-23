#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
    }
    queue<int> q;
    q.push(1);
    int depth = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i)
        {
            int top = q.front();
            q.pop();
            if (l[top] != 0)
                q.push(l[top]);
            if (r[top] != 0)
                q.push(r[top]);
        }
        depth++;
    }
    cout << depth;
    return 0;
}