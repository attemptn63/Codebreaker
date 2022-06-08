#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);
#define pi pair<int,int>
#define pb(x) push_back(x)
#define pob() pop_back()

int main() {
	speed
	int N;cin>>N;
	int H[N];
	for(int i = 0;i<N;i++){
		cin>>H[i];
	}
	vector<int>st;
	int ptr = 0;
	for(int i = 1;i<=N;i++){
		st.pb(i);
		while(!st.empty() && H[ptr] == st.back()){
			st.pob();
			ptr++;
		}
	}
	if(st.empty())cout<<"safe and sound";
	else cout<<"seven years of misfortune";
}
