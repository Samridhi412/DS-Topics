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
void rearrange(vector<int>& arr,int n){
	int j=1;
	int temp=arr[0];
	while(j<n&&arr[j]<temp){
		arr[j-1]=arr[j];
		j++;
	}
	j--;
	arr[j]=temp;
}
void merge_arrays(vector<int>& arr1,vector<int>& arr2,int n,int m){
	int i=0;
	while(i<n){
		if(arr1[i]>arr2[0]){
			swap(arr1[i],arr2[0]);
			rearrange(arr2,m);
		}
		i++;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// int n,m;
	// cin>>n>>m;
	// vector<int> arr1(n),arr2(m);
	// for(int i=0;i<n;i++){
	// 	cin>>arr1[i];
	// }
	// for(int j=0;j<m;j++){
	// 	cin>>arr2[j];
	// }
	// merge_arrays(arr1,arr2,n,m);
	// cout<<"output:"<<endl;
	// for(auto x:arr1){
	// 	cout<<x<<" ";
	// }
	// cout<<endl;
	// for(auto y:arr2){
	// 	cout<<y<<" ";
	// }
	// cout<<endl;
	set<vector<int>> s;
	cout<<"*********///////////////********"<<endl;
	s.insert({1,2,3,4,5,6});
	s.insert({3,5,2,1,4});
	cout<<s.size()<<" ";
	return 0;
}