#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() 
{
	int a,total = 0; cin>>a;
	int coms[a],op;
	if(a%2=1){
		op = a - 1;
		op /= 2;
	}
	else{
		op = a - 1;
		op /= 2;
		op += 1;
	}
	for(int i = 0; i < a; i++){
		cin>>coms[i];
		total += coms[i];
	}
	for(int i = 0; i < a; i++){
		int b = coms[i];
		int totalA = total, totalB = total;
		for(int j = 1; j < a; j++){
			//something ig
		}
	}
}
/*
 * The idea is that after the first hack, the unaccessible half is taken
 * by the operator. Hence, consider every node as the first move and 
 * find the best half for the operator to take: Add halves of either 
 * side and find the bigger one. If number of nodes are even, the two
 * players get an equal number. However, the operator would have 1 more 
 * piece as the original node is excluded. Hence, for even it is a bit
 * more complicated. For odd, just find the larger half on either side 
 * of the original node. Time Complexity: O(N^2)
 */
