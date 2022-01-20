#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define EN putchar('\n')
#define INT_INF (int)(0x3f3f3f3f)
#define LL_INF (long long)(0x3f3f3f3f3f3f3f3f)
inline int read(){
	register int x=0;register int y=1;
	register int c=getchar();
	while(c<'0'||c>'9') y&=(c!='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
	return y?x:-x;
}
#define N 1000006
int n;
int a[N],t[N],op[N];
char ans[N];
int b[N];
inline void output(){
	int l=1,r=(n<<1);
	for(int i=1;i<=n;i++){
		putchar(ans[i]);
		if(ans[i]=='L') b[i]=a[l++];
		else b[i]=a[r--];
		ans[i]=0;
	}
	for(int i=n;i;i--){
		if(a[l]==b[i]) putchar('L'),l++;
		else if(a[r]==b[i]) putchar('R'),r--;
	}
	EN;
}
int main(){
		freopen("palin.in","r",stdin);
		freopen("palin.out","w",stdout);
int $=read();while($--){
	n=read();
	for(int i=1;i<=(n<<1);i++) a[i]=read(),t[a[i]]=i;
	for(int i=1;i<=(n<<1);i++)if(t[a[i]]^i) op[i]=t[a[i]],op[t[a[i]]]=i;
	//ans[1]=L
	int L=2,R=(n<<1),l=op[1],r=op[1];ans[1]='L';
	for(int i=2;i<=n;i++){
		if(L!=l){
			if(L!=l-1&&a[L]==a[l-1]) ans[i]='L',L++,l--;
			else if(a[L]==a[r+1]) ans[i]='L',L++,r++;
			else goto ANS_R;
		}
		else goto ANS_R;
		continue;
	ANS_R:
		if(R!=r){
			if(R!=r+1&&a[R]==a[r+1]) ans[i]='R',R--,r++;
			else if(a[R]==a[l-1]) ans[i]='R',R--,l--;
			else goto FAIL;
		}
		else goto FAIL;
	}
	output();
	continue;
FAIL:
	//ans[1]=R
	L=1;R=(n<<1)-1;l=r=op[n<<1];ans[1]='R';
	for(int i=2;i<=n;i++){
		if(L!=l){
			if(L!=l-1&&a[L]==a[l-1]) ans[i]='L',L++,l--;
			else if(a[L]==a[r+1]) ans[i]='L',L++,r++;
			else goto ANS_R2;
		}
		else goto ANS_R2;
		continue;
	ANS_R2:
		if(R!=r){
			if(R!=r+1&&a[R]==a[r+1]) ans[i]='R',R--,r++;
			else if(a[R]==a[l-1]) ans[i]='R',R--,l--;
			else goto FAIL2;
		}
		else goto FAIL2;
	}
	output();
	continue;
FAIL2:
	for(int i=1;i<=n;i++) ans[i]=0;
	puts("-1");
}
	return 0;
}
