#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define f first
#define s second
vector<int>adjlist[1000010];
int ans = 0;
void dfs(int x,int count){
	ans = max(ans,count);
	for(int i:adjlist[x]){
		dfs(i,count+1);
	}
	return;
}
int32_t main(){
	speed
	int n;cin>>n;
	for(int i = 1;i<=n-1;i++){
		int a;cin>>a;
		adjlist[a].push_back(i);
	}
	dfs(0,0);
	cout<<ans+1;
}
