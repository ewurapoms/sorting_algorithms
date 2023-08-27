#include "deck.h"

/**
 * sort_deck - sorts a deck of card
 * @deck: to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *queen, *king, *spade, *joker;
	deck_node_t *new;
	size_t len;

	len = deck_size(*deck);

	if (!deck || !*deck || len < 2)
		return;

	new = *deck;
	while (new)
	{
		if (new->prev && card_value(new) < card_value(new->prev))
		{
			queen = new->prev->prev;
			king = new->prev;
			spade = new;
			joker = new->next;

			king->next = joker;
			if (joker)
				joker->prev = king;
			spade->next = king;
			spade->prev = queen;
			if (queen)
				queen->next = spade;
			else
				*deck = spade;
			king->prev = spade;
			new = *deck;
			continue;
		}
		else
			new = new->next;
	}
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: the comparison value
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
 * card_value - returns the value of a card
 * @node: ...
 * Return: value between 1 and 52
 */
int card_value(deck_node_t *node)
{
	int d, v = 0;
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};

	for (d = 1; d <= 13; d++)
	{
		if (!_strcmp(node->card->value, val[d - 1]))
			v = d;
	}

	for (d = 1; d <= 4; d++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[d - 1]))
			v += (13 * d);
	}

	return (v);
}

/**
 * deck_size - function returns length of list
 * @list: head of list
 * Return: len
 */
size_t deck_size(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
