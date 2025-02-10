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
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin()+1,b.end());
	int len=(n+k+1)/2;
	int ans=Max;
	int lx,rx;
	for(int i=1;i+len-1<=n;i++){
		if(b[i+len-1]-b[i]<ans){
			lx=b[i];
			rx=b[i+len-1];
			ans=b[i+len-1]-b[i];
		}
	}
	cout<<lx<<' '<<rx<<'\n';
	int last=1;
	for(int i=1;i<=n;i++){
		if(lx<=a[i]&&a[i]<=rx)a[i]=1;
		else a[i]=-1;
	}
	int cnt=0;
	int res=0;
	for(int i=1;i<=n;i++){
		if(cnt==k-1)break;
		res+=a[i];
		if(res==1){
			cout<<last<<' '<<i<<'\n';
			last=i+1;
			res=0;
			cnt++;
		}
	}
	cout<<last<<' '<<n<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}