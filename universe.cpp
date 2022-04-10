#include <bits/stdc++.h>
using namespace std;
int ok;
bool havecats[100001];
vector<int> adjlist[100001];
int dfs(int node, int numcats){
    if (numcats > ok) return 0;
    int ans = 0;
    bool isleaf = true;
    for (auto i : adjlist[node]){
        isleaf = false;
        if (havecats[i]) ans += dfs(i, numcats + 1);
        else ans += dfs(i, 0);
    }
    if (isleaf) return 1;
    else return ans;
}
int main() {
    int n;
    cin >> n >> ok;
    for (int i = 1; i <= n; i++){
        int f; cin >> f;
        havecats[i] = f == 1;
    }
    int a, b;
    while (cin >> a >> b){
        adjlist[a].push_back(b);
    }
    cout << dfs(1, (havecats[1] ? 1 : 0)) << endl;
}
