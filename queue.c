#include <stdio.h>
#include <stdlib.h>

//    Queue Node
typedef struct node{
   int data;
   struct node *next;
}node;

//    Front & Rear
node *front = NULL;
node *rear = NULL;

//    Enqueue
int enqueue(int data){
   // Queue is empty
   if( front == NULL){
      node *new = (node *)malloc(sizeof(node));
      new->data = data;
      new->next = NULL;

      front = rear = new;
   }else{ //not empty
      node *new = (node *)malloc(sizeof(node));
      new->data = data;
      new->next = NULL;

      rear->next = new;
      rear = new;
   }
}

// Dequeue
int dequeue(){
// Queue is empty
if(front == NULL){
   printf("Queue is empty \n");
} 

node *temp = front;

front = front->next;

free(temp);

return 0;
}

int display(){

   //Queue is empty
   if( front == NULL){
      printf("Queue is empty\n");
      return 0;
   }
   printf("Queue: ");
   node *index = front;
   while(index != NULL){
      printf("%d - ", index->data);
      index = index->next;
   }
   printf("\n");
   return 0;
}


int main(){
   enqueue(5);
   enqueue(6);
   enqueue(8);
   enqueue(10);

   display();


   dequeue();
   dequeue();
   dequeue();
   dequeue();

   enqueue(3);
   enqueue(1);
   enqueue(1);
   
   display();
   return 0;
}