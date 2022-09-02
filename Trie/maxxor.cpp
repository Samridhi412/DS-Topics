#include<iostream>
using namespace std;
struct node{
	node* links[2];
	bool containsKey(int bit){
		return links[bit]!=NULL;
	}
	node* get(int bit){
		return links[bit];
	}
	void put(int bit,node* nn){
		links[bit]=nn;
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
	int find_max(int num){
		node* nn=root;
		int maxxor=0;
		for(int i=31;i>=0;i--){
			int mask=(1<<i);
			int bit=num&mask;
			if(nn->containsKey(!bit)){
				maxxor|=mask;
				nn=nn->get(!bit);
			}
			else{
				nn=nn->get(bit);
			}
		}
		return maxxor;
	}
};
