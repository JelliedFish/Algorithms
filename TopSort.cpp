#include<iostream>
#include<fstream>
#include<stack>
#include<vector>

using namespace std;


struct V{
    int color = 0;
    vector<int> edge;
};

stack <int> S;
V Nodes[100000];


bool DFS( int cur ){

    Nodes[cur].color = 1;

    for (int i = 0; i < Nodes[cur].edge.size(); i++){

        if (Nodes[Nodes[cur].edge[i]].color == 1){
            return false;
        }

        if (Nodes[Nodes[cur].edge[i]].color == 0){
            if (!DFS(Nodes[cur].edge[i])){
                return false;
            }
        }
    }

    Nodes[cur].color = 2;
    S.push(cur + 1);
    return true;
}


int main (){
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);

    int n, m;
    int k1,k2;

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++){

        cin >> k1 >> k2;
        Nodes[k1 - 1].edge.push_back(k2 - 1);
    }


    for ( int i = 0; i < n; i++){

        if (Nodes[i].color == 0){

            if (!DFS(i)){

                int k = S.size();
                for(int i = 0; i < k; i++){
                    S.pop();
                }
                S.push(-1);
                break;
            }
        }
    }

    int k = S.size();

    for (int i = 0; i < k ; i++){
        cout << S.top()<<" ";
        S.pop();
    }

    return 0;
}
