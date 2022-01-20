//zhn 记住 你就是个大菜鸡 放平心态
//消注释！！！return 0！！！
//打暴力啊啊啊，别乱想正解，你想不出来
//实在不行直接打暴力，打完暴力之后“正解”和暴力分区
//别忘了用快读
//orz zrz qlr qyc zyz ljc zsy wyh wym lyt dln
//rp++
//sdsy nb！！！ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using std::max;
using std::sort;

int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int n,m1,m2;
int lq1[100010],lq2[100010];
bool yes[100010];
struct node{
	int x,y;
}air[100010];

bool cmp(node a,node b){ return a.x<b.x; }

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=rd();m1=rd();m2=rd();
	for(int i=1;i<=m1;i++){
		air[i].x=rd();
		air[i].y=rd();
	}
	sort(air+1,air+1+m1,cmp);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m1;j++){
			for(int k=1;k<j;k++){
				if(yes[k]&&air[j].x>=air[k].y){
					sum--;
					yes[k]=0;
				}
			}
			if(sum<i){
				sum++;
				yes[j]=1;
				lq1[i]++;
			}
		}
	}
	for(int i=1;i<=m2;i++){
		air[i].x=rd();
		air[i].y=rd();
	}
	sort(air+1,air+1+m2,cmp);
	memset(yes,0,sizeof(yes));
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m2;j++){
			for(int k=1;k<j;k++){
				if(yes[k]&&air[j].x>=air[k].y){
					sum--;
					yes[k]=0;
				}
			}
			if(sum<i){
				sum++;
				yes[j]=1;
				lq2[i]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,lq1[i]+lq2[n-i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
