#include <iostream>
#include <vector>
#include<fstream>


using namespace std;


struct V {
    int number_of_component;
    bool state;
    vector<int> adj;
    int value;
};


V v[100000];
int cnt;

int DFS(int i, int n) {

    v[i].state = false;

    v[i].number_of_component = cnt;

    for (int j = 0;  j < v[i].adj.size() ; j++) {

            if(v[v[i].adj[j]].state == true){
                v[v[i].adj[j]].state == false;

                v[v[i].adj[j]].number_of_component = cnt;

                DFS(v[i].adj[j],n);

            }
        }

        return 1;
}

int main() {

    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);

    int n;
    int m;
    int e[2];


    cin >> n >> m;





    for (int i = 0; i < m; i++) {

        cin >> e[0] >> e[1];

        v[e[0]-1].adj.push_back(e[1]-1);
        v[e[1]-1].adj.push_back(e[0]-1);
    }


    for (int i = 0; i < n; i++) {
      v[i].state = true;
      v[i].number_of_component = 0;
      v[i].value = i+1;
    }


    for (int i = 0; i < n; i++) {

        if (v[i].state == true) {
            cnt++;
            DFS(i,n);
        }
    }
    cout << cnt << endl;

    for (int i = 0; i < n; i++) {
        cout << v[i].number_of_component << " ";
    }
    return 0;
}
