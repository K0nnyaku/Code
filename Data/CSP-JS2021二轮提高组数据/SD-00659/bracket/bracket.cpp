#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
//#include<ctime>
#include<vector>
#include<set>
#define R register
#define N 509
#define ll long long
#define P 1000000007

inline ll Rd(){
	R ll x=0; R char ch;
	do{
		ch=getchar();
	}while(ch<'0'||ch>'9');
	do{
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	}while(ch>='0'&&ch<='9');
	return x;
}

int f[N][N],g[N][N],o[N][N],n,k, A[N][N];
char s[N];

inline bool bra(int i,int j){
	return (s[i]=='('||s[i]=='?') && (s[j]==')'||s[j]=='?');
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(R int i=1;i<=n;++i){
		o[i][i-1]=1;
		for(R int j=i;j<=i+k-1&&j<=n;++j)
			o[i][j] = o[i][j-1] & (s[j]=='?'||s[j]=='*');
	}
	for(R int i=1;i<n;++i)
		for(R int j=i+1;j<=n;++j){
			if(bra(i,j) && o[i+1][j-1])
//				printf("! %d %d\n",i,j),
				g[i][j] = 1;
		}
	for(R int l=2;l<=n;++l){
		for(R int i=1;i<=n;++i){
			R int j = i+l-1;if(j > n) break;
			// A S B [i,k] [k+1,l] [l+1,j]
			for(R int k = i; k < j; ++k)
				f[i][j] = (f[i][j] + 1LL*g[i][k] * A[k+1][j]) % P;
//			for(R int k = i;k < j; ++k)
//				for(R int l=k;l<j;++l)
//					printf("%d %d %d %d %d %d %d\n",i,k,l,j,g[i][k], o[k+1][l],f[l+1][j]),
//					f[i][j] = (f[i][j]+1LL*g[i][k] * o[k+1][l]%P*f[l + 1][j])%P;
			R int soo = bra(i,j);
			if(soo){
			// (S A)
			for(R int k = i;k < j - 1;++k)
				g[i][j] = (g[i][j] + 1LL * o[i+1][k] * f[k+1][j-1])%P;
			// (A S)
			for(R int k = i+1;k < j - 1;++k)
				g[i][j] = (g[i][j] + 1LL * f[i+1][k] * o[k+1][j-1]) % P;
			f[i][j] = (f[i][j]+g[i][j]) % P;
//			printf("! %d %d %d %d\n",i,j,f[i][j],g[i][j]);
			}
			for(R int l = i-1; l < j; ++l)
				A[i][j] = (A[i][j] + 1LL * o[i][l] * f[l+1][j]) % P;
		}
	}
	std::cout<< f[1][n] << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//一定别忘了加上freopen、fclose
//一定要检查数组大小！
//特判所有的边界情况！
//多测要清空！
//模数要写对了！
//尽量不要随机化乱搞！
//有时间的话和暴力对拍！
//先做简单题，再做难的！
//做不出的话就写暴力！
//qwqwq
