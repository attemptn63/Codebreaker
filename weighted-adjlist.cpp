#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int main() 
{
   vector<pi>adjlist[1005];
   int v, e, a ,b ,w;
   cin >> v >> e;
   for(int i = 0;i<e;i++){
	   cin>>a>>b>>w;
	   adjlist[a].push_back(make_pair(b,w));
	   adjlist[b].push_back(make_pair(a,w));
   }
   for(int i = 0;i<v;i++){
	   for(auto cur: adjlist[i]){
		   cout << i << " " << cur.first << " " << cur.second << "\n";
	   }
   }
}
