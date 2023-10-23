#include "ALISTLIB.c"
void nhapphantu(List *list){
	int n;
	int number;
	printf ("nhap vao n: ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		printf ("nhap vao phan tu thu %d : ",i);
		scanf ("%d",&number);
		insertList(number,i,list);
	}
}
void swap(int P, int Q, List *list){
	int temp1=retrieve(P,*list),temp2=retrieve(Q,*list);
	deleteList(P,list);
	insertList(temp2,P,list);
	deleteList(Q,list);
	insertList(temp1,Q,list);
}
void bubblesort(List *list){
	Position P,Q;
	for (P=firstList(*list); P < endList(*list) ;P++){
		for (Q=next(P,*list);Q< endList(*list);Q++){
			if (retrieve(P,*list) > retrieve(Q,*list)){
				swap(P,Q,list);
			}
		}
	} 

}

int main(){
	List list;
	
	
	nhapphantu(&list);
	printf("cac phan tu trong danh sach: ");
	printList(list);
	bubblesort(&list);
	printf("cac phan tu sau khi sap xep: ");
	printList(list);
}
