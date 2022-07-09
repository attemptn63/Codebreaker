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
struct node{
   int start, end, middle, val;
   node *left = nullptr;
   node *right = nullptr;
   node(int s, int e): start(s), end(e), middle((s+e)/2), val(0){
        if (start != end){
            left = new node(start, middle);
            right = new node(middle + 1, end);
        }
   }
   void update(int idx, int value){
       if (start == end){
           val = value;
           return;
       }
       if (idx <= middle){
           left->update(idx, value);
       } 
       if (idx > middle){
           right->update(idx, value);
       }
       val = min(left->val, right->val);
   }
   int rmq(int s, int e){
       if (start == s && end == e) return val;
       if (s > middle) return right->rmq(s, e);
       if (e <= middle) return left->rmq(s, e);
       return min(left->rmq(s, middle), right->rmq(middle + 1, e));
   }
};
node* root;
void init(int N) {
    root = new node(0, N - 1);
}

void update(int P, int V) {
    root->update(P, V);
}

int query(int A, int B) {
    return root->rmq(A, B);
}

static int N, Q;

int main() {
    scanf("%d%d", &N, &Q);
    init(N);
    for ( int i = 0; i < Q; i++ ) {
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);
        if ( A == 1 ) update(B, C);
        else printf("%d\n", query(B, C));
    }
    return 0;
}
