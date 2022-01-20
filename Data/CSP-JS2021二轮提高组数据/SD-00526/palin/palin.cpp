#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int inline read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	} 
	return s*t;
} 
int const N=1e6+10;
int T,n,l,r,a[N];
int vis[N],ab[N];//标记数组,构造序列
int ans[N],s[N],ju; 
int ll[N],rr[N];//记录每个数字出现的左右位置 
void find(int cnt){
	//if(cnt==5) cout<<l<<" "<<r<<endl;
	if(cnt==2*n+1){
		int juu=0;
		for(int i=1;i<=2*n;i++){
			if(s[i]<ans[i]){
				juu=1;break;
			}
			else if(s[i]>ans[i]) break;
		}
		if(juu==1)    
			for(int i=1;i<=2*n;i++)
		    	ans[i]=s[i];
	    ju=1;
	}
	if(ab[cnt]==a[l]){
		s[cnt]=0;l++;
		find(cnt+1);
		l--;
	}
	if(ab[cnt]==a[r]){
		s[cnt]=1;r--;
		find(cnt+1);
		s[cnt]=0,r++;
	}
}
void dfs(int cnt){//生成一个序列,存在ab[]中 
    if(cnt==0){
    	//cout<<cnt<<endl;
    	for(int i=1;i<=n;i++)
    		ab[2*n-i+1]=ab[i];
    	/*if(ab[1]==4&&ab[2]==5){
    		for(int i=1;i<=n*2;i++)
    	        cout<<ab[i];
    	    cout<<endl;
		}*/
    	
		l=1,r=n*2;
        find(1);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue; 
		ab[cnt]=i;vis[i]=1;
		dfs(cnt-1);
		vis[i]=0;	
	}
}
void sol1(){ 
    ju=0;
    for(int i=1;i<=n*2;i++) ans[i]=1,ll[i]=rr[i]=0;
	for(int i=1;i<=n*2;i++){
		a[i]=read();
		if(ll[a[i]]) rr[a[i]]=i;
		else ll[a[i]]=i; 
	}
	for(int i=1;i<=n;i++){
		int t=rr[i]-ll[i];
		if(t==1||t==n){
			ab[n]=ab[n+1]=i;vis[i]=1;
			dfs(n-1);
			vis[i]=0;
		}
	}
	
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		n=read();
		sol1();
		if(ju==1){
			for(int i=1;i<=2*n;i++)
		        if(ans[i]==0) cout<<"L";
		        else cout<<"R";
		}
		else cout<<-1;
		cout<<endl;
	}
	
	return 0;
} 
