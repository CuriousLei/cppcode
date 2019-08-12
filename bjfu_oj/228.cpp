#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int c;
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void createList(int m,int n,LNode L1,LNode L2){
	LNode p,e;
	e=L1;
	for(int i=0;i<m;i++){
		initNode(p);
		cin>>p->c;
		e->next=p;
		e=p;
	}
	e=L2;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->c;
		e->next=p;
		e=p;
	}
}
int operate(LNode L1,LNode L2,LNode L3){
	LNode p,p0,q,end;
	
	int i=0;
	p=L1->next;
	p0=L1;
	end=L3;
	while(p){
		q=L2->next;
		while(q){
			if(q->c==p->c){
				break;
			}
			q=q->next;
		}
		if(q==NULL){
			p0->next=p->next;
			p->next=end->next;
			end->next=p;
			end=p;
			i++;
			p=p0->next;
			continue;
		}
		p=p->next;
		p0=p0->next;
	}
	return i;
}
void getList(LNode L){
	LNode p=L->next;
	while(p){
		cout<<p->c;
		p=p->next;
		if(p==NULL){
			cout<<endl;
		}else{
			cout<<" ";
		}	
	}
}
int main(){
	LNode L1,L2,L3;
	initNode(L1);
	initNode(L2);
	
	int m,n;
	cin>>m>>n;
	while(n!=0||m!=0){
		initNode(L3);
		createList(m,n,L1,L2);
		int i=operate(L1,L2,L3);
		getList(L3);
		cout<<i<<endl;
		cin>>m>>n;
	}
	return 0;
}
