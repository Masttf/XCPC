#include<bits/stdc++.h>
using namespace std;
struct milk{
	int x;
	int y;
}s[500000];
bool cmp(milk x,milk y){
	return x.x<y.x;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i].x>>s[i].y;
	}
	sort(s+1,s+m+1,cmp);
	int sum=0;
	for(int i=1;i<=m;i++){
		if(n>=s[i].y){
			sum+=s[i].x*s[i].y;
			n-=s[i].y;
		}else{
			sum+=s[i].x*n;
			break;
		}
	}
	cout<<sum;
	return 0;
}
