#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
int merge(int* arr,int low,int mid,int high){
	int i=low,j=mid+1;
	int cnt=0;
	int temp[high-low+1];
	int k=low;
	while(i<=mid&&j<=high){
		if(arr[i]>arr[j]){
			temp[k++]=arr[j];
			cnt+=(mid-i+1);
			j++;
		}
		else{
			temp[k++]=arr[i];
			i++;
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=high){
		temp[k++]=arr[j++];
	}
	for(int i=low;i<=high;i++){
		arr[i]=temp[i];
	}
	return cnt;
}
int mergesort(int* arr,int low,int high){
	int count=0;
	if(low<high){
		int mid=(low+high)>>1;
		count+=mergesort(arr,low,mid);
		count+=mergesort(arr,mid+1,high);
		count+=merge(arr,low,mid,high);
		// return l+r+val;
	}
	return count;
}
void solve(){
	ll n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<mergesort(arr,0,n-1)<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}