#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <long double, ll> pi;
typedef pair<ll,ll>lpi;
int main(){
	SPEED
	ll n;cin>>n;
	pi fractions[n];
	lpi numbers[n];
	for(int i = 0;i<n;i++){
		long double a,b;cin>>a>>b;
		fractions[i] = pi(a/b,i);
		numbers[i] = lpi(a,b);
	}
	sort(fractions,fractions + n);
	for(int i = 0;i<n;i++){
		cout<<numbers[fractions[i].second].first<<" "<<numbers[fractions[i].second].second<<"\n";
	}
}
