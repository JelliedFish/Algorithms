#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>





using namespace std;

struct V{
    int x;
    int y;
    bool color = false;
};
const long INF = 1000000000;

int main() {

  freopen("spantree.in", "r", stdin);
  freopen("spantree.out", "w", stdout);


    int n;
    double sum = 0;
    int k1,k2;

 cin    >>  n;

   vector <vector <double>> table;
    vector <V> Nodes(n);
    vector <double > min_e(n,INF);


    for (int i = 0 ; i < n; i++) {

   cin  >>  k1 >> k2;

      Nodes[i].x = k1;
      Nodes[i].y = k2;

    }

    for (int i = 0 ; i < n; i++) {
     table.resize(n);

        for (int j = 0 ; j < n; j++) {
        table[i].resize(n);

         table [i][j] = sqrt((Nodes[i].y-Nodes[j].y)*(Nodes[i].y-Nodes[j].y) + (Nodes[i].x-Nodes[j].x)*(Nodes[i].x-Nodes[j].x));

        }
    }


    for (int i = 0 ; i < n; i++) {

        int v = -1;

        for (int j = 0; j < n; j++) {
            if ((!Nodes[j].color) && ((v == -1) || (min_e[j] < min_e[v])))
                v = j;
        }


        Nodes[v].color = true;

        if (i != 0) {
        sum += min_e[v];
        }

        for (int k = 0; k < n; k++) {

            if (((table[v][k] < min_e[k]) && (!Nodes[k].color)) && (table[v][k] != 0)) {
                min_e[k] = table[v][k];
            }

        }

    }

cout << fixed << setprecision(20) <<  sum;


        return 0;
}