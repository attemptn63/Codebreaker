#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
#define f first
#define s second
vector<int> adjlist[1000005];
int preorder[1000005];
int end1[1000005];
int ssize[1000005];
int ctr = 1;
int V, A, Q;
int ft[1000005];               
int ls(int x){
	return (x & (-x));
}

void update(int l, int r, int v){         
	r++;                                 
	for(; l <= V; l += ls(l)) ft[l] += v;	
	for(; r <= V; r += ls(r)) ft[r] -= v;
}

int query(int p){                         	
	int sum = 0;
	for(; p; p -= ls(p)) sum += ft[p];
	return sum; 
}

void dfs(int node,int parent){
	preorder[node] = ctr++;
	ssize[node] = 1;
	for (int i : adjlist[node]){if(i == parent)continue;dfs(i,node);}
	end1[node] = ctr-1;
}
int32_t main(){
	speed
	cin >> V >> Q; 
	for(int i = 0; i < V; i++) {
		cin >> A;
		if(A!=-1){
			adjlist[A].push_back(i);
		}
	}
	dfs(0,-1);
	for(int i = 0;i < V; i++){
		int x;cin>>x;
		update(preorder[i],preorder[i],x);
	}
	for(int i = 0;i< Q; i++){
		cin>>A;
		if(A == 1){
			int x;cin>>x;
			cout<<query(preorder[x])<<'\n';
		}
		else{
			int x,raise;
			cin>>x>>raise;
			update(preorder[x],end1[x],raise);
		}
	}
}
