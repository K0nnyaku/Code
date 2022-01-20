#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7;
typedef long long ll;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9')
	{
		sum=(sum<<1)+(sum<<3)+(c^48);
		c=getchar();
	}
	return sum*f;
}
int n,m,T,a[N],path[N],ans=114514000,fuck_[N],left_,right_,cnt;
bool flag;

void updat_(int x)
{
	for(int i=n*2;i>=1;i--)
	{
		path[i]=x%2;
		x>>=1;
	}
}

bool if_true()
{
	for(int i=1;i<=n;i++)
	{
		if(fuck_[i]!=fuck_[n*2-i+1])return false;
	}
	return true;
}



void dfs(int now,int cur)
{
	cnt++;
	if(flag==true)return; 

	if(cnt>=30000000)return;
	if(cur==2*n+1&&if_true())
	{
		flag=true;
		if(now<ans)
		{
			updat_(now);			
			ans=now;
		}
	}
	
	if(cur>=2*n+1)return ;
	
	fuck_[cur]=a[left_++];
	dfs(now<<1,cur+1);//L²Ù×÷
	left_--;
	
	fuck_[cur]=a[right_--];
	dfs((now<<1)+1,cur+1);//R²Ù×÷ 
	right_++;
	fuck_[cur]=0;
}

void print()
{
	for(int i=1;i<=n*2;i++)
	{
		if(path[i]==1)cout<<"R";
		else cout<<"L";
	}
	cout<<endl;
}

int main()
{
    freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		cnt=0;
		flag=false;
    	n=read();
    	right_=n*2;
    	left_=1;
	    for(int i=1;i<=n*2;i++)a[i]=read();
		
		dfs(0,1);
		
		if(flag==1)print();
	
		else cout<<-1<<endl;
	}	
	return 0;
}
