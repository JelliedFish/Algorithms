#include<iostream>
#include<fstream>
#include<vector>
#include<stack>

using namespace std;

struct V{
    vector<int> edge;
    int color = 0;
};

V Nodes[100000];
bool flag = true;
stack<int> S;
vector<int> S_1;


void TopSort(int cur){

    Nodes[cur].color = 2;

    for (int i = 0; i < Nodes[cur].edge.size(); i++){

        if (Nodes[Nodes[cur].edge[i]].color == 0 ){

            TopSort(Nodes[cur].edge[i]);

        }
    }

    S.push(cur);
}

bool Hamilitonian (int cur){

    for (int i = 0; i < Nodes[S_1[cur]].edge.size(); i++){

        if (S_1[cur + 1] == Nodes[S_1[cur]].edge[i]){

            return true;
        }
    }
    return false;
}


int main(){

   freopen("hamiltonian.in", "r", stdin);
   freopen("hamiltonian.out", "w", stdout);

    int n, m;
    int k1, k2;

    cin >> n >> m;

    for ( int i = 0; i < m; i++){

        cin >> k1 >> k2;
        Nodes[k1-1].edge.push_back(k2-1);
    }

    for (int i = 0; i < n; i++){

        if (Nodes[i].color == 0){
            TopSort(i);
        }
    }


    for (int i = 0; i < n; i++){
        S_1.push_back(S.top());
        S.pop();

    }

    for (int i = 0; i < S_1.size() - 1; i++){

        if (!Hamilitonian(i)){
            flag = false;
            cout << "NO";
            break;
        }
    }

    if(flag){
        cout <<"YES";
    }

return 0;
}
