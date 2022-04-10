#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x[MAXN],y[MAXN];
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	ll best = LLONG_MAX;
	int xans = 0;
	for (int i = 0; i < n; ++i) {
		long long sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += abs(x[i] - x[j]);
		}
		if (sum < best) {
			best = sum;
			xans = x[i];
		}
	}
	best = LLONG_MAX;
	int yans = 0;
	for (int i = 0; i < n; ++i) {
		long long sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += abs(y[i] - y[j]);
		}
		if (sum < best) {
			best = sum;
			yans = y[i];
		}
	}
	cout << xans << " " << yans << endl;
}
