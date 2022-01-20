#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
const int M=1e7+5;
int n,m1,m2;
struct node{
	int a;
	int b;
};
bool cmp(node x,node y){
	return x.a<y.a;
}
node plane1[N],plane2[N];
int cnt1,cnt2;
bool viszhan1[N],visshi1[N];
bool viszhan2[N],visshi2[N];
int visb1,visb2;
int ans; 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//input
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&plane1[i].a,&plane1[i].b);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&plane2[i].a,&plane2[i].b);
	}
	sort(plane1+1,plane1+1+m1,cmp);
	sort(plane2+1,plane2+1+m2,cmp);
	//
	ans=-1;
	for(int i=0;i<=n;i++){ //廊桥 
		cnt1=cnt2=0;
		memset(viszhan1,0,sizeof(viszhan1));
		memset(viszhan2,0,sizeof(viszhan2));
		memset(visshi1,0,sizeof(visshi1));
		memset(visshi2,0,sizeof(visshi2));
		visb1=i;
		visb2=n-i;
		//国内 
		for(int j=1;j<=m1;j++){
			//廊桥的释放
			for(int k=1;k<=j-1;k++){
				if(plane1[j].a>plane1[k].b&&
				viszhan1[k]==1&&visshi1[k]==0&&visb1<i){
					visb1++;
					visshi1[k]=1;
				}
			}
			//if(vistime1[plane1[j].a]==0&&j!=1&&visb1<i) visb1++;
			if(visb1>0){ //可以停 
				cnt1++;				
				visb1--;
				viszhan1[j]=1;
			}
		}
		//国外 
		for(int j=1;j<=m2;j++){
			//廊桥的释放
			for(int k=1;k<=j-1;k++){
				if(plane2[j].a>plane2[k].b&&
				viszhan2[k]==1&&visshi2[k]==0&&visb2<i){
					visb2++;
					visshi2[k]=1;
				}
			}
			//if(vistime2[plane2[j].a]==0&&j!=1&&visb2<n-i) visb2++;
			if(visb2>0){
				cnt2++;
//				for(int k=plane2[j].a;k<=plane2[j].b;k++)
//					vistime2[k]=1;
				visb2--;
				viszhan2[j]=1;
			}
		}
		ans=max(ans,cnt1+cnt2);
	}
	printf("%d\n",ans);
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
*/
