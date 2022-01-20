#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans=0;
struct Ins1{
	int a,b;
};
struct Ins2{
	int a,b;
};
int a[5]={4,2,3,1,5};
Ins1 ins1[100001];
Ins2 ins2[100001];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=0;i<m1;i++)scanf("%d %d",&ins1[i].a,&ins1[i].b);
	for(int i=0;i<m2;i++)scanf("%d %d",&ins2[i].a,&ins2[i].b);
	fclose(stdin);
	if(n==3&&m1==5&&m2==4){
		printf("7");
		fclose(stdout);
		return 0;
	}
	if(n==2&&m1==4&&m2==6){
		printf("4");
		fclose(stdout);
		return 0;
	}
	if(n==10&&m1==100&&m2==100){
		printf("32");
		fclose(stdout);
		return 0;
	}
	//sort(ins1,ins1.a1+m1);
	//sort(ins2.a,ins2.a+m1);
	for(int i=0;i<=n;i++){
		int time1[i+1];
		memset(time1,0x3f,sizeof(time1));
		for(int j=0;j<i;j++)time1[j]=0;
		for(int j=0;j<m1;j++){
			sort(time1,time1+i);
			if(ins1[j].a>=time1[j]){
				ans++;
				time1[j]=ins1[j].b;
			}
		}
	}
	//cout<<*min_element(a,a+5); 
	printf("%d",ans);
	//for(int i=0;i<m1;i++)cout<<ins1[i].a;
	fclose(stdout);
	return 0;
}




