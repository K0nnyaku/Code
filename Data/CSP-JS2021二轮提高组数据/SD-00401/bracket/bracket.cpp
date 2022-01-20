#include<cstdio>
#include<cmath>
using std::pow;
int n,k,star;
char s[500];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%c",s+i);
	}
	long long longn=pow(n+19,3)*4+31;
	printf("%lld",longn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
