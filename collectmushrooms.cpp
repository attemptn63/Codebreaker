#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <ll,ll> pi;
int main(){
	SPEED
	int n,m; cin>>n>>m;
	int mush[n];
	for(int i = 0;i<n;i++){
		cin>>mush[i];
	}
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a == 1)mush[b] = c;
		else{
			int ans = mush[b];
			for(int j = b + 1;j<=c;j++){
				ans = max(ans,mush[j]);
			}
			cout<<ans<<"\n";
		}
	}
}
