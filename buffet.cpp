#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SPEED ios_base::sync_with_stdio(0);cin.tie(NULL);
int p1[1000010],p2[1000010],dp1[1000010],dp2[1000010];
int32_t main(){
	SPEED
	int n,k;cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>p1[i];
	}
	for(int i = 0;i<n;i++){
		cin>>p2[i];
	}
	dp1[0]=p1[0];
	dp2[0]=p2[0];
	for(int i = 1;i<n;i++){
		dp1[i] = max(dp2[i - 1] + p1[i] - k,dp1[i - 1] + p1[i]);
		dp2[i] = max(dp1[i - 1] + p2[i] - k,dp2[i - 1] + p2[i]);
	}
	cout<<max(dp1[n - 1],dp2[n - 1]);
}
