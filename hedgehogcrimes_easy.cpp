#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define pb push_back
#define mod 998244353
int dp[3005][3005],n,k;;
int add(int a, int b) {return (a % mod + b % mod) % mod;}
int f(int idx, int used) {
	if (dp[idx][used] != -1) return dp[idx][used];
	if (idx == 0) return 1;
	int res = f(idx - 1, 0);
	if (used + 1 < k) res = add(res, f(idx - 1, used + 1));
	return dp[idx][used] = res;
}
main(){
	speed
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<f(n+1,k+1);
}
