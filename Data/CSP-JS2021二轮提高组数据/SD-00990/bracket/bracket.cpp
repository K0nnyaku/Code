#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
long long ans=0,n,k;
char a[510];
bool b[510];



bool build (){
 int dep[510];
	int d=0;
	for (int i=1;i<=n;i++)
	{

		if (a[i]==')') d--;
		dep[i]=d;
		if (a[i]=='(') d++;

	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='*')
		{
			int sum=0;
			for (int j=i-1;j>0;j--)
			{
				if (dep[i]==dep[j]) sum++;
				if (dep[j]<dep[i]||dep[j]>dep[i]) break;
				
			}
			if (sum>2) return 0;
			sum=0;
			for (int j=i+1;j<=n;j++)
			{
				if (dep[i]==dep[j]) sum++;
				if (dep[j]<dep[i]||dep[j]>dep[i]) break;

			}
			if (sum>2) return 0;
		}
	}
	return 1;
}


void check ()
{
	stack <int> stk;
	int len=0;
	for (int c=1;c<=n;c++)
	{
		if (a[c]=='(') stk.push(1);
		if (a[c]==')')
		{
			if (stk.empty()) return ;
			else stk.pop();
		}
		if (a[c]=='*'){
			len++;
			if (len>k) return ;
		}
		else len=0;
	}
	if (stk.empty())
	{
		bool t=build ();
		if (t) ans++;
 }
	if (ans>1000000007) ans-=1000000007;
	return ;
}
void dfs (int c,int len)
{
	
	if (c>n) {
		check ();
		return ;
	}
	if (b[c]==0)
	{
		if (a[c]=='*') dfs(c+1,len+1);
		else dfs(c+1,0);
	}
	else
	{
		a[c]='(';
		dfs(c+1,0);
		a[c]=')';
		dfs(c+1,0);
		if (len<k) {
			a[c]='*';
			dfs(c+1,len+1);
		}
	}
	return ;
}

//bracket
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	char ch[1000];
	cin>>n>>k;
	scanf("%s",&ch);
	for (int i=1;i<=n;i++)
	{
		a[i]=ch[i-1];
		if (a[i]=='?') b[i]=1;
	}
	if (k==1) cout<<0;
	if (a[1]!='*')dfs (1,0);
	else dfs(1,1);
	cout<<ans;
	return 0;
}



//1.��������Ϸ����У����ҷֱ�Ϊ���ͣ�
//2.���SA����AS������������
//3.�������ã�1��������ƥ��  2��������ڸ���* 3��ż���䵱�Ǻ�ʹ��
//4.�������ת��Ϊ�ж���������������*ʹ�����ķ���
//5  ү������   ������ дT3   ƭ�����־���

