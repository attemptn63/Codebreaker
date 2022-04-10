#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define f first
#define s second
int n,e1,e2,x1,x2,line1[10001],line2[10001],dp1[10001],dp2[10001],swap1[10000],swap2[10000];
int32_t main(){
	speed
	cin>>n>>e1>>e2;
	for(int i = 0;i<n;i++){
		cin>>line1[i];
	}
	for(int i = 0;i<n;i++){
		cin>>line2[i];
	}
	for(int i = 1;i<n;i++){
		cin>>swap1[i];
	}
	for(int i = 1;i<n;i++){
		cin>>swap2[i];
	}
	cin>>x1>>x2;
	dp1[0]=e1+line1[0];
	dp2[0]=e2+line2[0];
	for(int i = 1;i<n;i++){
		dp1[i] = min(dp1[i-1],dp2[i-1]+swap2[i]) + line1[i];
		dp2[i] = min(dp2[i-1],dp1[i-1]+swap1[i]) + line2[i];
	}
	int ans = min(dp1[n-1]+x1,dp2[n-1]+x2);
	cout<<ans;
	
}

