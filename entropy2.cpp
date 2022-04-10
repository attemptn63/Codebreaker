#include <bits/stdc++.h>
using namespace std;
const long long oo = (long long)1e18 + 500;
template <typename T> void chmax(T& a, const T b) { a=max(a,b); }
template <typename T> void chmin(T& a, const T b) { a=min(a,b); }
 
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long n,k; cin >> n >> k;
	vector<long long> v;
	long long m=0;
	long long ans=-oo;
	for(long long i = 1; i <= (long long)n; ++i) {
		long long x; cin >> x;
		if(x)v.push_back(x);
		if(x>0)--m;
		if(x<0)++m;
	}
	long long sum= 0;
	for(auto i:v)sum+=i;
		chmax(ans, sum);
	v.push_back(k);
	sort((v).begin(), (v).end(),[](long long a, long long b) {
		return llabs(a) < llabs(b);
	});
 
	long long c = 0;
	for(auto i:v) {
		long long idx = llabs(i);
		long long dif = idx-c;
		sum+=dif*m;
		c=idx;
		if(i>0)++m;
		else --m;
		chmax(ans, sum);
		if(llabs(i)==k)break;
	}
	cout << ans;
}
