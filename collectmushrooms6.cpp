#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mms;
int main() {
    int r, c, d, k;
    cin >> r >> c >> d >> k;
    int input[r+1][c+1];
    int dp[r+1][c+1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            char w; cin >> w;
            if (w == 'M') {mms.push_back({i, j});input[i][j]=0;}
            if (w == 'S') input[i][j] = 1;
            else input[i][j] = 0;
        }
    }
    for (int i = 1; i <= r; i++) { 
        for (int j = 1; j <= c; j++) 
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 
                        - dp[i - 1][j - 1] + input[i][j]; 
    }
    int ans = 0;
    for (auto i : mms){
        int x1 = i.first - d; if (x1 <= 0) x1 = 1;
        int x2 = i.first + d; if (x2 > r) x2 = r;
        int y1 = i.second - d; if (y1 <= 0) y1 = 1;
        int y2 = i.second + d; if (y2 > c) y2 = c;
        int f = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        if (f >= k) ans++;
    }
    cout << ans << endl;
}
