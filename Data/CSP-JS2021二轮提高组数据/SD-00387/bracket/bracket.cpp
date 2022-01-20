#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 510;

int n,k,ans;
char a[510],bkt[3] = {'(',')','*'};

//int read();
void dfs(int num);
bool check(int l,int r);

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i ++)
	{
		a[i] = getchar();
	}
	dfs(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void dfs(int num)
{
	if(num > n)
	{
		if(check(1,n))
		{
			ans ++;
		}
	}
	
	if(a[num] == '?')
	{
		for(int i = 0;i < 3;i ++)
		{
			a[num] = bkt[i];
			dfs(num+1);
		}
		a[num] = '?';
	}
	else
	{
		dfs(num+1);
	}
}

bool check(int l,int r)
{
	int stuck[N],top = 0,num = 0;
	bool sf1 = false,sf2 = false;
	for(int i = l;i <= r;i ++)
	{
		switch(a[i])
		{
			case '*':
			{
//				if(a[i-1] == ')' && sf1)sf2 = true;
				if(a[i-1] == '(' )sf1 = true;
				num ++;
				if(num > k)return false;//more
				stuck[++top] = i;
				break;
			}
			case '(':
			{
//				if(a[i-1] == '*')sf1 = true;
//				sf2 = false;
				num = 0;
				stuck[++top] = i;
				break;
			}
			case ')':
			{
				num = 0;
				while(a[stuck[top]] != '(')top --;
				if(!check(top,i))return false;
				if(sf2)return false;
				if(a[top-1] == '*' && a[i+1] == '*' && sf1)sf2 = true;
				else sf1 = false;
				top --;
				if(top < 0)return false;//no
				break;
			}
		}
	}
}

int read()
{
	int f = 1,num = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c <= '9' && c >= '0')
	{
		num = num*10+c-'0';
		c = getchar();
	}
	return num*f;
}
