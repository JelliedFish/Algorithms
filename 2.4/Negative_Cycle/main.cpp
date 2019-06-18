#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;



struct edge {
   int a;
   int b;
   int w;
};

int main() {


   freopen("negcycle.in", "r", stdin);
   freopen("negcycle.out", "w", stdout);

    int n,m = 0;

    cin >> n;

    vector <edge> e(n*n);
    vector <int> min_way;
    min_way.assign(n,INF);
    min_way[0] = 0;
    vector<int> way (n, -1);


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            int w;

            cin >> w;

            if (w != INF) {
                e[m].a = i;
                e[m].b = j;
                e[m].w = w;
                m++;
            }

        }
    }

    int x;

    for (int i = 0; i < n; i++) {

         x = -1;
        for (int j = 0; j < m; j++) {


                if ((min_way[e[j].b]) > (min_way[e[j].a] + e[j].w)) {
                min_way[e[j].b] = min_way[e[j].a] + e[j].w;
                way[e[j].b] = e[j].a;
                x = e[j].b;
            }
        }
    }

    if (x != -1) {
       int cur = x;

       for (int i = 0; i < n; i++) {
           cur = way[cur];
       }

        vector<int> path;

        for (int i = cur; ; i = way[i]) {

            path.push_back(i);
            if (i == cur && path.size() > 1)
                break;
        }

        reverse (path.begin(), path.end());


        cout << "YES" << endl << path.size() << endl;

        for (int i = 0; i < path.size(); i++) {
            cout << path[i]+1 << " ";
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}