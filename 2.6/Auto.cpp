#include <bits/stdc++.h>

using namespace std;
string t,p;
void naiveStringMatcher(string t, string p){
    int n = t.length();
    int m = p.length();
    vector<int> answer;
    for(int i = 0; i < n - m+1; i++){
        if(t.substr(i,m) == p){
            answer.push_back(i);
        }
    }
    cout << answer.size() << endl;
    for(size_t i = 0; i < answer.size(); i++){
        cout << answer[i]+1 << " ";
    }
}


int main()
{
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);

    cin >> p >> t;

    naiveStringMatcher(t,p);
    return 0;
}
