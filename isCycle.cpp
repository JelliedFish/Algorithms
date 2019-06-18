#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

struct Elem{
    int color = 0;
    vector<int> edge;
    Elem *parent;

};

int finder;
Elem V[100000];
int start, endd;
bool flag = false;

vector<int> parent;
bool Dfs(int index,int prev_index){


    V[index]->parent = *V[prev_index]

    if (V[index] != finder ) {


        V[index].color = 1;

        for (int i = 0; i < V[index].edge.size(); i++) {

            if (V[V[index].edge[i]].color == 0) {
                if (Dfs(V[index].edge[i]),index) {
                    return 1;
            }
        }

        V[index].color = 2;
        return 0;
    }
    else {
        for(int i = 0; i < V.size(); i++) {
            V[i].color = 2;
        }
    }
}

int main (){
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);

    int n, m;
    int l,r;

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        cin >> l >> r;
        V[l-1].edge.push_back(r-1);
    }

    for (int i = 0; i < n; i++){
        if (V[i].color == 0){
            if ( Dfs(i)){
                break;
            }
        }
    }


    if (flag){
        cout << "YES" << endl;

        int i = cycle.size() - 2;
        while(cycle[i] != cycle[cycle.size()-1]){
            i--;
        }
        for (i; i < cycle.size() - 1; i++){
            cout << cycle[i] << " ";
        }
    }

    else{
        cout << "NO";
    }

    return 0;
}