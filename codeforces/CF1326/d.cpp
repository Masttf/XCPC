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
const int mod=1e9+7;
const int Max=1e18;
void solve(){
	string s;cin>>s;
	int n=s.size();
	int l=-1,r=n;
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i-1])break;
		l=i,r=n-i-1;
	}
	if(l>=r){
		cout<<s<<'\n';
		return ;
	}
	string temp;
	for(int i=l+1;i<r;i++)temp+=s[i];
	//dbg(temp,l,r);
	auto manacher = [&](string &ss)->string{
		string res="^";
		for(auto x:ss){
			res+='#';
			res+=x;
		}
		res+="#$";
		int len=res.size();
		vector<int>p(len+1);
		int c=0,mxr=0;
		for(int i=1;i<len;i++){
			if(i<=mxr)p[i]=min(p[2*c-i],mxr-i+1);
			while(res[i-p[i]]==res[i+p[i]])p[i]++;
			if(i+p[i]-1>mxr){
				mxr=i+p[i]-1;
				c=i;
			}
		}
		int mx=0;
		int ps=-1;
		for(int i=1;i<len;i++){
			if(mx>=p[i]-1)continue;
			int start=(i-p[i])/2;
			int end=start+p[i]-1;
			if(start==0||end==ss.size()){
				mx=p[i]-1;
				ps=start;
			}
		}

		return ss.substr(ps,mx);
	};
	string ans="";
	for(int i=0;i<=l;i++)ans+=s[i];
	ans+=manacher(temp);
	for(int i=r;i<n;i++)ans+=s[i];
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}