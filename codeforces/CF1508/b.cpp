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
const int Max=1e18;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)a[i]=i;
	vector<int>p;
	int temp=k-1;
	while(temp){
		p.push_back(temp%2);
		temp/=2;
	}
	int sz=p.size();
	int nw=n;
	for(int i=0;i<sz;i++){
		int j=i;
		while(j<sz&&p[j]==1)j++;
		int len=j-i+1;
		int l=nw-len+1,r=nw;
		if(l<1){
			cout<<-1<<'\n';
			return ;
		}
		//dbg(len,l,r);
		for(int j=1;j<=len/2;j++,l++,r--){
			swap(a[l],a[r]);
		}
		nw-=len;
		i=j;
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}