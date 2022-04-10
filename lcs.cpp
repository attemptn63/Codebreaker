#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int dp[1001][1001];
int32_t main()
{
	speed
    string a,b;cin>>a>>b;
    for(int i=1;i<=a.length();i++){
		for(int j = 1;j<=b.length();j++){
			if(a[i-1] == b[j - 1])dp[i][j]=dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			
		}
	}
    cout<<dp[a.length()][b.length()];
}
