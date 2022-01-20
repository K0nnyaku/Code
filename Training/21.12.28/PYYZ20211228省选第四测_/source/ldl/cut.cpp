#include<iostream>
#include<cstdio>
#include<bitset>
#include<string>
using namespace std;
const int L=1022;
int n,m,mxL;
int T[L],lst[L],del[L][L],ins[L][2];
string s;
bitset<L> f[L],b[L],val[521];
void insert(bitset<L> x,int tx){
	for(int i=mxL;i>=0;i--){
		if(!x[i])continue;
		if(tx>T[i] || f[i].none())f[i]=x,T[i]=tx;
		x^=f[i];
	}
}
bitset<L> gans;
void printans(){
	gans.reset();
	for(int i=mxL;i>=0;i--)
		if(!gans[i])gans^=f[i];
	s=gans.to_string();
	int x=0;
	while(s[x]=='0' && x<s.size()-1)++x;
	for(;x<s.size();++x)putchar(s[x]); putchar('\n');
}
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	n=read(); m=read();
	for(int x,y,i=1;i<=m;i++){
		x=read(),y=read();
		cin>>s; bitset<L> th(s);
		mxL=max(mxL,(int)s.size());
		b[i]=th; ins[i][0]=x; ins[i][1]=y;
		del[lst[x]][x]=del[lst[y]][y]=i; lst[x]=lst[y]=i;
	}
	for(int i=1;i<=n;i++)
		del[lst[i]][i]=m+1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=mxL;j++)
			if(T[j]<=i)f[j].reset(),T[j]=0;
		val[ins[i][0]]^=b[i];
		val[ins[i][1]]^=b[i];
		insert(val[ins[i][0]],del[i][ins[i][0]]);
		insert(val[ins[i][1]],del[i][ins[i][1]]);
		printans();
	}
	return 0;
}
