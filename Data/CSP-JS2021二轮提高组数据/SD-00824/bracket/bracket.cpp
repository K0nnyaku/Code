#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define M 200200
#define INF 0x3f
#define Mod 1000000007
using namespace std;
int Ans;char C;bool O;
int inp(){
	O=false;
	while((C=getchar())<'0'||C>'9') if(C=='-') O=true;Ans=C-48;
	while((C=getchar())<='9'&&C>='0') Ans=(Ans<<3)+(Ans<<1)+C-48;
	return O?-Ans:Ans;
}

int n,k,a[M],tot,head[M],nxt[M],sum,ans,pos[M],cnt,CNT;
char s[M];

struct Edge{
	int f,t;
}edge[M];

void build(int f,int t){
	edge[++tot]=(Edge){f,t};
	nxt[tot]=head[f];head[f]=tot;
}

bool check(){
	//cout<<++CNT<<endl;
	sum=0;
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<" ";
		if(a[i]==1) sum++;
		if(a[i]==2) sum--;
		if(sum<0) return false;
	}
	//cout<<endl;
	if(sum) return false;
	return true;
}

void dfs(int x){
	for(int k=1;k<=3;k++){
		a[x]=k;
		//cout<<x<<" "<<a[x]<<endl;
		for(int i=head[x];i;i=nxt[i]){
			dfs(edge[i].t);
			if(check()){
			ans++;
			ans%=Mod;
			} 
		}
		
	}
}

int main(){
	freopen("bracket2.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	n=inp();k=inp();
	cin>>s+1;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') a[i]=1;
		if(s[i]==')') a[i]=2;
		if(s[i]=='*') a[i]=3;
		if(s[i]=='?'){
			pos[++cnt]=i;
			build(pos[cnt-1],i);
		}
		//cout<<cnt<<endl;
	}
	dfs(pos[1]);//cout<<pos[1]<<endl;
	return !printf("%d",ans%Mod);
}

