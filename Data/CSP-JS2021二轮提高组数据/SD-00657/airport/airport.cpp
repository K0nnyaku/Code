#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct aa{
	int qf,jl;
}sum1[100010],sum2[100010];
int n,m1,m2;
bool cmp(aa x,aa y){
	return x.jl<y.jl;
}
int k1,k2,am,ans,bm,t,b1[101001],b2[100100],q1[101001],q2[101001],front1=1,front2=1,last1=0,last2=0;
//k 临时数组数据数量，ambm，遍历过的飞机数量，t已经过去的时间，q队列数组 
void mn(int s1,int s2){
	while(am<=m1||bm<=m2){
		k1=0,k2=0;
		int x=sum1[am].jl,y=sum2[bm].jl;
		int ab;
		if(x<y)ab=1;
		if(x>y)ab=2;
		t=min(x,y);
				for(int i=front1;i<=last1;i++){
					if(q1[i]>t){
						b1[++k1]=q1[i];
						q1[k1]=q1[i];
					}else s1++;
				}
				for(int i=front2;i<=last2;i++){
					if(q2[i]>t){
						b2[++k2]=q2[i];
						q2[k2]=q2[i];
					}else s2++;
				}
				front1=1,last1=k1,front2=1,last2=k2;
				int s=0;
				if(s1>0&&ab==1){
					q1[++last1]=sum1[am].qf;
					s1--;
					s=1;
				}else if(s2>0&&ab==2){
					q2[++last2]=sum2[bm].qf;
					s2--;
					s=1;
				}
				if(ab==1)am++;
				if(ab==2)bm++;
				if(ans<k1+k2+s)ans=k1+k2+s;
			}
		
	
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(sum1,0x3f,sizeof(sum1));
	memset(sum2,0x3f,sizeof(sum2));
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		sum1[i].qf=y;
		sum1[i].jl=x;
		
	}
	for(int i=1;i<=m2;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		sum2[i].qf=y;
		sum2[i].jl=x;
	}
	
	sort(sum1+1,sum1+m1+1,cmp);
	sort(sum2+1,sum2+m2+1,cmp);
	for(int i=0;i<=n;i++){
		am=1;
		bm=1;
		k1=0;
		k2=0;
		front2=0;
		front1=0;
		last1=1;
		last2=1;
		t=0;
		int s1=i,s2=n-i;
		mn(s1,s2);
	} 
	cout<<ans<<endl;
}
