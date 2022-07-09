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
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define pi pair<int,int> 
#define pii pair<int,pi>
int fw[100001], fw2[100001];
const int N = 100000;
void update(int x, int y, int v) { 
    for (int tx=x; tx <= N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (int ty=y+1; ty <= N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y; 
}
int sum (int x) {
    int res = 0;
    for (int tx=x; tx>0; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
    return res;
}
int range_sum(int x, int y) {
    return sum(y)-sum(x-1);
}

main(){
	speed
	int n;cin>>n;
	for(int i = 1;i<=n;i++){
		int temp;cin>>temp;
		update(i,i,temp);
	}
	int coms;cin>>coms;
	while(coms--){
		int type;cin>>type;
		if(type == 0){
			int a,b;cin>>a>>b;
			cout<<range_sum(a+1,b+1)<<"\n";
		}
		else{
			int a,b,c;cin>>a>>b>>c;
			update(a+1,b+1,c);
		}
	}
}

