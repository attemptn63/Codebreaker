#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin>>t;
	for(int  i = 0;i < t;i++){
		ll query; cin>>query;
		ll l = 0;
		ll u = 1000000;
		while(u - l > 1){
			ll a =(u+l)/2;
			if(a*a*a>query){
				u = a;
			}
			else l = a;
		}
		cout<<l<<"\n";
	}
}
