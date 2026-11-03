
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define INFINITY 10000

enum node {
    permanent,
    tentative
};

int path[MAX_NODES], dist[MAX_NODES][MAX_NODES];
int src, dst, n, count = 0;

struct state {
    int predecessor;
    int length;
    enum node lbl;
} state[MAX_NODES];

void shortestpath(int s, int d);

int main()
{
    int i, j;

    printf("\n\t\tSHORTEST PATH CALCULATION\n");

    printf("\nEnter the number of nodes (LESS THAN 10): ");
    scanf("%d", &n);

    if (n < 2 || n > MAX_NODES) {
        printf("Invalid number of nodes!");
        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            printf("Enter the distance between %d & %d: ",
                   i + 1, j + 1);

            scanf("%d", &dist[i][j]);

            if (dist[i][j] < 0) {
                printf("Negative distance is not allowed!\n");
                return 0;
            }

            dist[j][i] = dist[i][j];
        }
    }

    printf("\nDistance Matrix\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter source node: ");
    scanf("%d", &src);

    printf("Enter destination node: ");
    scanf("%d", &dst);

    if (src < 1 || src > n || dst < 1 || dst > n) {
        printf("\nInvalid source or destination node!\n");
        return 0;
    }

    if (src == dst) {
        printf("\nSource and destination are the same.\n");
        printf("Shortest distance is 0\n");
        return 0;
    }

    shortestpath(src - 1, dst - 1);

    if (state[dst - 1].length == INFINITY) {
        printf("\nNo path exists between the nodes.\n");
        return 0;
    }

    printf("\nThe shortest path is: ");

    while (count > 0) {
        if (count == 1)
            printf("%d", path[count - 1] + 1);
        else
            printf("%d ==> ", path[count - 1] + 1);

        count--;
    }

    printf("\n\nDistance of shortest path is: %d\n",
           state[dst - 1].length);

    return 0;
}

void shortestpath(int s, int d)
{
    int i, k, min;
    struct state *p;

    for (p = &state[0]; p < &state[n]; p++) {
        p->predecessor = -1;
        p->length = INFINITY;
        p->lbl = tentative;
    }

    // Make source node permanent
    state[s].length = 0;
    state[s].lbl = permanent;

    k = s;

    while (1) {

        for (i = 0; i < n; i++) {

            if (dist[k][i] != 0 &&
                state[i].lbl == tentative) {

                if (state[k].length + dist[k][i] <
                    state[i].length) {

                    state[i].predecessor = k;
                    state[i].length =
                        state[k].length + dist[k][i];
                }
            }
        }

        min = INFINITY;
        k = -1;

        for (i = 0; i < n; i++) {

            if (state[i].lbl == tentative &&
                state[i].length < min) {

                min = state[i].length;
                k = i;
            }
        }

        if (k == -1 || min == INFINITY)
            break;

        state[k].lbl = permanent;

        if (k == d)
            break;
    }

    // Store shortest path
    i = 0;
    k = d;

    while (k >= 0) {
        path[i++] = k;
        count++;
        k = state[k].predecessor;
    }
}
