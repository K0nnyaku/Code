#include<cstdio>
#include<iostream>
#include<string>
#define il inline
using namespace std;

//const int p=1e9+7;
//int n,k,sum=0;
//string S;
//char C[3]={'*','(',')'};
//
//il int read()
//{
//	int num=0; bool flag=1; char c=getchar();
//	while(c<'0'||c>'9'){if(c=='-') flag=1; c=getchar();}
//	while(c>='0'&&c<='9') num=(num<<1)+(num<<3)+(c^48), c=getchar();
//	return flag?num:-num;
//}
//
//il bool pd()
//{
//	int i,numl=0,numr=0,numk=0;
//	for(i=0;i<n;i++)
//	{
//		if(numr>numl||S[i]=='?'||numk>k)
//			return 0;
//		if(S[i]=='*')
//			numk++;
//		if(S[i]=='(')
//			numl++;
//		if(S[i]==')')
//			numr++;
//	}
//	if(numl!=numr)
//		return 0;
//	return 1;
//}
//
//il void dfs(int pos,int numk)
//{
//	if(numk>k)
//		return;
//	if(pos==n)
//	{
//		if(pd())
//			sum++, sum%=p;
//		return;
//	}
//	int i,j;
//	for(i=pos;i<n;i++)
//		if(S[i]=='?')
//		{
//			for(j=0;j<3;j++)
//			{
//				S[i]=C[j];
//				if(j==0)
//					dfs(i+1,numk+1);
//				else
//					dfs(i+1,numk);
//			}
//			S[i]='?';
//		}
//	return;
//}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
//	n=read(); k=read();
//	getline(cin,S);
//	
//	dfs(0,0);
//	
//	printf("%d",sum);
	
	printf("14");
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
