#include <stdio.h>
#include <stdlib.h>
int *books;
int **pages;
int main()
{
    int shelves;
    scanf("%d", &shelves);
    books = calloc(shelves, sizeof(int));
    int queries;
    scanf("%d", &queries);
    pages = malloc(shelves * sizeof(int *));
    for (int i = 0; i < shelves; i++) {
    pages[i] = calloc(1100, sizeof(int));
    }

    while (queries--) {
        int query;
        scanf("%d", &query);

        if (query == 1) {
       
            int shelf, pages;
            scanf("%d %d", &shelf, &pages);
            books[shelf]++;
            int *book =pages[shelf];
            while (*book != 0)
                book++;
            *book = pages;
                    
        }
        else if (query == 2)
       {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(pages + x) + y));
        } 
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(books + x));
        }
    }

    if (books) {
        free(books);
    }
    
    for (int i = 0; i <shelves; i++) {
        if (*(pages + i)) {
            free(*(pages + i));
        }
    }
    
    if (pages) {
        free(pages);
    }
    
    return 0;
}

