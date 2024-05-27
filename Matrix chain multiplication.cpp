#include<stdio.h>
#include<limits.h>

int N;

int MatrixChainOrder(int p[])
{
    int n = N - 1;
    int m[n+1][n+1], s[n+1][n+1];
    int i, l, j, k, q;

    for(i=1; i<=n; i++)
        m[i][i] = 0;

    for(l=2; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i; k<j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                    printf("m[%d][%d] = %d split at k = %d\n", i, j, q, k);
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n", m[1][n]);
    return 0;
}

int main()
{
    int i;
    printf("Enter number of dimensions: ");
    scanf("%d", &N);
    int p[N];
    printf("Enter dimensions:");
    for(i=0; i<N; i++)
        scanf("%d", &p[i]);
    MatrixChainOrder(p);
    return 0;
}

