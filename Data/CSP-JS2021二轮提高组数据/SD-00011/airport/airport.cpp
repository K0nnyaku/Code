#include<cstdio>
#include<algorithm>
const int maxn(1e5+105);
int n,la,lb,cnt,cnta,cntb,ca,cb,ans=0,taa[maxn],tbb[maxn],lasta[maxn],lastb[maxn],ta[maxn],tb[maxn],suma[maxn],sumb[maxn],va[maxn],vb[maxn];
struct node
{
	int l,r,f;
}a[maxn],b[maxn],c[maxn],d[maxn];
bool cmp1(node x,node y){ return x.l<y.l; }
bool cmp2(node x,node y){ return x.r<y.r; }
bool cmp3(node x,node y){ return x.f<y.f; }
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int dfsa(int x)
{
	int res=0,num=0;
	for(int i=1;i<=la;i++) taa[i]=0;
	for(int i=1;i<=la;i++)
	{
	
		res+=taa[i];
		if(res<x)
		{
			res++;
			num++;
			taa[a[i].r]--;	
		}
	}	
	return num;			
}
int dfsb(int x)
{
	int res=0,num=0;
	for(int i=1;i<=lb;i++) tbb[i]=0;
	for(int i=1;i<=lb;i++)
	{
		res+=tbb[i];
		if(res<x)
		{
			res++;
			num++;
			tbb[b[i].r]--;	
		}
	}	
	return num;	
}
int dfsaa(int x)
{
	if(va[x]>1||x>la) return 0;
	va[x]++; 
	return dfsaa(a[x].r)+1;
}
int dfsbb(int x)
{
	if(vb[x]>1||x>lb) return 0;
	vb[x]++; 
	return dfsbb(b[x].r)+1;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&la,&lb);
	for(int i=1;i<=la;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=lb;i++) scanf("%d%d",&b[i].l,&b[i].r);
	for(int i=1;i<=la;i++) c[i].l=a[i].l,c[i].r=a[i].r;
	for(int i=1;i<=lb;i++) d[i].l=b[i].l,d[i].r=b[i].r;
	std::sort(a+1,a+la+1,cmp1);
	std::sort(b+1,b+lb+1,cmp1);
	std::sort(c+1,c+la+1,cmp2);
	std::sort(d+1,d+lb+1,cmp2);
	cnt=1;
	for(int i=1;i<=la;i++)
		ta[i]=a[i].l,a[i].l=i;
	for(int i=1;i<=lb;i++)
		tb[i]=b[i].l,b[i].l=i;
	for(int i=1;i<=la;i++)
		while(cnt<=la&&c[cnt].r<=ta[i]) c[cnt].r=i,cnt++;
	for(int i=cnt;i<=la;i++) c[i].r=la+1;
	cnt=1;
	for(int i=1;i<=lb;i++)
		while(cnt<=lb&&d[cnt].r<=tb[i]) d[cnt].r=i,cnt++;
	for(int i=cnt;i<=lb;i++) d[i].r=lb+1;
	std::sort(c+1,c+la+1,cmp1);
	std::sort(d+1,d+lb+1,cmp1);
	for(int i=1;i<=la;i++) a[i].r=c[i].r;
	for(int i=1;i<=lb;i++) b[i].r=d[i].r;
	if(n<=5000)
	{
		for(int i=0;i<=n;i++)
		ans=max(ans,dfsa(i)+dfsb(n-i));
		printf("%d\n",ans);
		return 0;
	}
	for(int i=1;i<=la;i++) lasta[i]=i+1;
	for(int i=1;i<=lb;i++) lastb[i]=i+1;
	for(int i=1;i<=la;i++)
	{
		int k=i;
		while(!va[k]&&k<=la) va[k]=1,a[k].f=++ca,k=a[k].r;
	}
	for(int i=1;i<=lb;i++)
	{
		int k=i;
		while(!vb[k]&&k<=lb) vb[k]=1,b[k].f=++cb,k=b[k].r;
	}
	for(int i=la;i;i--) va[i]=0;
	for(int i=lb;i;i--) vb[i]=0;
	std::sort(a+1,a+la+1,cmp3);
	std::sort(b+1,b+lb+1,cmp3);
	for(int i=1;i<=la;i++)
	{
		if(a[i].r>la) continue;
		if(!va[a[i].r]) va[a[i].r]=i;
		else
		{
			while(va[lasta[a[i].r]]&&lasta[a[i].r]<=la) lasta[a[i].r]++;
			a[i].r=lasta[a[i].r];
			lasta[a[i].r]++;
//			while(a[i].r<=la&&va[a[i].r]) a[i].r++;
			if(a[i].r<=la) va[a[i].r]=i;  
		}
	}
	for(int i=1;i<=lb;i++)
	{
		if(b[i].r>lb)continue;
		if(!vb[b[i].r]) vb[b[i].r]=i;
		else
		{
			while(vb[lastb[b[i].r]]&&lastb[b[i].r]<=lb) lastb[b[i].r]++;
			b[i].r=lastb[b[i].r];
			lastb[b[i].r]++;
//			while(b[i].r<=lb&&vb[b[i].r]) b[i].r++;
			if(b[i].r<=lb) vb[b[i].r]=i;  
		}
	}
	std::sort(a+1,a+la+1,cmp1);
	std::sort(b+1,b+lb+1,cmp1);
	for(int i=la;i;i--) va[i]=0;
	for(int i=lb;i;i--) vb[i]=0;
	for(int i=la;i;i--) va[a[i].r]=1;
	for(int i=lb;i;i--) vb[b[i].r]=1;
	for(int i=1;i<=la;i++)
		if(!va[i]) suma[++cnta]=dfsaa(i);
	for(int i=1;i<=lb;i++)
		if(!vb[i]) sumb[++cntb]=dfsbb(i);
	suma[0]=sumb[0]=0;
	for(int i=1;i<=n;i++) suma[i]+=suma[i-1],sumb[i]+=sumb[i-1];
	for(int i=0;i<=n;i++) ans=max(ans,suma[i]+sumb[n-i]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

