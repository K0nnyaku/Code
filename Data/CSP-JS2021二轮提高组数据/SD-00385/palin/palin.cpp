#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int T,n;
int a[1000001],l,r,l1,r1,anothe[1000001],vis[1000001],cnt=0,v[1000001],cnt1=0;
bool avl[1000001];
char ans[1000001];
inline int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(avl,0,sizeof(avl));
		cnt=cnt1=0;
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			if(vis[a[i]]){
				anothe[vis[a[i]]]=i;
				anothe[i]=vis[a[i]];
			}
			vis[a[i]]=i;
		}
		l=1,r=2*n,l1=0,r1=0;
		bool ff=0;
		while(1){
			if(cnt==n){
				ff=1;
				break; 
			}
			bool flag=0;
			if((!avl[a[l]])&&((l1==0&&r1==0)||(anothe[l]==l1-1||anothe[l]==r1+1))){
				flag=1;	
				avl[a[l]]=1;
				if(l1==r1&&l1==0) l1=r1=anothe[l];
				else{
					if(anothe[l]==l1-1) l1--;
					else r1++;
				}
				v[++cnt1]=a[l];
				ans[++cnt]='L';l++;
			}
			if(flag==0){
				if((l1==0&&r1==0)||(anothe[r]==l1-1||anothe[r]==r1+1)){
					flag=1;
					avl[a[r]]=1;
					if(l1==r1&&l1==0) l1=r1=anothe[r];
					else{
						if(anothe[r]==l1-1) l1--;
						else r1++;
					}
					v[++cnt1]=a[r];
					ans[++cnt]='R';r--;
				}
			}
			if(flag==0){
				break;
			}
		}
		if(!ff){
			memset(vis,0,sizeof(vis));
			memset(avl,0,sizeof(avl));
			cnt=cnt1=0;
			l=1,r=2*n-1,l1=anothe[2*n],r1=anothe[2*n];
			ff=0;
			ans[++cnt]='R';
			v[++cnt1]=a[2*n];
			avl[a[2*n]]=1;
			while(1){
			if(cnt==n){
				ff=1;
				break; 
			}
			bool flag1=0;
			if((!avl[a[l]])&&((l1==0&&r1==0)||(anothe[l]==l1-1||anothe[l]==r1+1))){
				flag1=1;	
				avl[a[l]]=1;
				if(l1==r1&&l1==0) l1=r1=anothe[l];
				else{
					if(anothe[l]==l1-1) l1--;
					else r1++;
				}
				v[++cnt1]=a[l];
				ans[++cnt]='L';l++;
			}
			if(flag1==0){
				if((l1==0&&r1==0)||(anothe[r]==l1-1||anothe[r]==r1+1)){
					flag1=1;
					avl[a[r]]=1;
					if(l1==r1&&l1==0) l1=r1=anothe[r];
					else{
						if(anothe[r]==l1-1) l1--;
						else r1++;
					}
					v[++cnt1]=a[r];
					ans[++cnt]='R';r--;
				}
			}
			if(flag1==0){
				break;
			}
		}
		if(!ff){
			printf("-1\n");continue;
		}
		}
		if(ff){
			for(int i=cnt1;i;i--){
				if(a[l]==v[i]){
					l++;ans[++cnt]='L';
				}else{
					r--,ans[++cnt]='R';
				}
			}
			for(int i=1;i<=cnt;i++) printf("%c",ans[i]);
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
