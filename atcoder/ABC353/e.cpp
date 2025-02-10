#include<bits/stdc++.h>
//#define int long long
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
void solve(){
	int n;cin>>n;
	vector<string>a(n+1);
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l+=a[i].size();
		a[i]=' '+a[i];
	}
	vector tr(30,vector<int>(l+1));
	vector<int> cnt(l+1);
	vector<int> cnt2(l+1);
	int tot=1;
	auto insert = [&](string s)->void{
		int p=1;
		int len=s.size()-1;
		for(int i=1;i<=len;i++){
			if(!tr[s[i]-'a'][p]){
				tr[s[i]-'a'][p]=++tot;
			}
			p=tr[s[i]-'a'][p];
			cnt[p]++;
			//dbg(s,i,p,cnt[p]);
		}
		cnt2[p]++;
	};
	auto ask = [&](string s)->long long{
		long long res=0;
		int p=1;
		int len=s.size()-1;
		for(int i=1;i<=len;i++){
			int sum=0;
			int target = s[i]-'a';
			for(int j=0;j<26;j++){
				if(j==target)continue;
				sum+=cnt[tr[j][p]];
			}
			//dbg(s,i,sum);
			res+=1ll*(i-1)*sum;
			p=tr[target][p];
			res+=1ll*i*cnt2[p];
		}
		res+=1ll*len*(cnt[p]-cnt2[p]);
		//dbg(res);
		return res;
	};
	long long ans=0;
	for(int i=n;i>=1;i--){
		//dbg(i);
		ans+=ask(a[i]);
		insert(a[i]);
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