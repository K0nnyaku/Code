#include<iostream> 
#include<cstdio>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[50010];
		for(int i=0;i<2*n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<2*n;i++)//���ڲ��Ե�18-20������������
		{
			cout<<"L";//���L����������ΪȫLʱ�ֵ�����С 
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
