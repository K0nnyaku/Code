#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
//#include<ctime>
#include<vector>
#include<set>
//#include<cassert>
#define R register
#define N 250050
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

struct seg{
	int qc[N<<2],le[N<<2],dy[N],shf[N],lsh[N],S[N],T[N],n;
	int zai[N],vec[N];
	
	seg(){
		memset(qc,0,sizeof(qc));
		memset(le,0,sizeof(le));
		memset(dy,0,sizeof(dy));
		memset(shf,0,sizeof(shf));
		memset(lsh,0,sizeof(lsh));
		memset(S,0,sizeof(S));
		memset(T,0,sizeof(T));
		memset(zai,0,sizeof(zai));
		memset(vec,0,sizeof(vec));
	}
	
	inline void Rst(int x,int l,int r){
		if(l==r){
			le[x]=1; qc[x]=0; return;
		}
		R int mid=(l+r)>>1,Ls=x<<1,Rs=Ls|1;
		Rst(Ls,l,mid),Rst(Rs,mid+1,r);
		le[x]=le[Ls]+le[Rs]; return;
	}
	
	inline int lyt(int x,int l,int r){
		if(l==r) return l;
		R int mid=(l+r)>>1,Ls=x<<1,Rs=Ls|1;
		if(qc[Ls]!=le[Ls]) return lyt(Ls,l,mid);
		else return lyt(Rs,mid+1,r);
	}
	
	inline void fgg(int x,int l,int r,int ps){
		if(l==r){
			qc[x]=1; return;
		}
		R int mid=(l+r)>>1,Ls=x<<1,Rs=Ls|1;
		if(ps<=mid) fgg(Ls,l,mid,ps); else fgg(Rs,mid+1,r,ps);
		qc[x]=qc[Ls]+qc[Rs];
	}
	
	inline void hyx(int x,int l,int r,int ps){
		if(l==r){
			qc[x]=0; return;
		}
		R int mid=(l+r)>>1,Ls=x<<1,Rs=Ls|1;
		if(ps<=mid) hyx(Ls,l,mid,ps); else hyx(Rs,mid+1,r,ps);
		qc[x]=qc[Ls]+qc[Rs];
	}
	
	inline void runn(){
		R int top=0;
		for(R int i=1;i<=n;++i){
			S[i]=Rd(),T[i]=Rd(),lsh[++top]=S[i],lsh[++top]=T[i];
		}
		std::sort(lsh+1,lsh+top+1);
		top=std::unique(lsh+1,lsh+top+1)-lsh-1;
//		assert(top==(n<<1));
		for(R int i=1;i<=n;++i){
			S[i]=std::lower_bound(lsh+1,lsh+top+1,S[i])-lsh;
			T[i]=std::lower_bound(lsh+1,lsh+top+1,T[i])-lsh;
			vec[S[i]]=i;
			vec[T[i]]=i;
//			printf("! %d %d\n",S[i],T[i]);
		}
		Rst(1,1,n+1);
		for(R int i=1;i<=top;++i){
			R int qd=vec[i];
			if(zai[qd]) zai[qd]=0,hyx(1,1,n+1,dy[qd]);
			else{
				R int pa=lyt(1,1,n+1);
				shf[pa]++,zai[qd]=1,dy[qd]=pa;
				fgg(1,1,n+1,pa);
			}
		}
//		for(R int i=1;i<=n;++i) printf("%d ",dy[i]);
		for(R int i=1;i<N;++i) shf[i]+=shf[i-1];
	}
}T1,T2;

int main(){
//	std::cerr<<sizeof(T1)*2<<'\n';
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	R int n=Rd();
	T1.n=Rd();
	T2.n=Rd();
	T1.runn();
	T2.runn();
	R int ans=0;
	for(R int i=0;i<=n;++i)
		ans=std::max(ans,T1.shf[i]+T2.shf[n-i]);
	std::cout<<ans;
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
