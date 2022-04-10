#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define mod 13371337
int n,v,coin[51],dp[51][10001];
int32_t main(){
	speed
	cin>>n>>v;
	memset(dp,0,sizeof(dp));
	memset(coin,0,sizeof(coin));
	for(int i = 1;i<=n;i++){
		cin>>coin[i];
	}
	for(int i = 1;i<=n;i++){
		dp[i][0] = 1;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=v;j++){
			if(j - coin[i] < 0){
				dp[i][j] = dp[i-1][j]%mod;
			}
			else dp[i][j] = (dp[i-1][j]%mod + dp[i][j-coin[i]]%mod)%mod;
		}
	}
	cout<<dp[n][v]%mod;
}

