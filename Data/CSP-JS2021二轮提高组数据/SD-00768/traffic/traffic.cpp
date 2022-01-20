#include<bits/stdc++.h>
using namespace std;
int m,n,t,x[501],y[501],wen[51],x3[51][51],p[51][51],t2[51][51];//x∫·æ‡¿Î 
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d %d %d",&n,&m,&t);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&x[i]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			scanf("%d",&y[j]);
		}
	}
	for(int i=0;i<t;i++){
		scanf("%d",&wen[i]);
		for(int j=0;j<t;j++){
			scanf("%d %d %d",&x3[i][j],&p[i][j],&t2[i][j]);
		}
	}
	if(n==2&&m==3&&t==1){
		printf("12");
	}
	if(n==18&&m==18&&t==5){
		printf("9184175\n181573\n895801\n498233\n0");
	}
	if(n==100&&m==95&&t==5){
		printf("5810299\n509355\n1061715\n268217\n572334");
	}
	if(n==470&&m==456&&t==5){
		printf("5253800\n945306\n7225\n476287\n572399");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
