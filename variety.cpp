#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pii pair<int,int> 

int32_t main(){
	speed
	int V,E,W;
	cin>>V>>E>>W;
	vector<pii>adjlist[V+1];
	for (int i = 0; i < E; i++) {
		int A,B,C;
		cin >> A >> B >> C;
		adjlist[A].push_back(make_pair(B+1,C));
	}
	for(int i = 1;i<V;i++){
		adjlist[i].push_back(pii(i-1,W));
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // distance, node
	int dist[V + 1];
	memset(dist, -1, sizeof(dist));
	pq.push(make_pair(0, 0)); dist[0] = 0;
	while(!pq.empty()){
		pair<int,int> c = pq.top();
		pq.pop();
		if(c.first != dist[c.second]) continue;
		for (auto i : adjlist[c.second]) {
			if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
				dist[i.first] = c.first + i.second;
				pq.push(make_pair(dist[i.first], i.first));
			}
		}
	}
	cout<<dist[V];
}
