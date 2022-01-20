#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100005;
int n,m1,m2,enterin,enterout,ans = -1,maxtime_guonei,maxtime_guoji;
int guonei[N][2],guoji[N][2];
int langqiao[N];

int YNstop(int n,int m)
{
	int sum = 0,cnt = 0,temp = 0;
	for (int i = 1;i <= maxtime_guonei;i++)
	{
		//printf("[i = %d,maxtime_guonei = %d]\n",i,maxtime_guonei);
		for (int j = 0;j <= i;j++)
		{
			if (langqiao[j] == i)
			{
				temp--;
				//printf("! pop %d %d %d,temp = %d!\n",i,j,langqiao[j],temp);
				langqiao[j] = 0;
			}
		}
		if (guonei[cnt][0] == i && temp >= n) cnt++;
		else if (guonei[cnt][0] == i && temp < n)
		{
			//printf("! add %d %d %d!\n",i,cnt,guonei[cnt][1]);
			langqiao[i] = guonei[cnt][1];
			sum++;
			cnt++;
			temp++;
		}
	}
	cnt = 0,temp = 0;
	int langqiao[N] = {0};
	for (int i = 1;i <= maxtime_guoji;i++)
	{
		//printf("[i = %d,maxtime_guoji = %d,guoji[cnt][0] = %d]\n",i,maxtime_guoji,guoji[cnt][0]);
		for (int j = 0;j <= i;j++)
		{
			if (langqiao[j] == i)
			{
				temp--;
				//printf("! pop %d %d %d,temp = %d!\n",i,j,langqiao[j],temp);
				langqiao[j] = 0;
			}
		}
		if (guoji[cnt][0] == i && temp >= m) cnt++;
		else if (guoji[cnt][0] == i && temp < m)
		{
			//printf("! add %d %d %d!\n",i,cnt,guoji[cnt][1]);
			langqiao[i] = guoji[cnt][1];
			sum++;
			cnt++;
			temp++;
		}
	}
	//printf("ans = %d\n}\n",sum);
	return sum;
}

void sortguonei()
{
	int Min = 0;
	int temp = 0,flag = 0;
	for (int i = 0;i < m1;i++)
	{
		Min = i;
		flag = 0;
		for (int j = i;j < m1;j++)
		{
			if (guonei[j][0] < guonei[Min][0])
			{
				flag = 1;
				Min = j;
			}
		}
		if (flag)
		{
			temp = guonei[i][1];
			guonei[i][1] = guonei[Min][1];
			guonei[Min][1] = temp;
			temp = guonei[i][0];
			guonei[i][0] = guonei[Min][0];
			guonei[Min][0] = temp;
		}
	}
}

void sortguoji()
{
	int Min = 0,temp = 0,flag = 0;
	for (int i = 0;i < m2;i++)
	{
		Min = i;
		flag = 0;
		for (int j = i;j < m2;j++)
		{
			if (guoji[j][0] < guoji[Min][0])
			{
				flag = 1;
				Min = j;
			}
		}
		if (flag)
		{
			temp = guoji[i][1];
			guoji[i][1] = guoji[Min][1];
			guoji[Min][1] = temp;
			temp = guoji[i][0];
			guoji[i][0] = guoji[Min][0];
			guoji[Min][0] = temp;
		}
	}
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2); 
	for (int i = 0;i < m1;i++)
	{
		enterin = 0,enterout = 0;
		scanf("%d%d",&enterin,&enterout);
		guonei[i][0] = enterin;
		guonei[i][1] = enterout;
		maxtime_guonei = max(enterin,max(enterout,maxtime_guonei));
	}
	sortguonei();
	//for (int i = 0;i < m1;i++) printf("%d-%d ",guonei[i][0],guonei[i][1]);
	//printf("\n");	
	for (int i = 0;i < m2;i++)
	{
		enterin = 0,enterout = 0;
		scanf("%d%d",&enterin,&enterout);
		guoji[i][0] = enterin;
		guoji[i][1] = enterout;
		maxtime_guoji = max(enterin,max(enterout,maxtime_guoji));
	}
	sortguoji();

	//for (int i = 0;i < m2;i++) printf("%d-%d ",guoji[i][0],guoji[i][1]);
	//printf("\n");
	for (int i = 0;i <= n;i++)
	{
		//printf("{\n guonei = %d,guoji = %d\n",i,n-i);
		ans = max(YNstop(i,n - i),ans);
	}
	printf("%d",ans);
	return 0;
} 
