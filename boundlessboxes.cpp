#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pii pair<int,int> 
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int h,w,s,dist[1010][1010];
queue<pii>q;
bool inBounds(int x, int y){
    return x > 0 && x <= h && y > 0 && y <= w && dist[x][y] == 0;
}

int32_t main(){
	speed
	cin>>h>>w>>s;
	if(h == 1 && w == 1){cout<<1;return 0;}
	for(int i = 0;i<s;i++){
		int x,y;cin>>x>>y;
		dist[x][y]=1;
		q.push(make_pair(x,y));
	}
	int ans = 0;
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		int x = cur.first; int y = cur.second;
		for(int i = 0;i<8;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!inBounds(nx,ny))continue;
			q.push(make_pair(nx,ny));
			dist[nx][ny] = dist[x][y] + 1;
			ans = max(ans, dist[nx][ny]);
		}
	}
	cout<<ans;
}
