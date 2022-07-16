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
void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sum;
	cin>>sum;
	int window_size=0;
	//*****************POSITIVE INTEGERS*************//
	// int i=0;
	// int j=0;
	int ans=0;
	// while(j<n){
	// 	ans+=arr[j];
	// 	if(ans<sum){
	// 		j++;
	// 	}
	// 	else if(ans==sum){
	// 		window_size=max(window_size,j-i+1);
	// 		j++;
	// 	}
	// 	else{
	// 		while(ans>sum){
	// 			ans-=arr[i];
	// 			i++;
	// 		}
	// 		if(ans==sum){
	// 		window_size=max(window_size,j-i+1);	
	// 		}
	// 		j++;
	// 	}
	// }
	//***********NEGATIVE INTEGERS*************//
	unordered_map<int,int> mpp;
	ans=0;
	for(int i=0;i<n;i++){
		ans+=arr[i];
		if(ans==sum){
			window_size=i+1;
		}
		else if(mpp.find(ans)==mpp.end()){
			mpp[ans]=i;
		}
		if(mpp.find(ans-sum)!=mpp.end()){
			window_size=max(window_size,i-mpp[ans-sum]);
		}
	}
	cout<<window_size<<endl;
	}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}