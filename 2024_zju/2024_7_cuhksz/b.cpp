#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int maxn=1e6+5;
int vis[maxn];
vector<int>prim;
void init(){
	vis[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i])prim.push_back(i);
		for(int j=0;prim[j]*i<maxn;j++){
			vis[prim[j]*i]=1;
			if(i%prim[j]==0)break;
		}
	}
}
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
void solve(){
	int n,k;cin>>n>>k;
	if(n==1){
		cout<<"Bob\n";
		return ;
	}
	if(k==1){
		cout<<"Alice\n";
		return ;
	}
	int ok=0;
	for(auto x:prim){
		int d=qmi(x,k);
		//dbg(d);
		if(d>n)break;
		if(n%d==0){
			ok=1;
			break;
		}
	}
	if(!ok){
		cout<<"Bob\n";
		return ;
	}else{
		cout<<"Alice\n";
		return ;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}