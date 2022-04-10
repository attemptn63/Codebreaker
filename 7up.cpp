#include <bits/stdc++.h>
using namespace std;
bool contain7(string X){
        if(X.find('7')<X.length()){ 
            return true;
        }
        else return false;
}
int main() {
    int N,K,X;
    cin>>N>>K>>X;
    for(int i=0;i<K;i++){
        if(X%7==0 || contain7(to_string(X))){
            cout<<"UP!"<<"\n";
            static_cast<int>(X);
            X+=N;

        }
        else{
            cout<<(int)X<<"\n";
            X+=N;
        }
    }
    
}
