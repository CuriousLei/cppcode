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
void createList(LNode L,int n){
	LNode p,w;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->value;
		w=L;
		while(w->next){
			if(p->value<w->next->value){
				p->next=w->next; 
				w->next=p;
				break;
			}else{
				w=w->next;
			}
		}
		if(w->next==NULL){
			w->next=p;
		}
	}
}
void output(LNode L,int n){
	LNode p=L;
	while(n!=0){
		p=p->next;
		n--;
	}
	cout<<p->value<<endl;
}
int main(){
	LNode L;
	int n;
	cin>>n;
	while(n!=0){
		initNode(L);
		createList(L,2*n);
		output(L,n);
		cin>>n;
	}
	return 0;
}
