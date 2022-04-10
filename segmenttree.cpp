#include <bits/stdc++.h>
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
