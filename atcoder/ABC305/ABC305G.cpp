#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void solve(){
	int n,m;cin>>n>>m;
	vector<string>s(m);
	for(int i=0;i<m;i++)cin>>s[i];

	vector<string>res;
	vector<string>res2;
	vector<char>track;
	auto dfs = [&] (auto self,int now,int target){
		if(now==target){
			string temp="";
			for(auto x:track)temp+=x;
			res.push_back(temp);
			return ;
		}
		for(int i=0;i<2;i++){
			track.push_back((char)('a'+i));
			self(self,now+1,target);
			track.pop_back();
		}
		return ;
	};
	if(n<6){
		dfs(dfs,1,n+1);
		int ans=0;
		for(auto x:res){
			int ok=1;
			for(int i=0;i<m;i++){
				if(x.find(s[i])!=-1)ok=0;
			}
			ans+=ok;
		}
		cout<<ans<<'\n';
		return ;
	}

	dfs(dfs,1,6);
	res2=res;
	res.clear();
	dfs(dfs,1,7);

	auto get = [&](string x)->int{
		return lower_bound(res2.begin(),res2.end(),x)-res2.begin();
	};

	vector<vector<int>>tr(100,vector<int>(2));
	vector<int>e(1<<6);
	vector<int>fail(1<<6);
	int cnt=0;
	auto insert = [&](string x)->void{
		int p=0;
		for(char it:x){
			if(!tr[p][it-'a'])tr[p][it-'a']=++cnt;
			p=tr[p][it-'a'];
		}
		e[p]++;
	};

	auto bulid = [&]()->void{
		queue<int>q;
		for(int i=0;i<2;i++){
			if(tr[0][i]){
				q.push(tr[0][i]);
			}
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<2;i++){
				if(tr[u][i]){
					fail[tr[u][i]]=tr[fail[u]][i];
					q.push(tr[u][i]);
				}else tr[u][i]=tr[fail[u]][i];
			}
		}
		return ;
	};

	auto check = [&](string x)->bool{
		int p=0;
		for(char it :x){
			p=tr[p][it-'a'];
			for(int j=p;j;j=fail[j]){
				if(e[j])return false;
			}
		}
		return true;
	};

	for(int i=0;i<m;i++)insert(s[i]);
	bulid();

	vector<vector<int>>g(32,vector<int>(32));
	vector<vector<int>>t(1,vector<int>(32));
	for(int i=0;i<64;i++){
		if(check(res[i])){
			string temp1="";
			string temp2="";
			for(int j=0;j<5;j++)temp1+=res[i][j];
			for(int j=1;j<6;j++)temp2+=res[i][j];
			g[get(temp2)][get(temp1)]=1;
			t[0][get(temp2)]=1;
		}
	}
	auto mul = [&](vector<vector<int>>x,vector<vector<int>>y)->vector<vector<int>>{
		int sz=x.size();
		vector<vector<int>>temp(sz,vector<int>(32));
		for(int i=0;i<sz;i++){
			for(int j=0;j<=32;j++){
				for(int k=0;k<32;k++){
					temp[i][j]+=x[i][k]+y[k][j];
					if(temp[i][j]>=mod)temp[i][j]-=mod;
				}
			}
		}
		return temp;
	};

	auto qmi = [&](vector<vector<int>>a,int b)->vector<vector<int>>{
		vector<vector<int>>temp(32,vector<int>(32));
		for(int i=0;i<32;i++)temp[i][i]=1;
		while(b){
			if(b&1)temp=mul(temp,a);
			b>>=1;
			a=mul(a,a);
		}
		return temp;
	};
	vector<vector<int>>ans=qmi(g,n-6);

	ans=mul(t,ans);
	int kk=0;
	for(int i=0;i<32;i++)kk+=ans[0][i];
	cout<<kk<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
