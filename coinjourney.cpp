#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
long long n,Q;
long long A[MAXN], ss[MAXN], mx[MAXN];
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1; i <= n; ++i) cin >> A[i];
	for(int i = 1; i <= n; ++i) ss[i]=ss[i-1]+A[i];
	for(int i = 1; i <= n; ++i) mx[i]=max(ss[i],mx[i-1]);
	while(Q--) {
		long long x; cin >> x;
		if(mx[n]<x){
			cout<<-1<<' ';continue;
		}
		long long lo=0,hi=n+1;
		while(lo<hi-1) {
			long long mid=(lo+hi)/2;
			if(mx[mid]>=x)hi=mid;
			else lo=mid;
		}
		cout << hi << ' ';
	}
 
}
