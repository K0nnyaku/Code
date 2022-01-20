#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+2;
bool f=0;
int n,m,mm;
struct qwe{
	int ks,js;
}yi[N],er[N];
int A[N],cnt,sum[N],summ[N],b[N],bb[N],nt,c[N],cc[N],s,ss,ans,l[N],ll[N],anss,da,id,t;
void cl1(int u){
	int o=0;
	for(int i=1;i<=m;i++){
		da=1e8,id=0;
		for(int j=i-1;j>id;j--){
			if(yi[i].ks>=yi[j].js&&!b[j]&&yi[j].js<da){
				da=yi[j].js;
				id=j;
			}
		}
		if(id){
			b[id]=1;ans++;t=id;
		}
		if(!id){
			if(o+1<=u) o++,ans++;
			else b[i]=1;
		}
	}
}
void cl2(int u){
	int o=0;
	for(int i=1;i<=mm;i++){
		da=1e8,id=0;
		for(int j=i-1;j>id;j--){
			if(er[i].ks>=er[j].js&&!bb[j]&&er[j].js<da){
				da=er[j].js;
				id=j;
			}
		}
		if(id){
			t=id;
			bb[id]=1;ans++;
		}
		if(!id){
			if(o+1<=u) o++,ans++;
			else bb[i]=1;
		}
	}
}
bool nn(int a,int b){
	return a>b;
}
bool yy(qwe a,qwe b){
	return a.ks<b.ks;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mm);
	for(int i=1;i<=m;i++) scanf("%d%d",&yi[i].ks,&yi[i].js);
	sort(yi+1,yi+m+1,yy);
	for(int i=1;i<=mm;i++) scanf("%d%d",&er[i].ks,&er[i].js);
	sort(er+1,er+mm+1,yy);
	for(int i=0;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(bb,0,sizeof(bb));
		ans=0;
		cl1(i);
		cl2(n-i);
		anss=max(anss,ans);
	}
	printf("%d\n",anss);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
