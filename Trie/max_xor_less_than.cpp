#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	node* links[2];
	bool containsKey(int bit){
		return (links[bit]!=NULL);
	}
	void put(int bit,node* nn){
		links[bit]=nn;
	}
	node* get(int bit){
		return links[bit];
	}
};
class Trie{
	node* root;
public:
	Trie(){
		root=new node();
	}
	void insert(int num){
		node* nn=root;
		for(int i=31;i>=0;i--){
			int mask=(1<<i);
			int bit=num&mask;
			if(!nn->containsKey(bit)){
				nn->put(bit,new node());
			}
			nn=nn->get(bit);
		}
	}
	int get_max(int num){
		node* nn=root;
		int ans=0;
		for(int i=31;i>=0;i--){
			int mask=(1<<i);
			int bit=num&mask;
			if(nn->containsKey(1-bit)){
				ans|=mask;
				nn=nn->get(1-bit);
			}
			else{
				nn=nn->get(bit);
			}
		}
		return ans;
	}
};
int main(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	int q;
	cin>>q;
	vector<pair<int,int>> queries(q);
	for(int i=0;i<q;i++){
		cin>>queries[i].first;
		cin>>queries[i].second;
	}
	vector<vector<int>> q2(q);
	for(int i=0;i<q;i++){
		q2.push_back({queries[i].second,queries[i].first,i});
	}
	sort(q2.begin(),q2.end());
	int j=0;
	Trie tt;
	vector<int> final_ans(q);
	for(int i=0;i<q;i++){
		while(j<n&&nums[j]<=q2[i][0]){
			tt.insert(nums[j]);
			j++;
		}
		if(j==0)final_ans[q2[i][2]]=-1;
		else
		{int result=tt.get_max(q2[i][1]);
				final_ans[q2[i][2]]=result;}
	}
	for(auto x:final_ans){
		cout<<x<<" ";
	}
	
	
	return 0;
}