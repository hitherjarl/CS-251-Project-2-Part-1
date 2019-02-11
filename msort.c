

#include "list.h"
#include "llist.c"
#include <stdio.h>
#include <stdlib.h>

void mSort(LIST *lst){
    //base case (Nothing on the list or 1 thing on the list)
    if(lst_is_empty(lst) || lst_length(lst) == 1)
        return;
    
    //split into 2 aL and aR: lst_prefix(...)
    LIST *aL = lst_prefix(lst, (lst_length(lst) / 2));
    //Merge-Sort aL
    mSort(aL);
    //Merge-Sort aR
    mSort(lst);
    //merge aL and aR: lst_merge_sorted(...)
    lst_merge_sorted(lst, aL);
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
    
    printf("\n****Merge-Sort****\n");
    mSort(lst1);
    lst_print(lst1);
}
