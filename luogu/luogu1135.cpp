#include<bits/stdc++.h>
using namespace std;
int n;
int res[205];
bool vis[205];
queue<int>q;
int bfs(int a,int b){
	int cnt=0;
	if(a==b) return 0;
	q.push(a);
	int flag=1;
	while(!q.empty()){
		if(!flag)break;
		int sz=q.size();
		for(int i=1;i<=sz;i++){
			int temp=q.front();
			q.pop();
			if(temp-res[temp]>0&&!vis[temp-res[temp]])q.push(temp-res[temp]),vis[temp-res[temp]]=1;
			if(temp+res[temp]<=n&&!vis[temp+res[temp]])q.push(temp+res[temp]),vis[temp+res[temp]]=1;
			if(temp-res[temp]==b||temp+res[temp]==b)flag=0;
		}
		cnt++;
	}
	if(flag)return -1;
	else return cnt;
}
int main(){
	int a,b;cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	vis[a]=1;
	cout<<bfs(a,b);
	return 0;
}
