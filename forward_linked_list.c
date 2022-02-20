#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef int DATA;


typedef struct node{
	DATA d;
	struct node* next;
} node;


typedef node* list;


node* create_new_node(DATA d)
{	
	node* p = malloc(sizeof(node));
	if (p == NULL)
	{
		printf("failed to allocate memory...");
		return NULL;
	}
	else
	{
		p -> d = d;
		return p;
	}
}


void delete_node(node* pd)
{
	free(pd);
}


void swap_nodes_in_list(list head, node* next_1, node* next_2)
{
}


list add_new_node(list head, DATA d)
{
	node* temp = head;
	head = create_new_node(d);
	if (head == NULL)
	{
		return temp;
	}
	else
	{
		head -> next = temp;
		return head;
	}	
}


void print_list(list head)
{
	int count = 0;
	node* current = head;
	printf("\n\n Start printing list...\n\n");
	while (current != NULL)
	{
		printf("\t %d \t -> ", current -> d);
		count++;
		if (count % 5 == 0)
		{
			printf("\n");
		}
		current = current -> next;
	}	
	printf("\n\n Finished printing list.\n\n");
}


list sort_list(list head)
{
	if ((head != NULL) && (head -> next != NULL))
	{
		node* flag_0 = NULL;
		node* flag_1 = head;
		node* flag_1_previous = NULL;
		
		while (flag_0 != head)
		{
			while (flag_1 -> next != flag_0)
			{
				if (flag_1 -> d > flag_1 -> next -> d)
				{
					if (flag_1_previous == NULL)
					{
						head = flag_1 -> next;
						flag_1 -> next = head -> next;
						head -> next = flag_1;
						flag_1_previous = head;
					}
					else
					{
						flag_1_previous -> next = flag_1 -> next;
						flag_1 -> next = flag_1 -> next -> next;
						flag_1_previous -> next -> next = flag_1;
						flag_1_previous = flag_1_previous -> next;
					}
				}
				else
				{
					flag_1_previous = flag_1;
					flag_1 = flag_1 -> next;
				}
			}
			flag_0 = flag_1;
			flag_1 = head;
			flag_1_previous = NULL;
		}
	}
	return head;
}


int main(void)
{
	int max_integer = 1000;
	int n_data = 100;
	
	srand(time(0));
	
	list head = create_new_node(rand() % max_integer);
	for (int i = 1; i < n_data; i++)
	{
		head = add_new_node(head, rand() % max_integer);
	}
	
	printf(" ----- Original linked list: ----- ");
	print_list(head);
	
	head = sort_list(head);
	printf(" ----- Sorted linked list: ----- ");
	print_list(head);
	
	return 0;
}
