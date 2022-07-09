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
int main() 
{
	int a,total = 0; cin>>a;
	int coms[a],op;
	if(a%2=1){
		op = a - 1;
		op /= 2;
	}
	else{
		op = a - 1;
		op /= 2;
		op += 1;
	}
	for(int i = 0; i < a; i++){
		cin>>coms[i];
		total += coms[i];
	}
	for(int i = 0; i < a; i++){
		int b = coms[i];
		int totalA = total, totalB = total;
		for(int j = 1; j < a; j++){
			//something ig
		}
	}
}
/*
 * The idea is that after the first hack, the unaccessible half is taken
 * by the operator. Hence, consider every node as the first move and 
 * find the best half for the operator to take: Add halves of either 
 * side and find the bigger one. If number of nodes are even, the two
 * players get an equal number. However, the operator would have 1 more 
 * piece as the original node is excluded. Hence, for even it is a bit
 * more complicated. For odd, just find the larger half on either side 
 * of the original node. Time Complexity: O(N^2)
 */
