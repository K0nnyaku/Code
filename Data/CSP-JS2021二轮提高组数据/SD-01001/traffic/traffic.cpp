#include<stdio.h>
#include<stdlib.h>
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
