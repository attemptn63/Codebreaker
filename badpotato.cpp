#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
main(){
	speed
	int n;cin>>n;
	int ans = 0,bestans[n];
	int first;cin>>first;
	if(first>=0){bestans[0]=first;ans = first;}
	else bestans[0] = 0;
	for(int i = 1;i<n;i++){
		int a;cin>>a;
		if(a>=0)bestans[i]=bestans[i-1]+a;
		else bestans[i] = 0;
		ans = max(bestans[i],ans);
	}
	cout<<ans;
}

