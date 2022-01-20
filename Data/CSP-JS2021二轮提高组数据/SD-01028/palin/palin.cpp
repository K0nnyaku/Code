#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1000005],b[1000005],n,T;
bool flg;
char ans[1000005];
bool check(){
	for(int i=1;i<=n;i++)
		if(b[i]!=b[2*n+1-i])
			return false;
	return true;
}
void func(int num,int l,int r){
	if(flg)	return ;
	if(num==2*n){
		if(check())	flg=true;
		return ;
	}
	if(flg)	return ;
	ans[num+1]='L';
	b[num+1]=a[l];
	func(num+1,l+1,r);
	if(flg)	return ;
	ans[num+1]='R';
	b[num+1]=a[r];
	func(num+1,l,r-1);
	if(flg)	return ;
	b[num+1]=0;
	ans[num+1]='\0';
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%i",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(ans,'\0',sizeof(ans));
		flg=false;
		scanf("%i",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%i",&a[i]);
		func(0,1,2*n);
		if(flg)
			for(int i=1;i<=2*n;i++)
				printf("%c",ans[i]);
		else
			printf("-1");
		printf("\n");
	}
	
	return 0;
}
