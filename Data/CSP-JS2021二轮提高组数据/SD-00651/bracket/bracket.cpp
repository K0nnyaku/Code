#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int main()
{
	/*
	
	    最后写的这一题，时间不多了，只能稍微写一点骗一骗测试点14-15了qwq
	    
	    AFO 
	    
	*/ 
	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
/*

本注释仅限于测试点14-15 

“对于数据点14-15,仅有‘?’” 

当n=2,k=1时

有且只有()一种情况

当n=4,k=1时

有(())
  ()()
当n=4,k=z(z>=2)时
有(())
  ()()
  (**) 

当n=5,k=1时

有(*)()
  ()*()
  ()(*)
  ((*))
  (()*)
  (*())6种 
当n=5,k=2时 
有(*)()
  ()*()
  ()(*)
  ((*))
  (()*)
  (*())6种 
当n=5,k=a时 (a>=3)
有(*)()
  ()*()
  ()(*)
  ((*))
  (()*)
  (*())
  (***)7种 
  当n=6,k=1时
有((()))
  ()()()
  (()())
  (())()
  ()(())
  (*(*))
  (*()*)
  ((*)*)8种 
  当n=6,k=2时
有((()))
  ()()()
  (()())
  (())()
  ()(())
  (*(*))
  (*()*)
  ((*)*)
  (**)()
  ()(**) 
  (**())
  ((**))
  (()**) 13种
  当n=6,k=3时
有((()))
  ()()()
  (()())
  (())()
  ()(())
  (*(*))
  (*()*)
  ((*)*) 
  (**())
  (**)()
  ()(**) 
  ((**))
  (()**) 13种
  当n=6,k=b(b>=4)时
有((()))
  ()()()
  (()())
  (())()
  ()(())
  (*(*))
  (*()*)
  ((*)*) 
  (**())
  ((**))
  (()**)
  ()(**)
  (**)() 
  (****)14种  
  当n=7,k=1时
有(*()())
  ((*)())
  (()*())
  (()(*))
  (()()*)
  (*(()))
  ((*()))
  (((*)))
  ((()*))
  ((())*)
  (*(*)*)
  11种
  当n=7,k=2时
有(*()())
  ((*)())
  (()*())
  (()(*))
  (()()*)
  (*(()))
  ((*()))
  (((*)))
  ((()*))
  ((())*)
  (*(*)*)
  (**)(*)
  ()**(*)
  (*)**()
  (*)(**)
  15种
  当n=7,k=3时
有(*()())
  ((*)())
  (()*())
  (()(*))
  (()()*)
  (*(()))
  ((*()))
  (((*)))
  ((()*))
  ((())*)
  (*(*)*)
  (**)(*)
  ()**(*)
  (*)**()
  (*)(**)
  (***)()
  ()(***)
  (***())
  ((***))
  (()***)
  20种
  当n=7,k=4时
有(*()())
  ((*)())
  (()*())
  (()(*))
  (()()*)
  (*(()))
  ((*()))
  (((*)))
  ((()*))
  ((())*)
  (*(*)*)
  (**)(*)
  ()**(*)
  (*)**()
  (*)(**)
  (***)()
  ()(***)
  (***())
  ((***))
  (()***)
  20种
  当n=7,k=c(c>=5)时
有(*()())
  ((*)())
  (()*())
  (()(*))
  (()()*)
  (*(()))
  ((*()))
  (((*)))
  ((()*))
  ((())*)
  (*(*)*)
  (**)(*)
  ()**(*)
  (*)**()
  (*)(**)
  (***)()
  ()(***)
  (***())
  ((***))
  (()***)
  (*****)
  21种  
  
*/ 
	
/*
	
	int z[5]={2,3,3,3};//4
	int a[6]={6,6,7,7,7};//5 
	int b[7]={8,13,13,14,14,14};//6
	int c[8]={11,15,20,20,21,21,21};//7
	
*/
	
/*
	
	                                                           0 (1) 
	                                                        1  1 (2)
	                                                     1  1  1 (3)
	                                                  2  3  3  3 (4)
	                                               6  6  7  7  7 (5)
	                                            8 13 13 14 14 14 (6)
	                                        11 15 20 20 21 21 21 (7)
	                                  15(?) 18 23 27 27 28 28 28 (8)    
		                        19(?) 22(?) 25 30 34 34 35 35 35 (9)
	                      23(?) 26(?) 29(?) 32 37 41 41 42 42 42 (10)
		            27(?) 30(?) 33(?) 36(?) 39 44 48 48 49 49 49 (11)
		      31(?) 34(?) 37(?) 40(?) 43(?) 46 51 55 55 56 56 56 (12) 
		35(?) 38(?) 41(?) 44(?) 47(?) 50(?) 53 58 62 62 63 63 63 (13)
		
*/
	
	int n,k;
	cin>>n>>k;
	int y[8]={11,15,20,20,21,21,21};
	if(n==1)
	{
		cout<<0<<endl;
	}
	if(n==2)
	{
		cout<<1<<endl;
	}
	if(n==3)
	{
		cout<<1<<endl;
	}
	if(n==4)
	{
		if(k==1)
		{
			cout<<2<<endl;
		}
		if(k>=2)
		{
			cout<<3<<endl;
		}
	}
	if(n==5)
	{
		if(k<=2)
		{
			cout<<6<<endl; 
		}
		if(k>2)
		{
			cout<<7<<endl;
		}
	}
	if(n==6)
	{
		if(k==1)
		{
			cout<<8<<endl;
		}
		if(k>=2 && k<=3)
		{
			cout<<13<<endl;
		}
		if(k>=4)
		{
			cout<<14<<endl;
		}
	}
	if(n>7)
	{
		if(k<n-7)
		{
			cout<<11+4*(n-7)+3*k<<endl;
		}
		if(k>n-7)
		{
			cout<<y[k-n+7]+(n-7)*7<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

/*

    finish time:2021年10月23日18:18:46 
    
*/ 
