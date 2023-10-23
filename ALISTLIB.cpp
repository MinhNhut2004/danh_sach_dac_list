#include <stdio.h>

#define Maxlength 10
typedef int ElementType;
typedef int Position;
struct List {
	ElementType Elements[Maxlength];
	Position Last;
};

Position firstList (List L){
	return 1;
}
Position endList(List L){
	return L.Last+1;
}
int emptyList (List L){
	return L.Last == 0;
}
int fullList (List L){
	if (L.Last == Maxlength) return 1;
	
}
void makenullList (List *L){
		L->Last = 0;
}
void insertList (int x,Position P, List *L){
	if (fullList(*L)) {
		printf ("Danh sach day");
	}
	else if (P < 1 ||  P > L->Last+1){
		printf ("Vi tri khong hop le");
	}
	else {
		Position Q;
		for (Q=L->Last;Q>P;Q--){
			L->Elements[Q] = L->Elements[Q-1];
		}
		L->Elements[P-1] = x;
		L->Last++;
	}
}
void deleteList(Position P, List *L){
	if (P<1 || P > L->Last+1){
		printf ("Vi tri sai");
	}
	else if (emptyList(*L)){
		printf ("Danh sach rong");
	}
	else {
		Position Q;
		for (Q=P;Q<L->Last;Q++){
			L->Elements[Q-1] = L->Elements[Q];
		}
		L->Last--;
	}
}
ElementType retrieve(Position P, List L){
	return L.Elements[P-1];
}
Position next(Position P, List L){
	return P+1;
}
Position Locate (int x,List L){
	Position P;
	P= firstList(L);
	while (P != endList(L)){
		if (retrieve(P,L) == x){
			return P;
		}
		else next(P,L);
	}
	return P;
}
Position previous (Position P, List L){
	return P-1;
}
int main (){
	List L;
	for (int i=0 ; i< Maxlength;i++){
		int number;
		printf ("nhap vao so: ");
		scanf ("%d",number);
		insertList(number,i,&L);
	}
}
