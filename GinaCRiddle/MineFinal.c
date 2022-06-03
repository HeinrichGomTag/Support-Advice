#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void Name(void)
{
	char name[20];
	char answer[4]; // Create a string variable to store the user's answer
	printf("Do you want to play a game? (yes/no)\n"); // Ask the user if they want to start the game
	scanf("%s", answer); // Get the user's answer

	// If the user's answer is yes, ask the user for their name
	if (answer[0] == 'y' || answer[0] == 'Y')
	{
		printf("What is your name?\n");
		scanf("%s", name); // Get the user's name
		printf("Hi %s, this is your adventure, and we are starting in Golden Island\n", name);

		char answer2[4];
		do
		{
			printf(
				"You are wandering in the island, and you found a weir cave with two paths. Do you want to go to the right path?\n");
			// Create a string variable to store the user's answer
			scanf("%s", answer2); // Get the user's answer
			if (answer2[0] != 'y' && answer2[0] != 'Y' && answer2[0] != 'n' && answer2[0] != 'N')
			{
				printf("Invalid option, write YES/yes or NO/no\n");
			}
		}
		while (answer2[0] != 'y' && answer2[0] != 'Y' && answer2[0] != 'n' && answer2[0] != 'N');

		// if the answer is y, the game continues going on the right path
		// if the answer is n, print "ok, you go to the left"
		if (answer2[0] == 'y' || answer2[0] == 'Y')
		{
			printf("ok, you go to the right\n");
			printf("you choose the correct path\n");
			char rope[4];
			do
			{
				printf(
					"oh no! you have fallen into a sinkhole. To escape you need to close between a rope or a climbing plant. If you want to use the rope, say yes, if not put no\n");
				// if the user says Y, print "it was a trap! You die"
				scanf("%s", rope);
				if (rope[0] != 'y' && rope[0] != 'Y' && rope[0] != 'n' && rope[0] != 'N')
				{
					printf("Invalid option, write YES/yes or NO/no\n");
				}
			}
			while (rope[0] != 'y' && rope[0] != 'Y' && rope[0] != 'n' && rope[0] != 'N');

			if (rope[0] == 'y' || rope[0] == 'Y')
			{
				printf("it was a trap! You die\n");
				Name();
			}
			/*if the user says N, print "you have chosen the correct way. Congrats".Print "You have escaped from the sinkhole, and now you can see the light out of the cave"
		print "do you want to go yo the light?"*/
			else if (rope[0] == 'n' || rope[0] == 'N')
			{
				printf("you have chosen the correct way. Congrats\n");
				printf("You have escaped from the sinkhole, and now you can see the light out of the cave\n");
				char light[4];
				do
				{
					printf("do you want to go to the light?\n");
					scanf("%s", light);
					if (light[0] != 'y' && light[0] != 'Y' && light[0] != 'n' && light[0] != 'N')
					{
						printf("Invalid option, write YES/yes or NO/no\n");
					}
				}
				while (light[0] != 'y' && light[0] != 'Y' && light[0] != 'n' && light[0] != 'N');

				// if the answer is y, print "you have managed to survive! Congrats"
				if (light[0] == 'y' || light[0] == 'Y')
				{
					printf("you have managed to survive! Congrats\n");
				}
				// if the answer is n, print "you die, start again"
				else if (light[0] == 'n' || light[0] == 'N')
				{
					printf("you die, start again");
				}
			}
		}
		else if (answer2[0] == 'n' || answer2[0] == 'N')
		{
			printf("ok, you go to the left\n");
			printf("You have encountered a riddle\n");
			printf("you must answer this question, or you die. What is square root of 276676?\n");
			int answer3;
			scanf("%d", &answer3);
			if (answer3 == 526)
			{
				printf("You are correct! You can continue to survive and now you can see the light out of the cave\n");
				char light[4];
				do
				{
					printf("Do you want to go to the light?");
					scanf("%s", light);
					if (light[0] != 'y' && light[0] != 'Y' && light[0] != 'n' && light[0] != 'N')
					{
						printf("Invalid option, write YES/yes or NO/no\n");
					}
				}
				while (light[0] != 'y' && light[0] != 'Y' && light[0] != 'n' && light[0] != 'N');

				// if the answer is y, print "you have managed to survive! Congrats"
				if (light[0] == 'y' || light[0] == 'Y')
				{
					printf("you have managed to survive! Congrats\n");
				}
				// if the answer is n, print "you die, start again"
				else if (light[0] == 'n' || light[0] == 'N')
				{
					printf("you die, start again\n");
				}
			}
			else
			{
				printf("You die\n");
				// Reset the program to the start
				Name();
			}
		}
		else
		{
			printf("Please enter a valid answer.\n");
			Name();
		}
	}
	// If the answer is n, print the phrase "why are you here?" and restart the game
	else if (answer[0] == 'n' || answer[0] == 'N')
	{
		printf("Why are you here?\n");
		Name();
	}
	else
	{
		printf("Please enter a valid answer.\n");
		Name();
	}
}

int main()
{
	Name();
	printf("Thanks for playing! \n");
	return 0;
}
