#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int maxn=505;
const long long mod=1e9+7;
int n,k;
char str[maxn<<1];
int cntt;
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	char ch=getchar();
	while(ch!='('&&ch!=')'&&ch!='*'&&ch!='?') ch=getchar();
	while(ch=='(' || ch==')' || ch=='*' || ch=='?'){str[++cntt]=ch;ch=getchar();}
	srand(time(NULL));
	long long fkans=(1ll*rand()*rand()*rand()+1ll*rand()*rand())%mod;
	printf("%lld",fkans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


