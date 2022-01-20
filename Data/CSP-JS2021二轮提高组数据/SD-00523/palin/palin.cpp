#include<iostream>
#include<cstdio>
#include<deque> 
#include<cstring>
using namespace std;
int n,T;
bool flag=0;
deque<int> q1,q2;
char s[100];
int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
bool check()
{
	int ln=q2.size();
	for(int i=1;i<=ln;i++)
	{
		if(q2.front()!=q2.back()) return 0;
		else {cout<<q2.front()<<' '<<q2.back()<<endl;q2.pop_back();q2.pop_front();}
	}
	return 1;
}
void dfs(int ln)
{
	
	if(ln==1) 
	{
		s[ln-1]='L';
		if(check()) {cout<<s<<endl;flag=1;return;}
		else return;
	}
	//if(flag==1) return;
	int b;
	q2.push_back(q1.front());b=q1.front();q1.pop_front();s[--ln]='L';dfs(ln);q2.pop_back();q1.push_front(b);s[ln++]=0;
	q2.push_back(q1.back());b=q1.back();q1.pop_back();s[--ln]='R';dfs(ln);q2.pop_back();q1.push_back(b);s[ln++]=0;
}
int main()
{
    freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		q1.clear();q2.clear();
		n=read();
		for(int i=1;i<=n*2;i++)
		{
			int a;
			cin>>a;
			q1.push_back(a);
		}
		flag=0;
		dfs(n*2);
		if(!flag) cout<<"-1"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}


