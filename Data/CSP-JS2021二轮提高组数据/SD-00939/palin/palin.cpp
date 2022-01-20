#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::string;

const int N=1098244;

int d[N],le[N],ri[N],stk[N],top,n;
string bsss;
bool check(int l,int r){
	if(l<1||r>n) return 0;
	top=0;
//	cerr<<"check: "<<l<<" "<<r<<"\n";
	for(int i=l;i<=r;i++) stk[++top]=d[i];
	std::sort(stk+1,stk+top+1);
	for(int i=1;i<=top;i++){
		if(stk[i]^i) return 0;
	}
	return 1;
}
int hs[N],ts[N],htop,ttop;
string rev(string a){
	string b="";
	for(int i=a.length()-1;~i;i--) b+=a[i];
	return b;
}
string hehe(int fl,int fr,int sl,int sr,int tl,int tr,string midd){
//	cerr<<"hehe: "<<fl<<" "<<fr<<" "<<sl<<" "<<sr<<" "<<tl<<" "<<tr<<" "<<midd<<"\n";
	string TAT=bsss;
	htop=ttop=0;
	for(int i=fr;i>=fl;i--) hs[++htop]=d[i];
	for(int i=tl;i<=tr;i++) ts[++ttop]=d[i];
	if(fr>=fl){
		int st=d[1];htop--;
		string strl="",strr="";
		for(int qwq=sl;qwq<=sr;qwq++){
			if(d[qwq]==st){
//				cerr<<"qwq: "<<qwq<<" "<<st<<"\n";
				for(int le=qwq-1,ri=qwq+1,i=2;i<(n>>1);i++){
//					cerr<<"\t"<<le<<" "<<ri<<" "<<hs[htop]<<" "<<ts[ttop]<<"\n";
					if(htop&&le>=sl&&hs[htop]==d[le]) strl+="L",strr+="L",le--,htop--;
					else if(htop&&ri<=sr&&hs[htop]==d[ri]) strl+="L",strr+="R",ri++,htop--;
					else if(ttop&&le>=sl&&ts[ttop]==d[le]) strl+="R",strr+="L",le--,ttop--;
					else if(ttop&&ri<=sr&&ts[ttop]==d[ri]) strl+="R",strr+="R",ri++,ttop--;
					else goto ed1;
				}
				break;
			}
		}
//		cerr<<strl<<" -ans- "<<strr<<"\n";
		TAT=std::min(TAT,"L"+strl+midd+rev(strr)+"L");
		ed1:;
	}
	htop=ttop=0;
	for(int i=fr;i>=fl;i--) hs[++htop]=d[i];
	for(int i=tl;i<=tr;i++) ts[++ttop]=d[i];
	if(tl<=tr){
		int st=d[n];ttop--;
		string strl="",strr="";
		for(int qwq=sl;qwq<=sr;qwq++){
			if(d[qwq]==st){
				for(int le=qwq-1,ri=qwq+1,i=2;i<(n>>1);i++){
					if(htop&&le>=sl&&hs[htop]==d[le]) strl+="L",strr+="L",le--,htop--;
					else if(htop&&ri<=sr&&hs[htop]==d[ri]) strl+="L",strr+="R",ri++,htop--;
					else if(ttop&&le>=sl&&ts[ttop]==d[le]) strl+="R",strr+="L",le--,ttop--;
					else if(ttop&&ri<=sr&&ts[ttop]==d[ri]) strl+="R",strr+="R",ri++,ttop--;
					else goto ed2;
				}
				break;
			}
		}
		TAT=std::min(TAT,"R"+strl+midd+rev(strr)+"L");
		ed2:;
	}
	return TAT;
}
void solve(){
	string ans="";bsss="";
	for(int i=1;i<=n;i++) bsss+="S",le[i]=ri[i]=0;
	ans=bsss;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(le[d[i]]) ri[d[i]]=i;
		else if(le[d[i]]==0) le[d[i]]=i;
	}
	for(int i=1;i<n;i++){
//		cerr<<i<<" --- "<<d[i]<<" "<<d[i+1]<<"\n";
		if(d[i]==d[i+1]){
			if(check(i+1,i+(n>>1))) ans=std::min(ans,hehe(1,i-1,i+2,i+(n>>1),i+(n>>1)+1,n,"LL"));
			if(check(i-(n>>1)+1,i)) ans=std::min(ans,hehe(1,i-(n>>1),i-(n>>1)+1,i-1,i+2,n,"RR"));
		}
	}
	for(int i=1;i<=(n>>1);i++){
//		cerr<<i<<" "<<le[i]<<" "<<ri[i]<<"\n";
		if(ri[i]-le[i]==(n>>1)){
			if(check(le[i],ri[i]-1)) ans=std::min(ans,hehe(1,le[i]-1,le[i]+1,ri[i]-1,ri[i]+1,n,"LR"));
		}
	}
	if(ans==bsss) cout<<"-1\n";
	else cout<<ans<<"\n";
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	std::ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;n<<=1;
		solve();
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3

*/
