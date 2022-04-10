#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
int n,w,dp[501][501],W[501],V[501];
int32_t main(){
	speed
	cin>>n>>w;
	for(int i = 1;i<=n;i++){
		cin>>W[i]>>V[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=w;j++){
			dp[i][j] = dp[(i-1)][j];
			if(j>=W[i])dp[i][j] = max(dp[i][j],dp[(i-1)][j-W[i]]+V[i]);
			if(j>0)dp[i][j] = max(dp[i][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][w];
}

