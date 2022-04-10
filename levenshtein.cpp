#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
int edit[3000][3000];
int32_t main(){
	speed
	string A,B;cin>>A>>B;
	int N = A.length();
	int M = B.length();
	for(int i = 0;i <= N;i++){	
		for(int j = 0;j <= M;j++){
			if(i == 0 || j == 0){edit[i][j] = max(i,j);continue;}
			if(A[i-1] == B[j-1])edit[i][j] = edit[i-1][j-1];
			else edit[i][j] = edit[i-1][j-1] + 1;
			edit[i][j] = min(edit[i][j],edit[i-1][j]+1);
			edit[i][j] = min(edit[i][j],edit[i][j-1]+1);
		}
	}
	cout<<edit[N][M];
}

