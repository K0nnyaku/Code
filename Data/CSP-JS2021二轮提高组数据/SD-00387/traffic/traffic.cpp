#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

//int read();

int main(){
//	freopen("traffic.in","r",stdin);
//	freopen("traffic.out","w",stdout);
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

int read()
{
	int f = 1,num = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c <= '9' && c >= '0')
	{
		num = num*10+c-'0';
		c = getchar();
	}
	return num*f;
}


