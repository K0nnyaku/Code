#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

long long n,guo,inter;
int garrive,gleave;
int iarrive,ileave;
int ansguo,ansinter;
int ans;
int moren;//��0��ʼ��
int moreni;
 
bool pang(int x,int y,long long q) //x����ʱ�� y�ߵ�ʱ�� q���ŵ������� 
{
	if(q==0) return false;
	if(q>=guo) return true;
	if(q<guo)
	{
		if(x>moren) 
		{
			moren=y;
		return true;
		}
		if(x<=moren)
		{
			q--;
			if(q<0) return false;
			else return true; 
		}
	}
	
}
bool pani(int x,int y,long long q) //x����ʱ�� y�ߵ�ʱ�� q���ŵ������� 
{
	if(q==0) return false;
	if(q>=inter) return true;
	if(q<inter)
	{
		if(x>moreni) 
		{
			moreni=y;
		return true;
		}
		if(x<=moreni)
		{
			q--;
			if(q<0) return false;
			else return true; 
		}
	}
	
}
int main()
{
 freopen("bracket.in","r",stdin);
 freopen("bracket.out","w",stdout);
    scanf("%lld%lld%lld",&n,&guo,&inter);
  	for(int i=0; i<=n; i++) //ö�ٹ������� 
   	{
    		inter=n-i;//��������
    	while(guo) //����������� 
		{
			scanf("%lld%lld",&garrive,&gleave); 
				if(pang(garrive,gleave,i)==true)
					ansguo++;	//�����ͣ�� ans++�� 
				guo--;
		}
		while(inter) //����������� 
		{
			scanf("%lld%lld",&iarrive,&ileave);
				if(pani(iarrive,ileave,inter)==true)
					ansinter++;//�����ͣ��  ans++�� 
				inter--;
		}	
		if(ans<ansguo+ansinter)
			ans=ansguo+ansinter;
	}
	printf("%d",ans+1);
 fclose(stdin);
 fclose(stdout);
return 0;
}


