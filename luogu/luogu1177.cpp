#include<iostream>
using namespace std;
int n,a[1000001];
void qsort(int l,int r)
{
	int mid=a[(l+r)/2];
	int i=l,j=r;
	do{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
