#include<bits/stdc++.h>
#define fo(i,x,y) for(int i=x;i<=y;++i)
#define go(i,x,y) for(int i=x;i>=y;--i)
#define sml(x,y) x=min(x,y)
#define big(x,y) x=max(x,y)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define umap unordered_map
#define add(x,y) x=(x+y)%qlr
using namespace std;
inline void out(int *a,int l,int r){fo(i,l,r) printf("%d ",*(a+i));puts("");}

inline int read(){
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

const int N=505,qlr=1e9+7;
char a[N];
int n,k,ok[N][N];
namespace pt65{
	int f[N][N],g[N][N];
	int solve(int l,int r){
		//printf("solve(%d,%d)\n",l,r);
		if(l==r) return 0;
		if(l==r+1) return 1;
		if(g[l][r]) return f[l][r];
		g[l][r]=1;
		if(!((a[l]=='?'||a[l]=='(')&&(a[r]=='?'||a[r]==')'))) return 0;
		//printf("[%d,%d]=%d,(A):\n",l,r,f[l][r]);
		add(f[l][r],solve(l+1,r-1));
		//if((a[l]=='?'||a[l]=='(')&&(a[r]=='?'||a[r]==')')) add(f[l][r],solve(l+1,r-1));//(A)
		//else return 0;
		//printf("[%d,%d]=%d,(SA):\n",l,r,f[l][r]);//选[l+1,i]这段为S,A=[i+1,r-1] 
		fo(i,l+1,r-3) if(ok[l+1][i]) add(f[l][r],solve(i+1,r-1));//,printf("%d,%d选择[%d,%d]\n",l,r,l+1,i);
		//printf("[%d,%d]=%d,(AS):\n",l,r,f[l][r]);//选[i,r-1]这段为S,A=[l+1,i-1] 
		fo(i,l+2,r-1) if(ok[i][r-1]) add(f[l][r],solve(l+1,i-1));
		//printf("[%d,%d]=%d,AB:\n",l,r,f[l][r]);
		//fo(i,l+1,r-1) add(f[l][r],1ll*solve(l,i)*solve(i+1,r));//AB
		//选[l,i]为A,[i+1,r]为B。钦定 i 是第一个与 l 匹配的位置 
		fo(i,l+1,r-1) if(a[i]==')'||a[i]=='?') add(f[l][r],1ll*(solve(l+1,i-1)+ok[l+1][i-1])*solve(i+1,r));
		//ASB
		//printf("[%d,%d]=%d,ASB:\n",l,r,f[l][r]);
		fo(i,l+1,r-1) fo(j,i,r-1) if(ok[i][j]) add(f[l][r],1ll*solve(l,i-1)*solve(j+1,r));
		/*fo(i,l+2,r-2) if(a[i]=='*'||a[i]=='?'){
			int R=i;
			while(R<r-1&&(a[R+1]=='*'||a[R+1]=='?')) R++;
			while(i<=R){
				//[i,j]全填*,A=[l,i-1],B=[j+1,r] 
				fo(j,i,min(R,i+k-1)) add(f[l][r],1ll*solve(l,i-1)*solve(j+1,r));
				i++;
			}i--;
		}*/
		//(S)
		//printf("[%d,%d]=%d,(S):\n",l,r,f[l][r]);
		add(f[l][r],ok[l+1][r-1]);
		/*if(r-l>1&&r-l-1<=k){
			puts("(S):");
			int flg=1;
			fo(i,l+1,r-1) if(a[i]==')'||a[i]=='('){
				flg=0;
				break;
			}add(f[l][r],flg);	
		}*/
		//printf("f[%d][%d]=%d ",l,r,f[l][r]);fo(i,l,r) putchar(a[i]);puts(""); 
		return f[l][r];
	}
}

void file(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}

int main(){
	file();
	cin>>n>>k;
	scanf("%s",a+1);
	fo(i,1,n) if(a[i]=='*'||a[i]=='?') ok[i][i]=1;
	fo(len,2,k)
		fo(l,1,n-len+1){
			int r=l+len-1;
			ok[l][r]=ok[l][l]&&ok[l+1][r];
			//printf("[%d,%d],%d\n",l,r,ok[l][r]);
		}//return 0;
	//fo(i,1,n) out(ok[i],1,n);
	cout<<pt65::solve(1,n);
	return 0;
}
/*
7 3
(*??*??
----------
5
*/

/*
10 2
???(*??(?)
-----------
19
*/
