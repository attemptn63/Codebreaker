#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	SPEED
	ll d,c;
	cin>>d>>c;
	set<ll>friends;
	for(int i = 0;i<c;i++){
		ll a,b;
		cin>>a>>b;
		if(a!=b){
		friends.insert(a);
		friends.insert(b);
		}
	}
	cout<<d - friends.size();
}
