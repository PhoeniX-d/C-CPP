#include <stdio.h>
#include <stdlib.h>

#define MAXQUERY		100000
#define MAXSHELVE		100000
#define MAXBOOKS		  1100

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books = NULL;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages = NULL;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
	
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
	if(total_number_of_shelves > MAXSHELVE || total_number_of_shelves < 1)
		return -1;
	if(total_number_of_queries > MAXQUERY || total_number_of_queries < 1)
		return -1;
	
	/* Memory allocation 1D array*/
	total_number_of_books = (int*)malloc(sizeof(int) * total_number_of_shelves);
	if(total_number_of_books == NULL)
	{
		printf("Memory allocation failed\n");
		return -1;
	}
	/* Memory allocation 2D array */
	total_number_of_pages = (int**)calloc(total_number_of_shelves ,sizeof(int*));
	if(total_number_of_pages == NULL)
	{
		printf("Memory allocation failed\n");
		return -1;
	}
    for (int i = 0; i < total_number_of_shelves; i++)
	{
        total_number_of_pages[i] = (int*)calloc(MAXBOOKS, sizeof(int));
		if(total_number_of_pages[i] == NULL)
		{
			printf("Memory allocation failed\n");
			return -1;
		}
    }
	
    while (total_number_of_queries--)
	{
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1)
		{
			int iShelf = 0, iPages = 0;
            scanf("%d %d", &iShelf, &iPages);
			if(iShelf < 0 || iShelf > total_number_of_shelves)
			{
				return -1;
			}
            total_number_of_books[iShelf]++;
            int *ipBook = total_number_of_pages[iShelf];
            while (*ipBook != 0)
            {
				ipBook++;
			}
            *ipBook = iPages;			
        }
		else if (type_of_query == 2)
		{
            int x, y;
            scanf("%d %d", &x, &y);
			if(x < 0 || x > total_number_of_shelves)
			{
				return -1;
			}
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        }
		else
		{
            int x;
            scanf("%d", &x);
			if(x < 0 || x > total_number_of_shelves)
			{
				return -1;
			}
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books)
	{
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++)
	{
        if (*(total_number_of_pages + i))
		{
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}