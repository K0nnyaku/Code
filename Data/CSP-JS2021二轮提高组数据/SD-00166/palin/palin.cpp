#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define max 500005
using namespace std;
int a[max],c[max],b[max],ca[max];
char ans[max],bns[max];
int n,t,star=1,j,ji=1,f=0;
bool check(int x,int y){
	int i=n;
	while(i>0){
		if(a[x]==b[i]){
			x++;
			bns[2*n-i+1]='L';
			i--;
		}else if(a[y]==b[i]){
			y--;
			bns[2*n-i+1]='R';
			i--;
		}else{
			return false;
		}
	}
	return true;
}
void pan(int &x,int &y){
	if(ji>n){
		/*for(int i=1;i<=n;i++){
			cout<<bns[i]<<" "<<ans[i]<<endl;
		}cout<<endl;*/
		if(check(x,y)){
			f++;
			int g=0;
			for(int i=1;i<=2*n;i++){
				if(ans[i]<bns[i]){
					break;
				}else if(ans[i]>bns[i]){
					g+=1;
				}if(g!=0){
					for(int s=1;s<=2*n;s++){
						ans[s]=bns[s];
					}
					break;
				}
			}
			return;
		}else{
			return;
		}
	}
	if(c[a[x]]!=1){
		b[ji]=a[x];
		//cout<<b[ji]<<endl;
		c[a[x]]=1;
		x++;
		bns[ji]='L';
		ji++;
		pan(x,y);
		x--;
		ji--;
		c[a[x]]=0;
	}if(c[a[y]]!=1){
		b[ji]=a[y];
		//cout<<b[ji]<<endl;
		c[a[y]]=1;
		bns[ji]='R';
		ji++;y--;
		pan(x,y);
		y++;ji--;
		c[a[y]]=0;
	}
}
int main(){
	freopen("palin1.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		scanf("%d",&a[i]);
		ans[i]='R';
	}
	j=2*n;
	if(a[1]>a[2*n]&&c[a[2*n]]!=1){
			b[ji]=a[2*n];
			c[a[2*n]]=1;
			j--;
			bns[ji]='R';
			ji++;
		}
	pan(star,j);
	if(f==0){
		cout<<-1<<endl;
	}else{
		for(int i=1;i<=2*n;i++){
			cout<<ans[i];
			if(i==2*n){
				cout<<endl;
				f=0;
				ji=1;
			}
		}
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
