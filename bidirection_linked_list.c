#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef int DATA;


typedef struct node{
	DATA d;
	struct node* previous;
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
		temp -> previous = head;
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
		printf("\t %d \t ↔ ", current -> d);
		count++;
		if (count % 5 == 0)
		{
			printf("\n");
		}
		current = current -> next;
	}	
	printf("\n\n Finished printing list.\n\n");
}


void print_list_reverse(list head)
{
	int count = 0;
	node* current = head;
	while (current -> next != NULL)
	{
		current = current -> next;
	}
	printf("\n\n Start printing list...\n\n");
	while (current != NULL)
	{
		printf("\t %d \t ↔ ", current -> d);
		count++;
		if (count % 5 == 0)
		{
			printf("\n");
		}
		current = current -> previous;
	}	
	printf("\n\n Finished printing list.\n\n");
}


list sort_list(list head)
{
	if ((head != NULL) && (head -> next != NULL))
	{
		node* flag_0 = NULL;
		node* flag_1 = head;
		
		while (flag_0 != head)
		{
			while (flag_1 -> next != flag_0)
			{
				if (flag_1 -> d > flag_1 -> next -> d)
				{
					if ((flag_1 != head) && (flag_1 -> next -> next != NULL))
					{
						flag_1 -> next = flag_1 -> next -> next;
						flag_1 -> next -> previous -> previous = flag_1 -> previous;
						flag_1 -> next -> previous -> previous -> next = flag_1 -> next -> previous;
						flag_1 -> previous = flag_1 -> next -> previous;
						flag_1 -> next -> previous -> next = flag_1;
						flag_1 -> next -> previous = flag_1;
					}
					else if (flag_1 == head)
					{
						head = flag_1 -> next;
						head -> next -> previous = flag_1;
						flag_1 -> next = head -> next;
						flag_1 -> previous = head;
						head -> previous = NULL;
						head -> next = flag_1;
					}
					else
					{
						flag_1 -> previous -> next = flag_1 -> next;
						flag_1 -> next -> previous = flag_1 -> previous;
						flag_1 -> previous = flag_1 -> next;
						flag_1 -> next -> next = flag_1;
						flag_1 -> next = NULL;
					}
				}
				else
				{
					flag_1 = flag_1 -> next;
				}
			}
			flag_0 = flag_1;
			flag_1 = head;
		}
	}
	return head;
}


list remove_repeat_method_1(list head)  /* First sort, and then remove adjacent repeated elements */
{
	head = sort_list(head);
	node* current = head;
	while (current -> next != NULL)
	{
		if (current -> d == current -> next -> d)
		{
			if (current -> next -> next != NULL)
			{
				current -> next = current -> next -> next;
				delete_node(current -> next -> previous);
				current -> next -> previous = current;
			}
			else
			{
				delete_node(current -> next);
				current -> next = NULL;
			}
		}
		else
		{
			current = current -> next;
		}
	}
	return head;
}


list remove_repeat_method_2(list head)  /* For every element, remove repeated ones behind them */
{
	if ((head != NULL) && (head -> next != NULL))
	{
		node* flag_0 = head;
		node* flag_1;
		while ((flag_0 != NULL) && (flag_0 -> next != NULL))
		{
			flag_1 = flag_0 -> next;
			while (flag_1 != NULL)
			{
				if ((flag_0 -> d) == (flag_1 -> d))
				{
					if (flag_1 -> next != NULL)
					{
						flag_1 -> previous -> next = flag_1 -> next;
						flag_1 -> next -> previous = flag_1 -> previous;
						node* temp = flag_1;
						flag_1 = flag_1 -> next;
						delete_node(temp);
					}
					else
					{
						flag_1 -> previous -> next = NULL;
						delete_node(flag_1);
						flag_1 = NULL;
					}
				}
				else
				{
					flag_1 = flag_1 -> next;
				}
			}
			flag_0 = flag_0 -> next;
		}
	}
	return head;
}


void test_1()   /* This is regular homework. */
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
	printf(" ----- Reverse print: ----- ");
	print_list_reverse(head);
}


int main(void)
{
	
	int max_integer = 50;
	int n_data = 200;
	
	srand(time(0));
	
	list head = create_new_node(rand() % max_integer);
	list head_copy = create_new_node(head -> d);
	
	for (int i = 1; i < n_data; i++)
	{
		head = add_new_node(head, rand() % max_integer);
		head_copy = add_new_node(head_copy, head -> d);
	}
	printf(" ----- Original linked list: ----- ");
	print_list(head);
	
	head = remove_repeat_method_1(head);
	printf(" ----- Removed repeated elements using method 1 (first sort, then remove repeated adjacents): ----- ");
	print_list(head);
	
	
	head_copy = remove_repeat_method_2(head_copy);
	printf(" ----- Removed repeated elements using method 2 (for every element, remove repated ones behind them): ----- ");
	print_list(head_copy);
	
	return 0;
}

