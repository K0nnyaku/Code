#include <bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define UF(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define foredge(i) int i=head[u],v=edges[i].to;i;i=edges[i].nxt,v=edges[i].to

using namespace std;
const ll N=100005,M=400005;
ll read(){
	ll x=0,i=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')i=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return i!=0?x:-x;
}

void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void write(ll x,char c){
	if(x<0)putchar('-'),write(-x);
	else write(x);
	putchar(c);
}

struct Edge{
	int nxt,to,w;
	Edge(int a=0,int b=0,int c=0){
		nxt=a,to=b,w=c;
	}
}edges[M];
int epos,head[N];
void add(int u,int v,int w=0){
	edges[++epos]=Edge(head[u],v,w);
	head[u]=epos;
}
int n,k;
char str[505];
int cnt;
int ct[251];
bool hv[251];
bool check(){
	int d=0;
	F(i,1,n){
		if(str[i]=='(') d++,ct[d]=0,hv[d]=0;
		if(str[i]==')'){
			if(ct[d]>0&&hv[d]) return 0;
			d--;
			ct[d]--;
			hv[d]=1;
		}
		if(str[i]=='*')
		{
			if(d==0&&(i==1||i==n)) return 0;
			if(str[i+1]!='*')
			ct[d]++;
		}
		if(d<0) return 0;
		//cout<<i<<' '<<d<<endl;
	}
	F(i,1,n){
		if(str[i]=='*'){
			int fr=i;
			while(str[i+1]=='*')++i;
			if(i-fr+1>k)return 0;
		}
	}
	if(d) return 0;
	return 1;
}
void dfs(int pos, int pre){
	if(pos==n+1){
		if(check()) cnt++;
		return;
	}
	if(str[pos]!='?'){
		if(str[pos]==')') pre--;
		if(str[pos]=='(') pre++;
		dfs(pos+1,pre);
		return;
	}
	if(pre-1>=0)
	str[pos]=')', dfs(pos+1,pre-1);
	if(pos!=1&&pos!=n)
	str[pos]='*', dfs(pos+1,pre);
	str[pos]='('; dfs(pos+1,pre+1);
	str[pos]='?';
} 
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	//check();
	scanf("%s",str+1);
	dfs(1,0);
	write(cnt,'\n');
	return 0;
}
