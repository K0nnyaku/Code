#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e6+10;
int t,n,a[N],b1[N],b2[N];
int s[N],tot,cnt,pd;
void dfs(int l1,int r1,int l2,int r2){
	if(l1<0||l2<0||r1>2*n||r2>2*n)
		return;
	//cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<a[l1]<<' '<<a[l2]<<' '<<tot<<' '<<cnt<<endl;
	if(tot==cnt-1){
		for(int i=1,j=2*n;i<j;i++,j--)
			if(a[s[i]]!=a[s[j]])
				return;
		//for(int i=1;i<=2*n;i++)
		//	cout<<s[i]<<' ';
		//cout<<endl;
		pd=1;
		return;
	}
	if(pd)
		return;	
	if(a[l2]==a[r2]){
		s[++tot]=l2;
		s[--cnt]=r2;
		dfs(l1,r1,l2+1,r2-1);
		if(pd)
			return;
		s[tot--]=0;
		s[cnt++]=0;
	}
	if(a[l1]==a[l2]){
		s[++tot]=l2;
		s[--cnt]=l1;
		dfs(l1-1,r1,l2+1,r2);
		if(pd)
			return;
		s[tot--]=0;
		s[cnt++]=0;
	}
	if(a[r1]==a[l2]){
		s[++tot]=l2;
		s[--cnt]=r1;
		dfs(l1,r1+1,l2+1,r2);
		if(pd)
			return;
		s[tot--]=0;
		s[cnt++]=0;
	}
	if(a[l1]==a[r2]){
		s[++tot]=r2;
		s[--cnt]=l1;
		dfs(l1-1,r1,l2,r2-1);
		if(pd)
			return;
		s[tot--]=0;
		s[cnt++]=0;
	}
	if(a[r1]==a[r2]){
		s[++tot]=r2;
		s[--cnt]=r1;
		dfs(l1,r1+1,l2,r2-1);
		if(pd)
			return;
		s[tot--]=0;
		s[cnt++]=0;
	}
	return;
}
void print(){
	int l=1,r=2*n;
	for(int i=1;i<=2*n;i++){
		int p=s[i];
		s[i]=0;
		if(p==l){
			printf("L");
			l++;
			continue;
		}
		if(p==r){
			printf("R");
			r--;	
			continue;
		}
		printf("R");
	}
	printf("\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		for(int i=1;i<=2*n;i++)
			b1[i]=b2[i]=0;
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			if(b1[a[i]]==0)
				b1[a[i]]=i;
			else b2[a[i]]=i;
		}
		pd=0;
		int l1=b2[a[1]]-1,r1=l1+2,l2=2,r2=2*n;
		tot=0,cnt=2*n+1;
		s[++tot]=1;
		s[--cnt]=l1+1;
		dfs(l1,r1,l2,r2);
		if(pd==1){
			print();
			continue;
		}
		l1=b1[a[2*n]]-1,r1=l1+2,l2=1,r2=2*n-1;
		tot=0,cnt=2*n+1;
		s[++tot]=2*n;
		s[--cnt]=l1+1;
		dfs(l1,r1,l2,r2);
		if(pd==1){
			print();
			continue;
		}
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

