#include <bits/stdc++.h>
using namespace std;
vector<int> g[510];
int dist[510];
bool visited[510];
int V, E, A, B;	
queue<int>q;
int main(){
	memset(dist,-1,sizeof(dist));
	memset(visited,0,sizeof(visited));
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}
	q.push(1);
	dist[1] = 0;
	visited[1] = 1;
	while(!q.empty()){
		int cur = q.front();q.pop();
		for(auto i: g[cur]){
			if(!visited[i]){
				q.push(i);
				visited[i]= true;
				dist[i] = dist[cur] + 1;
			}
		}
	}
	int ans = 0;
	for(int i = 2;i<=V;i++){
		if(dist[i]<=2 && dist[i] != -1){
			ans++;
		}
	}
	cout<<ans;
}

