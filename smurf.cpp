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
   int n,check,check2;
   cin>>n;
   deque<int>smurf;
   if(n%2==0){
	   check = 0;
   }
   else check = 1;
   check2 = 0;
   for(int i = 0;i<n;i++){
	   int a;
	   cin>>a;
	   if(check2 == 0 && check == 0){
		   smurf.push_back(a);
	   }
	   else if(check2 == 1 && check == 0){
		   smurf.push_front(a);
	   }
	   else if(check2 == 0 && check == 1){
		   smurf.push_front(a);
	   }
	   else smurf.push_back(a);
	   if(check2 == 0){
		   check2 = 1;
	   }
	   else check2 = 0;
   }
   for(int i = 0;i<n;i++){
	   cout<< smurf[i]<<" ";
   }
}

