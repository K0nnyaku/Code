#include <cstdio>
#include <algorithm>

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=1e2+7,INF=1e9+7,Mod=998244353;
int n,k,ans;
char s[N];

int checK(){
//	printf("%s\n",s+1);
	int c=0,r=0;
	for(int i=1;i<=n;i++){
		if(i==1&&s[i]=='*')return 0; 
		if(s[i]=='(')++c;
		if(s[i]==')')--c;
		if(s[i]=='*')++r;
		else r=0;
		if(r>k)return 0;
		if(c<0)return 0;
	}
	if(c>0)return 0;
	return 1;
}

void dfs(int p){
	if(p==n){
		if(checK()==1)++ans;
	}
	else{
		if(s[p+1]=='?'){
			s[p+1]='(';
			dfs(p+1);
			s[p+1]=')';
			dfs(p+1);
			s[p+1]='*';
			dfs(p+1);
			s[p+1]='?';
		}
		else dfs(p+1);
	}
	return;
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	n=read(),k=read();
	scanf("%s",s+1);
	dfs(0);
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

