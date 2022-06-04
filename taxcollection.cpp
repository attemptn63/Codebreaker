#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pb(x) push_back(x)
#define pob() pop_back()
int main(){
	ll n;cin>>n;
	ll arr[n];
	bool tf[n];
	vector<ll>pref;
	for(ll i = 0;i<n;i++){
		cin>>arr[i];
	}
	for(ll i = 0;i<n;i++){
		cin>>tf[i];
		if(tf[i]){
			pref.pb(arr[i]);
		}
	}
	sort(pref.begin(),pref.end());
	for(ll i = 0;i<n;i++){
		if(tf[i]){
			arr[i] = pref.back();
			pref.pob();
		}
	}
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		ans += arr[i]*(n-i);
	}
	cout<<ans;
}
