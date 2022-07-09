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
const long long oo = (long long)1e18 + 500;
template <typename T> void chmax(T& a, const T b) { a=max(a,b); }
template <typename T> void chmin(T& a, const T b) { a=min(a,b); }
 
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long n,k; cin >> n >> k;
	vector<long long> v;
	long long m=0;
	long long ans=-oo;
	for(long long i = 1; i <= (long long)n; ++i) {
		long long x; cin >> x;
		if(x)v.push_back(x);
		if(x>0)--m;
		if(x<0)++m;
	}
	long long sum= 0;
	for(auto i:v)sum+=i;
		chmax(ans, sum);
	v.push_back(k);
	sort((v).begin(), (v).end(),[](long long a, long long b) {
		return llabs(a) < llabs(b);
	});
 
	long long c = 0;
	for(auto i:v) {
		long long idx = llabs(i);
		long long dif = idx-c;
		sum+=dif*m;
		c=idx;
		if(i>0)++m;
		else --m;
		chmax(ans, sum);
		if(llabs(i)==k)break;
	}
	cout << ans;
}
