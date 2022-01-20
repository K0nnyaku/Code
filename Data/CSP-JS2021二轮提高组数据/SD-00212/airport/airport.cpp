#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct pp{
	int in,out;
}ch[300000],fr[300000];
int df[300000];
bool cmp(pp a,pp b){
	return a.in<b.in;
}
void ze(int a){
	for(int i=0;i<=a;i++){
		df[i]=0;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,x=0,rear=0,froat=0,x1=0;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&ch[i].in,&ch[i].out);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&fr[i].in,&fr[i].out);
	}
	sort(ch+1,ch+m1+1,cmp);
	sort(fr+1,fr+m2+1,cmp);
	for(int i=0;i<=n;i++){
		rear=1;
		froat=1;
		int x=0,z=0;
		for(int j=1;j<=m1;j++){
			int cu=ch[j].in;
			for(int l=1;l<rear;l++){
				if(cu>=df[l]&&df[l]!=0){
					df[l]=0;
					z--;
				} 
			}
			if(z<i){
				x++;
				df[rear]=ch[j].out;
				z++;
				rear++;
			}
		}
		rear=1;
		z=0;
		for(int j=1;j<=m2;j++){
			int cu=fr[j].in;
			for(int l=1;l<rear;l++){
				if(cu>=df[l]&&df[l]!=0){
					df[l]=0;
					z--;
				} 
			}
			if(z<n-i){
				x++;
				df[rear]=fr[j].out;
				z++;
				rear++;
			}
		}
		x1=max(x,x1);
	}
	cout<<x1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
