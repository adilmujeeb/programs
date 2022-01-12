#include<stdio.h>
#include<stdlib.h>

/* Linked list Node structure */
struct Node {
    int val;
    struct Node* next;
}; 

struct Node *head = NULL;

void display_list();

void create_list() {
   int num, i, val;
   struct Node *ptr=NULL, *temp=NULL;
  
   if(head != NULL) {
       printf("Linked list already initialized, use other options\n");
       return;
   }
 
   __fpurge(stdin);
   printf("\nEnter how many nodes to be created in the list:");
   scanf("%d", &num);
   __fpurge(stdin);
   __fpurge(stdin);
   for (i =0; i < num; i++) {
       __fpurge(stdin);
       temp = (struct Node*) malloc(sizeof(struct Node));
       /* Error Handling */ //TODO
       printf("Enter node(%d) value:", i+1);
       scanf("%d", &val);
       temp->val = val;
       temp->next = NULL;
       if(head == NULL) {
           ptr = temp;
           head = ptr;
       } else {
           ptr->next = temp;
           ptr = ptr->next;
       }
   }
}

void display_list() {
    struct Node *ptr1 = head;
    if(head == NULL) {
       printf("Empty list\n");
       return;
    }
    while(ptr1 != NULL){
        printf("%d", ptr1->val);
        ptr1 = ptr1->next;
        if(ptr1 != NULL)
             printf("->");
    }
    printf("End of list\n");
}

void add_first_node() {
    struct Node *temp;
    int val;

    temp = (struct Node*) malloc(sizeof(struct Node));
    /* Error Handling */ //TODO
    printf("Enter node value:");
    scanf("%d", &val);
    temp->val = val;
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void add_last_node() {
    struct Node *temp, *ptr1;
    int val;

    temp = (struct Node*) malloc(sizeof(struct Node));
    /* Error Handling */ //TODO
    printf("Enter node value:");
    scanf("%d", &val);
    temp->val = val;
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
    } else {
        ptr1 = head;
        while(ptr1->next != NULL) 
           ptr1 = ptr1->next;
        ptr1->next = temp;
    }
}

int node_count(){
    struct Node *temp;
    int count = 0;
   
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count; 
}

void add_middle_node() {
    struct Node *temp, *ptr1 = head;
    int i = 1, pos, count,val;

    printf("Enter node position where new node to be added:");
    scanf("%d", &pos);

    count = node_count();
    if (pos <=0 || pos > count) {
        printf("Wrong position, only %d nodes in the list. Use positive number > 0.", count);
        return;
    } else if (pos == 1) {
        add_first_node();
        return;
    } else {
        while(i < pos - 1) {
            ptr1 = ptr1->next;
            i++;
        }
        temp = (struct Node*) malloc(sizeof(struct Node));
        /* Error Handling */ //TODO
        printf("Enter node value:");
        scanf("%d", &val);
        temp->val = val;
        temp->next = ptr1->next;
        ptr1->next = temp;
    }
}

void add_node() {
       int option;

       printf("***** Add Node in List *****\n");
       printf("1. Add Node from beginning of the list\n");
       printf("2. Add Node in the middle\n");
       printf("3. Add Node at the end\n");

       scanf("%d", &option);

       switch(option) {
           case 1:
                  add_first_node();
                  break;
           case 2:
                  add_middle_node();
                  break;
           case 3:
                  add_last_node();
                  break;
           default:
                  printf("Invalid option");
       }
}

void del_first_node(){
    struct Node *temp;
    int val;

    if(head == NULL) {
        printf("Nothing to delete, empty list");
        return;
    } else {
        printf("deleting first node...\n");
        temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
        display_list();
    }
}

void del_last_node() {
    struct Node *temp, *ptr1;
    int val;

    if(head == NULL) {
        printf("Nothing to delete, empty list");
        return;
    } else {
        printf("deleting last node...\n");
        ptr1 = head;
        if(ptr1->next == NULL){ // single node case
            head = NULL;
            free(ptr1);
            return;
        }
        while(ptr1->next->next != NULL) 
           ptr1 = ptr1->next;
        temp = ptr1->next;
        ptr1->next = NULL;
        free(temp);
        display_list();
    }
    return;
}

void del_middle_node() {
    struct Node *temp, *ptr1 = head;
    int i = 1, pos, count,val;

    printf("Enter node position which is to be deleted:");
    scanf("%d", &pos);

    count = node_count();
    if (pos <=0 || pos > count) {
        printf("Wrong position, only %d nodes in the list. Use positive number > 0.", count);
        return;
    } else if (pos == 1) {
        del_first_node();
        display_list();
        return;
    } else if (pos == count) {
        del_last_node();
        display_list();
        return;
    } else {
        while(i < pos - 1) {
            ptr1 = ptr1->next;
            i++;
        }
        temp = ptr1->next;
        ptr1->next = temp->next;
        temp->next = NULL;
        free(temp);
        display_list();
    }
}

void del_node() {
       int option;

       printf("***** Delete Node in List *****\n");
       printf("1. Delete Node from beginning of the list\n");
       printf("2. Delete Node in the middle\n");
       printf("3. Delete Node at the end\n");

        __fpurge(stdin);
       scanf("%d", &option);
       switch(option) {
           case 1:
                  del_first_node();
                  break;
           case 2:
                  del_middle_node();
                  break;
           case 3:
                  del_last_node();
                  break;
           default:
                  printf("Invalid option");
       }
}

void reverse_list() {
    struct Node *current, *prev = NULL, *next;
    current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    int choice = -1;
    char ch = 'y';

    do {
       printf("***** Linked List *****\n");
       printf("1. Create List\n");
       printf("2. Diplay List\n");
       printf("3. Add Node\n");
       printf("4. Delete Node\n");
       printf("5. Reverse List\n");
       printf("6. Exit\n");
       printf("Enter choice:");
       scanf("%d", &choice);

       switch(choice) {
           case 1:
               create_list(); 
               break;
           case 2:
               display_list();
               break;
           case 3:
               add_node();
               break;
           case 4:
               del_node();
               break;
           case 5:
               reverse_list();
               break;
           case 6:
               exit(0);
           default:
               printf("\nIncorrect choice\n");
               //continue;
        }
        printf("\nDo you want to continue (Y/N):");
        //fflush(stdin);
        __fpurge(stdin);
        scanf("%c", &ch);
    } while(ch == 'y');
    
    return 0;
}
