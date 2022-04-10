#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int n,p,cats[1000010],ans,s,sum;
int32_t main()
{
	speed
    cin>>n>>p;
    for(int i = 0;i<n;i++){
		cin>>cats[i];
	}
	for(int e = 0;e<n;e++){
		sum+=cats[e];
		while(sum>=p){
			sum-=cats[s];
			s++;
		}
		ans = max(ans,e - s + 1);
	}
	cout<<ans;
}
