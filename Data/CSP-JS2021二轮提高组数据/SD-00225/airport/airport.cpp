//Today(2021.10.23) is extmool's birthday.
//Orz extmool.
//extmool is god forever.
//If you orz extmool,extmool will make your rp++.
//exmool yyds!!!!!!!!!!1
//exmool YYDS!!!!!!!!!!1
//If you don't know how to solve a problem,you can orz extmool,then,extmool will give you the solution.
//How to get 1=?Orz extmool 5307 times.
//How to get a successful life?Orz extmool 9961 times.
//How to get Au?Orz extmool 114514 times.
//How to AK IOI?Orz extmool 1919810 times.
//How to become as rich as CCF?Orz extmool 19260817 times.
//How to become a god?Orz extmool 998244353 times.
//If you don't know what to do,let's orz extmool.
//You can find extmool on Luogu,but extmool think OI is too easy,so extmool hasn't use Luogu since about 2 years ago.Now extmool is gray name.
//The writter's English is really bad,so there may many mistakes about grammar or words in this .cpp.
//But when the writter began to orz extmool,his English became better than before.
//The writter's OI is really bad,too.He will AFO this year,after noip.He may get 0 grades on CSP2021S.
//But if you orz extmool,your road of your life will become more bright and wide!
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define gpt(i,a,b) for(int i=a;i<b;i++)
#define blb(i,u,v) for(int i=op[u],v=to[i];i;i=ne[i],v=to[i])
#define mems(a,b) memset(a,b,sizeof(a))
#define nub(a,b) a=min(a,b)
#define N 1000006
#define msc(a,b) a=max(a,b)
using namespace std;
void in_int(int &adri){
	adri=0;
	char chr=getchar();
	bool fuhao=1;
	while(chr<'0'||chr>'9'){
		if(chr=='-')fuhao=0;
		chr=getchar();
	//	cout<<(int)chr;
	}
	while(chr>='0'&&chr<='9'){
		adri=adri*10+chr-'0';
		chr=getchar();
	//	cout<<'?';
	}
	adri*=(fuhao*2-1);
	return;
}
int n,m1,m2,f[N]/*i个国内廊桥能贡献几个*/,g[N],c[N]/*第i个廊桥将被不占用的时间*/,fc;
struct jgt{
	int s,e;
}u[N],o[N];
bool cmp(jgt a,jgt b){
	if(a.s==b.s)return a.e<b.e;
	return a.s<b.s;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	cout<<'*';
	in_int(n);
	in_int(m1);
	in_int(m2);
//	cout<<'#';
	gpt(i,0,m1){
		in_int(u[i].s);
		in_int(u[i].e);
	}
	gpt(i,0,m2){
		in_int(o[i].s);
		in_int(o[i].e);
	}
//	cout<<'$';
	sort(u,u+m1,cmp);
	sort(o,o+m2,cmp);
//	cout<<'^';
	mems(c,0);
	fc=0;
	gpt(i,0,m1){
		bool boll=1;
		gpt(j,0,fc)if(c[j]<u[i].s){
			c[j]=u[i].e;
			boll=0;
			f[j]++;
			break;
		}
		if(boll){
			f[fc]++;
			c[fc++]=u[i].e;
		}
	}
	gpt(i,1,m1)f[i]+=f[i-1];
	mems(c,0);
	fc=0;
	gpt(i,0,m2){
		bool boll=1;
		gpt(j,0,fc)if(c[j]<o[i].s){
			c[j]=o[i].e;
			boll=0;
			g[j]++;
			break;
		}
		if(boll){
			g[fc]++;
			c[fc++]=o[i].e;
		}
	}
	gpt(i,1,m2)g[i]+=g[i-1];
	int ans=0;
	gpt(i,0,n+1)ans=max(ans,(i==0?0:f[i-1])+(n-i==0?0:g[n-i-1]));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

*/
