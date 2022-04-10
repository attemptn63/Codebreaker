#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int h,w,ans = 0,mos[505][505],memo[505][505];
int32_t main()
{
	speed
    cin>>h>>w;
    for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			cin>>mos[i][j];
		}
	}
	for(int row = 0;row<h;row++){
		for(int column = 0;column<w;column++){
			if(w!=1){
				if(row == 0)memo[row][column]=mos[row][column];
				else if(column==0)memo[row][column]=max(memo[row-1][column]+mos[row][column],memo[row-1][column+1]+mos[row][column]);
				else if(column==w-1)memo[row][column]=max(memo[row-1][column]+mos[row][column],memo[row-1][column-1]+mos[row][column]);
				else {memo[row][column]=max(memo[row-1][column]+mos[row][column],memo[row-1][column-1]+mos[row][column]);memo[row][column]=max(memo[row-1][column+1]+mos[row][column],memo[row][column]);}
			}
			else{memo[row][column]=memo[row-1][column]+mos[row][column];}
			if(row == h - 1){ans = max(ans,memo[row][column]);}
		}
	}
	cout<<ans;
    return 0;
}
