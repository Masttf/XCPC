#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[100005];
int find(int x,int n){
	int left=1,right=n;//构建闭区间
	while(left<=right){
		int mid=left+(right-left)/2;
		if(a[mid]>x){
			right=mid-1;
		}else if(a[mid]<x){
			left=mid+1;
		}else if(a[mid]==x){
			right=mid-1;
		}
	}
	if(a[left]==x)return b[left];
	else return -1;
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	int x;
	for(int i=1;i<=m;i++){
		cin>>x;
		cout<<find(x,n);
	}
	return 0;
}
