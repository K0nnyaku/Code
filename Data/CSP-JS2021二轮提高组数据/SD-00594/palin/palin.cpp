#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[2000005];
char s[2000005];
bool check(int l,int r,int L,int R)
{
	if(l==2) s[1]='L';
	else s[1]='R';
	s[n+1]=0;
	s[n]='L';
	int t=1,u=n-1;
	while(l<=r||L<=R)
	{
		if(l<=r)
		{
			if(l<r&&a[l]==a[r])
			{
				s[++t]='L';
				s[u--]='L';
				l++,r--;
				continue;
			}
			if(a[l]==a[L])
			{
				s[++t]='L';
				s[u--]='R';
				l++,L++;
				continue;
			}
		}
		if(L<=R)
		{
			if(a[R]==a[r])
			{
				s[++t]='R';
				s[u--]='L';
				r--,R--;
				continue;
			}
			if(L<R&&a[R]==a[L])
			{
				s[++t]='R';
				s[u--]='R';
				L++,R--;
				continue;
			}
		}
		return 0;
	}
/*	printf("t=%d,u=%d\n",t,u);
	for(int i=0;i<=n+1;i++)
		printf("%d ",s[i]);
	printf("\n"); */
	printf("%s\n",s+1);
	return 1;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n*=2;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int id=-1;
		for(int i=2;i<=n;i++)
			if(a[i]==a[1]) id=i;
		if(check(2,id-1,id+1,n)) continue;
		id=-1;
		for(int i=1;i<n;i++)
			if(a[i]==a[n]) id=i;
		if(!check(1,id-1,id+1,n-1))
			printf("-1\n");
	}
	return 0;
}
