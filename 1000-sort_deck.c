#include "deck.h"

/**
 * sort_deck - sort deck of the card
 * @deck: doubly linked list
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr;
	size_t length;
	deck_node_t *one, *two, *three, *four;

	length = list_len_deck(*deck);
	if (!deck || !*deck || length < 2)
	{
		return;
	}
	curr = *deck;
	while (curr)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
		{
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;

			two->next = four;
			if (four)
			{
				four->prev = two;
			}
			three->next = two;
			three->prev = one;
			if (one)
			{
				one->next = three;
			}
			else
				*deck = three;
			two->prev = three;
			curr = *deck;
			continue;
		}
		else
			curr = curr->next;
	}
}

/**
 * card_value - returns the card value
 * @node: card in the deck
 *
 * Return: Always 0
 */

int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int x, ki_val = 0;

	x = 1;
	while (x <= 13)
	{
		if (!_strcmp(node->card->value, val[x - 1]))
		{
			ki_val = x;
		}
		x++;
	}
	x = 1;
	while (x <= 4)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[x - 1]))
		{
			ki_val = ki_val + (13 * x);
		}
		x++;
	}

	return (ki_val);
}

/**
 * _strcmp - compares two  the strings in sote
 * @s1: first string
 * @s2: second string
 *
 * Return: Always 0
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * list_len_deck - returns length of the list
 * @list: list head
 *
 * Return: Always 0
 */

size_t list_len_deck(deck_node_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}
