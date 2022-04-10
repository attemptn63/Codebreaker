#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SPEED ios_base::sync_with_stdio(0);cin.tie(NULL);
int h,w,memo[1010][1010],m = 1000000007;
char wall[1010][1010];
int32_t main(){
	SPEED
	cin>>h>>w;
	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			cin>>wall[i][j];
		}
	}
	for(int i = 0;i<w;i++){
		if(wall[0][i]=='X')break;
		memo[0][i]=1;
	}
	for(int i = 0;i<h;i++){
		if(wall[i][0]=='X')break;
		memo[i][0]=1;
	}
	for(int i = 1;i<h;i++){
		for(int j = 1;j<w;j++){
			if(wall[i][j]=='X'){memo[i][j]=0;continue;}
			memo[i][j]=(memo[i-1][j]+memo[i][j-1])%m;
		}
	}
	cout<<memo[h-1][w-1];
	
}
