#include<iostream>
#include<cstdio>
using namespace std;
int t;
string a,c="XZ",ans[101];
void qaq(int i,string b,string sum,int n,int L,int R) {
	if(i==n*2+1) {
		int q=1;
		for(int j=0; j<n*2; j++) {
			if(b[j]!=b[n*2-j-1]) {
				q=0;
				break;
			}
		}
		if(q==1) {
			for(int j=0; j<n*2; j++) {
				if(c[j]>sum[j]) {
					c=sum;
					break;
				}
				if(c[j]<sum[j])break;
			}
		}
		return;
	}
	qaq(i+1,b+a[L],sum+"L",n,L+1,R);
	qaq(i+1,b+a[R],sum+"R",n,L,R-1);
	return;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n,q;
	cin>>t;
	for(int qwq=1; qwq<=t; qwq++) {
		cin>>n;
		for(int i=0; i<n*2; i++) {
			cin>>q;
			if(q<10)a[i]=q+'0';
			else if(q==10)a[i]='0';
			else {
				if(q==11)a[i]='~';
				if(q==12)a[i]='`';
				if(q==13)a[i]='!';
				if(q==14)a[i]='@';
				if(q==15)a[i]='#';
				if(q==16)a[i]='$';
				if(q==17)a[i]='%';
				if(q==18)a[i]='^';
				if(q==19)a[i]='&';
				if(q==20)a[i]='*';
				if(q==21)a[i]='(';
				if(q==22)a[i]=')';
				if(q==23)a[i]='_';
				if(q==24)a[i]='-';
				if(q==25)a[i]='+';
				if(q==26)a[i]='=';
				if(q==27)a[i]='q';
				if(q==28)a[i]='w';
				if(q==29)a[i]='e';
				if(q==30)a[i]='r';
				if(q==31)a[i]='t';
				if(q==32)a[i]='y';
				if(q==33)a[i]='u';
				if(q==34)a[i]='i';
				if(q==35)a[i]='o';
				if(q==36)a[i]='p';
				if(q==37)a[i]='a';
				if(q==38)a[i]='s';
				if(q==39)a[i]='d';
				if(q==40)a[i]='f';
				if(q==41)a[i]='g';
				if(q==42)a[i]='h';
				if(q==43)a[i]='j';
				if(q==44)a[i]='k';
				if(q==45)a[i]='l';
				if(q==46)a[i]='z';
				if(q==47)a[i]='x';
				if(q==48)a[i]='c';
				if(q==49)a[i]='v';
				if(q==50)a[i]='b';
				if(q==51)a[i]='n';
				if(q==52)a[i]='m';
				if(q==53)a[i]='Q';
				if(q==54)a[i]='W';
				if(q==55)a[i]='E';
				if(q==56)a[i]='R';
				if(q==57)a[i]='T';
				if(q==58)a[i]='Y';
				if(q==59)a[i]='U';
				if(q==60)a[i]='I';
				if(q==61)a[i]='O';
				if(q==62)a[i]='P';
				if(q==63)a[i]='A';
				if(q==64)a[i]='S';
				if(q==65)a[i]='D';
				if(q==66)a[i]='F';
				if(q==67)a[i]='G';
				if(q==68)a[i]='H';
				if(q==69)a[i]='J';
				if(q==70)a[i]='K';
				if(q==71)a[i]='L';
				if(q==72)a[i]='Z';
				if(q==73)a[i]='X';
				if(q==74)a[i]='C';
				if(q==75)a[i]='V';
				if(q==76)a[i]='B';
				if(q==77)a[i]='N';
				if(q==78)a[i]='M';
				if(q==79)a[i]='[';
				if(q==80)a[i]='{';
				if(q==81)a[i]=']';
				if(q==82)a[i]='}';
				if(q==83)a[i]=';';
				if(q==84)a[i]=':';
				if(q==85)a[i]='"';
				if(q==86)a[i]='.';
				if(q==87)a[i]='|';
				if(q==88)a[i]=',';
				if(q==89)a[i]='<';
				if(q==90)a[i]='.';
				if(q==91)a[i]='>';
				if(q==92)a[i]='/';
				if(q==93)a[i]='?';
				if(q==94)a[i]=' ';
				if(q==95)a[i]='.';
				if(q==96)a[i]='1';
				if(q==97)a[i]='t';
				if(q==98)a[i]='a';
				if(q==99)a[i]='8';
				if(q==100)a[i]='s';
			}
		}
		qaq(1,"","",n,0,n*2-1);
		if(c=="XZ")ans[qwq]="-1";
		else ans[qwq]=c;
		c="XZ";
	}
	for(int qwq=1; qwq<=t; qwq++) {
		cout<<ans[qwq]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
