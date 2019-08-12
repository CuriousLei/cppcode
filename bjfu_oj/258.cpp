#include"iostream"
#include"string"
using namespace std;
typedef struct node{
	node *next;
	char c;	
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void reverse(LNode L,LNode p){
	if(p->next){
		LNode e;
		e=p->next;
		p->next=e->next;
		e->next=L->next;
		L->next=e;
		reverse(L,p);
	}
}
void output(LNode L){
	LNode p=L->next;
	while(p){
		cout<<p->c;	
		p=p->next;	
	}
	cout<<endl;
}
int main(){
	LNode L,p,e;
	char c;
	string str;
	while(1){
		initNode(L);
		p=L;
		cin>>str;
		for(int i=0;i<str.length();i++){
			c=str[i];
			initNode(e);
			e->c=c;
			p->next=e;
			p=e;
		}
		if(L->next->c=='0'&&L->next->next==NULL){
			break;
		}
		reverse(L,L->next);
		output(L);
	}
	return 0;
}
