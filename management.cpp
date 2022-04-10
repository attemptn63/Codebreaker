#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <ll,ll> pi;
int main(){
	SPEED
	int n;cin>>n;
	int manage[n];
	memset(manage,0,sizeof(manage));
	for(int i = 1;i<n;i++){
		int a; cin>>a;
		manage[a-1]++;
	}
	for(int i = 0;i<n;i++){
		cout<<manage[i]<<"\n";
	}
}
