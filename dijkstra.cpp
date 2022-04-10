#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll V, E, A, B, C;
	
	cin >> V >> E;
	vector<pair<ll,ll> > adjList[V + 1];
	for (ll i = 0; i < E; i++) {
		cin >> A >> B >> C;
		adjList[A].push_back(make_pair(B,C));
		adjList[B].push_back(make_pair(A,C));
	}
	priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq; // distance, node
	ll dist[V + 1];
	memset(dist, -1, sizeof(dist));
	pq.push(make_pair(0, 1)); dist[1] = 0;
	while(!pq.empty()){
		pair<ll,ll> c = pq.top();
		pq.pop();
		if(c.first != dist[c.second]) continue;
		for (auto i : adjList[c.second]) {
			if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
				dist[i.first] = c.first + i.second;
				pq.push(make_pair(dist[i.first], i.first));
			}
		}
	}
	cout<<dist[V];
}
