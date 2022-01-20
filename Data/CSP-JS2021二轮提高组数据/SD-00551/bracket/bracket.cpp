#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
string a;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracker.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>a;
	int len=a.length();
	a[len-1]=')';
	a[0]=')';
	int num=0;
	for(int i=0;i<len;i++){
		if(a[i]=='?') num++;
	}
	printf("%d\n",n+(k*num)-1);
	return 0;
}
