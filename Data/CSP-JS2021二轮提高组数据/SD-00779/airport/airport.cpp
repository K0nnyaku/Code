#include<iostream>
#include<cstdio>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define ls(k) k<<1
#define rs(k) k<<1|1
#define mid() (L+R)>>1
using namespace std;
inline int rn(){
	char c=getchar();
	int ans=0,d=1;
	while(c<'0'||c>'9'){
		if(c=='-') d=-d;
		c = getchar();
	}while(c>='0'&&c<='9'){
		ans = ans*10+(c^48);
		c = getchar();
	}return ans*d;
}
void out(int n){
	if(n<0){
		putchar('-');
		n = -n;
	}
	if(!n){
		putchar('0');
		return;
	}
	char f[100];
	int top=0;
	while(n){
		f[++top] = n%10 + '0';
		n/=10;
	}while(top){
		putchar(f[top--]);
	}
	return;
}
const int N= 1e5+1,inf = 0x3f3f3f3f;
int n, m1, m2;
struct air{
	int b,e;
}a[N],b[N];
int mn = -inf;
bool cmp(const air& a,const air& b){
	return a.b<b.b;
}
struct Tree{
	int L,R,mn,mx;
	Tree(){
		mn = inf;
		mx = -inf;
	}
}tr[2][N<<2];
int last[2],num[2][N];
void build(int L,int R,int k,bool f){
	tr[f][k].L = L,tr[f][k].R = R;
	if(L==R){
		/*if(f) tr[k].mn = a[L];
		else tr[k].mn = b[L];*/
		return;
	}
	int mid = mid();
	build(L,mid,ls(k),f),build(mid+1,R,rs(k),f);
	//tr[k].mn = min(tr[ls(k)].mn,tr[rs(k)].mn);
	return;
}
int quary(int L,int R,bool f,int k=1){
	int r = tr[f][k].R,l=tr[f][k].L;
	if(l>R||r<L) return inf;
	if(L<=l&&R>=r){
		return tr[f][k].mn;
	}
	int mid = (r+l)>>1;
	int mn = inf;
	if(mid>=L) mn = min(mn,quary(L,R,f,ls(k)));
	if(mid<R) mn = min(mn,quary(L,R,f,rs(k)));
	return mn;
}
void add(int& id,int& m,bool f,int k=1){
	int L = tr[f][k].L,R = tr[f][k].R;
	if(L>id||R<id) return;
	if(L==R&&L==id){
		tr[f][k].mn = m;
		num[f][L]++;
		tr[f][k].mx = num[f][L];
		
		return;
	}
	int mid = mid();
	if(mid>=id) add(id,m,f,ls(k));
	if(mid<id) add(id,m,f,rs(k));
	tr[f][k].mn = min(tr[f][rs(k)].mn,tr[f][ls(k)].mn);
	tr[f][k].mx = max(tr[f][rs(k)].mx,tr[f][ls(k)].mx);
	return;
}
void up(int& t,int& m,bool f,int k=1){
	if(tr[f][k].L==tr[f][k].R){
		tr[f][k].mn = m;
		num[f][tr[f][k].L]++;
		//cout<<"Ê÷ "<<num[f][tr[f][k].L]<<endl;
		tr[f][k].mx = max(tr[f][k].mx,num[f][tr[f][k].L]);
		return;
	}
	int r = tr[f][rs(k)].mn,l=tr[f][ls(k)].mn;
	if(r<t){
		if(l<t){
			if(tr[f][ls(k)].mx>tr[f][rs(k)].mx) up(t,m,f,ls(k));
			else up(t,m,f,rs(k));	
		}
		else up(t,m,f,rs(k));
	}
	else up(t,m,f,ls(k));
	/*if(l==tr[f][k].mn) up(t,m,f,ls(k));
	else up(t,m,f,rs(k));*/
	tr[f][k].mn = min(tr[f][ls(k)].mn,tr[f][rs(k)].mn);
    tr[f][k].mx = max(tr[f][rs(k)].mx,tr[f][ls(k)].mx);
	return;
}
bool cmp1(const int& a,const int& b){
	return a>b;
}
void work(){
	build(1,m1,1,0);
	add(++last[0],a[1].e,0);
	for(int i=2;i<=m1;i++){
		//cout<<i<<" "<<quary(1,m1,0)<<endl;
		if(quary(1,m1,0)>a[i].b)
		add(++last[0],a[i].e,0);
		else up(a[i].b,a[i].e,0);
	}
	//sort(num[0]+1,num[0]+last[0]+1,cmp1);
	for(int i=1;i<=n;i++)
	num[0][i]+=num[0][i-1];
	//cout<<last[0]<<" "<<quary(1,m1,0)<<endl;
	//cout<<num[0][1]<<" "<<num[0][2]<<endl<<endl;
	
	build(1,m1,1,1);
	add(++last[1],b[1].e,1);
	for(int i=2;i<=m2;i++){
		//cout<<i<<" "<<quary(1,m1,0)<<endl;
		if(quary(1,m2,1)>b[i].b)
		add(++last[1],b[i].e,1);
		else up(b[i].b,b[i].e,1);
	}
	//sort(num[1]+1,num[1]+last[1]+1,cmp1);
	for(int i=1;i<=n;i++)
	num[1][i]+=num[1][i-1];
	//cout<<last[0]<<" "<<last[1]<<endl;
	//cout<<num[1][1]<<" "<<num[1][2]<<endl;
	//int sum = 1,l=0,r=n,rn=last[1]+last[0];
	int ans = -inf;
	for(int i=0;i<=n;i++){
		ans = max(ans,num[0][i]+num[1][n-i]);
	}
	/*while(sum<=n&&i+j<=rn){
		if(num[0][i]<num[1][j]) {
		ans+=num[1][j++];
		cout<<"ans+ i "<<num[1][j-1]<<endl;
		}
		else {
		ans+=num[0][i++];
		cout<<"ans+ j "<<num[0][i-1]<<endl;
		}
		sum++;
		//cout<<"sum+ "<<sum<<endl;
	}*/
	cout<<ans;
	return;
}
int main()
{
    freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=rn(),m1=rn(),m2=rn();
	for(int i=1;i<=m1;i++){
		a[i] = (air){rn(),rn()};
	}for(int i=1;i<=m2;i++){
		b[i] = (air){rn(),rn()};
	}
	/*int l=0,r=n;
	while(l<r){
		int mid = (l+r)>>1;
		if(check(mid)){
			
		}else{
			
		}
	}*/
	sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);
	/*for(int i=1;i<=m1;i++){
		cout<<a[i].b<<" "<<a[i].e<<endl;
	}*/
	work();
	return 0;
}
