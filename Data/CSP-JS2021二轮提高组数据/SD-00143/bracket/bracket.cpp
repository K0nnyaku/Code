#include<cstdio>
#include<cstring>
using namespace std;
inline int read(void){
	int ans=0;
	char us=getchar();
	while(us<'0'||us>'9')us=getchar();
	while(us>='0'&&us<='9'){
		ans=(ans<<1)+(ans<<3)+(us^48);
		us=getchar();
	}
	return ans;
}
char s[505];
short duiying[505];
int ans;
int n;
int k;
bool f;
bool peiduied[505];
int peidui1(int tr){
	++tr;
	while(s[tr]!=')'){
		if(s[tr]=='('){
			duiying[tr]=peidui1(tr);
			tr=duiying[tr];
		}
		++tr;
	}
	return tr;
}
bool check(void){
	memset(duiying,0,sizeof duiying);
	memset(peiduied,0,sizeof peiduied);
	for(int j=1;j<=n;++j)if(s[j]=='('&&duiying[j]==0)duiying[j]=peidui1(j);
	int beg=0;
	bool ed=true;
	for(int j=n;j>=1;--j){
		if(s[j]=='*'&&beg==0){
			ed=true;
			beg=j;
			if(s[j+1]=='('&&!peiduied[duiying[j+1]]){
				peiduied[duiying[j+1]]=true;
				ed=false;
			}
		}
		if(ed&&s[j]=='*'&&s[j-1]==')'){
			beg=0;
			peiduied[j-1]=true;
			ed=false;
		}
		if(ed&&s[j]=='*'&&s[beg+1]==')'&&s[j-1]=='(')ed=false;
	}
	return(!ed);
}
void dfs(int nw,int u,int t){
	while(nw<=n&&s[nw]!='?'){
		if(s[nw]=='(')++u;
		if(s[nw]==')')--u;
		if(s[nw]=='*')++t;
		else t=0;
		if(u<0||t>k)return;
		++nw;
	}
	if(nw>n){
		if(u==0&&check()){
			++ans;
			ans%=1000000007;
		}
		return;
	}
	if(t<k){
		s[nw]='*';
		dfs(nw+1,u,t+1);
		s[nw]='?';
	}
	s[nw]='(';
	dfs(nw+1,u+1,0);
	s[nw]='?';
	if(u>0){
		s[nw]=')';
		dfs(nw+1,u-1,0);
		s[nw]='?';
	}
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	char us=getchar();
	while(us!='('&&us!=')'&&us!='*'&&us!='?')us=getchar();
	int i;
	for(i=1;i<=n;++i){
		s[i]=us;
		us=getchar();
	}
	if(s[1]==')'||s[1]=='*'||s[n]=='('||s[n]=='*'){
		printf("0");
		return 0;
	}
	s[1]='(';
	s[n]=')';
	int r=0;
	for(i=1;i<=n;++i){
		if(s[i]!='*')r=0;
		else ++r;
		if(r>k){
			printf("0");
			return 0;
		}
	}
	ans=0;
	dfs(1,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
		
	
