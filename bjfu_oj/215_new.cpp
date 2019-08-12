#include"iostream"
#include"iomanip"
#include"string"
using namespace std;
typedef struct node{
	node *next;
	string no;
	string name;
	float price;
}*linkList;
void initNode(linkList &L){
	L=new node;
	L->next=NULL;
}
void sort(linkList L){
	linkList v,q,q0,w=NULL;
//	for(linkList w=NULL;L->next!=w;w=q){
//		for(q=L->next,q0=L;q->next!=w;q=q->next,q0=q0->next){
//			v=q->next;
//			if(q->price<=v->price){
//				q->next=v->next;
//				q0->next=v;
//				v->next=q;
//				q=v;
//			}
//		}
//	}
	while(L->next!=w){
		for(q0=L,q=L->next,v=q->next;v!=w;q0=q0->next,q=q->next,v=v->next){
			if(q->price<=v->price){
				q->next=v->next;
				q0->next=v;
				v->next=q;
				q=q0->next;
				v=q->next;
			}
		}
		w=q;
	}
}
int main(){
	linkList L,p,w;
	string no,name;
	float price;
	initNode(L);
	w=L;
	while(1){
		cin>>no>>name>>price;
		if(no=="0"&&name=="0"&&price==0){
			break;
		}
		initNode(p);
		p->no=no;
		p->name=name;
		p->price=price;
		w->next=p;
		w=p;
	} 
	sort(L);
	p=L->next;
	while(p){
		cout<<p->no<<" "<<p->name<<" "<<fixed<<setprecision(2)<<p->price<<endl;
		p=p->next;
	}
	return 0;
}
