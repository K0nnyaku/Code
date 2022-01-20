#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
inline int maxx(int a,int b){
	return a>b?a:b;
}
int arrive1[MAXN]={0},arrive2[MAXN]={0};
struct airline{
	int a,b;
}air[MAXN];
char vis[MAXN];
int cmp1(airline a1,airline a2){
	return a1.a<a2.a;
}
int n,m1,m2,res=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&air[i].a,&air[i].b);
	int cnt=m1,last,index=1;
	memset(vis,0,sizeof(vis));
	sort(air+1,air+m1+1,cmp1);
	while(cnt){
		last=0;
		arrive1[index]=arrive1[index-1];
		for(int i=index;i<=m1;i++){
			if(vis[i]||air[i].a<=last)continue;
			arrive1[index]++;
			last=air[i].b;
			vis[i]=1;
			cnt--;
		}
		index++;
	}
	for(int i=1;i<=m2;i++)scanf("%d%d",&air[i].a,&air[i].b);
	cnt=m2,last=0,index=1;
	memset(vis,0,sizeof(vis));
	sort(air+1,air+m2+1,cmp1);
	while(cnt){
		last=0;
		arrive2[index]=arrive2[index-1];
		for(int i=index;i<=m2;i++){
			if(vis[i]||air[i].a<=last)continue;
			arrive2[index]++;
			last=air[i].b;
			vis[i]=1;
			cnt--;
		}
		index++;
	}
	for(int i=0;i<=n;i++)res=maxx(res,arrive1[i]+arrive2[n-i]);
	printf("%d",res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

