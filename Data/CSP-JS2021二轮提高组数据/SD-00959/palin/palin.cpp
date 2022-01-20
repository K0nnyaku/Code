#include<cstdio>
using namespace std;
int n,l,r,a[1000005],w[1000005],used;
bool ch[1000005],ok;
bool check()
{
	int i;
	for(i=1;i<=n;++i)if(w[i]!=w[2*n+1-i])return 0;
	return 1;
}
void work(int step)
{
	if(step==2*n+1)
	{
		if(check())ok=1;
		return;
	}
	ch[step]=0;
	w[step]=a[l++];
	work(step+1);
	l--;
	if(ok)return;
	ch[step]=1;
	w[step]=a[r--];
	work(step+1);
	r++;
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n*2;++i)scanf("%d",&a[i]);
		ok=0;l=1;r=2*n;
		work(1);
		if(!ok)printf("-1\n");
		else
		{
			for(i=1;i<=2*n;++i)
				if(ch[i]==0)printf("L");
				else printf("R");
			printf("\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

