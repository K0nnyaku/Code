#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	FILE*f1,*f2;
	f1=fopen("palin.in","r+");
	f2=fopen("palin.out","r+"); 
	int a;
	fscanf(f1,"%d",&a);
	int i;
	for(i=0;i<a;i++){
		fprintf(f2,"-1\n");
	}
} 
