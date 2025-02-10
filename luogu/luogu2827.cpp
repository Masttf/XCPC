#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int res[maxn];
priority_queue<int> q2;
queue<int> v1,v2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,q,t;
	double u,v;
	cin>>n>>m>>q>>u>>v>>t;
	double p=u/v;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		q2.push(x);
	}
	int delat=0;//维护队列中的数加上这个长度就是正常的长度
	for(int i=1;i<=m;i++){
		int temp = -999999999;
		int w;
		if (q2.size() && temp < q2.top()) {
			temp = q2.top();
			w = 0;
		}
		if (v1.size() && temp < v1.front()) {
			temp = v1.front();
			w = 1;
		}
		if (v2.size() && temp < v2.front()) {
			temp = v2.front();
			w = 2;
		}
		if (w == 1) v1.pop();
		else if (w == 2) v2.pop();
		else q2.pop();
		temp+=delat;
		int a1=temp*p,a2=temp-a1;
		a1-=delat,a2-=delat;//再入队要维护这个定义所以要减去这个数
		a1-=q,a2-=q;//同时这个两个数没有加所以再减去
		v1.push(a1);v2.push(a2);
		if(i%t==0)cout<<temp<<' ';
		delat+=q;
	}
	cout<<'\n';
	for(int i=1;i<=n+m;i++){
		int temp = -999999999;
		int w;
		if (q2.size() && temp < q2.top()) {
			temp = q2.top();
			w = 0;
		}
		if (v1.size() && temp < v1.front()) {
			temp = v1.front();
			w = 1;
		}
		if (v2.size() && temp < v2.front()) {
			temp = v2.front();
			w = 2;
		}
		if (w == 1) v1.pop();
		else if (w == 2) v2.pop();
		else q2.pop();
		if(i%t==0)cout<<temp+delat<<' ';
	}
	return 0;
}
