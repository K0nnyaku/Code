#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=510;
int n,k,kuo[N][5],num,many;
string ch;
void f1(string x)//找一级括号
{
	mem(kuo,0);
	int l=x.size(),st=-1;
	for (int i=0;i<l;i++)
	{
		if (x[i]=='(') st=i;
		if (x[i]==')'&&st!=-1)
		{
			kuo[++num][1]=st;kuo[num][2]=i;
			st=-1;
		}
	}
	for (int i=1;i<=num;i++)
	  printf("%d %d\n",kuo[i][1],kuo[i][2]); 
} 
bool stop(string x)
{
	for (int i=0;i<x.size();i++)
	  if (x[i]!='0') return 0;
	return 1;//为全0串 就返回1 可以停止 
}
bool find(string x,string &y)//判断一级括号中的东西合不合法 
{
	for (int i=1;i<=num;i++)
	{
		int shu=0;
		for (int j=kuo[i][1]+1;j<kuo[i][2]-1;j++)
		  if (x[j]=='*')
		  {
			shu++;
		  }
		  else 
		  {
		  	if (shu>=k) return 0;
		  	else shu=0;
		  }
		many++;
	    for (int j=kuo[i][1];j<=kuo[i][2];j++)
	      x[j]=many;
	}
	return 1; 
}
void judge(string x)//判断x合不合法 
{
	many=0;
	string y=x;
	while(!stop(x))
	{
		num=0;
	    f1(x,y);
		if (!find(x)) break;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>ch;
	printf("0");
	judge(ch);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
 ((**()*(*))*)(***)
*/
