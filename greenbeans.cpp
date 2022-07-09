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
int K[305], T[305], S[305];
int memo[305][305][1001];
int n;
int dp(int idx, int completed, int t){
    if (t == 0 || idx == n || completed < S[idx]) return 0;
    if (memo[idx][completed][t] != -1) return memo[idx][completed][t];
    int ans = -1e9;
    if (t >= T[idx]) ans = max(ans, dp(idx+1, completed+1, t-T[idx]) + K[idx]);
    ans = max(ans, dp(idx+1, completed, t));
    return memo[idx][completed][t] = ans;
}
int32_t main()
{   
    memset(memo, -1, sizeof memo);
    int m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> K[i] >> T[i] >> S[i];
    }
    cout << max(0, dp(0, 0, m)) << endl;
}
