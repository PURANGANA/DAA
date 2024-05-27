#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main()
{
    int profit[20], weight[20], W, n, i; 
	printf("Enter no. of objects:");
	scanf("%d",&n);
    printf("Enter the profit of objects:");//{ 60, 100, 120 }
for(i=0;i<n;i++){
	scanf("%d",&profit[i]);
}
printf("Enter the weight of objects:");//{ 10, 20, 30 }
for(i=0;i<n;i++){
	scanf("%d",&weight[i]);
}
printf("Enter max weight:");
scanf("%d",&W);
   
    printf("Value = %d", knapSack(W, weight, profit, n));
    return 0;
}
