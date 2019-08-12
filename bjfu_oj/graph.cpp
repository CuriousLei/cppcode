#include"iostream"
using namespace std;
#define MVNum 100
typedef struct node{
	node *next;
	int vexId;
	int info;
}*arcnode;
typedef struct{
	arcnode *firstarc;
	int data;	
}adjList[MVNum];
typedef struct{
	int vexnum,arcnum;
	adjList L;
}Graph;
int main(){
	
	return 0;
}
