#include <iostream>
#include <cstdio>
using namespace std;

struct _n
{
	int _num;
	int _z;
};

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	int a1[10000],a2[10000],b1[10000],b2[10000];
	int a[100001]={},b[100001]={};
	cin>>n>>m1>>m2;
	for (int l=0;l<m1;l++){
		cin>>a1[l];
		cin>>a2[l]; 
	} 
		for (int l=0;l<m2;l++){
		cin>>b1[l];
		cin>>b2[l];
	} 
	int n1=0,x,y;
	for (int l=0;l<m1-n1;l++)
	{
		if (a1[l]>a1[l+1]){
			x=a1[l];
			a1[l]=a1[l+1];
			a1[l+1]=x;
			y=a2[l];
			a2[l]=a2[l+1];
			a2[l+1]=x;
		}
		n1++;
	}
	n1=0;
	for (int l=0;l<m2-n1;l++)
	{
		if (b1[l]>b1[l+1]){
			x=b1[l];
			b1[l]=b1[l+1];
			b1[l+1]=x;
			y=b2[l];
			b2[l]=b2[l+1];
			b2[l+1]=x;
		}
		n1++;
	} 
	
	_n _i,_o;
	int _max=0;
	for (int l=0;l<=n;l++){
		int t=0,z1=1,z2;
		int xm=0;
		_i._z=l;
		_o._z=n-l;
		_i._num=l;
		_o._num=n-l;
		if (_i._z>0){
			for (int i=0;i<m1;i++){
				if (_i._num>0) {
					z2=1;
					_i._num--;
					t++;
				}
				else z2=0;
				
				if (_i._num<_i._z){
					if (a2[i]<a1[i+1]&&z1==1) _i._num++;
					if (_i._num<_i._z){
						if (i!=0&&a1[i+1]>=a2[i-1]&&z1==1) _i._num++;
					}
				}
				z1=z2;
			}
		}
		z1==1;
		if (_o._z>0){
			for (int i=0;i<m2;i++){
				if (_o._num>0) {
					z2=1;
					_o._num--;
					t++;
				}
				else z2=0;
				if (_o._num<_o._z){
					if (b2[i]<b1[i+1]&&z1==1) _o._num++;
					if (_o._num<_o._z){
						if (i=m2-1) 
						if (i!=0&&b1[i+1]>=b2[i-1]&&z1==1) _o._num++;
					}
				}
			}
		}
		if (_max<t) _max=t;
	}
	cout<<_max+1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
