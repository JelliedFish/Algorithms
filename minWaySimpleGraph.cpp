#include<iostream>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

struct V{
    char Value;

    int distance;
    char parent ;

};

int main (){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;

    V Matrix [n][m];

    int StartI, StartJ,FinishI,FinishJ;
    queue<int> QI;
    queue<int>QJ;
    stack<char> stack_way;


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> Matrix[i][j].Value;

            if (Matrix[i][j].Value == 'S'){
                StartI = i;
                StartJ = j;
            }
            if (Matrix[i][j].Value == 'T'){
                FinishI = i;
                FinishJ = j;
            }
        }
    }

    QI.push(StartI);
    QJ.push(StartJ);


    Matrix[StartI][StartJ].distance = 0;

    while (!QI.empty()){

        int vi = QI.front();
        int vj = QJ.front();
        QI.pop();
        QJ.pop();


        if (vj - 1 > -1){

            if (Matrix[vi][vj - 1].Value == '.'){
                Matrix[vi][vj - 1].Value = '#';
                QI.push(vi);
                QJ.push(vj-1);
                Matrix[vi][vj - 1].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi][vj- 1].parent = 'L';



            }
            else if (Matrix[vi][vj - 1].Value == 'T'){
                Matrix[vi][vj - 1].Value = '#';
                Matrix[vi][vj - 1].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi][vj - 1].parent = 'L';

                break;
            }
        }

        if (vj + 1 < m){

            if (Matrix[vi][vj + 1].Value  == '.'){
                Matrix[vi][vj + 1].Value = '#';
                QI.push(vi);
                QJ.push(vj+1);
                Matrix[vi][vj + 1].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi][vj + 1].parent = 'R';

            }
            else if (Matrix[vi][vj + 1].Value  == 'T'){
                Matrix[vi][vj + 1].Value = '#';
                Matrix[vi][vj + 1].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi][vj + 1].parent = 'R';
                break;
            }
        }


        if (vi - 1 > -1){

            if (Matrix[vi - 1][vj].Value  == '.'){
                Matrix[vi - 1][vj].Value = '#';
                QI.push(vi-1);
                QJ.push(vj);
                Matrix[vi - 1][vj].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi - 1][vj].parent = 'U';
            }
            else if (Matrix[vi - 1][vj].Value  == 'T'){
                Matrix[vi - 1][vj].Value = '#';
                Matrix[vi - 1][vj].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi - 1][vj].parent = 'U';
                break;
            }
        }

        if (vi + 1 < n){

            if (Matrix[vi + 1][vj].Value == '.'){
                Matrix[vi + 1][vj].Value = '#';
                QI.push(vi+1);
                QJ.push(vj);
                Matrix[vi + 1][vj].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi+ 1][vj].parent = 'D';
            }
            else if (Matrix[vi + 1][vj].Value == 'T'){
                Matrix[vi + 1][vj].Value = '#';
                Matrix[vi + 1][vj].distance = Matrix[vi][vj].distance + 1;
                Matrix[vi + 1][vj].parent = 'D';
                break;
            }
        }
    }
    int vi = FinishI;
    int vj = FinishJ;
    if (Matrix[vi][vj].parent == 'R'|| Matrix[vi][vj].parent == 'L'|| Matrix[vi][vj].parent == 'U'|| Matrix[vi][vj].parent == 'D'){
        cout << Matrix[FinishI][FinishJ].distance << endl;

        for (int i = 0; i < Matrix[FinishI][FinishJ].distance; i++){

            if (Matrix[vi][vj].parent == 'L'){
                vj = vj + 1;
                stack_way.push('L');
            }
            else  if (Matrix[vi][vj].parent == 'R'){
                vj = vj - 1;
                stack_way.push('R');


            }
            else if (Matrix[vi][vj].parent == 'D'){
                vi = vi - 1;
                stack_way.push('D');



            }
            else  if (Matrix[vi][vj].parent == 'U'){
                vi = vi + 1;
                stack_way.push('U');

            }
        }
        for (int i = 0; i < Matrix[FinishI][FinishJ].distance; i++){
            cout << stack_way.top();
            stack_way.pop();
        }
    }
    else {
        cout << -1;
    }




    return 0;
}