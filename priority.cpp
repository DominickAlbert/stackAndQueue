#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next, *prev;
} *head, *rear;

Node *createNode(int value){
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void readNode(Node *currentNode)
{
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node sebelumnya: %p\n", currentNode->prev);
}

void printStack(){
  for (Node *temp = head ; temp != NULL; temp = temp->prev)
  {
    readNode(temp);
    puts("|");
    puts("v");
  }
  puts("NULL");
}

void push(int value){

    Node *temp = createNode(value); 

    if(!head){          //No LL
        head = temp;
        rear = temp;
    }
    else if(value > head->value){   //Only one Node 
        head->next = temp;
        temp->prev = head;
        head = temp;
    }
    else if(value < rear->value){
        rear->prev = temp;
        temp->next = rear;
        temp->prev = NULL;
        rear = temp;
    }
    else{
        Node *Curr = rear;

        while(Curr->value > value){
            Curr = Curr->next;
        }
        temp->next = Curr;
        Curr->prev = temp;        
    }
}

void pop(){
    if(!head){
        return;
    }
    else if(!head->prev){
        head = NULL;
        free(head);
    }
    else{
        Node *newHead = head->prev;
        head->prev = newHead->next = NULL;
        free(head);
        head = newHead;
    }
}



int main(){
    
    push(2);
    push(3);
    push(1);
    push(5);
    push(7);
    push(8);

    pop();
    
    printStack();
    


    return 0;
}