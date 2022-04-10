#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() 
{
   vector<int> g[10001];
	int V, E, A, B;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	for (int i = 0; i <= V; i++) {
		for (auto j: g[i]) { 
			cout << j << " ";
		}
		cout<<endl;
	}

}
