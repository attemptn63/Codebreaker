#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int main() {
    int num;
    cin >> num;
    int num1st;
    cin >> num1st;
    dp.push_back(num1st);
    for (int i = 1; i < num; i++){
        int points;
        cin >> points;
        if (points < dp[i - 1] + points) dp.push_back(points);
        else dp.push_back(dp[i - 1] + points);
    }
    cout << *min_element(begin(dp), end(dp)) << endl;
}
