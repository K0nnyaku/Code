#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
const int mod = 1e9+7;
string s,w;int n,k,a[maxn],b[maxn],flag[maxn];
int stank[maxn],top,wait[maxn],lst[maxn];
long long ans=0;
int check(){
	int cnt=0,head=0;
	for(int i=1;i<=n;i++)
		b[i]=0,flag[i]=0;
	for(int i=1;i<=n;){
		stank[i]=0,top=0;
		if(a[i]==1)b[++head]=-1,i++,cnt=0;
		if(a[i]==2)b[++head]=-2,i++,cnt=0;
		if(a[i]==3){
			cnt++;
			while(a[i+1]==3){
				i++;cnt++;
			}
			if(cnt>k){
				return 0;
			}
			else b[++head]=cnt,i++;
		}
	}
	
	int num=0;cnt=0;int tmp=0;
	for(int i=1;i<=n;i++)lst[i]=0,wait[i]=0;
	
	
	for(int i=1;i<=head;i++){
		if(b[i]==-1){
			stank[++top]=-1;
			lst[++num]=top;
		}
		else if(b[i]==-2){
			if(!top||!num){
				return 0;
			}
			if(top){
				if(!num){
					return 0;
				}
				if(flag[lst[num]]%2&&flag[lst[num]]!=1){
					return 0;
				}
				top=lst[num]-1;
				num--; 
				if(stank[top]>0)
					top--,flag[lst[num]]++;
			}
		}
		else if(b[i]){
			if(stank[top]>0){
				return 0;
			}
			stank[++top]=b[i];
			wait[top]=i;
			flag[lst[num]]++;
		}
	}
	
	if(top){
		for(int i=1;i<=top;i++)
			if(stank[i]==-1||stank[i]==-2)return 0;
		if(top==1&&stank[top]>0)return 0;
		
		for(int i=1;i<=top;i++){
			int kk=wait[i];
			if((b[kk-1]!=-1||b[kk+1]!=-2)||(kk==head)||kk==1){
				return 0;
		}
		return 1;
	}}
	if(!top){
		return 1;
	}
	
}
void dfs(int x){
	if(x==n+1){
		ans=(ans+check())%mod;
//		for(int i=1;i<=n;i++)
//			printf("%d ",a[i]);
//		puts("");
//		printf("ans_pre = %d ans = %d Is = %d \n",ans,ans+check(),check());
//		ans+=check();
		return ;
	}
	if(a[x]==0)
	for(int i=1;i<=3;i++){
		a[x]=i;
		dfs(x+1);
		a[x]=0;
	}
	else dfs(x+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
		scanf("%d%d",&n,&k);
		cin>>s;
		for(int i=0;i<n;i++)
			if(s[i]=='(')a[i+1]=1;
			else if(s[i]==')')a[i+1]=2;
			else if(s[i]=='*')a[i+1]=3;	
	dfs(1);
	printf("%d\n",ans);
	
	return 0;
}
