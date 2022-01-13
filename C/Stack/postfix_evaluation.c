#include<stdio.h>
#include<ctype.h>

int stack[100];
int top = -1;

void push(int x) {

   if(top == 99) {
       printf("Error: Stack overflow!\n");
       return;
   }

   stack[++top] = x;
   return;

}

int pop() {
    int val;

    if(top == -1){
       printf("Error: Stack underflow");
       return -1;
    }

    val = stack[top--];

    return val;
}

void postfix_evaluation(char *expr) {
   int val1, val2, res;

   while(*expr != '\0') {
      if(*expr == ' ') {
         expr++;
         continue;
      } else if (isdigit(*expr)) {
          res = *expr - '0';
          push(res);
          expr++;
      } else if (*expr == '*') {
          val1 = pop();
          val2 = pop();
          res = val1 * val2;
          push(res);
          expr++;
      } else if (*expr == '+') {
          val1 = pop();
          val2 = pop();
          res = val1 + val2;
          push(res);
          expr++;
      }else if (*expr == '-') {
          val1 = pop();
          val2 = pop();
          res = val2 - val1;
          push(res);
          expr++;
      }
   }
   printf("Result = %d\n", pop());
}


int main(){
 char expr[] = "2 3 * 5 4 * + 9 -";
 char *ptr = expr;

 printf("Postfix expression = %s\n", expr);
 postfix_evaluation(ptr);

 return 0;
}
