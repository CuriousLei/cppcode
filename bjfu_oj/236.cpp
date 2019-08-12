#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int value;
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
int Abs(int x){
	return x>0?x:-x;
}
void createList(LNode L,int n){
	LNode p,e;
	int m=0;
	e=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->value;
		e->next=p;
		e=p;
		if(m<Abs(p->value)){
			m=Abs(p->value);
		}
	}
	L->value=m;
}
void deleteNode(LNode L){
	LNode p,e;
	int *item;
	item=new int[L->value+1];
	for(int i=0;i<L->value+1;i++){
		item[i]=0;
	}
	p=L;
	while(p->next){
		if(item[Abs(p->next->value)]){
			e=p->next;
			p->next=e->next;
			delete e;
		}else{
			item[Abs(p->next->value)]=1;
			p=p->next;
		}
	} 
}
void output(LNode L){
	LNode p;
	p=L->next;
	while(p){
		cout<<p->value;
		p=p->next;
		if(p==NULL){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	LNode L;
	int n;
	cin>>n;
	while(n!=0){
		initNode(L);
		createList(L,n);
		deleteNode(L);
		output(L);
		cin>>n;
	}
	return 0;
}
