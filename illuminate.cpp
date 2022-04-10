#include <bits/stdc++.h>
using namespace std;
int main(){
	long long h,l,empty = 0,ans = 0,count = 0;
	cin>>h>>l;
	char light[h][l];
	for(int i = 0;i<h;i++){
		for(int j = 0;j<l;j++){
			cin>>light[i][j];
			if(light[i][j]=='.')empty++;
		}
	}
	for(int i = 0;i<h;i++){
		for(int j = 0;j<l;j++){
			if(light[i][j]=='#'){
				ans+=count*count;
				count = 0;
			}
			else count++;
		}
		ans+=count*count;
		count = 0;
	}
	for(int i = 0;i<l;i++){
		for(int j = 0;j<h;j++){
			if(light[j][i]=='#'){
				ans+=count*count;
				count = 0;
			}
			else count++;
		}
		ans += count*count;
		count = 0;
	}
	cout<<ans - empty;
	
}
