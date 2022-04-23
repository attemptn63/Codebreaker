#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);
#define int long long
#define f first
#define sec second
#define pb push_back
set<int>s;
int32_t main(){
	speed
	int n,rain=0;cin>>n;
	for(int i = 0;i<n;i++){
		int a,b;cin>>a>>b;
		if(a==1){
			if(s.find(b-rain)!=s.end()){
				cout<<"YES\n";
			}
			else cout<<"NO\n";
		}
		else if(a==2){
			s.insert(b - rain);
		}
		else rain+=b;
	}
}
