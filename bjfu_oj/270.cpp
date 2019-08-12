#include"iostream"
#include"string"
using namespace std;
typedef struct TNode{
	TNode *left,*right;
	char v;
}*biTree;
void initNode(biTree &T){
	T=new TNode;
	T->left=NULL;
	T->right=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
int getDgree1(biTree T){
	if(T){
		if(!T->left&&!T->right){
			return 1;
		}else{
			return getDgree1(T->left)+getDgree1(T->right);
		}
	}
}
int getDgree2(biTree T){
	if(T){
		if(!T->left&&T->right||T->left&&!T->right){
			return 1+getDgree2(T->left)+getDgree2(T->right);
		}else{
			return getDgree2(T->left)+getDgree2(T->right);
		}
	}else{
		return 0;
	}
}
int getDgree3(biTree T){
	if(T){
		if(T->left&&T->right){
			return 1+getDgree3(T->left)+getDgree3(T->right);
		}else{
			return getDgree3(T->left)+getDgree3(T->right);
		}
	}else{
		return 0;
	}
}
int main(){
	biTree T;
	string s;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		k=-1;
		createTree(T,s);
		cout<<getDgree1(T)<<" "<<getDgree2(T)<<" "<<getDgree3(T)<<endl;
	}
	return 0;
}
