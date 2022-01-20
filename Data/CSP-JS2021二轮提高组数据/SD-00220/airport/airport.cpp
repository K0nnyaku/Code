#include<bits/stdc++.h> 
using namespace std;
int n,m1,m2;
int a1[101],b1[101],a2[101],b2[101];
int c,d,ans,f1[101][5],f2[101][5];
int xx,yy,k1,k2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i],&b1[i]);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&a2[i],&b2[i]);
	}
	for(int i=0;i<=n;i++){
		c=i;
		d=n-i;
		xx=0;
		yy=0;
		k1=100000001;
		k2=100000001;
		if(c!=0){
			for(int j=1;j<=m1;j++){
				for(int z=1;z<=c;z++){
					if(f1[z][2]!=0){
						for(int w=1;w<=c;w++){
							k1=min(k1,f1[w][2]);
						}
						if(a1[j]>f1[z][2] && f1[z][2]==k1){
							f1[z][2]=b1[j];
							f1[z][1]=a1[j];
							xx++;
							continue;
					}}	
					else{
					if(a1[j]>f1[z][2]){
						f1[z][2]=b1[j];
						f1[z][1]=a1[j];
						xx++;
						continue;
					}				
				}
			}
		}
		if(d!=0){
			for(int j=1;j<=m2;j++){
				for(int z=1;z<=d;z++){
					if(f2[z][2]!=0){
						for(int w=1;w<=c;w++){
							k2=min(k2,f2[w][2]);
						}
						if(a2[j]>f2[z][2] && f2[z][2]==k2){
							f2[z][2]=b2[j];
							f2[z][1]=a2[j];
							yy++;
							continue;
					}}	
					else{
					if(a2[j]>f2[z][2]){
						f2[z][2]=b2[j];
						f2[z][1]=a2[j];
						yy++;
						continue;
					}				
				}
				}
			}
		}
		ans=max(ans,xx+yy);
	}}printf("%d",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

