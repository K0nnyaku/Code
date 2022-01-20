#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n;
int a[1000005];
int ss[500005];
int b[1000005];
char z[1000005];
int l,r;
bool yes;
void dfs(int x){
	cout<<x<<" ";
	if(x>2*n){
		yes=1;
		return;
	}
	if(ss[a[l]]==0||ss[a[l]]==n*2-x+1){
		//cout<<a[l]<<" "<<ss[a[l]]<<endl;
		b[x]=a[l];
		if(x<=n){
			//cout<<1;
			ss[a[l]]=x;
			//cout<<ss[a[l]];
		}
		l++;
		z[x]='L';
		dfs(x+1);
		if(yes){
			return;
		}
	}
	l--;
	
	if(ss[a[r]]==0||ss[a[r]]==n*2-x+1){
		b[x]=a[r];
		if(x<=n){
			ss[a[r]]=x;
		}
		r--;
		z[x]='R';
		dfs(x+1);
		if(yes){
			return;
		}
	}
	r++;
	
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(ss,0,sizeof ss);
		memset(z,0,sizeof z);
		yes=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		l=1;
		r=2*n;
		dfs(1);
		if(!yes){
			printf("-1\n");
		}
		else{
			for(int i=1;i<=2*n;i++){
				printf("%c",z[i]);
			}
			printf("\n");
			for(int i=1;i<=2*n;i++){
				printf("%d",b[i]);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


