#include<stdio.h>
#include<ctype.h>
#include<string.h>

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

void prefix_evaluation(char *expr) {
   int val1, val2, res, len, i = 0;
   
   len = strlen(expr);
   printf("Len = %d\n", len);
   i = len-1;

   while(i >= 0) {
      if(expr[i] == ' ') {
         i--;
         continue;
      } else if (isdigit(expr[i])) {
          res = expr[i] - '0';
          push(res);
          i--;
      } else if (expr[i] == '*') {
          val1 = pop();
          val2 = pop();
          res = val1 * val2;
          push(res);
          i--;
      } else if (expr[i] == '+') {
          val1 = pop();
          val2 = pop();
          res = val1 + val2;
          push(res);
          i--;
      }else if (expr[i] == '-') {
          val1 = pop();
          val2 = pop();
          res = val1 - val2;
          push(res);
          i--;
      }
   }
   printf("Result = %d\n", pop());
}


int main(){
 char expr[] = "- + * 2 3 * 5 4 9";
 char *ptr = expr;

 printf("Prefix expression = %s\n", expr);
 prefix_evaluation(ptr);

 return 0;
}
