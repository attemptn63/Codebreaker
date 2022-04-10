#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
int n,w,dp[2][100005],W[101],V[101];
int32_t main(){
	speed
	cin>>n>>w;
	for(int i = 1;i<=n;i++){
		cin>>W[i]>>V[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=w;j++){
			dp[i%2][j] = dp[(i-1)%2][j];
			if(j>=W[i])dp[i%2][j] = max(dp[i%2][j],dp[(i-1)%2][j-W[i]]+V[i]);
			if(j>0)dp[i%2][j] = max(dp[i%2][j],dp[i%2][j-1]);
		}
	}
	cout<<dp[n%2][w];
}

