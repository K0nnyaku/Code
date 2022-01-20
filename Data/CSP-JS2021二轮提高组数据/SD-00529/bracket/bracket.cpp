#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
char a[500];
int number;
int kkkkk;
int k[500]={1,1};
int judge(int l,int r,int ls,int lb,int rb){
	int i=l;
    for(;a[i]!='?'&&i<=r;i++){
    	if(a[i]='*')  ls++;
    	if(a[i]='('){
		lb++;
		}
		if(a[i]=')'){
		rb++;
		}
    	if(a[i]=='('||a[i]==')') ls=0;
	}
	if(l==r){
		if(rb==lb){
			return 1;
		}
		return 0;
	}
	if(lb==rb){
		if(kkkkk==ls){
			return (judge(i+1,r,0,lb+1,rb))%1000000009;
		}
		return (judge(i+1,r,0,lb+1,rb)+judge(i+1,r,ls+1,lb,rb))%1000000009;
	}
	if(ls==kkkkk){
		return (judge(i+1,r,0,lb+1,rb)+judge(i+1,r,0,lb,rb+1))%1000000009;
	}
	return (judge(i+1,r,0,lb+1,rb)+judge(i+1,r,0,lb,rb+1)+judge(i+1,r,ls+1,lb,rb))%1000000009;
}
int main(){
	memset(k,0,sizeof(k));
	FILE*f1,*f2;
	f1=fopen("bracket.in","r+");
	f2=fopen("bracket.out","r+"); 
	fscanf(f1,"%d%d",&number,&kkkkk);
	fgets(a,501,f1);
	int b=strlen(a);
    int lb,rb;
    int i;
    for(i=1;i<b-1;i++){
    	if(a[i]=='('){
    		lb++;
		}
		if(a[i]==')'){
			rb++;
		}
	}
	int c=judge(1,b-2,0,lb,rb);
    fprintf(f2,"%d",c);
} 
