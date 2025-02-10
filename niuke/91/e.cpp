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
constexpr int mod=1e9+7;
string res1="ACCEPT";
string res2="WA";
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	s=' '+s;
	vector p(26,vector<int>());
	for(int i=1;i<=n;i++){
		p[s[i]-'A'].push_back(i);
	}
	auto check1 = [&](int l,int r)->bool{
		int now=l;
		//dbg(l,r);
		for(auto x:res1){
			int d=lower_bound(p[x-'A'].begin(),p[x-'A'].end(),now)-p[x-'A'].begin();
			//dbg(d);
			if(d==p[x-'A'].size())return false;
			d=p[x-'A'][d];
			//dbg(x,d);
			if(d>r)return false;
			now=d+1;

		}
		return true;
	};
	auto check2 = [&](int l,int r)->bool{
		int now=l;
		for(auto x:res2){
			int d=lower_bound(p[x-'A'].begin(),p[x-'A'].end(),now)-p[x-'A'].begin();
			if(d==p[x-'A'].size())return false;
			d=p[x-'A'][d];
			if(d>r)return false;
			now=d+1;
		}
		return true;
	};
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i+res1.size()-1,r=n;
		int la=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check1(i,mid)){
				r=mid-1;
				la=mid;
			}else l=mid+1;
		}
		la=max(la,i+k-1);
		l=i+k-1,r=n;
		int lb=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check2(i,mid)){
				r=mid-1;
				lb=mid;
			}else l=mid+1;
		}
		ans+=max(0ll,lb-la);
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