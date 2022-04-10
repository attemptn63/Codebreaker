#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,starting,pairs = 0;
string names[300001];
ll len[21];
int main(){
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>names[i];
	}
	starting = 0;
	for(int i = 0;i<n;i++){
		if(i - starting > k){
			len[names[starting].length()] -= 1;
			starting += 1;
		}
		len[names[i].length()] += 1;
		pairs += len[names[i].length()] - 1;
	}
	cout<<pairs;
}
