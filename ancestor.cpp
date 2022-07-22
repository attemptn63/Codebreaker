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
int p[100005][20],n,ctr=0;
vector<int>adjlist[100005];
void precomp(){
    for (int k=1;k<20;k++) {
        for (int i=0;i<n;i++) {
            if (p[i][k-1] != -1) {
                p[i][k] = p[p[i][k-1]][k-1]; // 2^k parent is the 2^(k-1)th parent’s 2^(k-1)th parent
            } else p[i][k] = -1; // no 2^k-th parent
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
    for (int i : adjlist[node]){if(i == parent)continue;p[i][0]=node;dfs(i,node);}
}
int32_t main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        int a,b;cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(0,-1);
    precomp();
    int q;cin>>q;
    for(int i = 0;i<q;i++){
        int x,k;
        cin>>x>>k;
        cout<<kth_parent(x,k)<<"\n";
    }
}
