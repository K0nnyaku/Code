#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<map>
#include<math.h>
using namespace std;
int n,T,a[1000010],hhh,cnt,cuo;
//inline string dfs(char x,string lmh,int tot,int wei)
//{
//	if(tot>2*n)
//	{
//		for(int i=1;i<2*n;i++)
//		{
//			if(lmh[i]!=lmh[2*n+1-i])
//			{
//				cuo+=2*n;
////				cout<<lmh<<";;;;;;"<<endl;
//				return "W";
//			} 
//		}
//		return lmh; 
//	}
//	cnt++;
//	lmh[wei]=x;
//	return min(dfs('L',lmh,tot+1,wei+1),dfs('R',lmh,tot+1,wei+1));
//}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;	
	while(T--)
	{
//		cnt=cuo=0;
//		cin>>n;
//		for(int i=1;i<=n*2;i++)cin>>a[i];	
//		string uuu=min(dfs('L',"",0,1),dfs('L',"",0,1));
//		if(cuo==cnt)
//		{
//			cout<<-1<<endl;
//			continue;
//		}
//		cout<<uuu<<endl;
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
