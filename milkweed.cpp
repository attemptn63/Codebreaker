#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
queue<pi>q;
int h, w;
int start_w,start_h;
bool isgrass[110][110];
int dist[110][110];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int main(){
	cin>>w>>h>>start_w>>start_h;;
	for(int i = h; i >= 1;i--){
		for(int j = 1; j<= w; j++){
			char ca; cin>>ca;
			if(ca == '.'){
				isgrass[i][j] = 1;
			}
		}
	}
	memset(dist, -1, sizeof dist);
	dist[start_h][start_w] = 0;
	q.push(make_pair(start_h,start_w));
	int ans = 0;
	while(!q.empty()){
		pi cur = q.front(); q.pop();
		int x = cur.first; int y = cur.second;
		for(int i = 0;i<8;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx <= 0 or nx > h) continue;
			if(ny <= 0 or ny > w) continue;
			if(isgrass[nx][ny] == 0) continue;
			if(dist[nx][ny] != -1) continue;
			q.push(make_pair(nx,ny));
			dist[nx][ny] = dist[x][y] + 1;
			ans = max(ans, dist[nx][ny]);
		}
	}
	cout<<ans;
}
