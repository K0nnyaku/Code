#include<bits/stdc++.h>
using namespace std;
int n,k,top=1;
char z[501],s[501];
void dfs(int x,int m){
	if(x==n&&top<=1){
		cout<<s<<endl;
		return;
	}
	else if(s[x]=='('){
			z[top]='(';
			top++;
			dfs(x+1,m);
	}
	else if(s[x]==')'){
		top--;
		dfs(x+1,m);
		m=0;
	}
	else if(s[x]=='*'){
		m++;
		dfs(x+1,m);
	}
	else{
		if(top<n-x){
			s[x]='(';
			int y=m;
			m=0;
			dfs(x,m);
			m=y;
			s[x]='?';
			top--;
		}
		if(m<k&&top<n-x&&m>0){
			s[x]='*';
			m++;
			dfs(x,m);
			m--;
			s[x]='?';
		}
		if(top!=1&&m>0){
			cout<<top<<endl;
			s[x]=')';
			dfs(x,m);
			s[x]='?';
			top++;
			z[top]='(';
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	//cout<<n<<k<<s;
	dfs(0,0);
	return 0;
} 
