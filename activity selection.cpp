#include<stdio.h>
int main(){
   int start[50] = {1 , 2, 3, 4, 7, 8, 9, 9, 11, 12};
   int finish[] = {3, 5, 4, 7, 10, 9, 11, 13, 12, 14};
   int activities = sizeof(start)/sizeof(start[0]);
   int i, j;
   printf ("Following activities are selected \t");
   i = 0;
   printf("%d\t", i);
   for (j = 1; j < activities; j++){
      if (start[j] >= finish[i]){
         printf ("%d ", j);
         i = j;
      }
   }
   return 0;
}
