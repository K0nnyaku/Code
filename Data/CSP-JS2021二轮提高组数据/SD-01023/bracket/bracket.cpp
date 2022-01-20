#include<bits/stdc++.h>
using namespace std;
namespace _zzd{
	const int maxn=1e5+10;
	int n,k,top,ans,flag;
 char s[maxn],z[maxn];
 map<string ,int> chan;
void dfs(int step,int tot,int zuo,string t){
	if(tot>k) return;
	
	if(step==n+1){if(zuo) return; if(chan[t]) return;
	
ans++,chan[t]=1;//cout<<t<<endl;
return;	}
	if(s[step]=='(') {dfs(step+1,tot,zuo+1,t+"(");return;}
	if(s[step]=='*') {dfs(step+1,tot+1,zuo,t+"*");return;}
	if(s[step]==')') {dfs(step+1,0,zuo-1,t+")");return;}

	if(tot<k&&step!=n) {
		if(flag&&t[step-2]==')')
	flag=0;
	else
	dfs(step+1,tot+1,zuo,t+"*");	
	}
	 if(tot) {dfs(step+1,0,zuo+1,t+"(");
	            flag=1;}
	 if(!tot) dfs(step+1,0,zuo+1,t+"(");
	 if(zuo) dfs(step+1,0,zuo-1,t+")");
}
	void mymain(){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)cin>>s[i];
		dfs(1,0,0,"");
	printf("%d",ans);
			return;
		}
}
int main(){	

    freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
 //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<1;
_zzd::mymain();
	//fclose(stdin);
    //fclose(stdout);

	return 0;
}

