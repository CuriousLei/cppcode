#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int data;
}*hashTable;
void initNode(hashTable &HT){
	HT=new node;
	HT->next=NULL;
}
int hashValue(int key){
	return key%13;
}
void insert(hashTable &HT,int key){
	int v=hashValue(key);
	hashTable e=&HT[v],p;
	while(e->next){
		e=e->next;
	}
	initNode(p);
	p->data=key;
	e->next=p;
}
void deleteNode(hashTable HT,int key){
	int v=hashValue(key);
	hashTable e=&HT[v];
	hashTable p=e->next;
	while(p){
		if(p->data==key){
			e->next=p->next;
			delete p;
			p=e->next;
			continue;
		}
		e=e->next;
		p=p->next;
	}
}
int main(){
	hashTable HT,p;
	int n,i,key;
	HT=new node[13];
	while(1){
		for(i=0;i<13;i++){
			HT[i].next=NULL;
		}
		cin>>n;
		if(n==0){
			break;
		}
		for(i=0;i<n;i++){
			cin>>key;
			insert(HT,key);
		}
		cin>>key;
		deleteNode(HT,key);
		//Êä³ö
		for(i=0;i<13;i++) {
			cout<<i;
			p=HT[i].next;
			while(p){
				cout<<" "<<p->data;
				p=p->next;
			}
			cout<<endl;
		}
	}
	return 0;
}
