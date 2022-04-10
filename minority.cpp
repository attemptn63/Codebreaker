#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	string s;
	for(int i = 0;i<n;i++){
		cin>>s;
		int zero = 0; int one = 0;
		for(int j = 0;j<s.length();j++){
			if(s[j]=='0') zero++;
			else one++;
		}
		if(s.length()<3){
			cout<<0<<endl;
		}
		else{
			if(zero == one){
				cout<<zero - 1<<endl;
			}
			else cout<<min(zero,one)<<endl;
		}
	}
}
