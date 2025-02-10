#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int s1[maxn],s2[maxn];
priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<int>q2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>s1[i];
	for(int i=1;i<=n;i++)cin>>s2[i];
	int cur=1;
	for(int i=1;i<=m;i++){
		q2.push(s1[i]);
		q1.push(q2.top());
		q2.pop();	
		while(i==s2[cur]){
			int temp=q1.top();
			q1.pop();
			q2.push(temp);
			cout<<q2.top()<<'\n';
			cur++;
		}
	}
	return 0;
}
