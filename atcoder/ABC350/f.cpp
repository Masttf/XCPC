#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
constexpr int Max=1e18;
constexpr int maxn=5e5+5;
int ty[maxn],l[maxn],r[maxn];
string ans,s;
char cg (char x){
	if(x>='a'&&x<='z'){
		return 'A'+x-'a';
	}else return 'a'+x-'A';
}
void get2(int ll,int rr);
void get(int ll,int rr){
	for(int i=rr;i>=ll;i--){
		if(!ty[i]&&r[i]){
			get2(r[i],i);
			i=r[i];
		}else if(s[i]!='('&&s[i]!=')')ans+=cg(s[i]);
	}
}
void get2(int ll,int rr){
	for(int i=ll;i<=rr;i++){
		if(ty[i]==1&&l[i]){		
			get(i,l[i]);
			i=l[i];
		}else if(s[i]!='('&&s[i]!=')')ans+=s[i];
	}
}
void solve(){
	cin>>s;
	s=' '+s;
	int n=s.size()-1;
	vector<int>tr(n+1);
	auto add = [&](int x,int val)->void{
		while(x<=n){
			tr[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=tr[x];
			x-=lowbit(x);
		}
		return res;
	};
	vector<int>stk;
	for(int i=1;i<=n;i++){
		if(s[i]=='(')stk.push_back(i);
		else if(s[i]==')'){
			int ll=stk.back();
			stk.pop_back();
			l[ll]=i;
			r[i]=ll;
			add(ll,1);
			add(i+1,-1);
		}
	}
	for(int i=1;i<=n;i++){
		ty[i]=ask(i)%2;
	}
	for(int i=1;i<=n;i++){
		if(ty[i]==1&&l[i]){
			get(i,l[i]);
			i=l[i];
		}else if(s[i]!='('&&s[i]!=')')ans+=s[i];
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}