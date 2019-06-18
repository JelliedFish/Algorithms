#include <iostream>
#include <vector>


using namespace std;

int n,m,k,cnt;
vector <vector <int>> g(201,vector <int>(201,-1));
vector <int> mt;
vector <bool> used;

bool Kuhn (int v) {

    if (used[v]) return false;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {

        int to = g[v][i];
        if (to != -1) {
        if (mt[to] == -1 || Kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
        }

    }

    return false;
}

int main() {

    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);


    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int ai,bi;

        cin >> ai >> bi;
        g[ai-1][bi-1] = bi-1;
    }

    mt.assign (m, -1);

    for (int v = 0; v < n; v++) {

        used.assign(n, false);
        Kuhn (v);
    }

    for (int i = 0; i < m; i++) {
        if (mt[i]!=-1)
            cnt++;
    }


    cout << cnt;



    return 0;
}