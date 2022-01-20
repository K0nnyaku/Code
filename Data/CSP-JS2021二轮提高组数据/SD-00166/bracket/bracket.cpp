#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10000000];
int n;
void get(){
	char ch;
	ch=getchar();
	while(ch){
	if(ch<'0'||ch>'9'){
		if(ch=='-'){
			a=-1; 
			ch=getchar();
		}
	}if(ch>='0'&&ch<='9'){
		a=a*10+ch-'0';
		ch=getchar(); 
	}
}
}
int pai(int x,int y,int z){
	if(x==z){
		return a[z];
	}
	int i=x,j=y+1;
	while(i<=y||j<=z){
		if(a[i]<=a[y]){
			i++;
			continue;
		}if(a[j]>=a[y]){
			j++;
			continue;
		}if(i<=y&&j<=z){
			swap(a[i],a[j]);
		}else if(i<=y){
			swap(a[i],a[y]);
		}else if(j<=z){
			swap(a[j],a[y]);
		}
	}
	pai(x,(x+y)>>1,y);
	pai(y+1,(y+1+z)>>1,z);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pai(1,(n+1)>>1,n);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
