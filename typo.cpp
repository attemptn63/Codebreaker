#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,t;
	cin>>s>>t;
	if(s == t){cout<<"Yes";return 0;}
	for(int i = 1;i<(int)s.length();i++){
		swap(s[i],s[i+1]);
		if(s == t){cout<<"Yes";return 0;}
		else swap(s[i+1],s[i]);
	}
	cout<<"No";
}
