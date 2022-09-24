#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

bool yesOrNo(char question[150]);
int mainGame();
void userName();
int gameFlow(int step);
bool riddleQuestion(int question, int correctAnswer);

int main()
{
	mainGame();
	return 0;
}

bool yesOrNo(char question[150])
{
	char answer[3];
	printf("%s", question);
	scanf("%s", answer);
	switch (answer[0])
	{
	case 'y':
	case 'Y':
		return true;
	case 'n':
	case 'N':
		return false;
	default:
		printf("That is not a valid answer, try again\n");
		return yesOrNo(question);
	}
}

int mainGame()
{
	if (yesOrNo("Do you want to play a game? (Y/N)\n"))
	{
		userName();
	}
	else
	{
		printf("Why are you here?\n");
		return mainGame();
	}
}

void userName()
{
	char answer[100];
	printf("What is your name?\n");
	scanf("%s", answer);
	printf("Hi %s, this is your adventure and we are starting in Golden Island!\n", answer);
	if (gameFlow(1) == 0) mainGame();
}

int gameFlow(int step)
{
	switch (step)
	{
	case 1:
		{
			if (yesOrNo(
				"You are wandering in the island, and you find a weird cave with two paths. Do you want to go to the path on the right?\n"))
			{
				printf("You chose the correct path\n");
				return gameFlow(2);
			}
			printf("Ok, you go the left\n");
			return gameFlow(3);
		}
	case 2:
		{
			if (yesOrNo("Oh no! You have fallen into a sinkhole. "
				"To escape you need to choose between a rope or climbing a plant. "
				"If you want to use the rope, say Y, if not put N\n"))
			{
				printf("It was a trap! You died...\n");
				return 0;
			}
			printf("You have chosen the correct way. Congratulations! :D\n");
			printf("You have escaped from the sinkhole, and now you can see the light out of the cave\n");
			return gameFlow(4);
		}
	case 3:
		printf("You've encountered a riddle:\n"
			"You must answer this question or you die. ");
		if (riddleQuestion(276676, 526))
		{
			printf("You are correct! You can continue with your life and now you can see the light out of the cave.\n");
			return gameFlow(4);
		}
		printf("That was incorrect! You died...\n");
		return 0;
	case 4:
		{
			if (yesOrNo("Do you want to go to the light?\n"))
			{
				printf("You have managed to survive! Congratulations!\n");
				return 1;
			}
			printf("You died... Start again\n");
			return 0;
		}
	}
}

bool riddleQuestion(int question, int correctAnswer)
{
	int answer;
	printf("What is the square root of %d?\n", question);
	scanf("%d", &answer);
	if (answer == correctAnswer)
	{
		return true;
	}
	return false;
}
