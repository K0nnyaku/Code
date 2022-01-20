#include<iostream> //40pts
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e6+5;
int T,n,m,a[N],b[N],bk[100][100005];
char s[N];
int read(){
	int ans=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0'){
		ans=(ans<<3)+(ans<<1)+ch-'0';
		ch=getchar();
	}
	return ans;
}
inline bool dfs(int dep,int drct,int l,int r){
	if(dep>m)
		return true;
	
	if(drct){
		b[dep]=a[r--];
		s[dep]='R';
	}
	else{
		b[dep]=a[l++];
		s[dep]='L';
	}
	if(dep<=n){
		if(bk[T][b[dep]])return false;
		bk[T][b[dep]]++;
	}
	if(dep>n)
		if(b[dep]!=b[m-dep+1])
			return false;
	if(dfs(dep+1,0,l,r)||dfs(dep+1,1,l,r))
		return true;
	if(dep<=n){
		bk[T][b[dep]]--;
	}
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		m=n<<1;
		if(n>100){
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<=m;++i)
			a[i]=read();	
		if(dfs(1,0,1,m)||dfs(1,1,1,m)){
			for(int j=1;j<=m;++j)
				cout<<s[j];
			cout<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
	return 0;
} 
