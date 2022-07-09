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
#define int long long
using namespace std;
vector<int> rabbits;
int memo[4010][4010];
int dp(int pos, int k){
    if (k == 0 || pos > rabbits.size() - 1) return 0;
    if (memo[pos][k] != -1) return memo[pos][k];
    return memo[pos][k] = max(dp(pos + 1, k), dp(pos + 2, k - 1) + rabbits[pos]);
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(memo, -1, sizeof memo);
    int n, k; cin >> n >> k;
    if (n == 1){
        int g; cin >> g; 
        if (g > 0) cout << g << endl;
        else cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        int g; cin >> g;
        rabbits.push_back(g);
    }
    ans = dp(0, k);
    int g; cin >> g; rabbits.push_back(g);
    memset(memo, -1, sizeof memo);
    ans = max(ans, dp(1, k));
    cout << ans << endl;
}
