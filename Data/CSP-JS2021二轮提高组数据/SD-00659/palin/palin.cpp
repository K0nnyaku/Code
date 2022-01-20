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
#define N 1020050
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

int zhi[N],n,a[N],dy[N],ps[N],mxx1[N],mnn1[N],mxx2[N],mnn2[N];
bool ok[N],oa11[N],oa12[N],oa21[N],oa22[N]; int csx[N],lxl[N],lxr[N];
char s[N]; int b[N];
char mb[N];

struct que{
	int nl,nr;
	int la,ra;
	
	que(){} que(int nl_,int nr_,int la_,int ra_){
		nl=nl_,nr=nr_,la=la_,ra=ra_;
	}
	inline bool operator<(const que&qc) const{
		return (nl!=qc.nl)?(nl>qc.nl):(nr<qc.nr);
	}
	inline bool operator==(const que&qq) const{
		return nl==qq.nl&&nr==qq.nr;
	}
}qwq[N<<1],qaq[N<<1];

inline bool cmp(const que&x,const que&y){ //就狂搞
	return x.la>y.la;
}

inline void DD(int t,bool *oa1,bool *oa2){
	//左边： <=t ↓ >t ↑
	//右边： <=t ↑ >t ↓
	oa1[0]=oa2[n+n+1]=1;
	R int qzm,okk;
	qzm=n+n+1,okk=1;
	for(R int i=1;i<=n+n;++i){
		if(dy[i]<=t) okk&=(dy[i]<qzm),qzm=std::min(qzm,dy[i]); oa1[i]=okk;
	}
	qzm=0,okk=1;
	for(R int i=1;i<=n+n;++i){
		if(dy[i]>t) okk&=(dy[i]>qzm),qzm=std::max(qzm,dy[i]); oa1[i]&=okk;
	}
	qzm=n+n+1,okk=1;
	for(R int i=n+n;i>=1;--i){
		if(dy[i]<=t) okk&=(dy[i]<qzm),qzm=std::min(qzm,dy[i]); oa2[i]=okk;
	}
	qzm=0,okk=1;
	for(R int i=n+n;i>=1;--i){
		if(dy[i]>t) okk&=(dy[i]>qzm),qzm=std::max(qzm,dy[i]); oa2[i]&=okk;
	}
}

inline void shua(){
	for(R int i=1;i<n+n;++i){
		if(s[i]>mb[i]) return;
		if(s[i]<mb[i]){
//			std::cerr<<"CG\n";
			for(R int j=1;j<n+n;++j) mb[j]=s[j];
			return;
		}
	} return;
}

inline void gztl(int lt,int rt){
	if(lt==1) return;
	R int la=dy[1],ra=dy[1],bz=1; s[1]='L';
	R int nl=2,nr=n+n;
	while(nl<lt||nr>rt){
		R int isl=(dy[nl]==ra+1||dy[nl]==la-1),isr=(dy[nr]==ra+1||dy[nr]==la-1);
		if(nl<lt&&isl){
			s[++bz]='L';
			if(dy[nl]==ra+1) s[n+n-bz+1]='R',++ra;
			else if(dy[nl]==la-1) s[n+n-bz+1]='L',--la;
			++nl;
		}
		else if(nr>rt&&isr){
			s[++bz]='R';
			if(dy[nr]==la-1) s[n+n-bz+1]='L',--la;
			else if(dy[nr]==ra+1) s[n+n-bz+1]='R',++ra;
			--nr;
		} else return;
	} shua();
}

inline void gztr(int lt,int rt){
	if(rt==n+n||mb[1]=='L') return;
	R int la=dy[n+n],ra=dy[n+n],bz=1; s[1]='R';
	R int nl=1,nr=n+n-1;
	while(nl<lt||nr>rt){
		R int isl=(dy[nl]==ra+1||dy[nl]==la-1),isr=(dy[nr]==ra+1||dy[nr]==la-1);
		if(nl<lt&&isl){
			s[++bz]='L';
			if(dy[nl]==ra+1) s[n+n-bz+1]='R',++ra;
			else if(dy[nl]==la-1) s[n+n-bz+1]='L',--la;
			++nl;
		}
		else if(nr>rt&&isr){
			s[++bz]='R';
			if(dy[nr]==la-1) s[n+n-bz+1]='L',--la;
			else if(dy[nr]==ra+1) s[n+n-bz+1]='R',++ra;
			--nr;
		} else return;
	} shua();
}

inline bool spj(){
	R int la=1,ra=n+n;
	for(R int i=1;i<=n+n;++i){
		if(mb[i]=='L') b[i]=a[la++];
		else b[i]=a[ra--];
		if(la>n+n+1||ra<0) return 0;
	}
	for(R int i=1;i<=n+n;++i) if(b[i]!=b[n+n-i+1]) return 0;
	return 1;
}

inline void rst(){ //球球了，多放过去几个吧/ll/ll/ll
	n=Rd();
	for(R int i=0;i<=n+n+1;++i){
		zhi[i]=dy[i]=ps[i]=0,csx[i]=0;
		ok[i]=oa11[i]=oa12[i]=oa21[i]=oa22[i]=0;
		mxx1[i]=0,mnn1[i]=1000000000;
		mxx2[i]=0,mnn2[i]=1000000000;lxl[i]=lxr[i]=0;
		mb[i]='Z';
	}
	for(R int i=1;i<=n+n;++i) a[i]=Rd();
//	for(R int i=1;i<=n+n;++i) a[i]=(i-1)%n+1;
//	std::random_shuffle(a+1,a+n+n+1);
	for(R int i=1;i<=n+n;++i){
		if(ps[a[i]]) dy[i]=ps[a[i]];
		else ps[a[i]]=i;
	}
	for(R int i=0;i<=n+n+1;++i) ps[i]=0;
	for(R int i=n+n;i>=1;--i){
		if(ps[a[i]]) dy[i]=ps[a[i]];
		else ps[a[i]]=i;
	}
	R int wq=0;
	for(R int i=1;i<=n;++i) wq+=(!csx[a[i]]),++csx[a[i]];
	ok[n]=(wq==n);
	for(R int i=n+1;i<=n+n;++i){
		wq-=(csx[a[i-n]]==1); --csx[a[i-n]]; wq+=(!csx[a[i]]); ++csx[a[i]];
		ok[i]=(wq==n);
	}
	R int okk=0;
	for(R int i=1;i<=n+n;++i) okk+=ok[i];
	if(!okk){
		printf("-1\n");
		return;
	}
//	printf("!!%d\n",okk);
	for(R int i=1;i<=n+n;++i) mxx1[i]=std::max(mxx1[i-1],dy[i]),mnn1[i]=std::min(mnn1[i-1],dy[i]);
	for(R int i=n+n;i>=1;--i) mxx2[i]=std::max(mxx2[i+1],dy[i]),mnn2[i]=std::min(mnn2[i+1],dy[i]);
	DD(dy[1],oa11,oa12);
	DD(dy[n+n],oa21,oa22);
	for(R int i=1;i<=n+n;++i) lxl[i]=std::max(lxl[i-1],(mxx1[i]-mnn1[i]==i-1)?(i):(0));
	for(R int i=n+n;i>=1;--i) lxr[i]=std::max(lxr[i+1],(mxx2[i]-mnn2[i]==n+n-i)?(n+n-i+1):(0));
	R int top=0,tc=0;
	for(R int i=n;i<=n+n;++i){ //排斥掉一些不可能的解
		if(oa11[i-n]&&oa12[i+1]&&ok[i]){
			qwq[++top]=que(lxl[i-n],0,i-n+1,i);
		}
	}
	for(R int i=n;i<=n+n;++i){
		if(oa21[i-n]&&oa22[i+1]&&ok[i]){
			qwq[++top]=que(0,lxr[i-n],i-n+1,i);
		}
	}
	que hq=qwq[1];
	for(R int i=1;i<=top;++i) if(qwq[i]<hq) hq=qwq[i];
	for(R int i=1;i<=top;++i) if(qwq[i]==hq) qaq[++tc]=qwq[i];
	//剪枝：如果撑不住最大的l，那么必然不为最优解
	if(!top){
		printf("-1\n");
		return;
	}
//	gztl(qaq[1].la,qaq[1].ra);
	std::sort(qaq+1,qaq+tc+1,cmp);
	R int SJ=0;
	if(n>1000) SJ=std::min(180,tc); else SJ=tc;
//	if(tc<150) for(R int i=tc+1;i<=150;++i) qaq[i]=qaq[tc];
//	printf("!%d %d %d %d\n",tc,qaq[3].nl,qaq[3].la,qaq[3].ra);
	for(R int i=1;i<=SJ;++i)
		gztl(qaq[i].la,qaq[i].ra);
	for(R int i=1;i<=SJ;++i)
		gztr(qaq[i].la,qaq[i].ra);
//	for(R int i=n;i<=n+n;++i) if(ok[i]) gztl(i-n+1,i),gztr(i-n+1,i);
	if(mb[1]=='Z'){
		printf("-1\n"); return;
	}
//	std::cerr<<tc<<"!!!\n";
	mb[n+n]='L';
	for(R int i=1;i<=n+n;++i) putchar(mb[i]); putchar('\n');
//	std::cerr<<spj()<<'\n';
}

int main(){
//	srand(time(0));
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	R int T=Rd();
	while(T--) rst();
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
