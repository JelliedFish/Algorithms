#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <iomanip>

using namespace std;

vector < pair <int, pair<int, int> > > g;
vector <int> q;
long long sum = 0;

int find_set(int v)
{
    if (v == q[v])
        return v;
    return q[v] = find_set(q[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        q[b] = a;
}

int main()
{
	freopen("spantree3.in", "r", stdin);
 	freopen("spantree3.out", "w", stdout);

    int n, m;
    int k1, k2, k3;

    cin >> n >> m;

    g.resize(m); q.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        cin >> k1 >> k2 >> k3;
        g[i].first = k3;
        g[i].second.first = k1;
        g[i].second.second = k2;
    }

    for (int i = 1; i <= n; ++i)
        q[i] = i;

    sort(g.begin(), g.end());

    for (int i = 0; i < m; ++i)
    {
          if (find_set(g[i].second.first) != find_set(g[i].second.second))
        {
            sum += g[i].first;;
            union_sets(g[i].second.first, g[i].second.second);
        }
    }

    cout << sum;

    return 0;
}
