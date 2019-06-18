#include<iostream>
#include<fstream>
#include<stack>
#include<vector>

using namespace std;


struct V{
    vector<int> edge;
};

V Nodes[10000];




int main (){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    int k1,k2;

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++){

        cin >> k1 >> k2;
        Nodes[k1 - 1].edge.push_back(k2 - 1);
        Nodes[k2 - 1].edge.push_back(k1 - 1);

    }


    for ( int i = 0; i < n; i++){

      cout << Nodes[i].edge.size() << " ";
        }
    return 0;
}
