#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,x,y;
}res[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i].a>>res[i].b>>res[i].x>>res[i].y;
	int dx,dy;cin>>dx>>dy;
	for(int i=n;i>=1;i--){
		int tx=res[i].a+res[i].x;
		int ty=res[i].b+res[i].y;
		if(dx>=res[i].a&&dx<=tx&&dy>=res[i].b&&dy<=ty){
			cout<<i;
			break;
		}
	}
	return 0;
}
