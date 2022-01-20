#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int NR=5e5;
int T,n,len,a[NR*2],pos1[NR],pos2[NR],last[NR*2]; 
int ans[NR*2],ch[NR*2];
bool flag;
void shuzu()
{
	int lt=1,rt=len;
	for(int i=1;i<=len;i++)
	{
		if(ans[i]==0){
			ch[i]=a[lt];
			lt++;
		} 
		if(ans[i]==1){
			ch[i]=a[rt];
			rt--;
		}
	}
}
bool check()
{
	for(int i=1;i<=n;i++) if(ch[i]!=ch[len-i+1]) return false;
	return true;
}
void dfs(int step)
{
	if(step==len+1)
	{
		shuzu();
		if(check()!=true) return;
		
		if(flag!=true)
		{
			for(int i=1;i<=len;i++)
			{
				if(ans[i]==0) cout<<"L";
				if(ans[i]==1) cout<<"R";
			} 
		}
		flag=true;
		return;
	}
	for(int i=0;i<=1;i++)
	{
		ans[step]=i;
		dfs(step+1);
		ans[step]=-1;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	//提示：删除相等的数 
	cin>>T;
	while(T)
	{
		cin>>n;
		len=2*n;
		flag=false;
		memset(ans,-1,sizeof(ans));
		for(int i=1;i<=len;i++)
		{
			cin>>a[i];
		} 
		if(len>=44)
		{
			for(int i=1;i<=2*n;i++) cout<<"L";
			continue;
		}
		dfs(1);
		if(flag==false) cout<<"-1";
		cout<<endl;
		T--;
	}
	return 0;
}
