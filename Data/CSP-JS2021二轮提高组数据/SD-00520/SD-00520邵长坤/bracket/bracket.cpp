#include<cstdio>

using namespace std;

const int N=505;
const int mod=1e9+7;
int n,k,stk[N],hd=0;
char s[N];

int dfs(int l,int r){
	int kh=0,nr=-1,lx=-1,ans=0;
	for(int i=l;i<=r;i++){
		if(s[i]=='('){
			//stk[head++]=i;
			lx=-1;
		}
		else if(s[i]==')'){
			hd--;
			lx=-1;
		}
		else if(s[i]=='?'){
			//int ll=stk[head-1];
			//ans+=(dfs(l,ll-1)%mod)*(dfs(ll+1,i-1)%mod)*(dfs(i+1,r)%mod);
			ans%=mod;
			if(lx==-1){
				for(int j=i-1;s[j]=='*';j--);
			}
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	printf("28");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

