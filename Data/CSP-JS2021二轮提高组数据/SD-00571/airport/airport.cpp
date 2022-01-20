#include<bits/stdc++.h>
using namespace std;
const int N=5010;
struct fj{
	int st,ed;
}nl[N],yl[N];
bool vnl[N],vyl[N];
bool cmp(fj x,fj y){
	return x.st<y.st;
}
int n,m1,m2;
int lq[5010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		scanf("%d %d",&nl[i].st,&nl[i].ed);
	sort(nl+1,nl+m1+1,cmp);
	for(int i=1;i<=m2;i++)
		scanf("%d %d",&yl[i].st,&yl[i].ed);	
	sort(yl+1,yl+m2+1,cmp);
	int sum=0,maxx=0;
	for(int i=0;i<=n;i++){
		sum=0;
		memset(lq,0,sizeof(lq)); 
		memset(vnl,0,sizeof(vnl));
		memset(vyl,0,sizeof(vyl));
		for(int j=1;j<=m1;j++){
			for(int k=1;k<=i;k++){
				
				if(lq[k]<nl[j].st&&vnl[j]==0) lq[k]=nl[j].ed,sum++,vnl[j]=1;
			}
		}
		for(int j=1;j<=m2;j++){
			for(int k=i+1;k<=n;k++){
				if(lq[k]<yl[j].st&&vyl[j]==0) lq[k]=yl[j].ed,sum++,vyl[j]=1;
			}
		}
		maxx=max(sum,maxx);		
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
