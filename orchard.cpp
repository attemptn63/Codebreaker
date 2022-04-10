#include <bits/stdc++.h>
using namespace std;
short input[150][1000000];
int p[1000000];
int twoDMaxSum(int h, int w){
    int ans = INT_MIN;
    for (int i = 0; i < h; i++){
        for (int k = 0; k < w; k++){p[k] = 0;}
        for (int j = i; j < h; j++ ){
            int sum = 0;
            for (int k = 0; k < w; k++){
                p[k] += input[j][k];
                sum = max(p[k],sum+p[k]);
                ans = max(sum,ans);
            }
        }
    }
    return ans;
}
int main() {
    int h, w, num1s = 0;
    cin >> h >> w;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            int d;
            cin >> d;
            input[i][j] = (d == 0 ? -1: 1);
            if (d == 1) num1s++;
        }
    }
    cout << num1s - twoDMaxSum(h, w) << endl;
}
