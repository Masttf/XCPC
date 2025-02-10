#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int x,y;cin>>x>>y;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>res(n+1);
	vector<int>t1;
	vector<int>t2;
	for(int i=1;i<=n;i++){
		if(i%2==1)t1.push_back(i);
		else t2.push_back(i);
	}

	int ok=1;
	auto bfs = [&](vector<int>t,int target)->void{
		int now=0;
		int len=t.size();
		int d=(len+1)/2;
		vector<int>v1(1<<21);
		vector<int>v2(1<<21);
		map<int,int>m1;
		queue<pair<int,int>>q;
		q.push({0,0});
		int cnt=0;
		for(int i=0;i<d;i++){
			int sz=q.size();
			for(int j=1;j<=sz;j++){
				auto [k,id]=q.front();
				q.pop();
				if(i==d-1){
					m1[k+a[t[i]]]=cnt+1;
					m1[k-a[t[i]]]=cnt+2;
				}
				v1[++cnt]=id;
				v2[cnt]=k+a[t[i]];
				q.push({k+a[t[i]],cnt});
				v1[++cnt]=id;
				v2[cnt]=k-a[t[i]];
				q.push({k-a[t[i]],cnt});
			}
		}
		if(d==len){
			if(m1.count(target)){
				int now=m1[target];
				for(int i=d-1;i>=0;i--){
					int f=v1[now];
					if(v2[now]-v2[f]==a[t[i]])res[t[i]]=1;
					else res[t[i]]=-1;
					now=f;
				}
			}else ok=0;
		}else{
			vector<int>v3(1<<21);
			vector<int>v4(1<<21);
			queue<pair<int,int>>q2;
			q2.push({target,0});
			cnt=0;
			v4[0]=target;
			int now=-1;
			for(int i=len-1;i>=d;i--){
				int sz=q2.size();
				for(int j=1;j<=sz;j++){
					auto [k,id]=q2.front();
					q2.pop();
					if(i==d){
						if(m1.count(k+a[t[i]])){
							now=cnt+1;
						}else if(m1.count(k-a[t[i]])){
							now=cnt+2;
						}
					}
					v3[++cnt]=id;
					v4[cnt]=k+a[t[i]];
					q2.push({k+a[t[i]],cnt});
					v3[++cnt]=id;
					v4[cnt]=k+a[t[i]];
					q2.push({k-a[t[i]],cnt});
				}
			}
			if(now==-1)ok=0;
			else{
				for(int i=d-1;i>=0;i--){
					int f=v1[now];
					if(v2[now]-v2[f]==a[t[i]])res[t[i]]=1;
					else res[t[i]]=-1;
					now=f;
				}
			}
		}
	};

	bfs(t1,y);
	bfs(t2,x);
	if(!ok)cout<<"No\n";
	else{
		cout<<"Yes\n";
		int flag=1;
		for(int i=1;i<=n;i++){
			if(res[i]==-1){
				
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}