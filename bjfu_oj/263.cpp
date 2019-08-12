#include"iostream"
#include"string"
using namespace std;
typedef struct biTNode{
	char c;
	biTNode *lChild,*rChild;
}*biTree;
void initNode(biTree &T){
	T=new biTNode;
	T->lChild=NULL;
	T->rChild=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->c=s[k];
		createTree(T->lChild,s);
		createTree(T->rChild,s);
	}
}
//比较两棵树是否相等 
bool cmp(biTree T1,biTree T2){
	if(T1==NULL&&T2==NULL){
		return true;
	}else{
		if(T1->c!=T2->c){
			return false;
		}
		if(!cmp(T1->lChild,T2->lChild)){
			return false;
		}
		if(!cmp(T1->rChild,T2->rChild)){
			return false;	
		}
		return true;
	}
}
int main(){
	biTree T1,T2;
	string s;
	while(1){
		cin>>s;
		if(s=="0")
			break;
		k=-1;
		createTree(T1,s);
		cin>>s;
		k=-1;
		createTree(T2,s);
		if(cmp(T1,T2)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
