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
#define SPEED ios_base::sync_with_stdio(0);cin.tie(NULL);
int h,w,memo[1010][1010],m = 1000000007;
char wall[1010][1010];
int32_t main(){
	SPEED
	cin>>h>>w;
	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			cin>>wall[i][j];
		}
	}
	for(int i = 0;i<w;i++){
		if(wall[0][i]=='X')break;
		memo[0][i]=1;
	}
	for(int i = 0;i<h;i++){
		if(wall[i][0]=='X')break;
		memo[i][0]=1;
	}
	for(int i = 1;i<h;i++){
		for(int j = 1;j<w;j++){
			if(wall[i][j]=='X'){memo[i][j]=0;continue;}
			memo[i][j]=(memo[i-1][j]+memo[i][j-1])%m;
		}
	}
	cout<<memo[h-1][w-1];
	
}
