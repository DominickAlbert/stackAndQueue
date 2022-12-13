#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next, *prev;
} *front , *rear;

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
  printf("Alamat node sebelumnya: %p\n", currentNode->prev);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void printLL(){
    for (Node *temp = rear; temp != NULL; temp = temp->next){
        readNode(temp);
        puts("|");
        puts("V");
    }
}

void enqueue(int value){

    Node *temp = createNode(value);

    if(!front){    //No LL
        front = temp;
        rear = temp;
    }
    else if(rear == front){   //LL has only one node
        front->prev = temp;
        temp->next = front;
        rear = temp;
    }
    else{
        rear->prev = temp;
        temp->next = rear;
        rear = temp;
    }
}

void dequeue(){
    if(!front){ // NO LL
        return;
    }
    else if(rear == front){ // ONLY ONE NODE
        rear = front = NULL;
        free(rear);
        free(front);
    }
    else{
        Node *newFront = front->prev;
        newFront->next = front->prev = NULL;    //isolate Current front
        free(front);                              //Free the memory  
        front = newFront;                       //Make new front into the current front
    }
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue();
    printLL();

    

    return 0;
}