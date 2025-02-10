#include<bits/stdc++.h>
using namespace std;
struct apple{
	int st;
	int hg;
}m[5005];
bool cmp(apple x,apple y){
	return x.st<y.st;
}
int main(){
	int n,s;
	cin>>n>>s;
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>m[i].hg>>m[i].st;
	}
	sort(m+1,m+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a+b>=m[i].hg){
			if(s>=m[i].st){
				ans++;
				s-=m[i].st;
			}
		}
	}
	cout<<ans;
	return 0;
}
