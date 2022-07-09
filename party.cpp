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
vector<int> g[510];
int dist[510];
bool visited[510];
int V, E, A, B;	
queue<int>q;
int main(){
	memset(dist,-1,sizeof(dist));
	memset(visited,0,sizeof(visited));
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}
	q.push(1);
	dist[1] = 0;
	visited[1] = 1;
	while(!q.empty()){
		int cur = q.front();q.pop();
		for(auto i: g[cur]){
			if(!visited[i]){
				q.push(i);
				visited[i]= true;
				dist[i] = dist[cur] + 1;
			}
		}
	}
	int ans = 0;
	for(int i = 2;i<=V;i++){
		if(dist[i]<=2 && dist[i] != -1){
			ans++;
		}
	}
	cout<<ans;
}

