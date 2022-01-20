#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m1,m2,q1[100005],q2[100005]
,a1[100005],a2[100005],b1[100005],b2[100005];
//queue <ti> q1,q2;
int count1(int num)
{
	int i,j,re=0;
	for(i=0;i<m1;i++)
		for(j=0;j<num;j++){
			int x=q1[j];
			if(x==-1){
				re++;
				q1[j]=i;
				break;
			}
			else if(b1[x]<a1[i])
			{
				re++;
				q1[j]=i;
				break;
			}
		}
	return re;
}
int count2(int num)
{
	int i,j,re=0;
	for(i=0;i<m2;i++)
		for(j=0;j<num;j++){
			int x=q2[j];
			if(x==-1){
				re++;
				q2[j]=i;
				break;
			}
			else if(b2[x]<a2[i]){
				re++;
				q2[j]=i;
				break;
			}
		}
	return re;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i,j,k,ans=0,sum=0,tot=0;
	cin>>n>>m1>>m2;
	for(i=0;i<m1;i++)
		cin>>a1[i]>>b1[i];
	for(i=0;i<m2;i++)
		cin>>a2[i]>>b2[i];
	if(n==m1+m2){
		cout<<n<<endl;
		return 0;
	}
	for(i=0;i<=m1&&i<=n;i++)
	{
		if(n-i>m2)
			continue;
		sum=0;
		if(n-i==m2){
			sum=m2;
			memset(q1,-1,sizeof(q1)); 
			sum+=count1(i);
		}
		else if(i==m1){
			sum=m1;
			memset(q2,-1,sizeof(q2));
			sum+=count2(n-i);
		}
		else{
			memset(q1,-1,sizeof(q1));
			memset(q2,-1,sizeof(q2));
			sum+=count1(i)+count2(n-i);
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

