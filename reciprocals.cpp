#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <ll, ll> pi;
int main(){
	SPEED
	int n,m;cin>>n>>m;
	if(n%m==0){
		for(int i = 0;i<n;i++){
			cout<<n/m<<" ";
		}
		return 0;
	}
	else{
		for(int i = 1;i<m;i++)cout<<1<<" ";
		for(int i = 0;i<(n-m+1);i++)cout<<(n-m+1)<<" ";
	}
}
