#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,v;
	cin>>n>>v;
	int dp[v + 1],coin[n];
	for(int i = 0;i<n;i++){
		cin>>coin[i];
	}
	dp[0] = 0;
	for(int i = 1;i<=v;i++){
		dp[i] = 10010;	
	}
	for(int i = 1;i<=v;i++){
		for(int j = 0;j<n;j++){
			if(i>=coin[j]){
				dp[i] = min(dp[i - coin[j]] + 1,dp[i]);
			}	
		}
	}
	if(dp[v] >= 10010){
		cout<<-1;
	}
	else cout<<dp[v];
}
