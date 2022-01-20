#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int Ts;
int n,A[100005],B[3][100005],dum;//5e5*2+5
bool ansflag=0;
bool checkB(int B_id) {
	for(int i=1; i<=n; i++) {
		if(!(B[B_id][i]==B[B_id][2*n+1-i]))
			return 0;
	}
	return 1;
}
void betadfs(int afr,int aed,int opid) {
	if(ansflag) return;
//	printf("ex %d %d %d \n",afr,aed,opid);
	if(opid==(2*n+1)) {
//			for(int j=0;j<=2*n;j++)
//			printf("%d ",B[0][j]);
//			printf("\n");
		if(checkB(0)) {
//			printf("ANSFDDDDDDDDDDDDDDD \n");
			//	totans++;
			for(int i=1; i<=2*n; i++) {
				printf("%c",B[1][i]);
				ansflag=1;
			}
			printf("\n");
		};
		return ;
	};
	B[0][opid]=A[afr++] ;//L
	B[1][opid]='L';
	betadfs(afr,aed,opid+1);
	afr--;
	B[0][opid]=A[aed--] ;//R
	B[1][opid]='R';
	betadfs(afr,aed,opid+1);
	aed--;
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&Ts);

	for(; Ts>0; Ts--) { // dirty multitask workaround
		ansflag=0;
		//	totans=0;
		scanf("%d",&n);
				if(n>1000) {
					for(int i=1; i<=2*n; i++)
					scanf("%d",&dum);
					for(int i=0; i<n; i++) printf("L");
					printf("\n");	
				}
				else{
		for(int i=1; i<=2*n; i++)
			scanf("%d",&A[i]);
//	cout<<"inpsuc\n";
		betadfs(1,2*n,1);
//	cout<<"dfssuc\n";
		if(!ansflag) printf("-1\n");
//	else{
//	for(int i=2;i<=totans+1;+){
//		for(int j=1;j<=2*n;j++)
//			printf("%c",B[i][j]);
//		printf("\n");
//
//	}
//}
				}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
@test1
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
@test 2




*/
