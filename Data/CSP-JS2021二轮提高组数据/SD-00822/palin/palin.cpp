//什么时候我才能有杜爷一半强啊/kk
//永远都不可能了。我失败了。就此别过,我的OI。
#include<cstdio>
int nt[114];
int read(){
	char ch=getchar();int nn=0,ssss=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ssss*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){nn=nn*10+(ch-'0');ch=getchar();}
	return nn*ssss;
}
namespace sub1{
	const int N=1086;
	int c[N],a[N],q[N],v[N];
	bool check(int l,int r,int n){
		int i=l,j=r;
		for(int k=n;k;k--){
			if(a[i]!=q[k]&&a[j]!=q[k])return false;
			if(a[i]==q[k])c[n*2-k+1]=0,i++;
			else c[n*2-k+1]=1,j--;
		}
		for(int i=1;i<=2*n;i++)putchar(c[i]?'R':'L');putchar('\n');
		return true;
	}
	bool dfs(int l,int r,int np,int n){
		if(r-l+1==n)return(check(l,r,n));
		if(!v[a[l]]){
			c[np]=0;q[np]=a[l];v[a[l]]=true;
			if(dfs(l+1,r,np+1,n))return true;
			v[a[l]]=false;
		}
		if(!v[a[r]]){
			c[np]=1;q[np]=a[r];v[a[r]]=true;
			if(dfs(l,r-1,np+1,n))return true;
			v[a[r]]=false;
		}
		return false;
	}
	int mian(int n){
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			v[a[i]]=false;
		}
		if(!dfs(1,2*n,1,n))printf("-1\n");
		return 0;
	}
}
namespace sub2{
	const int N=500086;
	int a[N<<1],q[N<<1],cnt[N],cc[3],pos,l1,l2,q1[N<<1],q2[N<<1];
	bool check(int l,int r,int p,int n){
		int p1=p,p2=p+1;l1=1;l2=2*n;
		for(int i=1;i<=n;i++){
			if(a[p1]==a[l1]&&p1>=l&&l1<l){
				q[i]=q[n*2-i+1]=0;
				p1--;l1++;continue;
			}
			if(a[p2]==a[l1]&&p2<=r&&l1<l){
				q[i]=0;q[n*2-i+1]=1;
				p2++;l1++;continue;
			}
			if(a[p1]==a[l2]&&p1>=l&&l2>r){
				q[i]=1;q[n*2-i+1]=0;
				p1--;l2--;continue;
			}
			if(a[p2]==a[l2]&&p2<=r&&l2>r){
				q[i]=1;q[n*2-i+1]=1;
				p2++;l2--;continue;
			}
			return false;
		}
		for(int i=1;i<=2*n;i++)putchar(q[i]?'R':'L');
		putchar('\n');return true;
	}
	bool solve(int l,int r,int n){
		for(int i=l;i<=r;i++)
			if(a[i]==a[1]){
				if(check(l,r,i,n))return true;
				break;
			}
		for(int i=l;i<=r;i++)
			if(a[i]==a[2*n]){
				if(check(l,r,i,n))return true;
				break;
			}
		return false;
	}
	int mian(int n){
		cc[0]=cc[1]=cc[2]=pos=0;
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			cc[cnt[a[i]]]--;cnt[a[i]]++;cc[cnt[a[i]]]++;
			if(i<n)continue;
			if(i>n){cc[cnt[a[i-n]]]--;cnt[a[i-n]]--;cc[cnt[a[i-n]]]++;}
			if(cc[1]==n)pos=i;
		}
		if(!pos){printf("-1\n");return 0;}
		if(!solve(pos-n+1,pos,n))printf("-1\n");
		return 0;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	for(int i=1;i<=T;i++){
		int x=read();
		if(x<=20)sub1::mian(x);
		else sub2::mian(x);
	}
	fclose(stdin);fclose(stdout);return 0;
} 
