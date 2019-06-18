#include <iostream>
#include <vector>
#include <set>

using namespace std;


const int INF = 1000000;


int main() {



    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);

    int n,m;

    cin >> n >> m;


    vector <int> min_way(n,INF);

    vector <bool> visited(n);

    vector <vector <pair<int,int>>> table(n);



    for (int i = 0; i < m; i++) {

        int k1,k2,k3;

            cin >> k1 >> k2 >> k3;

            table[k1-1].push_back(make_pair(k3,k2-1));
            table[k2-1].push_back(make_pair(k3,k1-1));


        }

    int cur_node = 0;

    min_way[cur_node] = 0;

    set<pair<int, int>> q;

    q.insert(make_pair(min_way[cur_node], cur_node));

    while(!q.empty())
    {

        int v = q.begin()->second;

        q.erase(q.begin());

        for(size_t j = 0; j < table[v].size(); j++)
        {

            int to = table[v][j].second;

            int w = table[v][j].first;

            if(min_way[v] + w < min_way[to]){

                q.erase(make_pair(min_way[to], to));
                min_way[to] = min_way[v] + w;
                q.insert(make_pair(min_way[to], to));
            }

        }

    }

    for(int i = 0; i < n; i++)
    {
        cout << min_way[i] << " ";
    }

    return 0;
}
