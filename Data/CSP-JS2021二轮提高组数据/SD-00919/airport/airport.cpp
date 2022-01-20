#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int nei[N],wai[N],ans[N];//nei国内飞机，wai国外飞机，ans每种情况下停靠廊桥的飞机数量 
int n,m1,m2;//n 廊桥数目，m1国内飞机数，m2国际飞机数 
int maxx=0;//答案
int num1,num2;// 分配廊桥数
int jishi1=-1e8,jishi2=-1e8;//前一架飞机离开时间
int geshu1=0,geshu2=0;//分别停靠廊桥的飞机数量
int a,b;//起降时间
int xxx,yyy;//计数
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)//读入国内航班情况
	{
    		scanf("%d%d",&a,&b);
    		nei[i]=a*10000+b;
    }
    for(int i=1;i<=n;i++)//读入国际航班情况
    {
    		scanf("%d%d",&a,&b);
    		wai[i]=a*10000+b;
	}
	sort(nei+1,nei+m1);
	sort(wai+1,wai+m1);
	for(int i=0;i<n;i++)
	{
		num1=i;//国内分配的廊桥数
		num2=n-i;//国外分配的廊桥数
		for(int j=1;j<=m1;j++) //飞机标号
		{
			if(num1==0) geshu1=0;//分配廊桥数为零时，无法停靠飞机
			else//不为零时
			{
				if(nei[j]/10000>=jishi1&&geshu1<=num1);//出发时间大于前一飞机的离开时间且停靠数不超过廊桥数
					geshu1+=1;//停靠数加一 
					jishi1=nei[j]%10000;//更新离开时间
			}
		}
		for(int k=1;k<=m2;k++)
		{
			if(num2==0) geshu2=0;
			else
			{
				if(wai[k]/10000>=jishi2&&geshu2<=num2);
					geshu2+=1;
					cout<<geshu2;
					jishi2=wai[k]%10000;
			}
		}
		ans[i]=geshu1+geshu2;
	}
	for(int i=1;i<=n;i++)
		maxx=max(maxx,ans[i]);
	cout<<maxx;
	return 0;
}
