#include <stdio.h>

void simple_fill() {
    int cur_w;
    float tot_v;
    int i, maxi;
    int used[10];
    int n,c[10],v[10],W;

printf("Enter no. of objects:");
scanf("%d",&n);
printf("Enter the cost of objects:");
for(i=0;i<n;i++){
	scanf("%d",&c[i]);
}
printf("Enter the value of objects:");
for(i=0;i<n;i++){
	scanf("%d",&v[i]);
}
printf("Enter max weight:");
scanf("%d",&W);
 
    for (i = 0; i < n; ++i)
        used[i] = 0; /* I have not used the ith object yet */
 
    cur_w = W;
    while (cur_w > 0) { /* while there's still room*/
        /* Find the best object */
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maxi == -1) || ((float)v[i]/c[i] > (float)v[maxi]/c[maxi])))
                maxi = i;
 
        used[maxi] = 1; /* mark the maxi-th object as used */
        cur_w -= c[maxi]; /* with the object in the bag, I can carry less */
        tot_v += v[maxi];
        if (cur_w >= 0)
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, v[maxi], c[maxi], cur_w);
        else {
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_w/c[maxi]) * 100), v[maxi], c[maxi], maxi + 1);
            tot_v -= v[maxi];
            tot_v += (1 + (float)cur_w/c[maxi]) * v[maxi];
        }
    }
 
    printf("Filled the bag with objects worth %.2f$.\n", tot_v);
}
 
int main(int argc, char *argv[]) {
    simple_fill();
 
    return 0;
}
