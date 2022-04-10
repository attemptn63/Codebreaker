#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,even = 0,odd = 0; cin>>n;
	for(int i = 0;i<n;i++){
		int a; cin>>a;
		if(a%2==0){
			even++;
		}
		else odd++;
	}
	cout<<even*odd;
}
