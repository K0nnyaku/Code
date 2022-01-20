#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int re()
{
	int s=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=s*10+ch-48,ch=getchar();
	return s*f;
}
void wr(int s)
{
	if(s<0)s=-s,putchar('-');
	if(s>9)wr(s/10);
	putchar(s%10+48);
}
const int inf=200+7;
int QWQ,n;
int a[inf],head,tail;
int ls_[inf],ans_[inf],_ans[inf];
char caozuo[inf],ans__[inf];
stack<int>h;
void init()
{
	head=1;tail=n*2;
	memset(a,0,sizeof(a));
	memset(ls_,0,sizeof(ls_));
	memset(ans_,0,sizeof(ans_));
	memset(ans__,0,sizeof(ans__));
	while(h.size())h.pop();
	for(int i=1;i<=2*n;i++)
		_ans[i]=0x7f7f7f7f;
}
void pd()
{
	int cnt=0;
	while(h.size())
		ls_[++cnt]=h.top(),h.pop();
	for(int i=cnt;i>0;i--)
		h.push(ls_[i]);
	for(int i=1;i<=n*2;i++)
		if(ls_[i]!=ls_[2*n+1-i])return;
	for(int i=1;i<=n*2;i++)
		ans_[i]=ls_[i];
	for(int i=2*n;i>0;i--)
	{
		if(ans_[i]>_ans[i])break;
		if(ans_[i]<_ans[i])
		{
			for(int j=1;j<=n*2;j++)
			{
				_ans[j]=ans_[j];
				ans__[j]=caozuo[j];
			}
			break;
		}
	}
}
void dfs(int now)
{
	if(now==2*n+1)
	{
		pd();
		return;
	}
	caozuo[now]='L';
	h.push(a[head]);
	head++;
	dfs(now+1);
	head--;h.pop();
	caozuo[now]='R';
	h.push(a[tail]);
	tail--;
	dfs(now+1);
	tail++;h.pop();
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	QWQ=re();
	while(QWQ--)
	{
		n=re();init();
		for(int i=1;i<=2*n;i++)a[i]=re();
		dfs(1);
		if(_ans[1]==2139062143)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n*2;i++)
			printf("%c",ans__[i]);
		puts("");
	}
	return 0;
}
