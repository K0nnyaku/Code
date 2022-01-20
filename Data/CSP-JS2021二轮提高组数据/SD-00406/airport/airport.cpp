#include<iostream>
#include<cstdio>
using namespace std; 
int main(){
	freopen("airport1.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,c,f;
	cin>>n>>m1>>m2;
	int ct[m1][1],ft[m2][1],p[n+1];
	for(int i=1;i<=m1;i++){
		for(int j=0;j<=1;j++){
			cin>>ct[i][j];
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=0;j<=1;j++){
			cin>>ft[i][j];
		}
	}
	int cn[n+1],fn[n+1];
	for(int j=1;j<=n+1;j++){cn[j]=0;}
	for(int j=1;j<=n+1;j++){fn[j]=0;}
	for(int i=0;i<=n;i++){
		c=i;
		f=n-i;
		int cnu[c],fnu[f],a[m1],b[m2];
		for(int j=1;j<=c;j++){cnu[j]=0;}
		for(int j=1;j<=f;j++){fnu[j]=0;}
		for(int j=1;j<=m1;j++){a[j]=0;}
		for(int j=1;j<=m2;j++){b[j]=0;}
		if(c!=0){
			for(int j=1;j<=c;j++){
				int min=9999999,q=0;
				for(int k=1;k<=m1;k++){
					if(k>=c){
						if(a[k]!=0){
							if(min>ct[k][0]){
								min=ct[k][0];
								q=k;
							}
						}
						cnu[j]=ct[q][1];
						a[q]=0;
						cn[i]++;
					}else{
						cn[i]=k;
						for(int p=1;p<=m1;p++){a[p]=0;}
					}					
				}			
			}
			if(cnu[c]!=0){
				for(int j=1;j<=m1-c;j++){
					//if(a[i]!=0){
						int min=9999999,t;
						for(int k=1;k<=m1;k++){
							if(a[k]!=0){
								if(min>ct[k][0]){
									min=ct[k][0];
									t=k;
								}
							}					
						}
						int max=-1,y;
						for(int k=1;k<=m1;k++){
							if(a[k]!=0){
								if(max<cnu[k]){
									max=cnu[k];
									y=k;
								}
							}					
						}
						if(max>min){
							cnu[t]=ct[y][1];
							a[y]=0;
							cn[i]++;
						}
					//}
				}
			}
		}else{
			cn[i]=0;
		}
		if(f!=0){
			for(int j=1;j<=f;j++){
				int min=9999999,q=0;
				for(int k=1;k<=m2;k++){
					if(k>=f){
						if(b[k]!=0){
							if(min>ft[k][0]){
								min=ft[k][0];
								q=k;
							}
						}
						fnu[j]=ft[q][1];
						b[q]=0;
						fn[i]++;
					}else{
						fn[i]=k;
						for(int p=1;p<=m2;p++){b[p]=0;}
					}
				}
			}
			if(fnu[f]!=0){
				for(int j=1;j<=m2;j++){
					//if(b[y]!=0){
						int min=9999999,t;
						for(int k=1;k<=m2;k++){
							if(b[k]!=0){
								if(min>ft[k][0]){
									min=ft[k][0];
									t=k;
								}
							}					
						}
						int max=-1,y;
						for(int k=1;k<=m2;k++){
							if(b[k]!=0){
								if(max<fnu[k]){
									max=fnu[k];
									y=k;
								}
							}					
						}
						if(max>min){
							fnu[t]=ft[y][1];
							b[y]=0;
							fn[i]++;
						}
					//}
				}
			}
		}else{
			fn[i]=0;
		}
		p[i]=cn[i]+fn[i];
	}
	int max1=-1;
	for(int i=0;i<=n;i++){
		if(max1<p[i]){
			max1=p[i];
		}
	}
	cout<<max1;
	return 0;
}
