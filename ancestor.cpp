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
#define f first
#define s second
int p[100005][20],n;
vector<int>adjlist[100005];
void precomp(){
    for (int k=1;k<20;k++) {
        for (int i=0;i<n;i++) {
            if (p[i][k-1] != -1) {
                p[i][k] = p[p[i][k-1]][k-1];
            } else p[i][k] = -1;
        }
    }
}
int kth_parent(int x, int k){
    for (int i = 0; i <= 20; i++){
        if (k & (1 << i)) x = p[x][i];
        if (x <= -1) return -1;
    }
    return x;
}
void dfs(int node,int parent){
    p[node][0] = parent;
    for (auto i : adjlist[node]){if(i == parent)continue;dfs(i,node);}
}
int32_t main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        int a,b;cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(0,-1);
    p[0][0] = -1;
    precomp();
    int q;cin>>q;
    for(int i = 0;i<q;i++){
        int x,k;
        cin>>x>>k;
        cout<<kth_parent(x,k)<<"\n";
    }
}
/*10
0 1
1 2
2 3
3 4
4 5
6 0
7 2
2 8
3 9
5
5 3
5 5
7 2
6 2
8 2
*/
