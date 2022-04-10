#include <bits/stdc++.h>
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

