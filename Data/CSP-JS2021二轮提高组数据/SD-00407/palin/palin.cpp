#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#define max_n 200005
using namespace std;
int a[max_n*2],p1[max_n],p2[max_n];
char s[max_n*2],ans[max_n*2];
bool vis[max_n],rec[max_n],fd=false;
int T,n;
inline int read(){
	int flag=1,ans=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')flag=-flag;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return flag*ans;
}
void work(int t,int ss,int l1,int l2,int r1,int r2){
	if(t==n-1){
		if(l1==0&&a[r2]==ss)s[1]='R',s[n*2]='L';
		if(a[l1]==ss&&r2==2*n)s[1]='L',s[2*n]='L';
		if(fd==false){
			strcpy(ans,s);
			return;
		}
		bool bl=true;
		for(int i=1;i<=2*n;i++)if(ans[i]<s[i])bl=false;
		if(bl)strcpy(ans,s);
	}
	if(a[l1]==a[l2]){
		s[n-t]='L',s[n+t]='L';
		work(t+1,a[l1],l1-1,l2+1,r1,r2);
	}
	if(a[l1]==a[r1]){
		s[n-t]='L',s[n+t]='R';
		work(t+1,a[l1],l1-1,l2,r1-1,r2);
	}
	if(a[l2]==a[r2]){
		s[n-t]='R',s[n+t]='L';
		work(t+1,a[l2],l1,l2+1,r1,r2+1);
	}
	if(a[r1]==a[r2]){
		s[n-t]='R',s[n+t]='R';
		work(t+1,a[r1],l1,l2,r1-1,r2+1);
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		fd=false;
		memset(p1,0,sizeof(p1));
		memset(p2,0,sizeof(p2));
		memset(vis,0,sizeof(vis));
		n=read();
		for(int i=1;i<=n*2;i++){
			a[i]=read();
			if(!p1[a[i]])p1[a[i]]=i;
			else p2[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			bool bl=true;
			int ct=0;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=n;j++){
				ct++;
				if(a[j]==i)break;
				if(vis[a[j]]=true){
					bl=false;break;
				}
				vis[a[j]]=true;
			}
			for(int j=2*n;j>=n+1;j--){
				ct++;
				if(a[j]==i)break;
				if(vis[a[j]]==true){
					bl=false;break;
				}
				vis[a[j]]=true;
			}
			if(ct==n-1&&bl){
				s[n-1]='L',s[n+1]='R';
				work(1,i,p1[i],p1[i],p2[i],p2[i]);
			}
		}
		if(fd)printf("%s\n",ans);
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

