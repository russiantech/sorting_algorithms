#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - enumerates card suit.
 * @SPADE: spades suits
 * @HEART: heart suits
 * @CLUB: clubs suits
 * @DIAMOND: diamond suits
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - play card
 *
 * @value: val of card
 * "Ace" to "King"
 * @kind: card kind
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - reps deck of cards
 *
 * @card: pointer to card of deck_node_s
 * @prev: pointer to previous node in deck_node_s
 * @next: pointer to next node in deck_node_s
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
