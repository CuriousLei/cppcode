#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
typedef struct{
	string no;
	string name;
	float price;
}book;
typedef struct node{
	book data;
	node *next;
}*linkList;
void initNode(linkList &L){
	L=new node;
	L->next=NULL;
}
void createList(linkList &L){
	int n;
	linkList p,w=L;
	cin>>n;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->data.no>>p->data.name>>p->data.price;
		w->next=p;
		w=w->next;
	}
} 
void deduplicate(linkList L){
	linkList p,w,w0;
	p=L->next;
	while(p->next){
		w0=p;
		w=p->next;
		while(w){
			if(w->data.no==p->data.no&&w->data.name==p->data.name&&w->data.price==p->data.price){
				w0->next=w->next;
				delete w;
				w=w0->next;
			}
			w=w->next;
			w0=w0->next;
		}
		p=p->next;
	}
}
void output(linkList L){
	int k=0;
	linkList p=L->next;
	while(p){
		p=p->next;
		k++;
	} 
	cout<<k<<endl;
	p=L->next;
	while(p){
		cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;
		p=p->next;
	} 
}
int main(){
	linkList L;
	initNode(L);
	createList(L);
	deduplicate(L);
	output(L);
	return 0;
	
}
