#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int nei[N],wai[N],ans[N];//nei���ڷɻ���wai����ɻ���ansÿ�������ͣ�����ŵķɻ����� 
int n,m1,m2;//n ������Ŀ��m1���ڷɻ�����m2���ʷɻ��� 
int maxx=0;//��
int num1,num2;// ����������
int jishi1=-1e8,jishi2=-1e8;//ǰһ�ܷɻ��뿪ʱ��
int geshu1=0,geshu2=0;//�ֱ�ͣ�����ŵķɻ�����
int a,b;//��ʱ��
int xxx,yyy;//����
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)//������ں������
	{
    		scanf("%d%d",&a,&b);
    		nei[i]=a*10000+b;
    }
    for(int i=1;i<=n;i++)//������ʺ������
    {
    		scanf("%d%d",&a,&b);
    		wai[i]=a*10000+b;
	}
	sort(nei+1,nei+m1);
	sort(wai+1,wai+m1);
	for(int i=0;i<n;i++)
	{
		num1=i;//���ڷ����������
		num2=n-i;//��������������
		for(int j=1;j<=m1;j++) //�ɻ����
		{
			if(num1==0) geshu1=0;//����������Ϊ��ʱ���޷�ͣ���ɻ�
			else//��Ϊ��ʱ
			{
				if(nei[j]/10000>=jishi1&&geshu1<=num1);//����ʱ�����ǰһ�ɻ����뿪ʱ����ͣ����������������
					geshu1+=1;//ͣ������һ 
					jishi1=nei[j]%10000;//�����뿪ʱ��
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
