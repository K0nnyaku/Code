#include<bits/stdc++.h>
using namespace std;
#define I inline 
int T,n,a[1000005],b[500005],cnt;bool flag,vis[500005];
I int rd(){
	int w=1,p=0;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}while(isdigit(c)){
		p=(p<<3)+(p<<1)+c-'0';
		c=getchar();
	}return p*w;
} 
I void dfs(int id,string s,int bg,int ed){
	if(flag)return;
	if(id==2*n){
		flag=1;
		cout<<s<<"L"<<endl;
		return;
	}if(id<=n){
			if(!vis[a[bg]]&&!flag){
				b[id]=a[bg];
				vis[b[id]]=1;
				dfs(id+1,s+"L",bg+1,ed);
				vis[b[id]]=0;
			}if(!vis[a[ed]]&&!flag){
				b[id]=a[ed];
				vis[b[id]]=1;
				dfs(id+1,s+"R",bg,ed-1);
				vis[b[id]]=0;
			}
	}else{
		if(b[n-(id-n)+1]==a[bg]&&!flag){
			bg++;dfs(id+1,s+'L',bg,ed);
		}else if(b[n-(id-n)+1]==a[ed]&&!flag){
			ed--;dfs(id+1,s+'R',bg,ed);
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=rd();
	while(T--){
		n=rd();
		for(int i=1;i<=2*n;i++)a[i]=rd();
		cnt=1;flag=0;
		dfs(1,"",1,2*n);
		if(!flag)cout<<-1<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
