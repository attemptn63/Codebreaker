#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define f first
#define s second
vector<int> adjlist[200001];
int preorder[200001];
int end1[200001];
int ssize[200001];
int ctr = 0;
int dfs(int node,int parent){
	preorder[node] = ctr++;
	ssize[node] = 1;
	for (int i : adjlist[node]){if(i == parent)continue; ssize[node] += dfs(i,node);}
	end1[node] = ctr-1;
	return ssize[node];
}
int32_t main(){
	speed
	int V, A;
	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> A;
		adjlist[A].push_back(i);
	}
	dfs(0,-1);
	cin>>A;
	for(int i = 0;i<A;i++){
		int x;cin>>x;
		vector<int>temp;
		for(int i = 0;i<x;i++){
			int b;cin>>b;
			temp.push_back(b);
		}
		sort(temp.begin(),temp.end(),[](int a, int b){
            return preorder[a] < preorder[b];
        });
		int ans = 0;int endp = 0;
		for(int i:temp){
			if(preorder[i]<=endp)continue;
			ans += ssize[i];
			endp = end1[i];
		}
		cout<<ans<<"\n";
	}
}

