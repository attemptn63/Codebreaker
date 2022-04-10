#include <iostream>
#include <algorithm>
using namespace std;
bool waytosort(int i, int r){
    return i > r;
}

int main(){
    int n,limit,highest;
    int excess = 0;
    int day[1000], night[1000];
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> day[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> night[i];
    }
    cin >> limit;

    sort(day,day+n);
    sort(night,night + n,waytosort);
    for(int i = 0; i < n; ++i){
        if(day[i] + night[i] > limit){
            highest = day[i] + night[i];
            excess += highest - limit;
        }
    }
    cout << excess * 100;
}
