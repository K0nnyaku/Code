#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10,M=1e5+10;
int n,m1,m2;
int ans1,ans2,ans;
int c1[N],c2[N],d1[N],d2[N];
struct plane{
	int a,b;
}p1[M],p2[M];
bool cmp(plane x,plane y)
{
	return x.a<y.a;
}
void copy()
{
	for(int i=p1[1].a;i<=p1[m1].b;i++) d1[i]=c1[i];
	for(int i=p2[1].a;i<=p2[m2].b;i++) d2[i]=c2[i];
}
void cover()
{
	for(int i=p1[1].a;i<=p1[m1].b;i++) c1[i]=d1[i];
	for(int i=p2[1].a;i<=p2[m2].b;i++) c2[i]=d2[i];
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++)
    {
    	scanf("%d%d",&p1[i].a,&p1[i].b);
    	for(int j=p1[i].a;j<=p1[i].b;j++)  c1[j]++;
    }
    for(int i=1;i<=m2;i++)
    {
    	scanf("%d%d",&p2[i].a,&p2[i].b);
    	for(int j=p2[i].a;j<=p2[i].b;j++)  c2[j]++;
    }
    sort(p1+1,p1+m1+1,cmp);
    sort(p2+1,p2+m2+1,cmp);
    copy();
    for(int i=0;i<=n;i++)
    {
    	for(int j=1;j<=m1;j++)
    	{
    	  if(c1[p1[j].a]<=i) ans1++;
    	  else{ for(int t=p1[j].a;t<=p1[j].b;t++) c1[t]--;} 
    	}
    	for(int j=1;j<=m2;j++)
    	{
    	   if(c2[p2[j].a]<=n-i) ans2++;
    	   else{ for(int t=p2[j].a;t<=p2[j].b;t++) c2[t]--;}
    	}
    	ans=max(ans,ans1+ans2);
    	ans1=0;
    	ans2=0;
    	cover();
    }
    printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

