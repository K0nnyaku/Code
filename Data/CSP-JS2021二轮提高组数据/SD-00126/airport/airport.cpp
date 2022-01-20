#include<bits/stdc++.h>
using namespace std;
#define N 100005

int H[N],ab[N];
struct data{int a,b;}p[N];
int n,m1,m2,top,ans,k;

void up(int x)
{
	int i=x,j=i/2;
	while(j)
	{
		if(H[i]<H[j])
		{
			swap(H[i],H[j]);
			i=j;
			j=i/2;
		}
		else
		  break;
	}
}
void down(int x)
{
	int i=x,j=2*x;
	while(j<=top)
	{
		if(H[j]>H[j+1]&&j<top)j++;
		if(H[i]>H[j])
		{
			swap(H[i],H[j]);
			i=j;
			j=2*i;
	    }
	    else
	      break;
	}
}

bool cmp(data x,data y)
{
	return x.a<y.a;
}

void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
}

int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	read(n);read(m1);read(m2);
	//scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i){
		read(p[i].a);read(p[i].b);
	}
	 
	 //scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+1+m1,cmp);
	
	for(int t=1;t<=n;++t)
	{
		k=0;top=0;
		for(int i=1;i<=m1;++i)
		{
			while(top&&H[1]<p[i].a)
			{
				H[1]=H[top--];
				down(1);
			}
			
			if(top<t){
				k++;
				H[++top]=p[i].b;
				up(top);
			}
		 } 
		ab[t]=k;
	}
	ans=ab[n];
	
	for(int i=1;i<=m2;++i){
		read(p[i].a);read(p[i].b);
	}
	sort(p+1,p+1+m2,cmp);
	
	for(int t=1;t<=n;++t)
	{
		k=0;top=0;
		for(int i=1;i<=m2;i++)
		{
			while(top&&H[1]<p[i].a)
			{
				H[1]=H[top--];
				down(1);
			}
			
			if(top<t){
				k++;
				H[++top]=p[i].b;
				up(top);
			}
			
		 }
		if(ab[n-t]+k>ans)ans=ab[n-t]+k;
	}
	printf("%d",ans);
	return 0;
 } 
/*  
21!9-324@emb

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10



 
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

 */
