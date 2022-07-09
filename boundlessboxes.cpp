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
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int h,w,s,dist[1010][1010];
queue<pii>q;
bool inBounds(int x, int y){
    return x > 0 && x <= h && y > 0 && y <= w && dist[x][y] == 0;
}

int32_t main(){
	speed
	cin>>h>>w>>s;
	if(h == 1 && w == 1){cout<<1;return 0;}
	for(int i = 0;i<s;i++){
		int x,y;cin>>x>>y;
		dist[x][y]=1;
		q.push(make_pair(x,y));
	}
	int ans = 0;
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		int x = cur.first; int y = cur.second;
		for(int i = 0;i<8;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!inBounds(nx,ny))continue;
			q.push(make_pair(nx,ny));
			dist[nx][ny] = dist[x][y] + 1;
			ans = max(ans, dist[nx][ny]);
		}
	}
	cout<<ans;
}
