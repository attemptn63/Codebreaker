#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define f first
#define s second
vector<int> adjlist[100010];
int memo[100010][2];
int dp(int node,bool taken,int parent){
	if(memo[node][taken]!=-1)return memo[node][taken];
	int ans = taken;
	for(auto i: adjlist[node]){
		if(i == parent)continue;
		if(taken)ans+=dp(i,0,node);
		else ans += max(dp(i,0,node),dp(i,1,node));
	}
	return memo[node][taken] = ans;
}
int32_t main(){
	speed
	int n;cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);

	}
	memset(memo,-1,sizeof(memo));
	cout<<max(dp(1,0,-1),dp(1,1,-1));
}
