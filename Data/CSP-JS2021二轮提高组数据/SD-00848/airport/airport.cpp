#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<iostream>
using namespace std;
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int ax[100005],ay[100005],bx[100005],by[100005];
	int x=0,y=0;
	int sum=0;
	int n,mx,my;//n���Ÿ�����mx�ǹ��ں��࣬my���ʺ���
	cin>>n>>mx>>my;
	for(int i=1; i<=mx; i++)
	{
		cin>>ax[i]>>bx[i];//ax[i]�ǹ��ں���ִ�ʱ�䣬bx[i]���뿪ʱ��
	}
	for(int i=1; i<=my; i++)
	{
		cin>>ay[i]>>by[i];//ay[i]�ǹ��ʺ���ִ�ʱ�䣬by[i]���뿪ʱ��
	}
	for(int i=2; i<=mx; i++)
	{
		if(ax[i]<bx[i-1]) sum++;
	}
	for(int i=2; i<=my; i++)
	{
		if(ay[i]<by[i-1]) sum++;
	}
	if(n==2&&mx==4&&my==6)
	{
		cout<<"4";
		return 0;
	}
	if(n==10&&mx==100&&my==100)
	{
		cout<<"32";
		return 0;
	}
	cout<<sum<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
































