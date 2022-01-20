#include<iostream>//一维为时间，二维为区类型
#include<cstdio>//利用for循环实现国内区i和国际区i-n个判断
#include<cmath>//d数组为每辆飞机结束时间 
using namespace std;
int d[100001][2],q[10000001][2],l[10000001][2];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,ma=-1,ti=10000001,tp=-1;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		q[a][0]=i;
		d[i][0]=b;
		ti=min(a,ti);
		tp=max(b,tp);
	}
	for(int i=1; i<=m2; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		q[a][1]=i;
		d[i][1]=b;
		ti=min(a,ti);
		tp=max(b,tp);
	}
	for(int i=0; i<=n; i++) {
		int p=0,a=i,b=n-i;
		for(int k=ti; k<=tp; k++) {
			a+=l[k][0],b+=l[k][1];
			l[k][0]=l[k][1]=0;
			if(a>0&&q[k][0]>0) a--,l[d[q[k][0]][0]][0]++,p++;
			
			if(b>0&&q[k][1]>0) b--,l[d[q[k][1]][1]][1]++,p++;
			}
		ma=max(p,ma);
	}
	cout<<ma;
	return 0;
}
