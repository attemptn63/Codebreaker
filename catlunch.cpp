#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
priority_queue<int>pq;
queue<int>q;
main(){
	speed
	int n,k;cin>>n>>k;
	for(int i = 0;i<n;i++){
		int a;cin>>a;
		if(i<k)pq.push(a);
		else q.push(a);
	}
	int preval = 0;
	int ans = 0;
	for(int i = 0;i<n;i++){
		preval+=pq.top();
		pq.pop();
		ans = max(ans,preval);
		if(!q.empty()){
			pq.push(q.front());q.pop();
		}
	}
	cout<<ans;
}

