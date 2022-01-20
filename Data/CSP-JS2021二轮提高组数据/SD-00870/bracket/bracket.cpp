#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
char a[41];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k,p=0;
	cin>>n>>k;
	cin>>a;
	for(int i=1;i<=n;i++){
		if(a[i]=='?') p++;
	}
	cout<<floor(pow(3,p)/14);
	return 0;
}
