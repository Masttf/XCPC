#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=100005;
int n,m;
int school[MAX];
int find(int target){
	int left=1,right=m;
	while(left<=right){
		int mid=(left+right)>>1;
		if(school[mid]==target){
			left=mid;
			break;
		}
		else if(school[mid]<target)left=mid+1;
		else if(school[mid]>target)right=mid-1;
	}
	if(left>m)return abs(school[right]-target);
	else if(right<1) return abs(school[left]-target);
	else return min(abs(school[left]-target),abs(school[right]-target));
}
signed main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>school[i];
	}
	sort(school+1,school+1+m);
	int sum=0;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		sum+=find(x);
	}
	cout<<sum;
	return 0;
}
