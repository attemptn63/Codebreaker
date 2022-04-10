#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define pb push_back
#define mod 998244353
main(){
	speed
	int cats,m,s;cin>>cats>>m>>s;
	vector<int>main;
	vector<int>side;
	for(int i = 0;i<m;i++){
		int a;cin>>a;
		main.pb(a);
	}
	for(int i = 0;i<s;i++){
		int a;cin>>a;
		side.pb(a);
	}
	sort(main.begin(), main.end());
    sort(side.begin(), side.end());
    int ans = 0;
    for (int i = 0; i < cats; i++){
        ans = max(main[i] + side[cats - i - 1], ans);
    }
    cout<<ans;
}
