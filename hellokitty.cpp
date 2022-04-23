#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define sec second
#define pb push_back
#define pi pair<int,int>
set<pi>s;
vector<int>x;
vector<int>y;
vector<int>xpr;
vector<int>ypr;
int32_t main(){
	int n;cin>>n;
	for(int i = 0;i<n;i++){
		int a,b;cin>>a>>b;
		x.pb(a);y.pb(b);
		s.insert(pi(a,b));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	xpr.pb(x[0]);
	ypr.pb(y[0]);
	for(int i = 1;i<n;i++){
		xpr.pb(xpr[i-1] + x[i]);
		ypr.pb(ypr[i-1] + y[i]);
	}
	int q;cin>>q;
	for(int i = 0;i<q;i++){
		int a,b;cin>>a>>b;
		if(s.find(pi(a,b))!=s.end()){cout<<"Cannot build here.\n";continue;}
		if(a==0&&b==0){cout<<xpr.back()+ypr.back()<<"\n";continue;}
		int xj = upper_bound(x.begin(),x.end(),a) - x.begin();
		int yj = upper_bound(y.begin(),y.end(),b) - y.begin();
		int ans;
		if(xj==0)ans = xpr.back() - n * a;
		else ans = xj * a - 2*xpr[xj-1] + xpr.back() - (n-xj) * a;
		if(yj==0)ans+=ypr.back() - n * b;
		else ans+= yj * b - 2*ypr[yj-1] + ypr.back() - (n-yj) * b;
		cout<<ans<<"\n";
	}	
}
	  
	  
	  
	  
	  
	  
	  
	  
	  
	

