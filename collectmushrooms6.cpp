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

vector<pair<int, int>> mms;
int main() {
    int r, c, d, k;
    cin >> r >> c >> d >> k;
    int input[r+1][c+1];
    int dp[r+1][c+1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            char w; cin >> w;
            if (w == 'M') {mms.push_back({i, j});input[i][j]=0;}
            if (w == 'S') input[i][j] = 1;
            else input[i][j] = 0;
        }
    }
    for (int i = 1; i <= r; i++) { 
        for (int j = 1; j <= c; j++) 
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 
                        - dp[i - 1][j - 1] + input[i][j]; 
    }
    int ans = 0;
    for (auto i : mms){
        int x1 = i.first - d; if (x1 <= 0) x1 = 1;
        int x2 = i.first + d; if (x2 > r) x2 = r;
        int y1 = i.second - d; if (y1 <= 0) y1 = 1;
        int y2 = i.second + d; if (y2 > c) y2 = c;
        int f = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        if (f >= k) ans++;
    }
    cout << ans << endl;
}
