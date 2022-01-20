#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x*f;
}

const int N=1e6;
int t,n,dat[N];
int b[N],ab[N];//ab->answer_b;
char opr[N],ao[N];//ao->answer_opr;
int h1,t1;
int t2;
bool flg=false;

bool check()//判断能不能修改答案;
{
	int l=n>>1,r=l+1;
	while(l>=1&&r<=n)//是不是回文串;
	{
		if(b[l]!=b[r]){return false;}
		l--;r++;
	}
	if(ab[1]==0)//第一次遇到回文串;
	{
		return true;
	}
	bool temp=false;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>ab[i]) break;
		else if(b[i]<ab[i])
		{
			temp=true;
			break;
		}
	}
	if(!temp){return false;}
	return true;
}

void cpy()
{
	for(int i=1;i<=n;i++)
	{
		ab[i]=b[i];
		ao[i]=opr[i];
	}
}

void work(int len)//现在a数组的长度;
{
	if(len==0)
	{
		//for(int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
		if(check())
		{
			flg=true;cpy();
		}
		return;
	}
	b[t2]=dat[h1++];
	opr[t2++]='L';
	work(len-1);
	t2--;h1--;
	b[t2]=dat[t1--];
	opr[t2++]='R';
	work(len-1);
	t2--;t1++;
}

void init()
{
	memset(ab,0,sizeof ab);
	flg=false;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		init();
		n=read();
		n<<=1;
		h1=1;t1=n;//分别指向队首元素和队尾元素;
		t2=1;//指向队尾的后一个元素;
		for(int i=1;i<=n;i++) dat[i]=read();
		work(n);
		if(!flg) printf("-1\n");
		else cout<<ao+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
2 
5 
4 1 2 4 5 3 1 2 3 5 
3 
3 2 1 2 1 3

*/
