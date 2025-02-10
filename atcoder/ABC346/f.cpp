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
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	string t;cin>>t;
	int len=s.size();
	s=' '+s;
	vector pre(30,vector<int>(len+1));
	for(int i=1;i<=len;i++){
		for(int j=0;j<26;j++)pre[j][i]=pre[j][i-1];
		pre[s[i]-'a'][i]++;
	}
	auto check = [&](int k)->bool{
		__int128 res=0;
		int last=-1;
		auto get = [&](int nw,int target)->void{
			int d=pre[nw][len];
			int dd=target/d;
			int kk=target-d*dd;
			res+=dd;
			if(kk==0){
				int kk=target-d*(dd-1);
				int l=1,r=len;
				int ans=1;
				while(l<=r){
					int mid=(l+r)>>1;
					int cnt=pre[nw][mid];
					if(cnt>=kk){
						r=mid-1;
						ans=mid;
					}else l=mid+1;
				}
				last=ans+1;
				if(ans==len)last=-1;
			}else{
				res++;
				int l=1,r=len;
				int ans=1;
				while(l<=r){
					int mid=(l+r)>>1;
					int cnt=pre[nw][mid];
					if(cnt>=kk){
						r=mid-1;
						ans=mid;
					}else l=mid+1;
				}
				last=ans+1;
				if(ans==len)last=-1;
			}
		};
		for(auto x:t){
			int nw=x-'a';
			int ddd=pre[nw][len];
			if(ddd==0)return false;
			if(last==-1){
				get(nw,k);
			}else{
				int d=pre[nw][len]-pre[nw][last-1];
				if(k<=d){
					int l=last,r=len;
					int ans=last;
					while(l<=r){
						int mid=(l+r)>>1;
						int cnt=pre[nw][mid]-pre[nw][last-1];
						if(cnt>=k){
							r=mid-1;
							ans=mid;
						}else l=mid+1;
					}
					last=ans+1;
					if(ans==len)last=-1;
				}else{
					int kk=k-d;
					get(nw,kk);
				}
			}
		}
		return res<=n;
	};
	int l=0,r=1e17;
	int d=1e17;
	assert(r<=d);
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
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