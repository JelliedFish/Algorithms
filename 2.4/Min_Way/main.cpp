#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int INF = 2e18;

vector <int> min_way (2000,INF);
int visited[2000];
int table[2000][2000];



signed main() {



    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


#ifndef HOME
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
#endif

    int k1,k2,k3;

    cin >> k1 >> k2 >> k3;

    min_way[k2-1] = 0;



    for (int i = 0; i < k1; i++) {

        for (int j = 0; j < k1; j++) {

            cin >> table[i][j];

            if (table[i][j] == -1) {
                table[i][j] = INF;
            }
            if (i == j) {
                table[i][j] = INF;
            }

        }
    }


    int cur_node = k2-1;


    for (int j = 0; j < k1 - 1; j++) {

        visited[cur_node] = 1;

        for (int next_node = 0; next_node < k1; next_node++) {

            min_way[next_node] = min(min_way[next_node], min_way[cur_node] + table[cur_node][next_node]);
        }




            int min = INF;
            int min_i = 0;

            for (int next_node = 0; next_node < k1; next_node++) {
                if (visited[next_node]!= 1) {
                    if (min_way[next_node] < min) {
                        min =    min_way[next_node];
                        min_i = next_node;
                    }
                }
            }

            if (min == INF) {
                break;
            }

            cur_node = min_i;

        }


    if (min_way[k3-1] != INF) {
        cout << min_way[k3-1];
    }
    else {
        cout << -1;
    }
        return 0;
    }