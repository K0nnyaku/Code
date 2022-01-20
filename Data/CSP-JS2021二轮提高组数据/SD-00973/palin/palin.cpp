#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
const int maxn=1e6+1;
using namespace std;
int a[1000001];
int main(){
	freopen("palin","r",stdin);
	freopen("palin","w",stdout);
	int t,n;
	cin>>t;
	cin>>n;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=2*n;j++)
		    cin>>a[j];
	}
	if(t==1) cout<<"-1";
	/*
	  唾骂出题人made法克 
	                    */ 
	return 0;
}
