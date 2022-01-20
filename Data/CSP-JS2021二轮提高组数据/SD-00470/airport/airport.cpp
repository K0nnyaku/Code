#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct AA{
	int x,y,a1,b1;
}a[5050],b[5050];
int c[5050],d[5050],xx,yy;
int cmp(AA m,AA n){
	return m.a1<n.a1;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int m1,m2,n,ans=0,m=0,nn=0;
	scanf("%d%d%d",&n,&m1,&m2); 
	for(int i=1;i<=m1;i++)
	scanf("%d%d",&a[i].a1,&a[i].b1);
	for(int i=1;i<=m2;i++)
	scanf("%d%d",&b[i].a1,&b[i].b1);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	
	for(int i=0;i<=n;i++){
		for(int l=0;l<=n;l++)
		c[l]=d[l]=0;
		xx=1,yy=1,m=0,nn=0;
		if(i!=0) m++;
		c[1]=a[1].b1;
		for(int j=2;j<=m1;j++){
			if(i==0) break;
			if(xx<i){
				m++;
				sort(c+1,c+1+xx);
				if(c[1]<a[j].a1) 
					c[1]=a[j].b1;
				else{
					xx++;
					c[xx]=a[j].b1;
				}
			}
			else{
				sort(c+1,c+1+xx);
				if(c[1]<a[j].a1) {
					c[1]=a[j].b1;
					m++;
				}
			}
		}
		if(i!=n) nn=1;
		d[1]=b[1].b1;
		for(int j=2;j<=m2;j++){
			if(i==n) break;
			if(yy<n-i){
				yy++;
				sort(d+1,d+1+yy);
				if(d[1]<b[j].a1) 
					d[1]=b[j].b1;
					else {
						yy++;
						d[yy]=b[j].b1;
					}
			}
			else{
				sort(d+1,d+1+yy);
				if(d[1]<b[j].a1) {
					d[1]=b[j].b1;
					nn++;
				}
			}}
		if(m+nn>ans) ans=m+nn;
	
		
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
