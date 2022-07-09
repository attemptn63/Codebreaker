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
vector<pii>edgelist;
int p[1000010];
int answers[500000];
int n,E,Q;
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
int32_t main(){
	speed
	cin >> n >> E >> Q;
	memset(answers,5,sizeof answers);
	for(int i = 0;i<E;i++){
		int a,b,c;cin>>a>>b>>c;
		edgelist.push_back(pii(c,pi(a,b)));
	}
	sort(edgelist.begin(),edgelist.end(),greater<pii>());
	for(int i = 1;i<=n;i++)p[i]=i;
	for(auto edge: edgelist){
		int c = edge.f;
		int a = edge.s.f;int b = edge.s.s;
		if(!same_set(a,b)){
			merge_set(a,b);
		}
	}
	answers[1] = 0;
	for(int i = 0;i<Q;i++){
		int x;cin>>x;
		//dfs here
	}
}

/*
4 4 2
1 2 10
1 3 30
2 4 20 
3 4 5
3 4
*/
