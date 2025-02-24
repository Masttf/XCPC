#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,m,k;cin>>n>>m>>k;
	string s;cin>>s;
	int len=s.size();
	s=' '+s;
	int u=1,d=n,l=1,r=m;
	int mu=1,md=n,ml=1,mr=m;
	for(int i=1;i<=len;i++){
		if(s[i]=='U'){
			if(u==1)mu++;
			else u--;
			d--;
		}else if(s[i]=='D'){
			if(d==n)md--;
			else d++;
			u++;
		}else if(s[i]=='L'){
			if(l==1)ml++;
			else l--;
			r--;
		}else{
			if(r==m)mr--;
			else r++;
			l++;
		}
	}
	//dbg(ml,mr,mu,md);
	if(ml>mr||mu>md){
		if(k==0)cout<<n*m<<'\n';
		else cout<<0<<'\n';
		return ;
	}
	if((mr-ml+1)*(md-mu+1)<k){
		cout<<0<<'\n';
	}else{
		set<pair<int,int>>res;
		int ni=0,nj=0;
		res.insert({ni,nj});
		for(int i=1;i<=len;i++){
			if(s[i]=='U'){
				ni++;
			}else if(s[i]=='D'){
				ni--;
			}else if(s[i]=='L'){
				nj++;
			}else{
				nj--;
			}
			res.insert({ni,nj});
		}
		//dbg(res.size());
		vector<vector<int>>cnt(n+5,vector<int>(m+5));
		auto add = [&](int lx,int ly,int rx,int ry)->void{
			cnt[lx][ly]++;
			cnt[rx+1][ly]--;
			cnt[lx][ry+1]--;
			cnt[rx+1][ry+1]++;
		};
		for(auto [i,j]:res){
			int llx=max(1ll,mu-i);
			int rrx=min(n,md-i);
			int lly=max(1ll,ml-j);
			int rry=min(m,mr-j);
			if(llx>rrx||lly>rry)continue;
			//dbg(i,j);
			//dbg(llx,lly,rrx,rry);
			add(llx,lly,rrx,rry);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
		}

		int tot=(mr-ml+1)*(md-mu+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(cnt[i][j]==tot-k)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}