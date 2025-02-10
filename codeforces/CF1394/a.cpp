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
	int n,d,m;cin>>n>>d>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>res1(1),res2(1);
	for(int i=1;i<=n;i++){
		if(a[i]>m)res1.push_back(a[i]);
		else res2.push_back(a[i]);
	}
	sort(res1.begin()+1,res1.end(),greater<int>());
	sort(res2.begin()+1,res2.end());
	vector<int>pre1(n+1),pre2(n+1);
	for(int i=1;i<res1.size();i++){
		pre1[i]=pre1[i-1]+res1[i];
	}
	for(int i=1;i<res2.size();i++){
		pre2[i]=pre2[i-1]+res2[i];
	}
	int sz1=res1.size()-1;
	int sz2=res2.size()-1;
	if(!sz1){
		cout<<pre2[n]<<'\n';
		return ;
	}
	int ans=0;
	for(int i=1;i<=sz1;i++){
		int mi=(i-1)*d;
		int mx=i*d;
		if(sz1-i>mx)continue;
		int len=0;
		if(sz1-i<mi){
			len=mi-sz1+i;
		}
		if(len>sz2)continue;//7 10
		int res=pre1[i]+pre2[sz2]-pre2[len];
		ans=max(ans,res);
		//dbg(i,ans,res);
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