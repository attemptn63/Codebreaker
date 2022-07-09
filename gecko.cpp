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
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int h,w,ans = 0,mos[505][505],memo[505][505];
int32_t main()
{
	speed
    cin>>h>>w;
    for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			cin>>mos[i][j];
		}
	}
	for(int row = 0;row<h;row++){
		for(int column = 0;column<w;column++){
			if(w!=1){
				if(row == 0)memo[row][column]=mos[row][column];
				else if(column==0)memo[row][column]=max(memo[row-1][column]+mos[row][column],memo[row-1][column+1]+mos[row][column]);
				else if(column==w-1)memo[row][column]=max(memo[row-1][column]+mos[row][column],memo[row-1][column-1]+mos[row][column]);
				else {memo[row][column]=max(memo[row-1][column]+mos[row][column],memo[row-1][column-1]+mos[row][column]);memo[row][column]=max(memo[row-1][column+1]+mos[row][column],memo[row][column]);}
			}
			else{memo[row][column]=memo[row-1][column]+mos[row][column];}
			if(row == h - 1){ans = max(ans,memo[row][column]);}
		}
	}
	cout<<ans;
    return 0;
}
