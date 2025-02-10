//本题会有困难的地方如何放入新的关系，
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
char res[maxn];
bool vis[maxn];
struct node{
	int val,x,y;
	bool operator <(const node y)const{
		if(val!=y.val) return val>y.val;
		else return x>y.x;
	}
};
priority_queue<node>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		if(res[i]=='B')cnt++;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	int c=min(cnt,n-cnt);
	cout<<c<<'\n';
	for(int i=1;i<n;i++){
		if(res[i]!=res[i+1]){
			node temp;
			temp.val=abs(a[i]-a[i+1]);
			temp.x=i;
			temp.y=i+1;
			q.push(temp);
		}
	}
	for(int i=1;i<=c;i++){
		while(vis[q.top().x]||vis[q.top().y])q.pop();
		node temp=q.top();
		vis[temp.x]=1;
		vis[temp.y]=1;
		q.pop();
		cout<<temp.x<<' '<<temp.y<<'\n';
		int p=temp.x,q2=temp.y;
		while(p>=1&&vis[p])p--;
		while(q2<=n&&vis[q2])q2++;
		if(p>=1&&q2<=n&&res[p]!=res[q2]){
			node t;
			t.val=abs(a[p]-a[q2]);
			t.x=p,t.y=q2;
			q.push(t);
		}
	}
	return 0;
}
