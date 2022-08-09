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
int kadane(vector<int>& arr,int n){
	int csum=arr[0];
	int msum=arr[0];
	for(int i=1;i<n;i++){
		csum+=arr[i];
		if(csum<0){
			csum=0;
		}
		if(csum>msum){
			msum=csum;
		}
	}
	return msum;
}
int kadaneof2(vector<int>& arr,int n){
	cout<<"here";
	vector<int> a(n*2);
	for(int i=0;i<n;i++){
		a[i]=arr[i];
	}
	for(int i=0;i<n;i++){
		a[i+n]=arr[i];
	}
	for(auto x:a){
		cout<<x<<" ";
	}
	cout<<endl;
	return kadane(a,2*n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<int> arr(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	if(k==1)cout<< kadane(arr,n);
	else if(sum<0)cout<< kadaneof2(arr,n);
	else cout<<kadaneof2(arr,n)+(k-2)*sum;
	return 0;
}