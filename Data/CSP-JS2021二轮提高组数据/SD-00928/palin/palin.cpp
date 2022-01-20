#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n;
bool flag=0;
bool check(int now[]){
	for(int i=1;i<=n;i++){
		if(now[i]!=now[2*n-i+1])
			return 0;
	}
	return 1;
}
void dfs(int x,char c[],int now[],int l,int r){
	if(flag)
		return;
	if(x==2*n){
		if(check(now)){
			for(int i=1;i<=2*n;i++){
				putchar(c[i]);
			}
			putchar('\n');
			flag=1;
		}
		return;
	}
		now[x+1]=a[l];
		c[x+1]='L';
		dfs(x+1,c,now,l+1,r);
		now[x+1]=a[r];
		c[x+1]='R';
		dfs(x+1,c,now,l,r-1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		if(n<=20){
			int now[105];
			char c[105];
			dfs(0,c,now,1,2*n);
			if(!flag)
				printf("-1\n");
			continue;
		}
		else{
			if(a[1]==a[2*n]){
				if(check(a)){
					for(int i=1;i<=2*n;i++){
						putchar('L');
					}
					putchar('\n');
					continue;
				}
				else{
					printf("-1\n");
					continue;
				}
			}
			else if(a[1]==a[2]&&a[2*n-1]==a[2*n]){
				printf("-1\n");
				continue;
			}
			else if(a[1]==a[2]){
				putchar('L');
				for(int i=1;i<=2*n-2;i++)
					putchar('R');
				putchar('L');
				putchar('\n');
				continue;
			}
			else if(a[2*n-1]==a[2*n]){
				putchar('R');
				for(int i=1;i<2*n;i++)
					putchar('L');
				putchar('\n');
				continue;
			}
			else{
				printf("-1\n");
				continue;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
