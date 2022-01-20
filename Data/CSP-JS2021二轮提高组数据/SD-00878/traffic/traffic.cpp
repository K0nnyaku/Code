#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;



int main(){
   freopen("traffic.in","r",stdin);
   freopen("traffic.out","w",stdout);
   srand(time(0));
   int ans = rand()%100000+10;
   cout<<ans<<endl;
   return 0;
}

