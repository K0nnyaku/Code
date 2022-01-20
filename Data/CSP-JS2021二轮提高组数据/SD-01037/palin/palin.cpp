#include<cstdio>
#include<cstring>
using namespace std;
int check(int l,int r,const int *a){
	while(l<r){
		if(a[l]!=a[r]) return 0;
		++l,--r;
	}
	return 1;
}
int a[1000005];
char b[1000005];
char cnt[500005];
int to[500005];
int pre[500005];
int Main(){
	int lb,rb;
	int i,n,j;
	int pos;
	int ans=-1;
	memset(cnt,0,sizeof cnt);
	
	scanf("%d",&n);
	if(n==1){
		puts("LL");
		return 0;
	}
	n<<=1;
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(cnt[a[i]])
			to[a[i]]=i;
		else 
			cnt[a[i]]=1,pre[a[i]]=i;
	}
	
Alpha:
	pos=to[a[1]];
	if(pos==2){
		if(check(3,n,a)){
			putchar('L');
			for(i=n;i>=3;--i)
				putchar('R');
			putchar('L');
			putchar('\n');
			return 0;
		}
		else{
			goto Bravo;
		}
	}
	else if(pos==n){
		if(check(2,n-1,a)){
			putchar('L');
			for(i=n;i>=3;--i)
				putchar('L');
			putchar('L');
			putchar('\n');
			return 0;
		}
		else{
			goto Bravo;
		}
	}
	else{
		int lp,rp;
		int lc,rc;
		lb=2,rb=n-1;
		b[1]='L';
		b[n]='L';
		lp=pos-1;
		rp=pos+1;
		lc=2;
		rc=n;
		while(lb<=rb){
			int p=to[a[lc]];
			if(p==lp&&lc<=lp){
				b[lb++]='L';
				b[rb--]='L';
				++lc;
				--lp;
				continue;
			}
			else if(p==rp&&rp<=rc){
				b[lb++]='L';
				b[rb--]='R';
				++lc;
				++rp;
				continue;
			}
			p=pre[a[rc]];
			if(p==lp&&lc<=lp){
				b[lb++]='R';
				b[rb--]='L';
				--rc;
				--lp;
				continue;
			}
			else if(p==rp&&rp<=rc){
				b[lb++]='R';
				b[rb--]='R';
				--rc;
				++rp;
				continue;
			}
			goto Bravo;
		}
		if(lb>rb){
			puts(b+1);
			return 0;
		}
	}
Bravo:;
	pos=pre[a[n]];
	if(pos==n-1){
		if(check(1,n-2,a)){
			putchar('L');
			for(i=n;i>=3;--i)
				putchar('R');
			putchar('L');
			putchar('\n');
			return 0;
		}
		else{
			puts("-1");
			return 0;
		}
	}
	else if(pos==1){
		if(check(2,n-1,a)){
			putchar('L');
			for(i=n;i>=3;--i)
				putchar('L');
			putchar('L');
			putchar('\n');
			return 0;
		}
		else{
			puts("-1");
			return 0;
		}
	}
	else{
		int lp,rp;
		int lc,rc;
		lb=2,rb=n-1;
		b[1]='R';
		b[n]='L';
		lp=pos-1;
		rp=pos+1;
		lc=1;
		rc=n-1;
		while(lb<=rb){
			int p=to[a[lc]];
			if(p==lp&&lc<=lp){
				b[lb++]='L';
				b[rb--]='L';
				++lc;
				--lp;
				continue;
			}
			else if(p==rp&&rp<=rc){
				b[lb++]='L';
				b[rb--]='R';
				++lc;
				++rp;
				continue;
			}
			p=pre[a[rc]];
			if(p==lp&&lc<=lp){
				b[lb++]='R';
				b[rb--]='L';
				--rc;
				--lp;
				continue;
			}
			else if(p==rp&&rp<=rc){
				b[lb++]='R';
				b[rb--]='R';
				--rc;
				++rp;
				continue;
			}
			puts("-1");
			return 0;
		}
		if(lb>rb){
			puts(b+1);
			return 0;
		}
	}
	return 0;
}
int main(){
	int t;
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--) Main();
	return 0;
}
