#include<bits/stdc++.h>
using namespace std;
int a[100001],a1[100001],b1[100001],b[100001],fa[100001],fb[100001],f[100001];
int n,m1,m2,j=0,ans;
void paia(int x,int y,int z){
	if(x==z){
		return;
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
			swap(a1[i],a1[j]);
		}else if(i<=y){
			swap(a[i],a[y]);
			swap(a1[i],a1[y]);
		}else if(j<=z){
		swap(a[j],a[y]);
		swap(a1[j],a1[y]);
		}
	}
	paia(x,(x+y)>>1,y);
	paia(y+1,(y+1+z)>>1,z);
}
void paib(int x,int y,int z){
	if(x==z){
		return;
	}
	int i=x,j=y+1;
	while(i<=y||j<=z){
		if(b[i]<=b[y]){
			i++;
			continue;
		}if(b[j]>=b[y]){
			j++;
			continue;
		}if(i<=y&&j<=z){
			swap(b[i],b[j]);
		}else if(i<=y){
			swap(b[i],b[y]);
		}else if(j<=z){
			swap(b[j],b[y]);
		}
	}
	paib(x,(x+y)>>1,y);
	paib(y+1,(y+1+z)>>1,z);
}
void pana(int x){
	if(x==0){
		fa[x]=0;
		return;
	}if(x>=m1){
		fa[x]=m1;
		return;
	}
	int x1=x,ji=1+x1;
	for(int l=1;l<=m1;l++){
		if(x>0){
			fa[x1]++;
			x--;
			f[l]=a1[l];
		}else{
			for(int i=1;i<=x1;i++){
				if(a[ji]>=f[i]){
					fa[x1]+=1;
					f[i]=a1[ji];
					ji++;
					j=1;
					break;
				}
			}
			if(j!=1){
				ji++;
			}if(j==1){
				j=0;
			}
			
		}
	}
	return;
}
void panb(int x){
	if(x==0){
		fb[x]=0;
		return;
	}if(x>=m2){
		fb[x]=m2;
		return;
	}
	int x1=x,ji=1+x1;
	for(int l=1;l<=m2;l++){
		if(x>0){
			fb[x1]++;
			x--;
			f[l]=b1[l];
		}else{
			for(int i=1;i<=x1;i++){
				//cout<<b[ji]<<" "<<f[i]<<endl;
				if(b[ji]>=f[i]){
					fb[x1]+=1;
					f[i]=b1[ji];
					ji++;
					j=1;
					break;
				}
			}
			if(j!=1){
				ji++;
			}if(j==1){
				j=0;
			}
		}
	}
	return;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i],&a1[i]);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i],&b1[i]);
	}
	paia(1,(m1+1)>>1,m1);
	paib(1,(m2+1)>>1,m2);
	for(int i=0;i<=n;i++){
		pana(i);
		panb(i);
	} 
	for(int i=0;i<=m2&&i<=n;i++){
		ans=max(ans,fa[i]+fb[n-i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
