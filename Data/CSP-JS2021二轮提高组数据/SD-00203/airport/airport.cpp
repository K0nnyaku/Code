#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
const int maxn=111111;
using namespace std;
struct timepoint{
	int a,b;
}c1[maxn*2];;
int n,m1,m2,ix[maxn];
int a1[maxn],b1[maxn],a2[maxn],b2[maxn],tota=0;//这是离散化后的数据
int ts[maxn]; 
inline bool cmp(timepoint x,timepoint y){
	return x.a<y.a?1:0;
}
int check(int a){
	int sum=0;
	memset(ix,0,sizeof(ix));
	for(int i=1;i<=m1;i++){

		bool able=1;
		for(int j=a1[i];j<=b1[i];j++){
			if((ix[j]>a)){
		
				able = 0 ;break;}
		}
		if(able){
			sum++; 	for(int j=a1[i];j<=b1[i];j++)ix[j]++;
			
		}
	}
	a=n-a; 
	memset(ix,0,sizeof(ix));for(int i=1;i<=m2;i++){
		bool able=0;
		for(int j=a2[i];j<=b2[i];j++){
			if((ix[j]>a)){
			
				able = 1 ;break;}
		}
		if(!able){
			sum++; 	for(int j=a2[i];j<=b2[i];j++)ix[j]++;
			
		}
	} 
	return sum;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		int a,b;
		cin>>a>>b;
		c1[++tota]={a,i};
		c1[++tota]={b,i};
	}	
	sort(c1+1,c1+tota+1,cmp);
	for(int i=1;i<=m1*2;i++){
		int tot=0;
	tot++;
		if(a1[c1[i].b]==0)a1[c1[i].b]=tot;
		else b1[c1[i].b]=tot;

	}
	tota=0;
	
	for(int i=1;i<=m2;i++){
		int a,b;
		cin>>a>>b;
		c1[++tota]={a,i};
		c1[++tota]={b,i};
	}	
	sort(c1+1,c1+tota+1,cmp);
	for(int i=1;i<=m1*2;i++){
		int tot=0;
tot++;
		if(a2[c1[i].b]==0)a2[c1[i].b]=tot;
		else b2[c1[i].b]=tot;

	}
	int max=-1,ans=0;
	for(int i=1;i<=n;i++){
		int tmp=check(i);
		if(tmp>max){
			max=tmp;ans=i;
		}
	}
	cout<<max;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
} 
