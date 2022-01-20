#include<bits/stdc++.h>
using namespace std;
int a[3000],b[3000];
char s[3000],ch[3000];
int n,df=0;
void dfs(int l,int r,int k){
	if(df==1)return ;
	if(k==2*n){
		//for(int i=1;i<=2*n;i++){
		//	cout<<b[i]<<" ";
		//}
		//cout<<endl; 
		int flag=0;
		for(int i=1,j=2*n;i<=n;i++,j--){
			if(b[i]!=b[j]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			//for(int i=1;i<=2*n;i++){
			//   cout<<ch[i]<<" ";
			//}
			//cout<<endl;
			for(int i=1;i<=2*n;i++){
				s[i]=ch[i];
			}
			df=1;
		}
		return;
	}
	b[k+1]=a[l+1];
	ch[k+1]='L';
	dfs(l+1,r,k+1);
	if(df==1)return ;
	b[k+1]=a[r-1];
	ch[k+1]='R';
	dfs(l,r-1,k+1);
	if(df==1)return ;
} 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	int T;
    scanf("%d",&T);
	while(T--){
		df=0;
	    memset(s,'Z',sizeof(s));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		dfs(0,2*n+1,0);
		if(s[1]=='Z')printf("-1\n");
		else{
			for(int i=1;i<=2*n;i++){
				cout<<s[i]<<" ";
			}
			printf("\n");
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3*/
