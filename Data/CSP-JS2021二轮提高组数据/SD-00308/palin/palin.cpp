#include<bits/stdc++.h>
using namespace std;
char lr[500005],sz[1000010],tmp[500005],tmpsz[1000010];
int p,lp,rp,n,ttime;

void csh(){
	memset(lr,0,sizeof(lr));
	p=0;
	lp=1;
	rp=2*n;
}

void lrlr(){
	if(p>n&&tmpsz[p]!=tmpsz[2*n+1-p]){
		csh();

		return;
	}
		
	if(p==2*n){
		for(int j=1;j<=2*n;j++){
			lr[j]=tmpsz[j];
		}
		
		return;
	}
	p++;
	tmp[p]='L';
	tmpsz[p]=sz[lp];
	lp++;
	lrlr();
	tmp[p]='R';
	tmpsz[p]=sz[rp];
	rp--;
	lrlr();
	csh();
	printf("2\n");
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&ttime);
//	printf("%d\n",ttime);
	for(int i=1;i<=ttime;i++){
		csh;
		scanf("%d",&n);
		getchar();
		for(int j=1;j<=2*n;j++){
			scanf("%c",&sz[i]);
			getchar();
		}
		lrlr();
		for(int j=1;j<=2*n;j++){
			printf("%c",lr[i]);
		}
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
