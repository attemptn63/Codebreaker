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
int n,e1,e2,x1,x2,line1[10001],line2[10001],dp1[10001],dp2[10001],swap1[10000],swap2[10000];
int32_t main(){
	speed
	cin>>n>>e1>>e2;
	for(int i = 0;i<n;i++){
		cin>>line1[i];
	}
	for(int i = 0;i<n;i++){
		cin>>line2[i];
	}
	for(int i = 1;i<n;i++){
		cin>>swap1[i];
	}
	for(int i = 1;i<n;i++){
		cin>>swap2[i];
	}
	cin>>x1>>x2;
	dp1[0]=e1+line1[0];
	dp2[0]=e2+line2[0];
	for(int i = 1;i<n;i++){
		dp1[i] = min(dp1[i-1],dp2[i-1]+swap2[i]) + line1[i];
		dp2[i] = min(dp2[i-1],dp1[i-1]+swap1[i]) + line2[i];
	}
	int ans = min(dp1[n-1]+x1,dp2[n-1]+x2);
	cout<<ans;
	
}

