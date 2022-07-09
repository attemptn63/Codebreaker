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
#define INT_MAX 1000000001
int adjMat[501][501];
void floyd(int N){
	   for(int k = 0; k < N; ++k){ 
	   for(int i = 0; i < N; ++i){
		   for(int j = 0; j < N; ++j){
				adjMat[i][j] = max(min(adjMat[i][k], adjMat[k][j]), adjMat[i][j]);

			}
		}
	}
}
int32_t main(){
	speed
	int n;cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int x;cin>>x;
			if(x!=0){
				adjMat[i][j] = x;
			}
		}
	}
	floyd(n);
	int ans = INT_MAX; 
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			ans = min(ans,adjMat[i][j]);
		}
	}
	cout<<ans;
}

