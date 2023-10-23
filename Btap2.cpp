#include "ALISTLIB.c"
#include <list> 
void nhapdulieu(List *L){
	makenullList(L);
	int n;
	int number;
	printf ("nhap vao so phan tu danh sach :");
	scanf ("%d",&n);
	for (int i=1 ; i<=n ;i++){
		printf ("nhap vao so thu %d :",i);
		scanf ("%d",&number);
		insertList(number,endList(*L),L);
	}	
}
float AVG (List L){
	
	int result =0;
	
	Position E=endList(L);
	for (int P=firstList(L) ; P <= E ;P++){
		result += retrieve(P,L);		
	}
	return result/L.Last;

}
void deleteX(int x,List *L){
	
	Position P=firstList(*L) ;
	while(P != endList(*L)){
		if (retrieve(P,*L) != x ){
			P=next(P,*L);
		}
		else {
			deleteList(P,L);
		}
	}

}
void Chan_le(List *Chan, List *Le, List L){
	makenullList(Chan);
	makenullList(Le);
	Position P=firstList(L) ;
	while(P != endList(L)){
		if (retrieve(P,L) % 2 ==0 ){
			insertList(retrieve(P,L),firstList(*Chan),Chan);
		}
		else {
			insertList(retrieve(P,L),firstList(*Le),Le);
		}
		P=next(P,L);
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
int main (){
	int x_delete;
	int point;
	int numberins;
	List L, Le,Chan;

	nhapdulieu(&L);
	printList(L);
	printf ("gia trung binh cac phan tu: %f ",AVG(L));
	
	printf ("\nNhap vao phan tu muon xoa: ");
	scanf ("%d",&x_delete);
	deleteX(x_delete,&L);
	printf ("cac phan tu sau khi xoa la: ");
	printList(L);
	
	printf ("sau khi xoa la: \n"); 
	bubblesort(&L);
	printList(L);
	
	
	Chan_le(&Chan,&Le,L);
	printf ("danh sach cac so chan la:");
	printList(Chan);
	printf ("danh sach cac so le la:");
	printList(Le);
	

	
}
