#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pii pair<int,int> 
#define INT_MAX 1000000001
int adjMat[501][501];
void floyd(int N){
	   for(int k = 0; k < N; ++k){ 
	   for(int i = 0; i < N; ++i){
		   for(int j = 0; j < N; ++j){
				adjMat[i][j] = max(min(adjMat[i][k], adjMat[k][j]), adjMat[i][j]);

			}
		}
	}
}
int32_t main(){
	speed
	int n;cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int x;cin>>x;
			if(x!=0){
				adjMat[i][j] = x;
			}
		}
	}
	floyd(n);
	int ans = INT_MAX; 
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			ans = min(ans,adjMat[i][j]);
		}
	}
	cout<<ans;
}

