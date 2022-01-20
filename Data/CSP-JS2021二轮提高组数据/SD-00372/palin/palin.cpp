#include <cstdio>
using namespace std;
long long int T,n,rec1[500001],a[1000001],tl,tr,b[1000001],rec2[500001];
bool chk,fnd;
long long int read(void){
	long long int tans=0;
	char ch=getchar();
	while((ch<'0')||(ch>'9'))
		ch=getchar();
	while((ch>='0')&&(ch<='9')) 
		tans=tans*10+ch-'0',
		ch=getchar();
	return tans;
};
void dfs2(const long long int l,const long long int r,const long long int k){
	if(k==0){
		if(chk==true){
			for(register long long int i=1;i<=n;i++)
				if(rec1[i]==0)
					putchar('L');
				else
					putchar('R');
			for(register long long int i=n;i>=1;i--)
				if(rec2[i]==0)
					putchar('L');
				else
					putchar('R');
			putchar('\n');
			fnd=true;
			return void();
		};
		return void();
	};
	bool rs=false;
	if(a[l]==b[k]){
		rs=true,
		rec2[k]=0;
		dfs2(l+1,r,k-1);
		if((chk==false)||(fnd==true))
			return void();
	};
	if(a[r]==b[k]){
		rs=true,
		rec2[k]=1;
		dfs2(l,r-1,k-1);
		if((chk==false)||(fnd==true))
			return void();
	};
	if(rs==false)
		chk=false;
	return void(); 
};
void dfs1(const long long int l,const long long int r,const long long int k){
	if(k==n+1){
		tl=1,
		tr=n<<1;
		for(register long long int i=1;i<=n;i++)
			if(rec1[i]==0)
				b[i]=a[tl],
				tl++;
			else
				b[i]=a[tr],
				tr--;
		chk=true;
		dfs2(l,r,n);
		return void();
	};
	rec1[k]=0;
	dfs1(l+1,r,k+1);
	if(fnd==true)
		return void();
	rec1[k]=1;
	dfs1(l,r-1,k+1);
	if(fnd==true)
		return void();
	return void();
};
int main(void){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		n=read();
		for(register long long int i=1;i<=(n<<1);i++)
			a[i]=read();
		fnd=false;
		dfs1(1,n<<1,1);
		if(fnd==false)
			printf("-1\n");
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
};
