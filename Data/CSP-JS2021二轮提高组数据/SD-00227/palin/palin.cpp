#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int maxn=5e5+500;
string ans;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int t,n,Left,Right;
int a[maxn],b[maxn];
void dfs(int step,string sum){
	if(step==2*n+1){
		int flag=false;
		for(int i=1;i<=n;i++)
			if(b[i]!=b[2*n-i+1])flag=true;
		if(flag)return;
		if(ans==""||sum<ans)ans=sum;
		return;
	}
	if(Left+1<=2*n){
		b[step]=a[Left];
		Left++;
		dfs(step+1,sum+'L');
		Left--;
	}
	if(Right-1>=0){
		b[step]=a[Right];
		Right--;
		dfs(step+1,sum+'R');
		Right++;
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	memset(a,0,sizeof a);
	t=read();
	while(t--){
		ans="";
		n=read();
		Left=1;Right=n*2;
		for(int i=1;i<=2*n;i++)a[i]=read();
		dfs(1,"");
		if(ans=="")printf("-1\n");
		else cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;	
}
