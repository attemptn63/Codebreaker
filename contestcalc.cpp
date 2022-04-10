#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,c;
	cin>>n;
	map<string,int>score;
	for(int i = 0;i<n;i++){
		string name;
		int scores;
		cin>>name>>scores;
		score[name] = scores;
	}
	cin>>c;
	long long ans = 0;
	for(int i = 0;i<c;i++){
		string name;
		cin>>name;
		ans += score[name];
	}
	ans/=c;
	cout<<ans;
}
