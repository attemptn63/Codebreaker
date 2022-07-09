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
int ok;
bool havecats[100001];
vector<int> adjlist[100001];
int dfs(int node, int numcats){
    if (numcats > ok) return 0;
    int ans = 0;
    bool isleaf = true;
    for (auto i : adjlist[node]){
        isleaf = false;
        if (havecats[i]) ans += dfs(i, numcats + 1);
        else ans += dfs(i, 0);
    }
    if (isleaf) return 1;
    else return ans;
}
int main() {
    int n;
    cin >> n >> ok;
    for (int i = 1; i <= n; i++){
        int f; cin >> f;
        havecats[i] = f == 1;
    }
    int a, b;
    while (cin >> a >> b){
        adjlist[a].push_back(b);
    }
    cout << dfs(1, (havecats[1] ? 1 : 0)) << endl;
}
