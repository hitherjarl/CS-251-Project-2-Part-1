

#include "list.h"
#include "llist.c"
#include <stdio.h>
#include <stdlib.h>

void qSort(LIST *lst){
	//base case (Nothing on the list or 1 thing on the list)
	if(lst_is_empty(lst) || lst_length(lst) == 1)
		return;
	
	//select first element in lst and make it the pivot
	LIST *pivot = lst_create();
	lst_push_back(pivot, lst->front->val);
	//move front of the list to be node after pivot
	lst->front = lst->front->next;
	//empty list to hold values
	LIST *lst2;
	
	/* lst_filter_leq 
	//partition A-(p)
		//A <=:(elements <= p)
		//A >=:(elements >= p)
	*/
	lst2 = lst_filter_leq(lst, pivot->front->val);
	
	//recurive call
	qSort(lst); //qSort A<=
	qSort(lst2);//qSort A>=
	
	/* lst_concat 
		place pivot into lst
		place lst2 into lst
		*/
	lst_concat(lst,pivot);
	lst_concat(lst,lst2);
	
	//return (A <=) * p * (A >=)
}

int main(){
	LIST *lst1 = lst_create();
	int userInput;
	
	printf("Enter integers into list terminating with any letter: ");
	int val = scanf("%d", &userInput);
	while(val != EOF && val != 0){
		lst_push_back(lst1, userInput);
		val = scanf("%d", &userInput);
	}
	
	lst_print(lst1);
	
	printf("\n****Quick-Sort****\n");
	qSort(lst1);
	lst_print(lst1);
}
