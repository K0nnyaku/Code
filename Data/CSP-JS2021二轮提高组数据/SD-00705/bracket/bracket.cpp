#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

long long n,guo,inter;
int garrive,gleave;
int iarrive,ileave;
int ansguo,ansinter;
int ans;
int moren;//从0开始；
int moreni;
 
bool pang(int x,int y,long long q) //x来的时间 y走的时间 q廊桥的数量； 
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
bool pani(int x,int y,long long q) //x来的时间 y走的时间 q廊桥的数量； 
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
  	for(int i=0; i<=n; i++) //枚举国内廊桥 
   	{
    		inter=n-i;//国际廊桥
    	while(guo) //处理国内区域 
		{
			scanf("%lld%lld",&garrive,&gleave); 
				if(pang(garrive,gleave,i)==true)
					ansguo++;	//如果能停靠 ans++； 
				guo--;
		}
		while(inter) //处理国际区域 
		{
			scanf("%lld%lld",&iarrive,&ileave);
				if(pani(iarrive,ileave,inter)==true)
					ansinter++;//如果能停靠  ans++； 
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


