#include<bits/stdc++.h>
using namespace std;
char c[505];
const int p=1e9+7;
int k,n,a[505],b[505],ans=0;
bool find(int t){
	int v=t,o=0,m=0;
	while(1){
		t-=a[t];
		if(c[t]==')'){
			o++;
			if(c[t+1]=='*') m++;
			else m--;
		}
		if(c[t]=='('){
			if(o==0){
				b[v]=t;
				break;
			}
			else{
				o--;
				if(c[t-1]!='*')
					m--;
			}
		}
	}
	if(m<=0) return 1;
	else return 0;
}
void dfs(int t,int i,bool j,int m){
	if(t==n){
		if(m==1){
			a[t]=i+1;
			if(find(t))
				ans++;
			a[t]=0;	
			for(int i=1;i<=n;i++)
				cout<<c[i];
			cout<<endl;	
		}
		ans%=p;
		return;
	}
	else if(c[t]!='?'){
		if(c[t]=='*'){
			if(i>=k||j) return;
			else dfs(t+1,i+1,0,m);
		}
		else if(c[t]==')'){
			if(m<=0) return;
			else{
				a[t]=i+1;
				if(find(t));
				dfs(t+1,0,0,m-1);
				b[t]=0;
				a[t]=0;
			}
		}
		else if(c[t]=='('){
			a[t]=i+1;
			dfs(t+1,0,0,m+1);
			a[t]=0;
		}
	}
	else if(c[t]=='?'){
		if(i<k&&j==0){
			c[t]='*';
			dfs(t+1,i+1,0,m);
			c[t]='?';
		}
		if(m>=1){
			a[t]=i+1;
			c[t]=')';
			if(find(t));
				dfs(t+1,0,0,m-1);
			c[t]='?';
			b[t]=0;
			a[t]=0;
		}
		c[t]='(';
		a[t]=i+1;
		dfs(t+1,0,0,m+1);
		c[t]='?';
		a[t]=0;
	}	
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		cin>>c[i];
	c[1]='(';	
	c[n]=')';
	dfs(1,0,0,0);
	cout<<ans; 	
	return 0;
}
