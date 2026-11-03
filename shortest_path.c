// Shortest Path (Dijkstra) - Computer Networks
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define INFINITY 10000

// Enumeration for node label
enum node
{
    permanent,
    tentative
};

int path[MAX_NODES], dist[MAX_NODES][MAX_NODES];
int src, dst, n, count = 0;

// Node structure
struct state
{
    int predecessor;
    int length;
    enum node lbl;
} state[MAX_NODES];

int shortestpath(int s, int d);

int main()
{
    int i, j;

    printf("\n\n\t\tSHORTEST PATH CALCULATION \n");
    printf("\nEnter the number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &n);

    if (n < 2 || n > MAX_NODES)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = 0;

    printf("(Enter 0 if there is no direct link)\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("Enter the distance between %d & %d : ", i + 1, j + 1);
            scanf("%d", &dist[i][j]);
            dist[j][i] = dist[i][j];
        }
    }

    printf("\nDistance Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("\t%d", dist[i][j]);
        printf("\n");
    }

    printf("\nEnter source node: ");
    scanf("%d", &src);
    printf("\nEnter destination node: ");
    scanf("%d", &dst);

    if (src < 1 || src > n || dst < 1 || dst > n)
    {
        printf("\nInvalid node number.\n");
        return 1;
    }

    if (src == dst)
    {
        printf("\nThere is no path for self\n");
        return 0;
    }

    if (!shortestpath(src - 1, dst - 1))
    {
        printf("\nNo path exists between %d and %d\n", src, dst);
        return 0;
    }

    printf("\nThe shortest path is: ");
    while (count > 0)
    {
        if (count == 1)
            printf("%d", path[count - 1] + 1);
        else
            printf("%d==>", path[count - 1] + 1);
        count--;
    }

    printf("\n\nDistance of shortest path is: %d\n", state[dst - 1].length);
    return 0;
}

int shortestpath(int s, int d)
{
    int i, k, min;
    struct state *p;

    // Initialise all nodes
    for (p = &state[0]; p < &state[n]; p++)
    {
        p->predecessor = -1;
        p->length = INFINITY;
        p->lbl = tentative;
    }

    // Make source node permanent
    state[s].length = 0;
    state[s].lbl = permanent;
    k = s;

    do
    {
        // Relax neighbours of k
        for (i = 0; i < n; i++)
        {
            if (dist[k][i] != 0 && state[i].lbl == tentative)
            {
                if ((state[k].length + dist[k][i]) < state[i].length)
                {
                    state[i].predecessor = k;
                    state[i].length = state[k].length + dist[k][i];
                }
            }
        }

        // Pick the tentative node with the smallest distance
        k = -1;
        min = INFINITY;
        for (i = 0; i < n; i++)
        {
            if (state[i].lbl == tentative && state[i].length < min)
            {
                min = state[i].length;
                k = i;
            }
        }

        if (k == -1) // remaining nodes unreachable
            return 0;

        state[k].lbl = permanent;
    } while (k != d);

    // Build the path (destination back to source)
    i = 0;
    k = d;
    do
    {
        path[i++] = k;
        k = state[k].predecessor;
        count++;
    } while (k >= 0);

    return 1;
}