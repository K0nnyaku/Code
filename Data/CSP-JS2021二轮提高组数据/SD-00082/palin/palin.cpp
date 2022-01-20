#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005],b[500005],s,w,tot;
char k[500005];
bool z;
bool pan(){
	for(int i=1;i<=n;i++){
		if(b[i]!=b[2*n+1-i])return false;
	}
	return true;
}
void dfs(int x,int y){
	if(z)return;
	if(y==0){
		k[x]='L';
		b[x]=a[s];
		s++;
	}
	if(y==1){
		k[x]='R';
		b[x]=a[w];
		w--;
	}
	if(x==2*n){
		/*for(int i=1;i<=x;i++){
			cout<<b[i];
		}
		cout<<endl;*/
		if(pan())z=true;
		return;
	}
	for(int i=0;i<=1;i++){
		dfs(x+1,i);
		if(i==0)s--;
		if(i==1)w++;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		z=false;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		s=1;w=2*n;
		dfs(1,0);
		s=1;w=2*n;
		if(!z)dfs(1,1);
		if(!z){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=2*n;i++){
			printf("%c",k[i]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
