#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio> 
using namespace std;
const int M=1e5+100;
int n,m[2];
int xx[M];
int sum;
struct plane{
	int a;
	int b;
}p[2][M];
bool cmp(plane a,plane b){
	return a.a<b.a;
}
int work(int key,int kk){
	if(kk==0)return 0;
	int cnt=0;
	for(int i=1;i<=m[key];i++){
		int flag=0,minn=0x7ffffff,x=0;
		for(int j=1;j<=sum;j++)
			if(p[key][i].a>xx[j]&&xx[j]<minn)
				minn=xx[j],x=j,flag=1;
		if(flag){
			cnt++;
			xx[x]=p[key][i].b;
			continue;
		}
		if(sum+1<=kk){
			xx[++sum]=p[key][i].b;
			cnt++;
		}
	}
	memset(xx,0,sizeof(xx));
	sum=0;
	return cnt;
}

int main(){ 
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m[0],&m[1]);	
	if(m[0]+m[1]<=n){
		printf("%d",m[0]+m[1]);
		return 0;
	}
	for(int i=1;i<=m[0];i++){
		scanf("%d%d",&p[0][i].a,&p[0][i].b);
	}
	
	for(int i=1;i<=m[1];i++){
		scanf("%d%d",&p[1][i].a,&p[1][i].b);
	}
	sort(p[0]+1,p[0]+m[0]+1,cmp);
	sort(p[1]+1,p[1]+m[1]+1,cmp);
	int maxx=0;
	for(int i=0;i<=n;i++){
		maxx=max(maxx,work(0,i)+work(1,n-i));	
	}
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
