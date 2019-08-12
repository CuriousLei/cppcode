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
void insert(node HT[],int key){
	hashTable p,e;
	e=&HT[hashValue(key)];
	while(e->next){
		e=e->next;
	}
	initNode(p);
	p->data=key;
	e->next=p;
}
int main(){
	int n,i,key,k;
	hashTable HT=new node[13],p;
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
		cin>>k;
		insert(HT,k);
		//Êä³ö
		for(i=0;i<13;i++){
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
