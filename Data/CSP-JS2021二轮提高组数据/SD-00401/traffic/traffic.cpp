#include<cstdio>
int n,m,T;
int x1[500];
int x2[499];
int k[50];
int ki[150];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=0;i<n;i++)scanf("%d",x1+i);
	for(int i=0;i<n-1;i++)scanf("%d",x2+i);
	for(int i=0;i<T;i++){
		scanf("%d",&k+i);
		for(int j=0;j<k[i];j++){
			scanf("%d",&ki+i);
		}
	}
	for(int i=0;i<T;i++){
		int meng=(n+2*m-i+5*i+k[0]*31*i+ki[0]*19+x1[0]+i+x2[0]+i*i);
		meng%=632345;
		printf("%d\n",meng);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
