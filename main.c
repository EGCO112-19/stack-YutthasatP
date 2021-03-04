#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j,check=0;
  
  Stack s;
  s.size=0;//
  s.top=NULL;
  

 
  for(i=1;i<argc;i++){
  
     for(j=0;j<strlen(argv[i]);j++){
       switch (argv[i][j]){
         case '{' : push(&s,argv[i][j]); break;
         case '[' : push(&s,argv[i][j]); break;
         case '(' : push(&s,argv[i][j]); break;
         case '}' : if (s.size == 0) check = 1; 
                    else check = pop(&s) - '{';               break;
         case ']' : if (s.size == 0) check = 1; 
                    else check = pop(&s) - '['; 
                    break;
         case ')' : if (s.size == 0) check = 1; 
                    else check = pop(&s) - '('; 
                    break;
       }
      if(check != 0)
        break;
     }
      if(s.size>0 || check != 0)
        printf ("The parentheses do not match for %s\n",argv[i]);
      else printf ("The parentheses match successfully for %s\n",argv[i]);
      check = 0;
      printf ("\n\nSize = %d\n\n",s.size);
      pop_all(&s);

  }




   return 0;
}
