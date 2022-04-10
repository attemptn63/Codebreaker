#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define f first
#define s second
vector<int> adjlist[500001];
int ssize[500001];
int dist[500001];
int total =0;
int n;
int dfs(int node,int parent,int depth_so_far){
	ssize[node] = 1;
	total += depth_so_far;
	for (auto i : adjlist[node]){if(i == parent)continue; ssize[node] += dfs(i,node,depth_so_far+1);}
	return ssize[node];
}
void findans(int u, int p, int sum){
    for (auto v : adjlist[u]){
        if (v==p) continue;
        int csum = sum - ssize[v] + ::n - ssize[v];
        total += csum;
        findans(v, u, csum);
    }
}

int32_t main(){
	speed
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);

	}
	dfs(1,-1,0);
	findans(1,-1,total);
	cout<<total;
}

