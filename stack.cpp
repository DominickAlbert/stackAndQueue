#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next, *prev;
} *top;

Node *createNode(int value){
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push(int value){

    Node *temp = createNode(value);

    if(!top){       //If the LL is empty
        top = temp;
    }
    else{
        top->next = temp;  
        temp->prev = top;
        top = temp;
    }
}

void pop(){

    if(!top){
        return;
    }
    else if(!top->prev){
        free(top);
        top = NULL;
    }
    else{
        Node *newTop = top->prev;
        newTop->next = NULL;
        top->prev = newTop->next = NULL; //Isolate Current top
        free(top);
        top = newTop;

    }
}

void readNode(Node *currentNode)
{
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node sebelumnya: %p\n", currentNode->prev);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void printStack(){
  for (Node *temp = top ; temp != NULL; temp = temp->prev)
  {
    readNode(temp);
    puts("|");
    puts("v");
  }
  puts("NULL");
}

int main(){
    
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    push(60);
    printStack();



}