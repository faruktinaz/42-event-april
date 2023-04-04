#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;

    int hand_value = 0;
	int num_a = 0;
	char *cards = argv[1];
	int card_index = 0;

	while (cards[card_index])
	{
        char card = cards[card_index];

        if (card >= '2' && card <= '9')
			hand_value += card - '0';
		else if (card == 'T' || card == 'J' || card == 'Q' || card == 'K')
            hand_value += 10;
		else if (card == 'A')
		{
			num_a++;
			hand_value += 11;
		}
		card_index++;
	}
    while (num_a > 0 && hand_value > 21)
	{
		hand_value -= 10;
		num_a--;
	}
	if (hand_value == 21)
		printf("Blackjack!\n");
	else
		printf("%d\n", hand_value);
	return (0);
}