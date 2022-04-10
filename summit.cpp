#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,d;
int summit(ll num){
	ll reached = num;
	ll deduct = 1;
	for(int i = 0;i < d - 1;i++){
		deduct *= d + i;
		reached += num / deduct;
	}
	if(reached > m){
		return 1;
	}
	else if(reached < m){
		return -1;
	}
	else return 0;
}
int main(){
	cin>>m>>d;
	ll h,l;
	h = m;
	l = 0;
	while(h - l > 1){
		ll mid = (h + l) / 2;
		if(summit(mid) == 1){
			h = mid;
		}
		else if(summit(mid) == -1){
			l = mid;
		}
		else if(summit(mid) == 0){
			cout<<mid;
			return 0;
		}
	}
	cout<<l;
}
