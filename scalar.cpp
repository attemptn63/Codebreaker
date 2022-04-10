#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
   cin>>n;
   vector<long long>v1;
   vector<long long>v2;
   for(int i = 0;i<n;i++){
       long long a; cin>>a;
       v1.push_back(a);
   }
    for(int i = 0;i<n;i++){
    long long a; cin>>a;
    v2.push_back(a);
   }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<long long>());
    long long c = 0;
    for(int i = 0;i<n;i++){
        c+= v1.back()*v2.back();
        v1.pop_back();
        v2.pop_back();
    }
    cout<<c;
}
