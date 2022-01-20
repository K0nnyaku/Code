#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef struct Plane{
	struct Plane *before,*next;
	int live;
	int arrive;
	int leave;
}P;
FILE *f1,*f2;
void Inl(P*  tail){
	P* k=(P*)malloc(sizeof(P));
	k->live=1;
	k->before=tail;
	fscanf(f1,"%d%d",&k->arrive,&k->leave);
	k->next=NULL;
	tail->next=k;
	tail=k;
}
void Outl(P *k){
	if(!k){
		return;
	}
	if(k->next) k->next->before=k->before;
	k->before->next=k->next;
	free(k);
}
void Quicksort(P*start,P*tail){
	P* k=start;
	P* f;
	for(;k!=NULL;k=k->next){
		for(f=start;f!=NULL;f=f->next){
			if(f->arrive>k->arrive){
				int tmp;
				tmp=f->arrive;
				f->arrive=k->arrive;
				k->arrive=tmp;
				tmp=f->leave;
				f->leave=k->leave;
				k->leave=tmp;
			}
		}
	}
}
int ink[100001];
int outk[100001];
void Judge(P*start,P*tail,int lnum,int c[],int pnum){
	int i,j;
	int flag;
	P* k=start;
	memset(c,0,sizeof(c));
	c[0]=0;
	for(i=1;i<=lnum;i++){
		flag=0;
		int flag2=0;
		int count=0;
		for(k=start;k!=NULL;k=k->next){
			if(flag2){
				int p=0;
				if(k->before==start){
					p=1;
				}
				Outl(k->before);
				if(p){
					start=k;
				}	
			}
			flag2=0;
			if(k->arrive>flag){
				count++;
				flag=k->leave;
				flag2=1;
			}
		}
		if(flag2){
			tail=tail->before;
			Outl(tail->next);
		}
		if(c[i-1]+count<pnum){
			c[i]=c[i-1]+count;
		}
		else{
			c[i]=pnum;
		}
	}
}
P* head1,*tail1,*head2,*tail2;
int main(){
	f1=fopen("airport.in","r+");
	f2=fopen("airport.out","r+"); 
	int a,innum,outnum;
	fscanf(f1,"%d%d%d",&a,&innum,&outnum);
	int i;
	head1=(P*)malloc(sizeof(P));
	tail1=head1;
	head1->next=head1->before=NULL;
	head2=(P*)malloc(sizeof(P));
	tail2=head2;
	head2->next=head2->before=NULL;
	for(i=0;i<innum;i++){
        Inl(tail1);
        tail1=tail1->next;
	}
    Quicksort(head1->next,tail1);
	Judge(head1->next,tail1,a,ink,innum);
	for(i=0;i<outnum;i++){
		Inl(tail2);
		tail2=tail2->next;
	}
	int now=0;
	Quicksort(head2->next,tail2);
	Judge(head2->next,tail2,a,outk,outnum);
	int max=0;
	for(i=0;i<=a;i++){
		if(ink[i]+outk[a-i]>max){
			max=ink[i]+outk[a-i];
		}
	}
	fprintf(f2,"%d",max);
	fclose(f1);
	fclose(f2);
	return 0;
} 
