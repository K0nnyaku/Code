#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=2002021;
int n,L,R; vector<char> ans;
int a[N],lst[N],vis[N],q[N],id[2][N],stk[N];
bool check(int x,int fx){
	ans.clear();
	ans.push_back(fx?'R':'L');
	int xl=x-1,xr=x+1,l=2-fx,r=2*n-fx;
//	cerr<<xl<<" "<<xr<<" "<<l<<" "<<r<<endl;
	for(int i=1;i<n;i++){
		if(l<L && xl>=L && a[l]==a[xl])ans.push_back('L'),--xl,++l;
		else if(l<L && xr<=R && a[l]==a[xr])ans.push_back('L'),++xr,++l;
		else if(r>R && xl>=L && a[r]==a[xl])ans.push_back('R'),--xl,--r;
		else if(r>R && xr<=R && a[r]==a[xr])ans.push_back('R'),++xr,--r;
		else return 0;
	}
	l=L-1; r=R+1; xl=L; xr=R;
	for(int i=ans.size()-1;i>=0;i--){
		if(ans[i]=='L'){
			if(a[xl]==a[l])++xl,ans.push_back('L');
			else --xr,ans.push_back('R'); --l;
		} else{
			if(a[xl]==a[r])++xl,ans.push_back('L');
			else --xr,ans.push_back('R'); ++r;
		}
	}
	return 1;
}
bool check1(){
	int l=1,r=n,top=0;
	for(int i=n+1;i<=2*n;i++){
		if(a[i]==a[l]){++l;stk[++top]=0;}
		else if(a[i]==a[r]){--r;stk[++top]=1;}
		else return false;
	}
	ans.clear();
	for(int i=1;i<=n;i++)ans.push_back('R');
	for(int i=1;i<=n;i++){
		if(!stk[i])ans.push_back('L');
		else ans.push_back('R');
	}
	return true;
}
bool check2(){
	int l=n+1,r=2*n,top=0;
	for(int i=n;i>=1;i--){
		if(a[i]==a[l]){++l;stk[++top]=0;}
		else if(a[i]==a[r]){--r;stk[++top]=1;}
		else return false;
	}
	ans.clear();
	for(int i=1;i<=n;i++)ans.push_back('L');
	for(int i=1;i<=n;i++){
		if(!stk[i])ans.push_back('L');
		else ans.push_back('R');
	}
	return true;
}
void printans(){
	for(int i=0;i<2*n;i++)
		putchar(ans[i]); putchar('\n');
}
bool findlr(){
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=2*n;i++){
		if(!vis[a[i]])vis[a[i]]=i,lst[i]=0;
		else lst[i]=vis[a[i]];
	}
	for(int i=1;i<=2*n;i++)vis[i]=0;
	int l=1,r=0;
	for(int i=2*n;i>n;i--){
		while(l<=r && lst[q[r]]<=lst[i])--r;
		q[++r]=i;
	}
	int fl=0,cnt=0;
	for(L=n+1;L>=1;L--){
		while(l<=r && q[l]>L+n-1)++l;
		if(l<=r && lst[q[l]]<L){
			R=L+n-1;
			if(!cnt || L==1 || R==2*n){
//				if(L!=1 && R!=2*n)cnt=1;
//				cerr<<"L="<<L<<" R="<<R<<endl;
				for(int i=1;i<=2*n;i++){
					if(i<L || i>R)id[0][a[i]]=i;
					else id[1][a[i]]=i;
				}
				if(L==1){
//					cerr<<"in!"<<endl;
					if(check1()){printans(),fl=1;break;}
				}
				if(L>1 && check(id[1][a[1]],0)){printans(),fl=1;break;}
				else if(R<2*n && check(id[1][a[2*n]],1)){printans(),fl=1;break;}
				if(R==2*n){
//					cerr<<"in!"<<endl;
					if(check2()){printans(),fl=1;break;}
				}
			}
		}
		while(l<=r && lst[q[r]]<=lst[L-1])--r;
		q[++r]=L-1;
	}
	if(!fl)return 0;
//	for(int i=1;i<=n;i++)
//		cout<<id[0][i]<<" "<<id[1][i]<<endl;
	return 1;
}
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int aq=read();
	while(aq--){
		n=read();
		for(int i=1;i<=2*n;i++)a[i]=read();
		if(n==1){puts("LL");continue;}
		if(!findlr())puts("-1");
//		cerr<<"L="<<L<<" R="<<R<<endl;
	}
	return 0;
}
/*
1
20
13 18 2 3 19 7 8 15 4 12 13 18 20 17 2 1 5 6 10 14 11 9 16 3 19 16 9 7 11 14 10 6 5 1 17 8 15 20 12 4

*/
