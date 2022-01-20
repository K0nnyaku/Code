#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MOD=1000000007;

int n,k,cou;
string s;
int q[505],l,checkx[505],len;
int ansplus;

inline int read()
{
	int ans=0,res=1;
	char ch=getchar();
	while ((ch>'9'||ch<'0')&&ch!='-')
		ch=getchar();
	if (ch=='-')
	{
		res=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*res;
}

inline void print(int x)
{
	if (x==0)
	{
		putchar('0');
		putchar('\n');
		return;
	}
	if (x<0)
		putchar('-');
	int tmp=x>0 ? x:-x;
	char F[200];
	int cou=0;
	while (tmp)
	{
		F[cou++]=tmp%10+'0';
		tmp/=10;
	}
	while (cou)
		putchar(F[--cou]);
	putchar('\n');
	return;
}

void dfs(int x)
{
	if (cou>k)
		return;
	if (l<0)
		return;
	if (x==s.size()-1)
	{
		if (l==1)
		{
			ansplus++;
			//cout << s << endl;
			if (ansplus>MOD)
				ansplus-=MOD;
		}
		return;
	}
	int tmp=cou,temp=q[l];
	switch (s[x])
	{
		case '(':
			l++;
			q[l]=x;
			cou=0;
			dfs(x+1);
			l--;
			cou=tmp;
			break;
		case ')':
			l--;
			cou=0;
			checkx[x]=temp;
			dfs(x+1);
			l++;
			q[l]=temp;
			checkx[x]=0;
			cou=tmp;
			break;
		case '*':
			cou++;
			dfs(x+1);
			cou--;
			break;
		case '?':
			if (len>l)
			{
				len--;
				s[x]='(';
				l++;
				q[l]=x;
				cou=0;
				dfs(x+1);
				l--;
				cou=tmp;
				len++;
			}
			if (s[x-1]==')'&&s[checkx[x-1]]-1=='*')
				break;
			if (s[q[l]-1]!='*'||s[x+1]!='*')
			{
				len--;
				s[x]=')';
				l--;
				cou=0;
				checkx[x]=temp;
				dfs(x+1);
				l++;
				checkx[x]=0;
				q[l]=temp;
				cou=tmp;
				len++;
			}
			len--;
			s[x]='*';
			cou=tmp+1;
			dfs(x+1);
			cou=tmp;
			s[x]='?';
			len++;
			break;
	}
	return;
}

inline void init()
{
	n=read();
	k=read();
	cin >> s;
	if ((s[0]!='('&&s[0]!='?')||(s[s.size()-1]!='?'&&s[s.size()-1]!=')'))
	{
		print(0);
		return;
	}
	for (int i=0;i<s.size();i++)
		if (s[i]=='?')
			len++;
	if (s[0]=='?')
		len--;
	if (s[s.size()-1]=='?')
		len--;
	s[0]='(';
	s[s.size()-1]=')';
	dfs(0);
	print(ansplus);
	return;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
