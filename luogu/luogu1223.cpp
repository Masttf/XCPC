#include<bits/stdc++.h>
using namespace std;
struct n{
	int x;
	int y;
}s[1005];
bool cmp(n a,n b){
	return a.x<b.x;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].x;
		s[i].y=i;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<n;i++){
		cout<<s[i].y<<' ';
	}
	cout<<s[n].y<<'\n';
	double sum=0;
	for(int i=1;i<=n;i++){
		sum+=s[i].x*(n-i);
	}
	printf("%.2f",sum/n);
	return 0;
}
