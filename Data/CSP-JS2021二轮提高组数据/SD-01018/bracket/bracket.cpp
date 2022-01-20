#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=510;
const int MOD=1e9+7;
int n,k;
char ch[N];
int cnt;
char tes[N];
void dfs(int m,int now,int head){
	if(m==n){
		return;
	}
	bool flag=0;
	int tmp1=0,tmp2=0;
	if(ch[m]=='*'){
		//printf("OK m:%d\n",m);
		tes[++head]='*';
		++now;
		if(now>(k+k)){ 
			return;
		}
		dfs(m+1,now,head);
	}
	if(ch[m]==')'){
		flag=1;
		tmp1=head;tmp2=now;
		while(tes[head]!='('&&head>=(now+1)){
			--now;
			--head;
		}
		if(tes[head]=='('){
			--head;
		}
		if((m+1)==n&&head==now){
			++cnt;
			return;
		}
		dfs(m+1,now,head);
		head=tmp1;
		now=tmp2;
	}
	if(ch[m]=='('){ 
		tes[++head]='(';
		dfs(m+1,now,head);
		
	}
	if(ch[m]=='?'){
		tes[++head]='(';
		dfs(m+1,now,head);
		if(now<3){
			tes[head]='*';
			dfs(m+1,now+1,head);
		}
		tes[head]=')';
		tmp1=head;
		tmp2=now;
		printf("SEE\n");
		while(tes[head]!='('&&head>=(now+1)){
			
			for(int v=1;v<=head;++v){
				printf("%c ",tes[v]);
			}
			--now;
			--head;
		}
		printf("YES\n");
		if(tes[head]=='('){
			--head;
			if((m+1)==n&&head==now){
				++cnt;
			}
			else dfs(m+1,now,head);
		}
		head=tmp1;
		now=tmp2;
		//printf("OK\n");
	} 
	if(flag==1){
		head=tmp1;
		now=tmp2;
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k); 
	scanf("%s",ch);
	printf("%c",ch[0]); 
	if(ch[0]!='('){
		printf("0");
		return 0;
	}
	tes[0]='(';
	dfs(1,0,1);
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
