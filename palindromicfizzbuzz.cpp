#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <ll,ll> pi;
bool ifPalindrome(ll x){
	string s = to_string(x);
	string p = s;
	reverse(p.begin(),p.end());
	return p == s;
}
int main(){
	SPEED
	ll a,b;
	cin>>a>>b;
	for(ll i = a;i<=b;i++){
		if(ifPalindrome(i))cout<<"Palindrome!"<<"\n";
		else cout<<i<<"\n";
	}
}
