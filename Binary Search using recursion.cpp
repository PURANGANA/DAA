#include <stdio.h>
int recursiveBinarySearch(int a[], int lb, int ub, int x){
   if (ub >= lb){
      int mid = lb+(ub - lb)/2;
      if (a[mid] == x)
         return mid;
      if (a[mid] > x)
         return recursiveBinarySearch(a, lb, mid-1, x);
      else
         return recursiveBinarySearch(a, mid+1, ub, x);
   }
   return -1;
}
int main(void){
int n,x,i;
  int a[50];
  printf("Enter no. of elements: ");
  scanf("%d", &n);
  printf("Enter array elements: ");
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  printf("Enter the element to be searched: ");
  scanf("%d", &x);
  int result = recursiveBinarySearch(a, 0, n - 1, x);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
