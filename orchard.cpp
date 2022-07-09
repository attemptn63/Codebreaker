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
short input[150][1000000];
int p[1000000];
int twoDMaxSum(int h, int w){
    int ans = INT_MIN;
    for (int i = 0; i < h; i++){
        for (int k = 0; k < w; k++){p[k] = 0;}
        for (int j = i; j < h; j++ ){
            int sum = 0;
            for (int k = 0; k < w; k++){
                p[k] += input[j][k];
                sum = max(p[k],sum+p[k]);
                ans = max(sum,ans);
            }
        }
    }
    return ans;
}
int main() {
    int h, w, num1s = 0;
    cin >> h >> w;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            int d;
            cin >> d;
            input[i][j] = (d == 0 ? -1: 1);
            if (d == 1) num1s++;
        }
    }
    cout << num1s - twoDMaxSum(h, w) << endl;
}
