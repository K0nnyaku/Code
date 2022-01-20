#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#define ll long long
using namespace std;
int in(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int p=1e9+7;
int n,k;
int L=0,R=0,W=0; 
int pos[600];
ll ans=0;
char c[600];
inline int Abs(int x){
	return x>0?x:-x;
}
bool check(){
	char st[600][2];
	int top=0;
	bool state[600][4]={0};//×óÓÒºÏ·¨£¬×óÓÒÀ¨ºÅ 
	bool f=0;
	bool sta[600][4]={0};
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(c[i]=='('){
			f=0;
			st[++top][0]=c[i];
			st[top][1]=i+'0';
		}
		else if(c[i]==')'){
			if(top>0){
				f=1;
				if(c[(st[top][1]-'0')-1]=='*') state[(st[top][1]-'0')-1][1]=1;
				--top;
			}else return 0;
		}
		else if(c[i]=='*'&&(c[i-1]!='*'||c[i+1]!='*')){
			if(c[i-1]=='(') state[i][2]=1;
			if(c[i+1]==')') state[i][3]=1;
			if(f) state[i][0]=1;
		}
	}
	int l;
	for(int i=1;i<=n;++i){
		if(c[i]=='*'){
			int xx=i;
			sta[++cnt][0]=state[i][0];
			sta[cnt][2]=state[i][2];
			while(c[i]=='*') ++i;
			if(i-xx>k) return 0;
			--i;
			sta[cnt][1]=state[i][1];
			sta[cnt][3]=state[i][3];
		}
	}
//	for(int i=1;i<=cnt;++i){
//		for(int j=0;j<=3;++j)
//			cout<<sta[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=cnt;++i){
		l=i+1;
		while((sta[l][0]&&sta[l][1])||(sta[l][2]&&sta[l][3])) ++l;
		if(l>cnt){
			return 1;
		}
		if(sta[i][2]&&sta[i][1]&&sta[l][0]&&sta[l][3]) return 0;
	}
	
	return 1;
}
void dfs(int id,int l,int r,int w){
	if(id==W+1){
//		cout<<ans<<endl,cout<<c+1<<endl;
		if(check()) ans=(ans+1)%p;
		return;
	}
	if(Abs(l+1-r)<=w-1){
		c[pos[id]]='(';
		dfs(id+1,l+1,r,w-1);
	}
	if(Abs(l-r-1)<=w-1){
		c[pos[id]]=')';
		dfs(id+1,l,r+1,w-1);
	}
	int num=0,i;
	i=pos[id]-1;
	while(c[i]=='*'&&i>0) ++num,--i;
	i=pos[id]+1;
	while(c[i]=='*'&&i<=n) ++num,++i;
	if(pos[id]!=1&&pos[id]!=n){
		c[pos[id]]='*';
		dfs(id+1,l,r,w-1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int Num=0;
	n=in(),k=in();
	cin>>(c+1);
	if(c[1]=='*'||c[n]=='*'){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(c[i]=='(') ++L;
		else if(c[i]==')') ++R;
		else if(c[i]=='?') ++W,pos[W]=i;
		else if(c[i]=='*') Num=c[i-1]=='*'?Num+1:1;
	}
	int cha=L-R;
	if(Num>k&&Abs(cha)>W){
		cout<<0<<endl;
		return 0;
	}
	dfs(1,L,R,W);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

