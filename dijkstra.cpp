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
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll V, E, A, B, C;
	
	cin >> V >> E;
	vector<pair<ll,ll> > adjList[V + 1];
	for (ll i = 0; i < E; i++) {
		cin >> A >> B >> C;
		adjList[A].push_back(make_pair(B,C));
		adjList[B].push_back(make_pair(A,C));
	}
	priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq; // distance, node
	ll dist[V + 1];
	memset(dist, -1, sizeof(dist));
	pq.push(make_pair(0, 1)); dist[1] = 0;
	while(!pq.empty()){
		pair<ll,ll> c = pq.top();
		pq.pop();
		if(c.first != dist[c.second]) continue;
		for (auto i : adjList[c.second]) {
			if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
				dist[i.first] = c.first + i.second;
				pq.push(make_pair(dist[i.first], i.first));
			}
		}
	}
	cout<<dist[V];
}
