#include <iostream>
using namespace std;

int main() {


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    bool cnt = true;

    cin >> n;

    int matrix[n][n];


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> matrix[i][j];

        }
    }


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (i == j) {
                if (matrix[i][j] == 1){
                    cnt = false;
                }
            }

            if (matrix[i][j] == 1) {
                if (matrix[i][j] != matrix[j][i]) {
                    cnt = false;
                }
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