#include<bits/stdc++.h>
using namespace std;
namespace _zzd{
	const int maxn=1e5+10;
	int n,k,T,a[maxn],b[maxn];
	string ans;
	bool check(){
		for(int i=1;i<=2*n;i++)
		if(b[i]==b[2*n-i+1]) continue;
		else return false;
		return true;
	}
void dfs(int step,string s,int l,int r){
//	cout<<s<<endl;
   //  if(ans!="")if(s[step-2]>ans[step-2]) return;
	if(step==2*n+1) {if(check()){
		if(ans>s||ans=="") ans=s;
	}return;
	}
	b[step]=a[l],dfs(step+1,s+"L",l+1,r);
		b[step]=a[r],dfs(step+1,s+"R",l,r-1);
}

	void mymain(){
		scanf("%d",&T);
	
		ans="";
	while(T--){
		scanf("%d",&n);	
		if(n>=1000){
			printf("-1\n");
			return;
		}
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		dfs(1,"",1,2*n);
		if(ans=="") printf("-1\n");
		else cout<<ans<<endl;
		ans="";
	}
			return;
		}
}

int main(){	

    freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
 //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<1;
_zzd::mymain();
	//fclose(stdin);
    //fclose(stdout);

	return 0;
}

