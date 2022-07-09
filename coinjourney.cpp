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
const long long MAXN = 1000005;
long long n,Q;
long long A[MAXN], ss[MAXN], mx[MAXN];
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1; i <= n; ++i) cin >> A[i];
	for(int i = 1; i <= n; ++i) ss[i]=ss[i-1]+A[i];
	for(int i = 1; i <= n; ++i) mx[i]=max(ss[i],mx[i-1]);
	while(Q--) {
		long long x; cin >> x;
		if(mx[n]<x){
			cout<<-1<<' ';continue;
		}
		long long lo=0,hi=n+1;
		while(lo<hi-1) {
			long long mid=(lo+hi)/2;
			if(mx[mid]>=x)hi=mid;
			else lo=mid;
		}
		cout << hi << ' ';
	}
 
}
