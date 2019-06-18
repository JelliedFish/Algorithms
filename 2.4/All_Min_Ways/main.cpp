#include <iostream>
#include <vector>


using namespace std;

int main() {


    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);

    const long INF = 1000000;
    long m,n;

    cin >> n >> m;
    vector < vector <long>> table (n,vector <long>(n,INF));



    for (int j = 0; j < m; j++) {
        long k1,k2,k3;

        cin >> k1 >> k2 >> k3;

        table[k1-1][k2-1] = k3;
    }


    for (int k = 0; k < n; k++) {

        for (int j = 0; j < n; j++) {

            for (int i = 0; i < n; i++){

                if (i != j){
                table[i][j] = min(table[i][j],table[i][k]+table[k][j]);
                }
                else {
                    table[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < n; j++) {

            cout << table[i][j] << " ";
        }
    }

    return 0;
}