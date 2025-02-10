#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	vector<string> a(5);
	vector<vector<int>> nt(5);
	for(int i=1;i<=3;i++){
		cin>>a[i];
		a[i]=' '+a[i];
		int len=a[i].size();
		nt[i].assign(len+1,0);
	}

	auto get_nt = [&](int t)->void{
		int n=a[t].size()-1;
		for(int i=2,j=0;i<=n;i++){
			while(j&&a[t][i]!=a[t][j+1])j=nt[t][j];
			if(a[t][i]==a[t][j+1])j++;
			nt[t][i]=j;
		}
	};
	for(int i=1;i<=3;i++)get_nt(i);

	auto check = [&](int x,int y)->bool{
		if(a[x].size()<a[y].size())swap(x,y);
		int n=a[x].size()-1;
		int m=a[y].size()-1;
		for(int i=1,j=0;i<=n;i++){
			while(j&&a[x][i]!=a[y][j+1])j=nt[y][j];
			if(a[x][i]==a[y][j+1])j++;
			if(j==m)return true;
		}
		return false;
	};
	vector<int>res(1,0);
	vector<int>vis(5);
	for(int i=1;i<=3;i++){
		for(int j=i+1;j<=3;j++){
			if(check(i,j)){
				if(a[i].size()>a[j].size())vis[j]=1;
				else vis[i]=1;
			}
		}
	}
	for(int i=1;i<=3;i++){
		if(!vis[i])res.push_back(i);
	}

	int ans=0;
	int sz=res.size();
	for(int i=1;i<sz;i++){
		ans+=a[res[i]].size()-1;
	}
	//dbg(ans,res.size());
	vector<int>track;
	vis.assign(5,0);
	auto gg = [&](int x,int y)->int{
		int n=a[x].size()-1;
		int m=a[y].size()-1;
		int j=0;
		for(int i=1;i<=n;i++){
			while(j&&a[x][i]!=a[y][j+1])j=nt[y][j];
			if(a[x][i]==a[y][j+1])j++;
		}
		return j;
	};
	auto get = [&]()->void{
		int n=track.size()-1;
		int cnt=0;
		cnt=a[track[0]].size()-1;
		for(int i=1;i<=n;i++){
			int x=track[i];
			int y=track[i-1];
			
			cnt+=a[x].size()-1;
			cnt-=gg(y,x);
		}
		ans=min(ans,cnt);
	};
	auto dfs = [&](auto self,int now)->void{
		if(now==res.size()){
			get();
			return ;
		}
		for(int i=1;i<res.size();i++){
			if(vis[i])continue;
			vis[i]=1;
			track.push_back(res[i]);
			self(self,now+1);
			track.pop_back();
			vis[i]=0;
		}
	};
	dfs(dfs,1);
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