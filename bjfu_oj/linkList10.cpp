#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
typedef struct{
	string no;
	string name;
	float price;
}book;
typedef struct linkNode{
	linkNode *next;
	book data;	
}*LNode;
void initNode(LNode &L){
	L=new linkNode;
	L->next=NULL;
}
void createList(LNode L){
	LNode p,e;
	int n;
	cin>>n;
	e=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->data.no>>p->data.name>>p->data.price;
		e->next=p;
		e=p;
	}
}
void distinct(LNode L){
	LNode p,e,w;
	int k=0;
	p=L->next;
	while(p){
		e=p->next;
		w=p;
		while(e){
			if(e->data.no==p->data.no){
				w->next=e->next;
				delete e;
				e=w->next;
				continue;
			}
			e=e->next;
			w=w->next;
		}
		p=p->next;
		k++;
	}
	cout<<k<<endl;
}
void getList(LNode L){
	LNode p=L->next;
	while(p){
		cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;
		p=p->next;
	}
}
int main(){
	LNode L;
	initNode(L);
	createList(L);
	distinct(L);
	getList(L);
	return 0;
}
