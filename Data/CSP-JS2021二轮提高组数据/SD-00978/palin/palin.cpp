#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 500005
using namespace std;
int ans1[N],a[N*4],cnt1,cnt2,cnta,cntb,ans2[N];
bool book[N];
struct BWE
{
	int id,num;
	bool used;
}l[N*4],r[N*4];
bool cmp(BWE x,BWE y)
{
	return x.num<y.num;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(ans1,0,sizeof ans1);
		memset(ans2,0,sizeof ans2);
		memset(book,false,sizeof book);
		cnt1=cnt2=cnta=cntb=0;
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
			//a[n*2+i]=a[i];
		}
		int x=0,y=0;
		for(int i=2;i<=n*2;i++)		
			if(a[i]==a[1])
			{
				x=i;
				break;
			}
		for(int i=1;i<n*2;i++)
			if(a[i]==a[n*2])
			{
				y=i;
				break;
			}
		int ll=1,rr=x;
		ans1[++cnta]=a[ll];
		while(1)
		{
			//printf("%d %d\n",ll,rr);
			int l1=ll-1,l2=ll+1,r1=rr-1,r2=rr+1;
			if(ll==1)
				l1=n*2;
			if(rr==1)
				r1=n*2;
			if(ll==n*2)
				l2=1;
			if(rr==n*2)
				r2=1;
			if(book[l1]&&book[l2]&&book[r1]&&book[r2])
				break;
			//ans[++cnt]=a[ll];
			book[ll]=book[rr]=true;
			if(!book[l1])
				l[++cnt1].id=l1,l[cnt1].num=a[l1];
			if(!book[l2])
				l[++cnt1].id=l2,l[cnt1].num=a[l2];
			if(!book[r1])
				r[++cnt2].id=r1,r[cnt2].num=a[r1];
			if(!book[r2])
				r[++cnt2].id=r2,r[cnt2].num=a[r2];
			sort(l+1,l+cnt1+1,cmp);
			bool flag=false;
			for(int i=1;i<=cnt1;i++)
				if(!l[i].used&&l[i].id!=0)
				{
					//l[i].used=true;
					for(int j=1;j<=cnt2;j++)
						if(!r[j].used&&r[j].num==l[i].num&&l[i].id!=r[j].id)
						{
							l[i].used=true;
							r[j].used=true;
							ll=l[i].id;
							rr=r[j].id;
							ans1[++cnta]=l[i].num;
							flag=true;
							break;
						}
					if(flag)
						break;
				}
			if(!flag)
				break;
		}
		ll=y,rr=n*2;
		ans2[++cntb]=a[ll];
		memset(book,false,sizeof book);
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		while(1)
		{
			//printf("[%d %d] %d\n",ll,rr,ans2[cntb]);
			int l1=ll-1,l2=ll+1,r1=rr-1,r2=rr+1;
			if(ll==1)
				l1=n*2;
			if(rr==1)
				r1=n*2;
			if(ll==n*2)
				l2=1;
			if(rr==n*2)
				r2=1;
			if(book[l1]&&book[l2]&&book[r1]&&book[r2])
				break;
			//ans[++cnt]=a[ll];
			book[ll]=book[rr]=true;
			if(!book[l1])
				l[++cnt1].id=l1,l[cnt1].num=a[l1];
			if(!book[l2])
				l[++cnt1].id=l2,l[cnt1].num=a[l2];
			if(!book[r1])
				r[++cnt2].id=r1,r[cnt2].num=a[r1];
			if(!book[r2])
				r[++cnt2].id=r2,r[cnt2].num=a[r2];
			sort(l+1,l+cnt1+1,cmp);
			bool flag=false;
			for(int i=1;i<=cnt1;i++)
				if(!l[i].used&&l[i].id!=0)
				{
					//l[i].used=true;
					for(int j=1;j<=cnt2;j++)
						if(!r[j].used&&r[j].num==l[i].num&&r[j].id!=l[i].id)
						{
							l[i].used=true;
							r[j].used=true;
							ll=l[i].id;
							rr=r[j].id;
							//printf("%d %d\n",l[i].id,l[i].num);
							ans2[++cntb]=l[i].num;
							flag=true;
							break;
						}
					if(flag)
						break;
				}
			if(!flag)
				break;
		}		
		if(cnta<n&&cntb<n)
		{
			printf("-1\n");
			continue;
		}
//		else
//		{
//			printf("0\n");
//		}
//		for(int i=1;i<=cnta;i++)
//			printf("%d ",ans1[i]);
//		printf("\n");	
//		for(int i=1;i<=cntb;i++)
//			printf("%d ",ans2[i]);
//		printf("\n");
		int head=1,tail=n*2;
		//printf("%d %d\n",cnta,cntb);
		if(cntb<n||(ans1[1]<ans2[1])&&cnta==cntb)
		{
			//printf("1");
			for(int i=1;i<=cnta;i++)
				if(ans1[i]==a[head])
				{
					printf("L");
					head++;
				}
				else if(ans1[i]==a[tail])
				{
					printf("R");
					tail--;
				}
			for(int i=cnta;i>=1;i--)
				if(ans1[i]==a[head])
				{
					printf("L");
					head++;
				}
				else if(ans1[i]==a[tail])
				{
					printf("R");
					tail--;
				}
		}	
		else
		{
			//printf("2");
			for(int i=1;i<=cntb;i++)
				if(ans2[i]==a[head])
				{
					printf("L");
					head++;
				}
				else 
				{
					printf("R");
					
				}
			for(int i=cntb;i>=1;i--)
				if(ans2[i]==a[head])
				{
					printf("L");
					head++;
				}
				else 
				{
					printf("R");
					
				}
		}
		printf("\n");
	}
	return 0;
}
