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
typedef long long ll;
#define MAX_N 2000
#define MAX_T 2000

vector<int> solved[MAX_N];
int points[MAX_T];
int score[MAX_N];
bool poiLess(int x, int y)
{
    if (score[x] > score[y])
        return true;
    else if (score[x] == score[y])
    {
        if (solved[x].size() > solved[y].size())
            return true;
        else if (solved[x].size() == solved[y].size())
            return x < y;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int n, t, p;

    scanf("%d %d %d", &n, &t, &p);
    assert(1 <= n && n <= MAX_N);
    assert(1 <= t && t <= MAX_T);
    assert(1 <= p && p <= n);

    p--;

    memset(points, 0, sizeof(points));
    for (int i = 0; i < n; i++)
    {
        solved[i].reserve(n);
        int x;
        for (int j = 0; j < t; j++)
        {
            scanf("%d", &x);
            if (x == 1)
                solved[i].push_back(j);
            else
                points[j]++;
        }
    }

    vector<int> sortedIds;
    sortedIds.reserve(n);
    for (int i = 0; i < n; i++)
    {
        score[i] = 0;
        for (unsigned int j = 0; j < solved[i].size(); j++)
            score[i] += points[solved[i][j]];
        sortedIds.push_back(i);
    }

    sort(sortedIds.begin(), sortedIds.end(), poiLess);
    for (int i = 0; i < n; i++)
        if (sortedIds[i] == p)
        {
            cout << score[p] << " " << (i + 1) << endl;
            return 0;
        }
    assert(false);

    return 0;
}
