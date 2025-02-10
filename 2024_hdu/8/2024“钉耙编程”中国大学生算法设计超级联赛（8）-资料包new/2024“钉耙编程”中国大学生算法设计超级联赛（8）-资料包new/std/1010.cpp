// #define ONLINE_JUDGE
#include<bits/stdc++.h>
#define REP(i,first,last) for(int i=(first);i<=(last);++i)
#define DOW(i,first,last) for(int i=(first);(last)<=i;--i)
#define LL long long
#define UI unsigned int
#define ULL unsigned long long
#define PII pair<int,int>
#define PIL pair<int,long long>
#define PLI pair<long long,int>
#define PLL pair<long long,long long>
#define MPR(a,b) make_pair(a,b)
#define CLEAN(a) memset(a,0,sizeof(a))
#define COVER(a,v) memset(a,v,sizeof(a))
#define FORV(v,i) for(auto i:v)
#define COPY(clone,a) memcpy(clone,a,sizeof(a))
#define SURVEILLANCE(type_name) IO::DeBugln("On line ",__LINE__," "#type_name"=",type_name)
#define YES Writeln("YES");
#define YESR {Writeln("YES");return;}
#define YESR0 {Writeln("YES");return 0;}
#define NO Writeln("NO");
#define NOR {Writeln("NO");return;}
#define NOR0 {Writeln("NO");return 0;}
#ifndef ONLINE_JUDGE
#define GAP IO::DeBugln("Gap on line ",__LINE__);fwrite(pbuf,1,pp-pbuf,stdout);IO::pp=IO::pbuf;fclose(stdout);freopen("data.out","w",stdout);
#define STOP IO::DeBugln("Stop on line ",__LINE__);fwrite(pbuf,1,pp-pbuf,stdout);fclose(stdout);exit(0);
#else
#define GAP
#define STOP
#endif
const int INF=1e9;
const LL INFL=1e18;
namespace IO
{
// #define GETCHAR_KEY
// #define PUTCHAR_KEY
const int IN_BUF=1<<23,OUT_BUF=1<<23;
int double_len(6);
bool spacebar_can_see(1);
const char NUMBER_TO_CHAR[36]={48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
const int CHAR_TO_NUMBER[128]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0};
char buf[IN_BUF],*ps=buf,*pt=buf,pbuf[OUT_BUF],*pp=pbuf;
template<class T>class Number{public:unsigned int len;int hex;T number;inline Number(const T number=0,const int hex=10,const int len=0):number(number),hex(hex),len(len){}inline operator T()const{return number;}inline Number<T>& operator =(const T &a){number=a;return *this;}};
inline bool CanSee(const char ch){return spacebar_can_see?(31<ch&&ch<127):(32<ch&&ch<127);}
inline bool IsNumber(const char ch){return (47<ch&&ch<58);}
inline bool IsNumber_(const int hex,const char ch){return (47<ch&&ch<48+hex)||(64<ch&&ch<55+hex)||(96<ch&&ch<87+hex);}
inline char GetChar(){
#ifdef GETCHAR_KEY
return getchar();
#endif
if(ps==pt){ps=buf;pt=buf+fread(buf,1,IN_BUF,stdin);}return ps==pt?EOF:*ps++;}
inline void PutChar(const char ch){
#ifdef PUTCHAR_KEY
putchar(ch);return;
#endif
if(pp==pbuf+OUT_BUF){fwrite(pbuf,1,OUT_BUF,stdout);pp=pbuf;}*pp++=ch;}
char read_ch(10);
template<class T>inline T ReadInt(){T x(0);bool f(1);while(!IsNumber(read_ch)&&(~read_ch)){if(read_ch==45){f=0;}read_ch=GetChar();}while(IsNumber(read_ch)&&(~read_ch)){x=(x<<1)+(x<<3)+(read_ch^48);read_ch=GetChar();}return f?x:-x;}
template<class T>inline T ReadUInt(){T x(0);while(!IsNumber(read_ch)&&(~read_ch)){read_ch=GetChar();}while(IsNumber(read_ch)&&(~read_ch)){x=(x<<1)+(x<<3)+(read_ch^48);read_ch=GetChar();}return x;}
template<class T>inline T ReadKInt(const int hex){T x(0);bool f(1);while(!IsNumber_(hex,read_ch)&&(~read_ch)){if(read_ch==45){f=0;}read_ch=GetChar();}while(IsNumber_(hex,read_ch)&&(~read_ch)){x=x*hex+CHAR_TO_NUMBER[read_ch];read_ch=GetChar();}return f?x:-x;}
template<class T>inline T ReadUKInt(const int hex){T x(0);while(!IsNumber_(hex,read_ch)&&(~read_ch)){read_ch=GetChar();}while(IsNumber_(hex,read_ch)&&(~read_ch)){x=x*hex+CHAR_TO_NUMBER[read_ch];read_ch=GetChar();}return x;}
inline double ReadDouble(){long long int_num(ReadInt<long long>());if(read_ch==46){double pow10(1.0),result(0);read_ch=GetChar();while(IsNumber(read_ch)&&(~read_ch)){pow10/=10.0;result+=pow10*(read_ch^48);read_ch=GetChar();}return int_num+(int_num<0?-result:result);}else{return (double)int_num;}}
inline void ReadT(int &x){x=ReadInt<int>();}
inline void ReadT(long long &x){x=ReadInt<long long>();}
inline void ReadT(bool &x){x=ReadUInt<bool>();}
inline void ReadT(unsigned int &x){x=ReadUInt<unsigned int>();}
inline void ReadT(unsigned long long &x){x=ReadUInt<unsigned long long>();}
inline void ReadT(double &x){x=ReadDouble();}
inline void ReadT(char &ch){for(;!CanSee(read_ch)&&(~read_ch);read_ch=GetChar()){};ch=read_ch;read_ch=10;}
inline void ReadT(Number<int> &x){x.number=ReadKInt<int>(x.hex);}
inline void ReadT(Number<long long> &x){x.number=ReadKInt<long long>(x.hex);}
inline void ReadT(Number<unsigned int> &x){x.number=ReadUKInt<unsigned int>(x.hex);}
inline void ReadT(Number<unsigned long long> &x){x.number=ReadUKInt<unsigned long long>(x.hex);}
inline void ReadT(char *s){int len(0);for(;!CanSee(read_ch)&&(~read_ch);read_ch=GetChar()){};for(;CanSee(read_ch)&&(~read_ch);read_ch=GetChar()){s[len++]=read_ch;}s[len]=0;read_ch=10;}
template<class T>inline void Read(T &t){ReadT(t);}
template<class T,class ...Args>void Read(T &t,Args &...args){ReadT(t);Read(args...);}
template<class T>inline void WriteUInt(T x){static char out_number[25];static int cnt;out_number[cnt=1]=x%10^48;while(x/=10){out_number[++cnt]=x%10^48;}while(cnt){PutChar(out_number[cnt--]);}}
template<class T>inline void WriteInt(const T x){if(x<0){PutChar(45);WriteUInt(-x);return;}WriteUInt(x);}
template<class T>
inline void WriteUKInt(T x,const int hex,int len){static char out_number[25];static int cnt;out_number[cnt=1]=NUMBER_TO_CHAR[x%hex];while(x/=hex){out_number[++cnt]=NUMBER_TO_CHAR[x%hex];}len-=cnt;while(0<len--){PutChar(48);}while(cnt){PutChar(out_number[cnt--]);}}
template<class T>inline void WriteKInt(const T x,const int hex,const int len){if(x<0){PutChar(45);WriteUKInt(-x,hex,len-1);return;}WriteUKInt(x,hex,len);}
inline void WriteDouble(double x,int len){if(x<0){PutChar(45);x=-x;}WriteUInt<unsigned long long>((unsigned long long)x);if(len){x-=(int)x;PutChar(46);while(len--){x*=10;if(!(unsigned long long)x){PutChar(48);}}if((unsigned long long)x){WriteUInt<unsigned long long>((unsigned long long)x);}}}
inline void WriteT(const int x){WriteInt<int>(x);}
inline void WriteT(const long long x){WriteInt<long long>(x);}
inline void WriteT(const bool x){PutChar(x|48);}
inline void WriteT(const unsigned int x){WriteUInt<unsigned int>(x);}
inline void WriteT(const unsigned long long x){WriteUInt<unsigned long long>(x);}
inline void WriteT(const double x){WriteDouble(x,double_len);}
inline void WriteT(const char *s){while(*s){PutChar(*s++);}}
inline void WriteT(const char x){PutChar(x);}
inline void WriteT(const Number<int> x){WriteKInt(x.number,x.hex,x.len);}
inline void WriteT(const Number<long long> x){WriteKInt(x.number,x.hex,x.len);}
inline void WriteT(const Number<unsigned int> x){WriteUKInt(x.number,x.hex,x.len);}
inline void WriteT(const Number<unsigned long long> x){WriteUKInt(x.number,x.hex,x.len);}
template<class T>inline void Write(const T t){WriteT(t);}
template<class T,class ...Args>void Write(const T t,const Args ...args){WriteT(t);Write(args...);}
inline void Writeln(){PutChar(10);}
template<class T>inline void Writeln(const T t){WriteT(t);PutChar(10);}
template<class ...Args>inline void Writeln(const Args ...args){Write(args...);PutChar(10);}
template<class ...Args>inline void WriteExit(const Args ...args){Write(args...);PutChar(10);exit(0);}
#ifndef ONLINE_JUDGE
template<class ...Args>inline void DeBug(const Args ...args){Write(args...);}
template<class ...Args>inline void DeBugln(const Args ...args){Writeln(args...);}
inline void DeBugln(){Writeln();}
#else
template<class ...Args>inline void DeBug(const Args ...args){}
template<class ...Args>inline void DeBugln(const Args ...args){}
inline void DeBugln(){}
#endif
class CodeToDo{public:inline CodeToDo(){
#ifndef ONLINE_JUDGE
freopen("data.in","r",stdin);freopen("data.out","w",stdout);
#endif
srand(time(0));}
inline ~CodeToDo(){double_len=3;fwrite(pbuf,1,pp-pbuf,stdout);
#ifndef ONLINE_JUDGE
fclose(stdin);fclose(stdout);
#endif
}}code_to_do;
}
template<typename T>inline T Max(const T a,const T b){return a<b?b:a;}
template<typename T,typename ...Args>T Max(const T a,const Args ...args){return Max(a,Max(args...));}
template<typename T>inline T Min(const T a,const T b){return a<b?a:b;}
template<typename T,typename ...Args>T Min(const T a,const Args ...args){return Min(a,Min(args...));}
template<typename T>inline void Swap(T &a,T &b){T temp=a;a=b;b=temp;}
template<typename T>inline T Abs(const T a){return a<0?-a:a;}
using namespace IO;
using namespace std;
const int MAXN=3e5+5;
const int MAX=(1ll<<31)-1;
int n,m;
namespace TRIE
{
	class Trie
	{
	public:
		class LazyTag
		{
		public:
			int o,a,x;
			inline LazyTag():o(0),a(0),x(0)
			{
 
			}
			inline LazyTag(const int o,const int a,const int x):o(o),a(a),x(x)
			{
 
			}
			inline void Merge(const LazyTag &m)
			{
				o^=o&m.a;
				a^=a&m.o;
				int xx=(o&m.x)|(a&m.x);
				o^=xx;
				o|=m.o;
				a^=xx;
				a|=m.a;
				x^=((x&m.a)|(x&m.o))^m.x^xx;
			}
			inline void Clean()
			{
				o=a=x=0;
			}
		};
		int son[2];
		LazyTag tag;
		inline void Clean()
		{
			tag.Clean();
			son[0]=son[1]=0;
		}
	}trie[MAXN*32];
	#define SON(x) trie[now].son[x]
	int trie_cnt=0;
	int root;
	inline void Clean()
	{
		root=1;
		trie_cnt=1;
		trie[1].Clean();
	}
	inline void PushDown(const int now,const int dep);
	void Merge(int &tree1,int &tree2,const int dep)
	{
		if(!tree1||!tree2)
		{
			tree1+=tree2;
			tree2=0;
			return;
		}
		if(dep==-1)
		{
			tree2=0;
			return;
		}
		PushDown(tree1,dep);
		PushDown(tree2,dep);
		Merge(trie[tree1].son[0],trie[tree2].son[0],dep-1);
		Merge(trie[tree1].son[1],trie[tree2].son[1],dep-1);
		tree2=0;
	}
	inline void PushDown(const int now,const int dep)
	{
		if(trie[now].tag.o&(1<<dep))
		{
			Merge(SON(1),SON(0),dep-1);
		}
		if(trie[now].tag.a&(1<<dep))
		{
			Merge(SON(0),SON(1),dep-1);
		}
		if(trie[now].tag.x&(1<<dep))
		{
			Swap(SON(0),SON(1));
		}
		if(SON(0))
		{
			trie[SON(0)].tag.Merge(trie[now].tag);
		}
		if(SON(1))
		{
			trie[SON(1)].tag.Merge(trie[now].tag);
		}
		trie[now].tag.Clean();
	}
	void Insert(const int val,int &now,const int dep=30)
	{
		if(!now)
		{
			now=++trie_cnt;
			trie[now].Clean();
		}
		if(dep==-1)
		{
			return;
		}
		PushDown(now,dep);
		if(val&(1<<dep))
		{
			Insert(val,SON(1),dep-1);
		}
		else
		{
			Insert(val,SON(0),dep-1);
		}
	}
	inline void Or(const int a)
	{
		trie[root].tag.Merge(Trie::LazyTag(a,0,0));
	}
	inline void And(const int a)
	{
		trie[root].tag.Merge(Trie::LazyTag(0,MAX^a,0));
	}
	inline void Xor(const int a)
	{
		trie[root].tag.Merge(Trie::LazyTag(0,0,a));
	}
	int QueryMax(const int val,const int now,const int dep=30,const int result=0)
	{
		if(!now)
		{
			return -1;
		}
		if(dep==-1)
		{
			return result;
		}
		PushDown(now,dep);
		bool p=val&(1<<dep);
		if(SON(p^1))
		{
			return QueryMax(val,SON(p^1),dep-1,result|(1<<dep));
		}
		else
		{
			return QueryMax(val,SON(p),dep-1,result);
		}
	}
}
inline void Work()
{
	Read(n,m);
	TRIE::Clean();
	int a;
	REP(i,1,n)
	{
		Read(a);
		TRIE::Insert(a,TRIE::root);
	}
	int opt;
	REP(i,1,m)
	{
		Read(opt,a);
		if(opt==1)
		{
			TRIE::Insert(a,TRIE::root);
		}
		if(opt==2)
		{
			TRIE::Or(a);
		}
		if(opt==3)
		{
			TRIE::And(a);
		}
		if(opt==4)
		{
			TRIE::Xor(a);
		}
		if(opt==5)
		{
			Writeln(TRIE::QueryMax(a,TRIE::root));
		}
	}
}
int main()
{
	int t;
	Read(t);
	while(t--)
	{
		Work();
	}
	return 0;
}
