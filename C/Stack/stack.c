#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top = -1;

void display_list();

void push(int x) {
  
   if(top == 99) {
       printf("Error: Stack overflow!\n");
       return;
   }
 
   stack[++top] = x;
   return;

}

void display() {
    int i=0;
    if(top == -1) {
       printf("Empty Stack\n");
       return;
    }
    for(i=0; i <= top; i++){
        printf("%d\n", stack[i]);
    }
}

int pop() {
    int val;

    if(top == -1){
       printf("Error: Stack underflow");
       return -1;
    }

    val = stack[top--];
    printf("Popping value: %d\n", val);
    
    return val;
}

void topval() {
    int val;

    if(top == -1){
       printf("Empty stack");
       return;
    }

    printf("Top value: %d\n", stack[top]);
    return;
}


int main() {
    int choice = -1, val = 0;
    char ch = 'y';

    do {
       printf("***** Stack using Array *****\n");
       printf("1. Push\n");
       printf("2. Pop\n");
       printf("3. Top\n");
       printf("4. Display\n");
       printf("5. Exit\n");
       printf("Enter choice:");
       scanf("%d", &choice);

       switch(choice) {
           case 1:
               printf("Enter value:");
               scanf("%d", &val);
               push(val); 
               break;
           case 2:
               pop();
               break;
           case 3:
               topval();
               break;
           case 4:
               display();
               break;
           case 5:
               exit(0);
           default:
               printf("\nIncorrect choice\n");
        }
        printf("\nDo you want to continue (Y/N):");
        __fpurge(stdin);
        scanf("%c", &ch);
    } while(ch == 'y');
    
    return 0;
}
