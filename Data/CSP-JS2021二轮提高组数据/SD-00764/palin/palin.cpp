#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[1001000],qu[1001000],top,c[1001000],ans,s[1001000];
void dfs(int l,int r){
	if(top==2*n){
		int flag=1;
		for(int i=1;i<=n;i++){
			if(qu[i]!=qu[2*n-i+1]){
				flag=0;
				break;
			}
		}
		if(flag==0) return ;
		ans=0;
		for(int i=1;i<=2*n;i++){
			if(c[i]==1&&s[i]==2){
				ans=1;
				break;
			}
			if(c[i]==2&&s[i]==1) return ;
		}
		if(ans==1){
			for(int i=1;i<=2*n;i++)
				s[i]=c[i];
		}
		return ;
	}
	if(l>r) return ;
	top++;
	
	qu[top]=a[l];
	c[top]=1;
	dfs(l+1,r);
	
	qu[top]=a[r];
	c[top]=2;
	dfs(l,r-1);
	
	top--;
	return ;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		top=0; ans=-1;
		for(int i=1;i<=2*n;i++)
			s[i]=2;
		dfs(1,2*n);
		if(ans==-1){cout<<-1<<endl;continue;}
		for(int i=1;i<=2*n;i++){
			if(s[i]==1) cout<<"L";
			else cout<<"R";
		}
		cout<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
