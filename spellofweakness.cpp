#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <ll, ll> pi;
vector<ll>health;
ll n,d,k;
bool possible(ll a){
	ll sum = accumulate(health.begin(),health.begin() + a, 0LL);
	for(ll i = a - 1, j = 0; i >= 0 && j < k;i--, j++){
		sum -= health[i] - (health[i]/2);
	}
	return sum <= d;
}
int main(){
	SPEED
	cin>>n>>d>>k;
	for(ll i = 0;i<n;i++){
		ll g; cin>>g;
		health.push_back(g);
	}
	sort(health.begin(), health.end());
	ll mini = 0;
	ll maxi = n + 1;
	while(maxi - mini > 1){
		ll mid = (maxi + mini)/2;
		if(possible(mid))mini = mid;
		else maxi = mid;
	}
	cout<<mini;
}
