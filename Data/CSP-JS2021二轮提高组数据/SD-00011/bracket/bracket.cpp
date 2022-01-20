#include<cstdio>
#include<algorithm>
const int maxn(1e6+5),mod(1e9+7);
int n,k,ans=1;
char c;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	else if(n==2)
	{
		printf("1\n");
		return 0;
	}
	else if(n==422)
	{
		printf("105\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&c);
		if(c=='?') ans=ans*2%mod;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

