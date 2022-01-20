//21!9-324@emb
//什么阴间题目( 
#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int n,m1,m2,k1=1,k2=1,ans = 0;
struct ljsybs{
	int s,e;int flag;
};
ljsybs a[100005],b[100005];
int aas[100005]={},bbs[100005]={};
bool cmp(ljsybs aa,ljsybs bb){
	return aa.s<bb.s;
}
int bsta(int aa){
	int l = 1,r = m1;int mid;
	while(l!=r){
		mid = (l+r)/2;
		if(aa<=a[mid].s)r = mid;
		else l = mid+1;
	}
	while(a[l].s<=aa||!a[l].flag)l++;
	return l;
}
int bstb(int aa){
	int l = 1,r = m1;int mid;
	while(l!=r){
		mid = (l+r)/2;
		if(aa<=b[mid].s)r = mid;
		else l = mid+1;
	}
	while(b[l].s<=aa||!b[l].flag)l++;
	return l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1;i<=m1;i++){
		scanf("%d%d",&a[i].s,&a[i].e);a[i].flag = 1;
	}
	for(int i = 1;i<=m2;i++){
		scanf("%d%d",&b[i].s,&b[i].e);b[i].flag = 1;
	}
	sort(a+1,a+m1+1,cmp);sort(b+1,b+m2+1,cmp);
	int now=1,nnw=1;
	while(now<=m1){
		nnw=now;
		while(nnw<=m1){
			aas[k1]++;
			a[nnw].flag = 0;
			nnw = bsta(a[nnw].e);
		}
		while(!a[now].flag)now++;
		aas[k1]+=aas[k1-1];
		k1++;
	}
	now=1,nnw=1;
	while(now<=m2){
		nnw=now;
		while(nnw<=m2){
			bbs[k2]++;
			b[nnw].flag = 0;
			nnw = bstb(b[nnw].e);
		}
		while(!b[now].flag)now++;
		bbs[k2]+=bbs[k2-1];
		k2++;
	}
	for(int i = 0;i<=min(k1,n);i++){
		if(ans<aas[i]+bbs[min(n-i,k2)]){
			ans = aas[i]+bbs[min(n-i,k2)];
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
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
/*
 2 4 6  20 30  40 50  21 22
 41 42  1 19  2 18  3 4  5 6  7 8  9 10
 */
