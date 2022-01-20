#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

#include <windows.h>
#undef max
#undef min

#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)


namespace tp3{

const int MX=100100;
using namespace std;

bool bcolor=0;
void EnableColor()
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD x;
	GetConsoleMode(h,&x);
	x|=4;
	SetConsoleMode(h,x);
	bcolor=1;
}

int NumLen(int a)
{
	int c=0;
	do ++c;
	while(a/=10);
	return c;
}

void GetStr(string& s,FILE* f=stdin)
{
	s.clear();
	int c=getc(f);
	while(c!=EOF&&isspace(c))c=getc(f);
	while(c!=EOF&&!isspace(c))
		s.push_back(c),c=getc(f);
}



struct Node
{
	int l,r,f,p,q,d;
	string s,c,e;
}T[MX];
int N;

void Clear()
{
	Fr(x,1,N)
	{
		T[x].l=T[x].r=T[x].f=0;
		T[x].p=T[x].q=T[x].d=0;
		T[x].s.clear(),T[x].c.clear(),T[x].e.clear();
	}
	N=0;
}


void WriteTree(string& s,int x)
{
	if(!x)return;
	s.push_back('(');
	WriteTree(s,T[x].l);
	s+=T[x].s; //TODO: T[x].c T[x].e ## #( #)
	WriteTree(s,T[x].r);
	s.push_back(')');
}

string Save()
{
	string s;
//	Fr(x,1,N)if(!T[x].f)
	Fr(x,1,N)if(!T[x].f&&T[x].s.size())
		WriteTree(s,x);
	return s;
}


void ReadNode(int x,const char*& p)
{
	string *ps=&T[x].s;
	while(*p&&*p!='('&&*p!=')')
	{
		if(*p=='#')
		{
			p++;
			if(*p==0)break;
			else if(*p=='c')ps=&T[x].c,p++;
			else if(*p=='e')ps=&T[x].e,p++;
			else ps->push_back(*p++);
		}
		else ps->push_back(*p++);
	}
}

int ReadTree(const char*& p)
{
	if(*p!='(')return 0;
	p++;
	int x=++N;
	int l=ReadTree(p);
	T[x].l=l,T[l].f=x;
	ReadNode(x,p);
	int r=ReadTree(p);
	T[x].r=r,T[r].f=x;
	while(*p&&*p++!=')');
	return x;
}



void GetInfo(int x,int d,int& c)
{
	if(!x)return;
	GetInfo(T[x].l,d+1,c);
	T[x].d=d,T[x].p=c,T[x].q=c+T[x].s.size()-1;
	c+=T[x].s.size()+1;
	GetInfo(T[x].r,d+1,c);
}

void Init()
{
	int c=1;
	Fr(x,1,N)if(!T[x].f&&T[x].s.size())
		GetInfo(x,1,c);
	Fr(x,1,N)
	{
		if(!T[x].c.size())T[x].c="0";
		if(!T[x].e.size())T[x].e="0";
	}
}

void Load(const string& s)
{
	Clear();
	const char *p=s.c_str();
	while(*p=='(')ReadTree(p);
	Init();
}

template<typename Tp1,typename Tp2,typename Tp3>
void Load(int n,Tp1 gl,Tp2 gr,Tp3 gs)
{
	Clear();
	N=n;
	Fr(x,1,N)
	{
		T[x].l=gl(x),T[T[x].l].f=x;
		T[x].r=gr(x),T[T[x].r].f=x;
		string s=gs(x);
		const char *p=s.c_str();
		ReadNode(x,p);
	}
	Init();
}

template<typename Tp1,typename Tp2>
void Load(int n,Tp1 t,Tp2 gs)
{
	Clear();
	N=n;
	Fr(x,1,N)
	{
		T[x].l=t[x].l,T[T[x].l].f=x;
		T[x].r=t[x].r,T[T[x].r].f=x;
		string s=gs(x);
		const char *p=s.c_str();
		ReadNode(x,p);
	}
	Init();
}



void PrintInfo()
{
	Fr(x,1,N)
	{
		printf("#%d f=%d l=%d r=%d s=\"%s\"",
			x,T[x].f,T[x].l,T[x].r,T[x].s.c_str());
		if(T[x].c.size())printf(" c=\"%s\"",T[x].c.c_str());
		if(T[x].e.size())printf(" e=\"%s\"",T[x].e.c_str());
		putchar('\n');
	}
}

void Draw(int tp=2)
{
	int md=0;
	Fr(x,1,N)md=max(md,T[x].d);
	int dl=NumLen(md);
	
	vector<int> a;
	Fr(x,1,N)if(!T[x].f)a.push_back(x);
	int dep=0;
	if(bcolor)printf("\033[0;1;32m");
	printf("[Tree]\n");
	if(bcolor)printf("\033[0m");
	while(a.size())
	{
		vector<int> b;
		
		printf("%*d| ",dl,++dep);
		int c=1,za=a.size();
		Fo(i,0,za)
		{
			int x=a[i];
			
			int u=T[x].l?T[T[x].l].q+tp:T[x].p;
			int v=T[x].r?T[T[x].r].p-tp:T[x].q;
			
			for(;c<u;++c)putchar(' ');
			if(bcolor)printf("\033[0;%sm",T[T[x].l].e.c_str());
			for(;c<T[x].p;++c)putchar('_');
			if(bcolor)printf("\033[0;%sm",T[x].c.c_str());
			printf("%s",T[x].s.c_str()),c+=T[x].s.size();
			if(bcolor)printf("\033[0;%sm",T[T[x].r].e.c_str());
			for(;c<=v;++c)putchar('_');
			if(bcolor)printf("\033[0m");
			
			if(T[x].l)b.push_back(T[x].l);
			if(T[x].r)b.push_back(T[x].r);
		}
		putchar('\n');
		
		
		if(tp==2&&b.size())
		{
			Fr(i,1,dl)putchar(' ');
			printf("| ");
			c=1;
			Fo(i,0,za)
			{
				int x=a[i];
				if(T[x].l)
				{
					int u=T[T[x].l].q+1;
					for(;c<u;++c)putchar(' ');
					if(bcolor)printf("\033[0;%sm",T[T[x].l].e.c_str());
					putchar('/'),++c;
					if(bcolor)printf("\033[0m");
				}
				if(T[x].r)
				{
					int u=T[T[x].r].p-1;
					for(;c<u;++c)putchar(' ');
					if(bcolor)printf("\033[0;%sm",T[T[x].r].e.c_str());
					putchar('\\'),++c;
					if(bcolor)printf("\033[0m");
				}
			}
			putchar('\n');
		}
		a=b;
	}
	putchar('\n');
}

void Print()
{
	Draw();
}

void Print(const string& s)
{
	Load(s),Draw();
}

template<typename Tp1,typename Tp2,typename Tp3>
void Print(int n,Tp1 gl,Tp2 gr,Tp3 gs)
{
	Load(n,gl,gr,gs),Draw();
}

template<typename Tp1,typename Tp2>
void Print(int n,Tp1 t,Tp2 gs)
{
	Load(n,t,gs),Draw();
}

} //namespace tp3

#undef Fo
#undef Fr
#undef Fl

