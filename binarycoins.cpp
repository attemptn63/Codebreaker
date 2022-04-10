#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <ll, ll> pi;
string toBinary(unsigned ll n)
{
    string r;
    while(n!=0) {
		r=(n%2==0 ?"0":"1")+r;
		n/=2;
	}
    return r;
}
int main(){
	SPEED
	unsigned ll n; cin>>n;
	if(n == 0){cout<<0;return 0;}
	string s = toBinary(n);
	int ans = 0;
	for(unsigned int i = 0;i<s.length();i++){
		if(s[i] == '1')ans++; 	
	}
	cout<<ans;
}
