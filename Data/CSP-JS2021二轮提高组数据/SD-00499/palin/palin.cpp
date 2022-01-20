#include<bits/stdc++.h>
using namespace std;
//rp++;
int n,t;
int a[500100];
int d[601000];
int b[500100];
int ans[500100];
int noww=1;
void find321(int c)
{
	memset(ans,0,sizeof(ans));
	int i=1,j=2*c;
	pair<int,int> flag1;
	int cnt11=0;
	int zuoyou=0;
	flag1.first=0;flag1.second=0;
	while(i<=j)
	{
		if(!flag1.first)
		{
			flag1.first=a[i++];
			flag1.second=1;
			cnt11++;
			ans[noww++]=0;
			continue;
		}	
		if(cnt11==c&&zuoyou==0)
		{
			flag1.first=a[i-1];
			flag1.second=i-1;
			//cout<<a[i-1]<<" "<<i-1<<" pos"<<endl;
			goto N;
			//cout<<1<<endl;
		}
		if(cnt11==c&&zuoyou==1)
		{
			flag1.first=a[j+1];
			flag1.second=j+1;
			goto M;
			//cout<<2<<endl;
		}
			if(cnt11<=c)//xian
			{
					if(d[flag1.first]-flag1.second-i>=j-d[flag1.first]+flag1.second)
					{	
						flag1.second=i;
						flag1.first=a[i++];
						cnt11++;
						ans[noww++]=0;
						zuoyou=0;
						//printf("\nf %d %d %d\n",flag1.first,flag1.second,cnt11);
						continue;
					}
					else
					{
						flag1.second=j;
						flag1.first=a[j--];
						cnt11++;
						zuoyou=1;
						ans[noww++]=1;
						continue;
					}
			}
			else//hou
			{
				N:
				M:
				//printf("\n arr %d %d %d %d\n",flag1.first,flag1.second,d[flag1.first]-flag1.second-i,j-d[flag1.first]+flag1.second);
					if(d[flag1.first]-flag1.second-i>=j-d[flag1.first]+flag1.second)
					{
						flag1.second=i;
						flag1.first=a[i++];
						cnt11++;
						zuoyou=0;
						
						
						if(cnt11==c+1) ans[noww++]=1;
						else ans[noww++]=0;
						continue;
					}
					else
					{	
						flag1.second=j;
						flag1.first=a[j--];
						cnt11++;
						zuoyou=1;
						
						if(cnt11==c+1) ans[noww++]=1;
						else ans[noww++]=1;
						continue;
					}
			}
			
		
	}
	if(noww-1!=n*2)
	{
		cout<<-1<<endl;
		return;
	}
	for(int i=1;i<noww;i++)
	{
		if(ans[i]) cout<<"R";
		else cout<<"L";
	}
	cout<<endl;
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			d[a[i]]+=i;
		}
		find321(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
