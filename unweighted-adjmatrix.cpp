#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() 
{
   int v, e, a, b;
   cin>>v>>e;
   int g[v+1][v+1];
   memset(g,0,sizeof(g));
   for(int i = 0;i<e;i++){
	   cin>>a>>b;
	   g[a][b]= 1;
	   g[b][a]= 1;
   }
   for(int i = 1;i<=v;i++){
	   for(int j = 1;j<=v;j++){
		   cout<<g[i][j];
	   }
	   cout<<"\n";
   }
}
