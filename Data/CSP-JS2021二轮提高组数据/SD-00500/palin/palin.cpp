#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n,head,tail,book,i,j;
	cin>>t;
	for( i=1;i<=t;i++){
		cin>>n;
	    head=1;tail=2*n;
	int a[2*n+1];//数组 
	int c[2*n+1];//编码 
	int d[2*n+1];//记录数据 
	int e[2*n+1];
	char b[2*n+1],r,l;//字符串 
	r='R';l='L';
	for(i=1;i<=2*n;i++){
		cin>>a[i];
		for(j=1;j<i;j++)
		    if(a[j]=a[i]){
		        c[j]=i;
		        c[i]=j;
			}
	}
	i=1;
    d[i]=a[head];
    head++;
    i++;
if(a[c[head-1]-1]==a[head]){
    	book=1;
    	d[i]=a[head];
    	head++;
    	i++;
	}		
	else if(c[a[c[head-1]+1]]==head){
		book=2;
		d[i]=a[head];
		head++;
		i++;}
	else if(c[a[c[head-1]-1]]==tail){
		book=1;
		d[i]=a[tail];
		tail--; i++;
		}
	else if(c[a[c[head-1]+1]]==tail){
		book=2;
		d[i]=a[tail];
		tail--; i++;
		}
	else {
		cout<<"-1";
		}
if(book==1)
	   for(j=c[d[i]]-1;j>=c[d[i]]-n/2+1;i--){
	   		if(c[a[j]]==head){
			d[i]=a[head];
			head++; i++;
		}
		else if(c[a[j]]==tail){
			    d[i]=a[tail];
			    tail--;i++; 
		}
		else {
			cout<<"-1";
		}
	   }
	if(book==2)
	   for(j=c[d[i]]+1;j<=c[d[i]]+n/2-1;i++){
	   		if(c[a[j]]==head){
			d[i]=a[head];
			head++; i++;
		}
		else if(c[a[j]]==tail){
			    d[i]=a[tail];
			    tail--;i++; 
		}
		else {
			cout<<"-1";
		}
	   }
	   head=1;tail=2*n;
	for( i=1;i<=n;i++){
		if(d[i]==a[head])
		{
			cout<<"L";
			head++;
		}
		if(d[i]==a[tail])	{
			cout<<"R";
			tail--;
		}
	}
	    
	}return 0;
}
