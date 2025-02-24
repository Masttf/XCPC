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
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<double>b(n+1);
	int sum=0;
	int mi=1;
	for(int i=1;i<=n;i++){
		cin>>a[i],sum+=a[i];
		if(a[i]<a[mi])mi=i;
	}
	auto check = [&](double x)->bool{
		for(int i=1;i<=n;i++)b[i]=a[i]-x;
		double sum1=0;
		for(int i=mi-1;i<=n;i++)sum1+=b[i];
		double sum2=0;
		for(int i=1;i<=mi+1;i++)sum2+=b[i];
		double sum3=0;
		for(int i=1;i<=n;i++)sum3+=b[i];
		return (sum1>=0||sum2>=0||sum3>=0);
	};
	double ans=0;
	double l=0,r=sum;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid;
		}else r=mid;
	}
	cout<<fixed<<setprecision(20)<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}