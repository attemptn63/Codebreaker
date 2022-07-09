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
#define pii pair<int,int> 

int32_t main(){
	speed
	int V,E,W;
	cin>>V>>E>>W;
	vector<pii>adjlist[V+1];
	for (int i = 0; i < E; i++) {
		int A,B,C;
		cin >> A >> B >> C;
		adjlist[A].push_back(make_pair(B+1,C));
	}
	for(int i = 1;i<V;i++){
		adjlist[i].push_back(pii(i-1,W));
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // distance, node
	int dist[V + 1];
	memset(dist, -1, sizeof(dist));
	pq.push(make_pair(0, 0)); dist[0] = 0;
	while(!pq.empty()){
		pair<int,int> c = pq.top();
		pq.pop();
		if(c.first != dist[c.second]) continue;
		for (auto i : adjlist[c.second]) {
			if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
				dist[i.first] = c.first + i.second;
				pq.push(make_pair(dist[i.first], i.first));
			}
		}
	}
	cout<<dist[V];
}
