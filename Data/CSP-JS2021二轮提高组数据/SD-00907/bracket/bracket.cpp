#include <iostream>
#include <cstring>
#include <cstdio>
#define P 1000000007
using namespace std;
int n,k,ans;
char a[505],c[505];
void read(int &x){
	int f=1;char c=getchar();x=0;
	while(c<'0'||c>'9'){
		if (c=='-')f=-f;
		c=getchar(); 
	}
	while (c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}x*=f;
}
int judge(char c[]){
	int lc=0,ls=0,rc=0;//×óÀ¨ºÅÍ³¼Æ£¬×óÀ¨ºÅ×ó±ßÓÐÎÞÐÇºÅ
	for (int i=0;i<n;i++){
		if (c[i]=='('){
			lc++;
//			printf("lc=%d,sc=%d,ls=%d\n",lc,sc,ls);
		}else if (c[i]=='*'){
			ls=lc;
			if (ls==rc&&ls>0&&c[i+1]==')')return 0;
		}else{
			lc--;rc++;if(lc==0)rc=0;
			if (lc<0)return 0;
			ls=lc;
		}
	}
	return 1;
}
void dfs(int p,char c[]){
	if (a[p]!='?'){
		dfs(p+1,c);
		return;
	}if (p>=n){
		if (c[0]!='('||c[n-1]!=')')return;
		int cl=0,cr=0,cs=0;
		for (int i=0;i<n;i++){
			if (c[i]=='(')cl++,cs=0;
			else if (c[i]==')')cr++,cs=0;
			else if (++cs>k)return;
		}if (cl!=cr)return;
		ans=(ans+judge(c))%P;
		return;
	}c[p]='(';
	dfs(p+1,c);
	c[p]='*';
	dfs(p+1,c);
	c[p]=')';
	dfs(p+1,c);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n);read(k);
	cin>>a;
	for (int i=0;i<n;i++)c[i]=a[i];
	dfs(0,c);
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
