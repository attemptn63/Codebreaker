#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[10000001];
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,c;
	cin>>n>>c;
	for(int i = 1;i<=n;i++)p[i]=i;
	for(int i = 0;i<c;i++){
		int a; cin>>a;
		cout<<find_set(a)<<"\n";
		if(find_set(a)>1)merge_set(find_set(a),find_set(a) - 1);
		else merge_set(a,n);
	}
}
