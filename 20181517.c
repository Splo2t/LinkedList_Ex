#include <stdio.h>
#include <stdlib.h>
struct _node{
    int value;
    struct _node *next;
}typedef node;

struct _linkedList{
    node *head;
    node *last;
    node *p;
}typedef linkedList;

linkedList *initList();
int countList(linkedList *list);
void printList(linkedList *list);
int printMidist(linkedList *list);
void printListReverse(linkedList *list);
void listOddDelete(linkedList *list);
void addNewNode(linkedList *list, int value);
node *findLastNode(linkedList *list);

int main() {
    int n;
    linkedList *list = initList();
    while(1){
        printf("정수를 입력하세요:");
        scanf("%d", &n);
        if(n == -1){
            break;
        }
        addNewNode(list, n);
    }
    printf("List:\t\t\t  ");
    printList(list);
    printf("\n");
    printf("countList:\t\t  %4d\n", countList(list));
    printf("midValueOfList:   ");
    printMidist(list);
    printf("\n");
    printf("reverseOfList:\t  ");
    printListReverse(list);
    printf("\n");
    listOddDelete(list);
    printf("afterDeleteOfList:");
    printList(list);
    return 0;
}

linkedList *initList(){
    linkedList *temp = (linkedList*)malloc(sizeof(linkedList));
    //node *tempNode = (node*)malloc(sizeof(node));
    //tempNode->next = NULL;
    temp->head = NULL;
    temp->last = NULL;
    return temp;
}

int countList(linkedList *list){
    int count = 1;
    node *temp = list->head;
    while(1){
        if(temp == list->last){
            return count;
        }
        else {
            temp = temp->next;
            count++;
        }
    }
}

void printList(linkedList *list){
    node *temp;
    temp = list->head;
    while(1){
        printf("%4d",temp->value);
        if(temp->next == NULL){
            return;
        }
        else {
            temp = temp->next;
        }
    }
}

int printMidist(linkedList *list){
    int mid = countList(list)/2;
    int count = 0;
    node *temp = list->head;
    while(1){
        if(count == mid){
            printf("%4d", temp->value);
            return mid;
        }
        else{
            temp = temp->next;
            count++;
        }
    }
}
void printListReverse(linkedList *list){
    int *arr = malloc(sizeof(int)*countList(list));
    node *prevLast;
    node *p = list->head;
    int i = 0;
    while(1){
        arr[i++] = p->value;
        p = p->next;
        if(p == NULL)
            break;
    }
    for(int i = 0; i < countList(list);i++){
        printf("%4d", arr[countList(list)-1-i]);
    }
}
void listOddDelete(linkedList *list) {
    node *p;
    node *temp;
    node *prevNode;
    p = list->head;
    prevNode = list->head;
    int count = 1;
    while (p != NULL) {
        if ((count % 2 == 1) && count != 1) {
            temp = p;
            prevNode->next = p->next;
            if(p == list->last){
                list->last = prevNode;
            }
            p = p->next;
            free(temp);
        }
        else if (count == 1){
            list->head = p->next;
            p = list->head;
            prevNode = list->head;
        }
        else {
                prevNode = p;
                p = p->next;
        }
        count++;
    }
}
void addNewNode(linkedList *list, int value){
    node *tempNode = (node*)malloc(sizeof(node));
    tempNode->next = NULL;
    tempNode->value = value;
    if(list->head == NULL){
        list->head = tempNode;
        list->last = tempNode;
    }
    else{
        list->last->next = tempNode;
        list->last = tempNode;
    }
}