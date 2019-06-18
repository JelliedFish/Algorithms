#include <bits/stdc++.h>

using namespace std;

int n, m, s, a, b;

int used[5001];
long long w, min_way[5001];
long long const INF = 0x3F3F3F3F3F3F3F3FLL;

struct node{

    int to;
    long long dist;

    node(const int& to, long long& dist)
            : to(to),
              dist(dist)
    {
    };
};

vector<vector<node>> g;

void Ford_Bellman(void){

    memset(min_way, 0x3F, sizeof(min_way));

    min_way[s] = 0;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            for(int k = 0; k < g[j].size(); k++){

                int to = g[j][k].to;
                long long dist = g[j][k].dist;
                if((min_way[j] < INF) && (min_way[to] > min_way[j] + dist))
                    min_way[to] = min_way[j] + dist;

            }
        }
    }
}

void dfs(int v){

    used[v] = 1;

    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i].to;
        if(!used[to])
            dfs(to);
    }

}
int main()
{
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);

    cin >> n >> m >> s;

    g.resize(n+1);

    for(int i = 1; i <=m; i++){

        cin >> a >> b >> w;

        g[a].push_back(node(b, w));
    }

    Ford_Bellman();

    memset(used, 0, sizeof(used));

    for(int i = 1; i <= n; i++){

        for(int j = 0; j < g[i].size(); j++){

            int to = g[i][j].to;
            long long dist = g[i][j].dist;
            if((min_way[i] < INF) && (min_way[to] > min_way[i] + dist) && (!used[to]))
                dfs(to);

        }
    }

    for(int i = 1; i <= n; i++){
        if(min_way[i] == INF)
            cout << "*" << endl;
        else if ((used[i]) || (min_way[i] <= -INF))
            cout << "-" << endl;
        else
            cout << min_way[i] << endl;
    }

    return 0;
}
