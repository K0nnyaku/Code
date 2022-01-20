#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rop(i,a,b) for(int i=a;i<b;++i) 
namespace webbermys{
	long long n,k,ans;
	int q[1000],cnt;
	char c[1000],a[1000];
	char d[3]={'(',')','*'};
	inline char read(){
		char c=getchar();
		while(c!='('&&c!=')'&&c!='?'&&c!='*')
			c=getchar();
		return c; 
	}
	bool precheck(char *c){
		if(c[1]!='('||c[n]!=')')
			return 0;
		long long cnt1=0,cnt2=0;//cnt1 () cnt2 *
		rep(i,1,n){
			if(cnt1<0)
				return 0;
			if(c[i]=='*')++cnt2;
			else{
				if(cnt2>k)return 0;
				else if(c[i]=='(')++cnt1,cnt2=0;
				else if(c[i]==')')--cnt1,cnt2=0;
			}
		}
		if(cnt1!=0) return 0;
		if(cnt2>k)return 0; 
		return 1;
	} 
	bool check(int l,int r,char *c){
		if(l>r)
			return 1;
		int flagg=1;
		rep(i,l,r)
			if(a[i]!='*')
				flagg=0;
		if(flagg)
			return 1;
		if(l==r)
			return 0; 
		if(c[l]=='*'&&c[r]=='*')
			return 0;
		if(c[l]=='*')
			rep(i,l,r)
				if(c[i]!='*')
					return check(i,r,c);
		int hh=-1,tt=-1,cnt=0,ocnt=0;//AA ºÍASA 
		int flag=-1;
		rep(i,l,r){
			if(c[i]=='(')cnt++;
			if(c[i]==')')cnt--;
			if(cnt!=0&&ocnt==0)hh=i;
			if(cnt==0&&ocnt!=0)tt=i;
			if(hh!=-1&&tt!=-1&&!(hh==l&&tt==r)){
				flag=check(hh,tt,c);
				if(flag==0)return 0;
				hh=-1;
			}
			ocnt=cnt;
		} 
		if(flag==1)return 1;
		if(c[l]=='('&&c[r]==')')
			return check(l+1,r-1,c);
	}
	void dfs(int now){
		if(now>cnt)
			return ans+=(precheck(a)&&check(1,n,a)),void();
			rep(j,0,2){
				if(q[now]==n&&j!=1)continue;
				if(q[now]==1&&j!=0)continue;
				a[q[now]]=d[j];
				dfs(now+1);
			} 
	}
	void Main(){
		freopen("bracket.in","r",stdin);
		freopen("bracket.out","w",stdout);
		scanf("%d%d",&n,&k);
		rep(i,1,n){
			c[i]=read();
			a[i]=c[i];
			if(c[i]=='?')
				q[++cnt]=i;
		}
		dfs(1);
		printf("%lld",ans); 
	}
}
 
int main(){
	webbermys::Main();
	return 0;	
}

//(**)*()
//(**(*))
//(*(**))
//(*)**()
//(*)(**)

//9 3 1
//(*()*()*)
