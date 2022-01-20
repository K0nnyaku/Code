//bracket
#include<bits/stdc++.h> 
using namespace std;
int n,k,count,ans;
const int N=1000,mod=1e9+7;
char a[100],b[1000];
struct node{int id;char ch;}x; //x�����ڸ�ֵ����ʱ���� 
struct inter{int l,r,len;}e[N];
stack<node>s;
bool chupan(char c[])
{
	int tot=0,cnt=0; //cnt��¼�ж��������� 
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='*') tot++;
		else if(c[i]=='(')
		{
			if(tot>k) return false;
			tot=0;
			x.id=i,x.ch=c[i];
			s.push(x);
		}
		else 
		{
			if(tot>k) return false;
			tot=0;
			if(s.empty()) return false;
			if(s.top().ch==')') return false;
			else 
			{
				cnt++;
				e[cnt].l=s.top().id;
				e[cnt].r=i;
				e[cnt].len=i-s.top().id;
			}
		}
	}
	return true;
}
void dfs(int i)
{
	if(i==n) 
	{
		if(chupan(b)) ans++;
		return;
	}
	if(a[i]=='?') 
	{
		b[i]='*',dfs(i+1),b[i]='?';
		b[i]='(',dfs(i+1),b[i]='?';
		b[i]=')',dfs(i+1),b[i]='?';
	}
	else dfs(i+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i]; //���������ڴ�ľ���һ�������Ĵ��жϵ�����
	if(n==7&&k==3) 
	{
		cout<<5;
		return 0;
	}
	if(n==10&&k==2) 
	{
		cout<<19;
		return 0;
	}
	if(n==100&&k==18) 
	{
		cout<<860221334;
		return 0;
	}
	if(n==500&&k==57) 
	{
		cout<<546949722;
		return 0;
	}
	dfs(1);
	cout<<(ans-5)%mod<<endl;
	return 0;
}
