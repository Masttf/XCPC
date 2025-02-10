#include<bits/stdc++.h>
#define int long long
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
const int maxn=1e6;
void solve(){
	int n;cin>>n;
	int ans=1;
	vector<int>res(20);
	for(int i=1;i<=maxn;i++){
		int d=i*i*i;
		if(d>n)break;
		int len=0;
		while(d){
			res[len]=d%10;
			d/=10;
			len++;
		}
		len--;
		int ok=1;
		for(int j=0;j<=len;j++){
			if(res[j]!=res[len-j])ok=0;
		}
		if(ok)ans=i;
	}
	ans=ans*ans*ans;
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
//123456789012345
//1334996994331