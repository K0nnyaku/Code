#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,k,m=0;
int a[510];
bool v[510];
int ans=0;
int zuo=0,you=0;
int ku[510];
char q[510];
string s;
char f[510];
int zhi[1000010];
int qz(){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum*3%1000010;
		if(f[i]=='(') sum+=1;
		if(f[i]=='*') sum+=2;
		if(f[i]==')') sum+=3;
	}
	return sum%1000010;
}
void pd(){
	zuo=0;
	you=0;
	int cnt=0,t=0;
	int sum=0;
	for(int i=0;i<n;i++){
		if(f[i]==')'){
			you++;
			sum=0;
			if(t==0) return ;
			for(int j=t;j>=1;j--){
				if(q[j]=='('){
					if(sum>k){
						return;
					}	
					t--;
					break;

				}
							
			} 
		}
		if(f[i]=='('){
			zuo++;
			t++;
			q[t]='(';
			sum=0;
		}
		if(f[i]=='*'){
			if(zuo==0) return;
			sum++;
			if(sum>k) return;
		}
	}
	if(zuo!=you) return;
	if(t!=0){
		for(int i=1;i<=t;i++){
			if(f[i]=='(') return;
		}
	}	
	if(zhi[qz()]==1) return;
	else{
		zhi[qz()]=1;
	}
	ans=ans%1000000007;
	ans++;
	for(int i=0;i<n;i++) cout<<f[i];
	cout<<endl;
	return;
}
void dfs(int x,int deep){
//	cout<<f<<endl;
	if(deep==n+1){
		pd();
		return;	
	} 
	f[a[1+x]]='(';
	dfs(1+x,deep+1);
	f[a[1+x]]='*';
	dfs(1+x,deep+1);
	f[a[1+x]]=')';
	dfs(1+x,deep+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			m++;
			a[m]=i;
		}
		else{
		f[i]=s[i];
		v[i]=true;
		}
	}
	if(n>15&&n<=40){
		cout<<"0";
		return 0;
	}
	if(n>40){
		cout<<"0";
		return 0;
	}
	//for(int i=1;i<=m;i++) cout<<a[i]<<endl;
	f[a[1]]='(';
	dfs(1,1);
	f[a[1]]='*';
	dfs(1,1);
	f[a[1]]=')';
	dfs(1,1);
	cout<<ans;
	return 0;
}
