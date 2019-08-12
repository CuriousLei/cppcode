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
void createList(LNode L,int m){
	LNode p;
	for(int i=0;i<m;i++){
		initNode(p);
		p->value=m-i;
		if(i==0){
			p->next=L;
		}else{
			p->next=L->next;	
		}
		L->next=p;
	}
}
void output(LNode L,int n){
	LNode p=L,w;
	int k=1;
	while(1){
		if(p->next==L){
			p=p->next;
			continue;
		}
		if(k%n==0){
			w=p->next;
			p->next=w->next;
			cout<<w->value;
			if(p==p->next){
				cout<<endl;
				break;
			}else{
				cout<<" ";
			}
			delete w;
			k++;
			continue;
		}
		k++;
		p=p->next;
	}
}
int main(){
	LNode L;
	int m,n;
	while(1){
		cin>>m>>n;
		if(m==0&&n==0){
			break;
		}
		initNode(L);
		createList(L,m);
		output(L,n);
	}
	return 0;
}
