#include <iostream>
using namespace std;

int main() {
    
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

    int e[2];
    int n;
    int m;
    bool cnt = false;

    cin >> n;
    cin >> m;

    int matrix[n][n];


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            matrix[i][j] = 0;

        }
    }

    for (int i = 0; i < m; i++) {

        cin >> e[0] >> e[1];

        matrix[e[0]-1][e[1]-1] ++;

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 1) {
                if (matrix[i][j] = matrix[j][i]) {
                    cnt = true;
                }
            }

            if (matrix[i][j] > 1 ) {
                cnt = true;
            }
        }
    }

    if (cnt == true) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;

}