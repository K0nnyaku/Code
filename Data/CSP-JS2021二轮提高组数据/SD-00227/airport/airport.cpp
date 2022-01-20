#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+500;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct plane{
	int a,b;
}p1[maxn],p2[maxn];
bool cmp(plane x,plane y){
	return x.a<y.a;
}
int n,m1,m2,ctop=0,dtop=0,Max=0;
int c[maxn*2],d[maxn*2],visit[maxn],Sum1[maxn],Sum2[maxn];
int search1(int x){
	int l=1,r=dtop,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		(x<=d[mid]?r:l)=mid;
	}
	return (x==d[l]?l:r);
}
int search21(int x,int l,int r){
	if(l>r)return 0;
	if(l+1>=r){
		if(p1[l].a<x&&p1[r].a<x)return 0;
		if(visit[l]==0&&p1[l].a>x)return l;
		if(visit[r]==0&&p1[r].a>x)return r;
		return 0; 
	}
	int mid;
	mid=(l+r)>>1;
	if(visit[mid]){
		int Left=search21(x,l,mid-1);
		int Right=search21(x,mid+1,r);
		if(Left==0&&Right==0)return 0;
		if(Left!=0)return Left;
		if(Left==0&&Right!=0)return Right;
	}
	if(x<p1[mid].a)return search21(x,l,mid);
	else return search21(x,mid,r);
}
int search22(int x,int l,int r){
	if(l>r)return 0;
	if(l+1>=r){
		if(p2[l].a<x&&p2[r].a<x)return 0;
		if(visit[l]==0&&p2[l].a>x)return l;
		if(visit[r]==0&&p2[r].a>x)return r;
		return 0; 
	}
	int mid;
	mid=(l+r)>>1;
	if(visit[mid]){
		int Left=search22(x,l,mid-1);
		int Right=search22(x,mid+1,r);
		if(Left==0&&Right==0)return 0;
		if(Left!=0)return Left;
		if(Left==0&&Right!=0)return Right;
	}
	if(x<p2[mid].a)return search22(x,l,mid);
	else return search22(x,mid,r);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&p1[i].a,&p1[i].b);
		c[++ctop]=p1[i].a;
		c[++ctop]=p1[i].b;
	}
	sort(p1+1,p1+1+m1,cmp);
	sort(c+1,c+1+ctop);
	for(int i=1;i<ctop;i++)
		if(c[i]!=c[i+1])d[++dtop]=c[i];
	d[++dtop]=c[ctop];
	for(int i=1;i<=m1;i++){
		p1[i].a=search1(p1[i].a);
		p1[i].b=search1(p1[i].b);
	}
	sort(p1+1,p1+1+m1,cmp);
	int tmp=0;
	for(int i=1;i<=m1;i++){
		if(visit[i]==0){
			tmp++;
			visit[i]=tmp;
			int last=i;
			while(1){
				int bnr=search21(p1[last].b,last+1,m1);
				if(bnr==0)break;
				else{
					last=bnr;
					visit[bnr]=tmp;
				}
			}
		}
	}
	for(int i=1;i<=m1;i++)Sum1[visit[i]]++;
	for(int i=1;i<=n;i++)Sum1[i]+=Sum1[i-1];
	memset(c,0,sizeof c);
	memset(d,0,sizeof d);
	memset(visit,0,sizeof visit);
	ctop=0;dtop=0;
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&p2[i].a,&p2[i].b);
		c[++ctop]=p2[i].a;
		c[++ctop]=p2[i].b;
	}
	sort(p2+1,p2+1+m2,cmp);
	sort(c+1,c+1+ctop);
	for(int i=1;i<ctop;i++)
		if(c[i]!=c[i+1])d[++dtop]=c[i];
	d[++dtop]=c[ctop];
	for(int i=1;i<=m2;i++){
		p2[i].a=search1(p2[i].a);
		p2[i].b=search1(p2[i].b);
	}
	sort(p2+1,p2+1+m2,cmp);
	tmp=0;
	for(int i=1;i<=m2;i++){
		if(visit[i]==0){
			tmp++;
			visit[i]=tmp;
			int last=i;
			while(1){
				int bnr=search22(p2[last].b,last+1,m2);
				if(bnr==0)break;
				else{
					last=bnr;
					visit[bnr]=tmp;
				}
			}
		}
	}
	for(int i=1;i<=m2;i++)Sum2[visit[i]]++;
	for(int i=1;i<=n;i++)Sum2[i]+=Sum2[i-1];
	for(int i=0;i<=n;i++)Max=max(Max,Sum1[i]+Sum2[n-i]);
	printf("%d\n",Max);
	fclose(stdin);fclose(stdout);
	return 0;
}
