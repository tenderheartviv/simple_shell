#include "shell.h"

/**
 * add_rvar_node - it adds a variable at the end
 * of a r_var list.
 * @head: it is the head of the linked list.
 * @lvar: This is the length of the variable.
 * @val: This is the value of the variable.
 * @lval: Length of the value.
 * Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *newnode, *tmp;

	newnode = malloc(sizeof(r_var));
	if (newnode == NULL)
		return (NULL);

	newnode->len_var = lvar;
	newnode->val = val;
	newnode->len_val = lval;

	newnode->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode;
	}

	return (*head);
}

/**
 * free_rvar_list - it frees a r_var list
 * @head: Head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *tmp;
	r_var *current;

	if (head != NULL)
	{
		current = *head;
		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*head = NULL;
	}
}
/**
 * rev_string - it reverses a string.
 * @s: it is the input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
