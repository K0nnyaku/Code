#include<cstdio>
#define MAXN 500005
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
short y[MAXN<<1],nw[MAXN];
bool cz[MAXN<<1];
bool pd[MAXN];
int n;
int hd,tl;
bool flag;
void dfs(int tr){
	if(tr>(n<<1)){
		for(int i=1;i<=n<<1;++i)printf("%c",(cz[i]?'L':'R'));
		flag=true;
		printf("\n");
		return;
	}
	if(tr>n){
		if(y[hd]==nw[(n<<1)-tr+1]){
			++hd;
			cz[tr]=true;
			dfs(tr+1);
			--hd;
		}
		else if(y[tl]==nw[(n<<1)-tr+1]){
			--tl;
			cz[tr]=false;
			dfs(tr+1);
			++tl;
		}
		return;
	}
	if(!pd[y[hd]]){
		pd[y[hd]]=true;
		nw[tr]=y[hd];
		++hd;
		cz[tr]=true;
		dfs(tr+1);
		nw[tr]=0;
		--hd;
		pd[y[hd]]=false;
		if(flag)return;
	}
	if(!pd[y[tl]]){
		pd[y[tl]]=true;
		nw[tr]=y[tl];
		--tl;
		cz[tr]=false;
		dfs(tr+1);
		nw[tr]=0;
		++tl;
		pd[y[tl]]=false;
		if(flag)return;
	}
}
	
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	T=read();
	int i,j;
	for(i=0;i<T;++i){
		n=read();
		for(j=1;j<=n<<1;++j)y[j]=read();
		hd=1;
		tl=n<<1;
		flag=false;
		dfs(1);
		if(!flag)printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
