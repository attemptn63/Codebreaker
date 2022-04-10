#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ipad[10010];
int a,s;
bool yes(int mid){
	int squid = 1;
	int grp = 0;
	for(int i = 0; i<a;i++){
		if(ipad[i] > mid){
			return false;
		}
		else if(grp + ipad[i] > mid){
			grp = 0;
			squid+=1;
			i -= 1;
		}
		else grp += ipad[i];
	}
	if(squid<=s){
		return true;
	}
	else return false;
}

int main(){
	cin>>a>>s;
	int max = 0;
	for(int i = 0;i<a;i++){
		cin>>ipad[i];
		max += ipad[i];
	}
	int h = max;
	int l = 0;
	while(h - l > 1){
		int mid = (h + l)/2;
		if(yes(mid)){
			h = mid;
		}
		else l = mid;
	}
	cout<<h;
}
