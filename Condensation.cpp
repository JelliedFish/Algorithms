#include<iostream>
#include<fstream>
#include<vector>
#include<stack>

using namespace std;

struct V {
    int color = 0;
    int value = 0;
    vector<int> edge ;
};

V Nodes[20000];
V Nodes_reverse[20000];

stack<int> S;
   int k = 0;

void dfs1(int cur){

    Nodes[cur].color = 1;
    for (int i = 0; i < Nodes[cur].edge.size(); i++){
        if (Nodes[Nodes[cur].edge[i]].color == 0){
            dfs1(Nodes[cur].edge[i]);
        }
    }

    S.push(cur);
}

void dfs2(int cur){
    Nodes_reverse[cur].value = k;
    Nodes_reverse[cur].color = 1;
    for (int i = 0; i < Nodes_reverse[cur].edge.size(); i++){
        if (Nodes_reverse[Nodes_reverse[cur].edge[i]].color == 0){
            dfs2(Nodes_reverse[cur].edge[i]);
        }
    }
}

int main(){
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);

    int n, m;
    int k1, k2;

    cin >> n >> m;

    for (int i = 0; i < m; i++){

        cin >> k1 >>k2;
        Nodes[k1 - 1].edge.push_back(k2 - 1);
        Nodes_reverse[k2 - 1].edge.push_back(k1 - 1);
    }

    for (int i = 0; i < n; i++){

        if (Nodes[i].color == 0){
            dfs1(i);
        }
    }

    for (int i = 0; i < n; i++){

        int flag = S.top();
        S.pop();

        if (Nodes_reverse[flag].color == 0){
            k++;
            dfs2(flag);
        }
    }

    cout << k << endl;

    for (int i = 0; i < n; i ++){
        cout << Nodes_reverse[i].value << " ";
            }


return 0;
}