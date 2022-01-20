#include<cstdio>
#include<cstdlib>
#include<ctime>

#define fuck return
const int CCF=0;

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(NULL));
	printf("%lld\n",1ll*rand()*rand()%(int)(1e9+7));
	fuck CCF;
}
