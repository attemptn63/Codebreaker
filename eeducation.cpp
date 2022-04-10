#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair <ll, ll> pi;
int main(){
	SPEED
	int a,b;
	cin>>a>>b;
	int fall[a];
	int check[b];
	vector<int>ans;
	for(int i = a-1;i>=0;--i){
		cin>>fall[i];
	}
	for(int i = 0;i<b;i++){
		cin>>check[i];
	}
	sort(check,check+b);
	for(int i = 0;i<a;i++){
		int x = lower_bound(check,check+b,fall[i]) - check;
		if(check[x] == fall[i])ans.push_back(fall[i]);
	}
	for(unsigned int i = 0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
