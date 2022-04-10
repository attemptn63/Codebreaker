#include <bits/stdc++.h>
using namespace std;
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
	for (int i = 0; i < N; ++i) p[i] = i;
}
