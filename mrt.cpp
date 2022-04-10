#include <bits/stdc++.h>
#define pii pair<int, int>
#define vpii vector<pii>
#define INT_MAX 1000000001
using namespace std;
int dist[200][200];
void floyd(int V){
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 200; j++){
            if (i == j){
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = INT_MAX;
            
        }
    }
    int stations, tracks, queries;
    cin >> stations >> tracks >> queries;
    for (int i = 0; i < tracks; i++){
        int s, e, tdist;
        cin >> s >> e >> tdist;
        dist[s][e] = tdist;
        dist[e][s] = tdist;
    }
    floyd(stations);
    int s, e;
    while (cin >> s >> e){
        cout << (dist[s][e] == INT_MAX ? -1 : dist[s][e]) << '\n';
    }
}
