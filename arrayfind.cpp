#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n; cin>>n;
	int find[n];
	for(int i = 0;i<n;i++){
		cin>>find[i];
	}
	sort(find, find + n);
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int x; cin>>x;
		int smaller = lower_bound(find, find + n,x) - find;
		int greater = upper_bound(find, find + n,x) - find;
		cout<<"Smaller: "<<smaller<<", Greater: "<<n - greater<<endl;
	}
		
}
