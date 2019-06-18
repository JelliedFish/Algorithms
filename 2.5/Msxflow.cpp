#include <iostream>
#include <bits/stdc++.h>

#define n 100
using namespace std;

int g[100][100];
int n_, m, a, b, bw;

bool bfs(int rG[n][n], int s, int t, int p[n]){
    vector<bool> used;
    used.assign(n, 0);

    queue<int> q;
    q.push(s);
    used[s] = true;
    p[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < n; i++){

            if((used[i] == false) && (rG[u][i] > 0)){
                q.push(i);
                used[i] = true;
                p[i] = u;
            }
        }
    }

    return (used[t] == true);
}

int Ford_Falkerson(int G[n][n], int s, int t){
    int i, j;
    int rG[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            rG[i][j] = G[i][j];

    int p[n];

    int maxf = 0;

    while(bfs(rG, s, t, p)){

        int pathf = INT_MAX;

        for( j = t; j != s; j = p[j]){
            i = p[j];
            pathf = min(pathf, rG[i][j]);
        }

        for( j = t; j != s; j = p[j]){
            i = p[j];
            rG[i][j] -= pathf;
            rG[j][i] += pathf;
        }
        maxf += pathf;
    }
    return maxf;
}

int main()
{
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);

    cin >> n_ >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> bw;
        g[a-1][b-1] = bw;
    }
    cout << Ford_Falkerson(g, 0, n_-1) << endl;
    return 0;
}
