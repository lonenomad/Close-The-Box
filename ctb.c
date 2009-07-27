#include <stdio.h>
#include <stdlib.h>	//for malloc
#include <time.h>	//for rand

void choose(void);
void options(int roll);
void printoptions(void);
int rolldice(void);

struct list {
	int piece_value;
	struct list *next;
};

typedef struct list piece;

void showpieces(piece *current);

int main() {
	int state = 1;			//the state of the program. controlled by user.
	piece *current, *head;		//pointers for linked list.
	int input;			//input choices from user.
	int roll;			//result of two rolled dice.
	int pieces_up = 0;		//number of pieces up

	head = NULL;
	for(int i = 10; i >= 1; i--) {
		current = malloc(sizeof(piece));
		current->piece_value = i;
		current->next = head;
		head = current;
		pieces_up++;
	}

	current = head;

/*	while(current) {
		printf("%d\t", current->piece_value);
		current = current->next;
	}
	printf("\n");
*/
	showpieces(current);

	printoptions();

	while(state) {
		printf("\nenter choice> ");
		input = getchar();
		getchar();		//for the return-carriage
		if(input == 'e') {
			state = 0;
			continue;
		}
		if(input == 'r') {
			roll = rolldice();
			printf("you rolled: %d\n", roll);
			printf("your options are: \n");
			options(roll);
			choose();
			continue;
		}
		if(input == 'o') {
			printoptions();
			continue;
		}
		if(input == 's') {
			current = head;
			showpieces(current);
			continue;
		}
	}
			
	return 0;
}


void choose() { 
	printf("enter choice: \n");	

}


void options(int roll) {
	if(roll <= 10) 
		printf("%d\n", roll);

	//for combinations using two pieces
	for(int i = 0; i < 10; i++) 
		for(int j = i+1; j < 10; j++) 
			if((i+1) + (j+1) == roll)
			      printf("%d, %d\n", i+1, j+1); 

	//for combinations using three pieces
	for(int i = 0; i < 10; i++)
		for(int j = i+1; j < 10; j++)
			for(int k = j+1; k < 10; k++)
				if((i+1) + (j+1) + (k+1) == roll)
				       printf("%d, %d, %d\n", i+1, j+1, k+1);

	//for combinations using four pieces
	for(int i = 0; i < 10; i++)
		for(int j = i+1; j < 10; j++)
			for(int k = j+1; k < 10; k++)
				for(int l = j+1; l < 10; l++)
					if((i+1) + (j+1) + (k+1) + (l+1) == roll)
						printf("%d, %d, %d, %d\n", i+1, j+1, k+1, l+1);

}


void printoptions(void) {
	printf("\nOptions\tr: rolls dice\n\to: print options\n");
	printf("\ts: show pieces\n\te: exit game\n");
}


void showpieces(piece *current) {
	while(current) {
		printf("%d\t", current->piece_value);
		current = current->next;
	}
	printf("\n");
}


int rolldice(void) {
	int i, j;

//	srand(time(NULL));
//	i = 1 + (rand() % 6);
//	srand(time(NULL));
//	j = 1 + (rand() % 6);

	srand(time(NULL));
	i = 1 + (rand() % 6);
	srand(i);
	j = 1 + (rand() % 6);

	return (i + j);
}

