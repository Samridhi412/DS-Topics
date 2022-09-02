#include<iostream>
using namespace std;
struct node{
	node* links[26];
	int countprefix=0;
	int endwith=0;
	bool containsKey(char ch){
		return (links[ch-'a']!=NULL);
	}
	node* get(char ch){
		return links[ch-'a'];
	}
	void put(char ch,node* nn){
		links[ch-'a']=nn;
	}
	void increaseprefix(){
		countprefix++;
	}
	void increaseend(){
		endwith++;
	}
	void reduceprefix(){
		countprefix--;
	}
	void reduceend(){
		endwith--;
	}
	int getEnd(){
		return endwith;
	}
	int getPrefix(){
		return countprefix;
	}
};
class Trie{
	node* root;
public:
	Trie(){
		root=new node();
	}
	void insert(string word){
			node* nn=root;
			for(int i=0;i<word.size();i++){
				if(!nn->containsKey(word[i])){
					nn->put(word[i],new node());
				}
				nn=nn->get(word[i]);
				nn->increaseprefix();
			}
			nn->increaseend();
		}
	int endswith(string word){
		node* nn=root;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				return 0;
			}
			nn=nn->get(word[i]);
		}
		return nn->getEnd();
	}	
	int startswith(string word){
		node* nn=root;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				return 0;
			}
			nn=nn->get(word[i]);
		}
		return nn->getPrefix();
	}
	void erase(string word){
		node* nn=root;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				return;
			}
			nn=nn->get(word[i]);
			nn->reduceprefix();
		}
		// nn->reduceprefix();
		nn->reduceend();
	}
};