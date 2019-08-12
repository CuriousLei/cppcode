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
	book item;
	node *next;
}*linkList;
void initNode(linkList &L){
	L=new node;
	L->next=NULL;
}
int main(){
	linkList L,p,w;
	string no,name;
	float price;
	int k=0;
	initNode(L);
	w=L;
	while(1){
		cin>>no>>name>>price;
		if(no=="0"&&name=="0"&&price==0){
			break;
		}
		initNode(p);
		p->item.no=no;
		p->item.name=name;
		p->item.price=price;
		w->next=p;
		w=w->next;
		k++;
	}
	cout<<k<<endl;
	p=L->next;
	while(p){
		cout<<p->item.no<<" "<<p->item.name<<" "<<fixed<<setprecision(2)<<p->item.price<<endl;
		p=p->next;
	}
	return 0;
}
