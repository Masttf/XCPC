#include <bits/stdc++.h>
#define int long long
using namespace std;
int res[200005];
vector<vector<int>> cnct(200005);
int ans[200005];
int d[200005];
int pre[200005];
queue<int>q;
int cnt=1;
int n;
int sum;
bool cmp(int x,int y){
	return res[x]<res[y];
}
void bfs(int x){
	q.push(x);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			int temp=q.front();q.pop();
			for(int i=0;i<cnct[temp].size();i++){
				if(!ans[cnct[temp][i]]&&cnct[temp][i]!=1){
					q.push(cnct[temp][i]);
					ans[cnct[temp][i]]=cnt;
				}
			}
		}
		cnt++;
	}
}
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		d[i]=i;
	}
	int x,y;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		cnct[x].push_back(y);
		cnct[y].push_back(x);
	}
	bfs(1);
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+res[d[i]];
	}
	for(int i=1;i<=n;i++){
		sum+=ans[d[i]]*((i-1)*(res[d[i]])+pre[n]-pre[i]);
		sum%=1000000007;
	}
	cout<<sum;
	return 0;
}
