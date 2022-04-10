#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[100001];
int power[100001];
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
	for(int i = 1;i<=n;i++){
		cin>>power[i];
		p[i] = i;
	}
	for(int i = 0;i<c;i++){
		int a,b;
		cin>>a>>b;
		if(same_set(a,b)){
			cout<<-1<<"\n";
			continue;
		}
		if(power[find_set(a)] > power[find_set(b)]){
			merge_set(b,a);
			cout<<find_set(a)<<"\n";
		}
		else if(power[find_set(a)] < power[find_set(b)]){
			merge_set(a,b);
			cout<<find_set(b)<<"\n";
		}
	}
}
