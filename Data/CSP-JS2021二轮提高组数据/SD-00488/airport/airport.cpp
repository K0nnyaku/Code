#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm> 
using namespace std;
int n,m1,m2;
int sum,ans;
int temp1[100010];
int temp2[100010];
struct node{
	int gt;
	int ot;
}; 
struct node a[101000],b[100010];
int sum1,sum2;
int comp(node x,node y){
	return x.gt<y.gt;
}
int jude1(int x){
	for(int i=1;i<=sum1;i++){
		if(a[x].gt>a[temp1[i]].ot){
			temp1[i]=x;
			return 1;
		}
	}
	return 0;
}
int jude2(int x){
	for(int i=1;i<=sum2;i++){
		if(b[x].gt>b[temp2[i]].ot){
			temp2[i]=x;
			return 1;
		}
	}
	return 0;
}
void vid(int x,int y){
	//国内
	if(x){
		int cnt1=0;
		for(int i=1;i<=m1;i++){
			if(cnt1<x){
				cnt1++;
				temp1[cnt1]=i;
				sum++;
			}
			else{
				if(jude1(i)){//有飞机离开 
					sum++;
				}
			}
		}
	}
	//国际 
	if(y){
		int cnt2=0;
		for(int i=1;i<=m2;i++){
			if(cnt2<y){
				cnt2++;
				temp2[cnt2]=i;
				sum++;
			}
			else{
				if(jude2(i)){
					sum++;
				}
			}
		}
	}
	ans=max(ans,sum);
	sum=0;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].gt,&a[i].ot);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].gt,&b[i].ot);
	}
	sort(a+1,a+1+m1,comp);
	sort(b+1,b+1+m2,comp);
	sum1=0;
	sum2=n;
	for(int i=1;i<=n+1;i++){
		vid(sum1,sum2);
		sum1++;
		sum2--;
		memset(temp1,0,sizeof(temp1));
		memset(temp2,0,sizeof(temp2));
	}
	printf("%d",ans);
	return 0;
}
