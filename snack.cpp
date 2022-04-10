#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	string s; cin>>s;
	int a[n],maxsum[n];
	for(int i = 0;i<n;i++){
		char c = s[i];
		if(c == 'M')a[i] = -2;
		else a[i] = c - 48;
	}
	int ans = maxsum[0] = a[0];
	if(n > 1){
		for(int i = 1;i<n;i++){
			maxsum[i] = max(maxsum[i - 1] + a[i], a[i]);
			ans = max(maxsum[i],ans);
		}
		if(ans >= 0){
			cout<<ans<<"\n";
		}
		else cout<<0;
	}
	else {
		if(ans >= 0){
			cout<<a[0]<<"\n";
		}
		else cout<<0;
	}
}
	

