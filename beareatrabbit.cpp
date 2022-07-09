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
int A[200010],memo[200010][2],n;
int dp(int x, int taken){
    if (memo[x][taken] != -1) return memo[x][taken];
    if (taken){
        if (x + 2 < n) return memo[x][taken] = max(dp(x + 2, 0), dp(x + 2, 1) + A[x + 2]);
    } else {
        if (x + 1 < n) return memo[x][taken] = max(dp(x + 1, 0), dp(x + 1, 1) + A[x + 1]);
    }
    return memo[x][taken] = 0;
}
int32_t main(){
	SPEED
	cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    memset(memo, -1, sizeof memo);
    cout << max(dp(0, 1) + A[0], dp(0, 0));
}
