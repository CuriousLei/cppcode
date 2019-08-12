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
int main(){
	LNode A,B,C,p,e,b,c;
	int n;
	cin>>n;
	while(n!=0){
		initNode(A);
		initNode(B);
		initNode(C);
		e=A;
		for(int i=0;i<n;i++){
			initNode(p);
			cin>>p->c;
			e->next=p;
			e=p;
		}
		p=A->next;
		b=B;
		c=C;
		while(p){
			if(p->c<0){
				A->next=p->next;
				p->next=b->next;
				b->next=p;
				b=p;
				p=A->next;
			}else{
				A->next=p->next;
				p->next=c->next;
				c->next=p;
				c=p;
				p=A->next;
			}
		}
		b=B->next;
		c=C->next;
		while(b){
			cout<<b->c;
			b=b->next;
			if(b==NULL){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
		while(c){
			cout<<c->c;
			c=c->next;
			if(c==NULL){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
		cin>>n;
	}
	return 0;
}
