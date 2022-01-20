#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
char s[1001];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	cout<<n*k%1000000007<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
