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
class ST{
	vector<int> st,lazy;
public:
	St(int size){
		st.resize(4*size);
		lazy.resize(4*size);
	}
}
void buildtree(int ind,int low,int high,int seg[],bool flag,int arr[]){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)>>1;
	buildtree(2*ind+1,low,mid,seg,!flag,arr);
	buildtree(2*ind+2,mid+1,high,seg,!flag,arr);
	if(flag)seg[ind]=seg[2*ind+1]|seg[2*ind+2];
	else seg[ind]=seg[2*ind+1]^seg[2*ind+2];
}
void update(int ind,int low,int high,int i,int val,int seg[],bool flag){
	if(low==high){
		seg[ind]=val;
		return;
	}
	int mid=(low+high)>>1;
	if(i<=mid)update(2*ind+1,low,mid,i,val,seg,!flag);
	else update(2*ind+2,mid+1,high,i,val,seg,!flag);
	if(flag)seg[ind]=seg[2*ind+1]|seg[2*ind+2];
	else seg[ind]=seg[2*ind+1]^seg[2*ind+2];
	
}
void solve(){
	int n,m;
	cin>>n>>m;
	int el=pow(2,n);
	int arr[el];
	for(int i=0;i<el;i++){
		cin>>arr[i];
	}
	int seg[4*el];
	bool flag;
	if(n&1){
		flag=1;
	}
	else{
		flag=0;
	}
	buildtree(0,0,el-1,seg,flag,arr);
	while(m--){
		int index,val;
		cin>>index>>val;
		index--;//1 based given
		update(0,0,el-1,index,val,seg,flag);
		arr[index]=val;
		cout<<seg[0]<<endl;
	}
}
void rangeupdate(int ind,int low,int high,int l,int r,int val){
	if(lazy[ind]!=0){
		seg[ind]+=(high-low+1)*lazy[ind];
		if(low!=high){
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}
	if(r<low||l>high||low>high){
		return;
	}
	if(low>=l&&high<=r){
		seg[ind]+=(high-low+1)*val;
		if(low!=high){
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		return;
	}
	int mid=(low+high)>>1;
	rangeupdate(2*ind+1,low,mid,l,r,val);
	rangeupdate(2*ind+2,mid+1,high,l,r,val);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int queryrange(int ind,int low,int high,int l,int r,int val){
	if(lazy[ind]!=0){
		seg[ind]+=(high-low+1)*lazy[ind];
		if(low!=high){
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}
	if(r<low||l>high||low>high)return;
	if(low>=l&&high<=r){
		return seg[ind];
	}
	int mid=(low+high)>>1;
	return queryrange(2*ind+1,low,mid,l,r,val)+queryrange(2*ind+2,mid+1,high,l,r,val);
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