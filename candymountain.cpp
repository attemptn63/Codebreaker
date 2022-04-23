#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);
#define int long long
#define f first
#define sec second
#define pb push_back
multiset<int>s;
int mount[100005],dp[100005];
int32_t main(){
	speed
	int n,k;cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>mount[i];
	}
	for(int i = 0;i<k;i++){
		s.insert(mount[i]);
		dp[i] = mount[i];
	}
	for(int i = k;i<=n;i++){
		int x = *s.begin();
		dp[i] = max(x,mount[i]);
		s.erase(s.find(dp[i-k]));
		s.insert(dp[i]);
	}
	cout<<dp[n];
}
	  
	  
	  
	  
	  
	  
	  
	  
	  
	

