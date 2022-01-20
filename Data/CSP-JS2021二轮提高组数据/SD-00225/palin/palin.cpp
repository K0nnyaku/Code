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
	}
	while(chr>='0'&&chr<='9'){
		adri=adri*10+chr-'0';
		chr=getchar();
	}
	adri*=(fuhao*2-1);
	return;
}
int n,to[N],u[N],wz[N],am[N];
bool er[N],ans[N]={1},flag=0;
void dfs(int sd,int l,int r,int ll,int rr){
//	cout<<sd<<' ';
	if(sd==n){
		int asss=n;
		for(int i=n-1;i>=0;i--){
			if(u[ll]==u[am[i]]){
				er[asss++]=0;
				ll++;
			}
			else if(u[rr]==u[am[i]]){
				er[asss++]=1;
				rr--;
			}
		}
		gpt(i,0,2*n)if(er[i]>ans[i])return;
		flag=1;
		gpt(i,0,2*n)ans[i]=er[i];
		return;
		//LRRLLRRRRL
		//FTTFFTTTTF
	}
	{
		int tl=to[l];
		er[sd]=0;
		am[sd]=l;
		if(tl==ll-1&&l+1<=ll-1)dfs(sd+1,l+1,r,ll-1,rr);
		if(tl==rr+1&&l<ll&&rr<r)dfs(sd+1,l+1,r,ll,rr+1);
	}
	{
		int tr=to[r];
		er[sd]=1;
		am[sd]=r;
		if(tr==ll-1&&l<ll&&rr<r)dfs(sd+1,l,r-1,ll-1,rr);
		if(tr==rr+1&&rr+1<=r-1)dfs(sd+1,l,r-1,ll,rr+1);
	}
}
int t;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	in_int(t);
	while(t--){
		in_int(n);
		mems(ans,1);
		mems(wz,-1);
		mems(to,0);
		mems(am,0);
		mems(er,0);
		mems(u,0);
		flag=0;
		gpt(i,0,2*n){
			in_int(u[i]);
			if(wz[u[i]]!=-1){
				to[i]=wz[u[i]];
				to[wz[u[i]]]=i;
			}
			wz[u[i]]=i;
		}
		er[0]=0;
		am[0]=0;
		dfs(1,1,2*n-1,to[0],to[0]);
		er[0]=1;
		am[0]=2*n-1;
		dfs(1,0,2*n-2,to[2*n-1],to[2*n-1]);
		if(!flag){
			cout<<"-1\n";
			continue;
		}
		gpt(i,0,n*2)cout<<(ans[i]?'R':'L');
		cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//02310231
