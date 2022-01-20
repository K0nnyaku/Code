#include<iostream>
#include<cstring>
#include<cstdio> 
#include<algorithm>
#include<cmath>
using namespace std;
int n,T,i,k,book=1;
char a[500005];
string s,m1,m2;
char L='L';
char R='R';
string ans,ooooo;
int flag(string hw)
{
	int h=hw.size();
	int now=h;
	while(now>h/2)
	{
		if(hw[h-now]!=hw[now-1])
			return 0;
		now--;
	}
	return 1;
}
void dfs(int head,int tail,string chuan1,string chuan2)
{
	if(book==0)
		return;
	if(head==tail)
	{
		chuan1+=a[head];
		chuan2+=L;
		if(flag(chuan1)==1)
		{
			ans=chuan2;
			book=0;
		}
		return;
	}
	dfs(head+1,tail,chuan1+a[head],chuan2+L);
	dfs(head,tail-1,chuan1+a[tail],chuan2+R);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(k=1;k<=T;k++)
	{
		ans=ooooo;
		cin>>n;
		for(i=1;i<=2*n;i++)
			cin>>a[i];
		dfs(1,2*n,m1,m2);
		if(ans==ooooo)
			cout<<-1<<endl;
		else 
			cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
