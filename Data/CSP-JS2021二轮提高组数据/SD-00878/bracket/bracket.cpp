#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

char c[10005];
int n,k;
int posi[10005];

char tmp[10005];
long long cnt = 0;

bool check(string a,int b,int d){
	for(int i=1;i<=b;i++){
		for(int j=i;j<=d;j++){
			if(a[1] == ')') return false;
			if(a[n] == '*') return false;
		}
	}
}

int main(){
   freopen("bracket.in","r",stdin);
   freopen("bracket.out","w",stdout);
   cin>>n>>k;
   int p=0;
   for(int i=1;i<=n;i++){
   	cin>>c[i];
   	if(c[i]=='?') posi[p++] = i;
   }
   memcpy(tmp,c);
   for(int i=1;i<=p;i++){//枚举 ?-->(的可能 
   	for(int j=1;j<=p;j++){//枚举 ?-->*的可能 
   		if(i == j) continue;
   		  for(int k=1;k<=p;k++){//枚举 ?-->)的可能 
   		  	if( j==k || i==k) continue;
   		  	tmp[posi[i]] = '(';
   		  	tmp[posi[j]] = '*';
   		  	tmp[posi[k]] = ')';
   		    if(check(tmp,n,k)) cnt++;
		 }
	   }
   }
   cout<<cnt<<endl;
   return 0;
}

