#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
typedef struct{
	string no;
	string name;
	float price;
}book;
typedef struct LNode{
	book item;
	LNode *next;
}*linkNode;
void initNode(linkNode &L){
	L=new LNode;
	L->next=NULL;
}
void createNode(linkNode L){
	linkNode p,node;
	string no,name;
	float price;
	p=L;
	cin>>no>>name>>price;
	while(no!="0"||name!="0"||price!=0){
		initNode(node);
		node->item.no=no;
		node->item.name=name;
		node->item.price=price;
		p->next=node;
		p=p->next;
		cin>>no>>name>>price;
	}
}
void sort(linkNode L){
	linkNode a,b,c,end,temp;
	end=NULL;
	while(L->next!=end){
		//cout<<L->next->item.no<<endl;
		for(a=L,b=a->next,c=b->next;c!=end;a=a->next,b=b->next,c=c->next){
			if(b->item.price<=c->item.price){
				b->next=c->next;
				a->next=c;
				c->next=b;
				temp=c;
				c=b;
				b=temp;
			}
		}
		end=b;
		//cout<<end->item.no<<endl<<endl;
	}
}
void getLinkList(linkNode L){
	linkNode p;
	p=L->next;
	while(p){
		cout<<p->item.no<<" "<<p->item.name<<" "<<fixed<<setprecision(2)<<p->item.price<<endl;
		p=p->next;
	}
}
int main(){
	linkNode L;
	initNode(L);
	createNode(L);
	sort(L);
	getLinkList(L);
	return 0;
}
