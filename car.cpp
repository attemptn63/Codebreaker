#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define f first
#define s second
vector<pii>edgelist;
int p[1000010];
int n,E,ans;
int find_set(int x){
	if (p[x] == x) return x;  
	p[x] = find_set(p[x]);
	return p[x];
}
bool same_set(int a, int b) {
	return find_set(a) == find_set(b);
}
void merge_set(int a, int b) {  
	p[find_set(a)] = find_set(b);
}
int32_t main(){
	speed
	cin >> n >> E;
	for(int i = 0;i<E;i++){
		int a,b,c;cin>>a>>b>>c;
		edgelist.push_back(pii(c,pi(a,b)));
	}
	sort(edgelist.begin(),edgelist.end());
	for(int i = 1;i<=n;i++)p[i]=i;
	for(auto edge: edgelist){
		int c = edge.f;
		int a = edge.s.f;int b = edge.s.s;
		if(!same_set(a,b)){
			merge_set(a,b);
			ans = max(ans,c);
		}
		if(same_set(1,n))break;
	}
	cout<<ans;
}

