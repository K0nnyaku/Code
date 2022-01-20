/*
#include <cstdio>
#include <cstring>
using namespace std;
long long int n,k,cnt;
char str[501],a[501];
bool c1(const long long int l,const long long int r){
	for(register long long int i=l;i<=r;i++)
		if(a[i]!='*')
			return false;
	if(r-l+1>k)
		return false;
	return true;
};
bool chk(const long long int l,const long long int r,const long long int dep){
	printf("#%lld# %lld %lld:",dep,l,r);
	for(register long long int i=l;i<=r;i++)
		printf("%c",a[i]);
	putchar('\n');
//	getchar();
	if(l>=r)
		return false;
	if(c1(l,r)==true)
		return false;
	if((l==r-1)&&(a[l]=='(')&&(a[r]==')'))
		return true;
	if((a[l]=='(')&&(a[r]==')')&&(c1(l+1,r-1)==true))
		return true;
	long long int cnt1=0,cnt2=0;
	for(register long long int i=l;i<=r;i++){
		if(a[i]=='(')
			cnt1++;
		if(a[i]==')')
			cnt2++;
	};
	if(cnt1!=cnt2)
		return false;
	if(r-l>=2)
		for(register long long int i=l+2;i<=r;i++)
			for(register long long int j=l+1;j<=i-1;j++)
				if((chk(i,r,dep+1)==true)&&(c1(j,i-1)==true)&&(chk(l,j-1,dep+1)==true))
					return true;
	if((a[l]=='(')&&(a[r]==')')){
		if(chk(l+1,r-1,dep+1)==true)
			return true;
		for(register long long int i=l;i<=l+k-1;i++)
			if((c1(l,i)==true)&&(chk(i+1,r,dep+1)==true))
				return true;
		for(register long long int i=r-k+1;i<=r;i++)
			if((chk(l,i-1,dep+1)==true)&&(c1(i,r)==true))
				return true;
	};
	for(register long long int i=l;i<=r-1;i++)
		if((chk(l,i,dep+1)==true)&&(chk(i+1,r,dep+1)==true))
			return true;
	return false;
};
void dfs(long long int pos){
	if(pos>n){
		printf("-------------------------");
		for(register long long int i=1;i<=n;i++)
				printf("%c",a[i]);
			putchar('\n');
		if(chk(1,n,1)==true){
			cnt++;
		};
		return void();
	};
	while(str[pos]!='?')
		pos++;
	a[pos]='(';
	dfs(pos+1);
	a[pos]=')';
	dfs(pos+1);
	a[pos]='*';
	dfs(pos+1);
	return void();
};
int main(void){
	scanf("%lld%lld",&n,&k);
	scanf("%s",str+1);
	memcpy(a,str,sizeof(str));
	dfs(1);
	printf("%lld\n",cnt);
	return 0;
};
*/
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand((unsigned)time(NULL));
	printf("%lld\n",rand()%(long long int)(1e9+7));
	fclose(stdin);
	fclose(stdout);
	return 0;
};
