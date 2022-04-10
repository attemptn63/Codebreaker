#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	ll arr[a], prefix[a];
	for(int i = 0;i<a;i++){
		cin>>arr[i];
		prefix[i] = 0;
		if(i == 0)prefix[i] = arr[i];
		else prefix[i] = prefix[i - 1] + arr[i];
	}
	for(int i = 0;i<b;i++){
		int c,d;
		cin>>c>>d;
		if(c == 1)cout<<prefix[d -1]<<"\n";
		else cout<<prefix[d - 1] - prefix[c - 2]<<"\n";
	}
}
