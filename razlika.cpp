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

const int MIN_V = -5000000;
const int RANGE_V = 10000001;

void countingSort(vector<int>& v) {
  vector<int> f(RANGE_V);
  for (int i = 0; i < (int) v.size(); ++i) {
    ++f[v[i] - MIN_V];
  }
  for (int i = 0, j = 0; i < RANGE_V; ++i) {
    while (f[i]--) {
      v[j++] = MIN_V + i;
    }
  }
}

int solve(vector<int>& v, int n, int k) {
  countingSort(v);
  k = n - k;
  
  deque<pair<int, int> > q;
  int ans = 2147483647;
  
  for (int i = 1; i < n; ++i) {
    if (!q.empty() && q.front().second - 1 <= i - k) {
      q.pop_front();
    }
    int d = v[i] - v[i - 1];
    while (!q.empty() && q.back().first >= d) {
      q.pop_back();
    }
    q.push_back(make_pair(d, i));
    
    if (i >= k - 1) {
      int M = v[i] - v[i - k + 1];
      int m = q.front().first;
      ans = min(ans, M + m);
    }
  }
  
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cout << solve(v, n, k) << "\n";
  
  return 0;
}
