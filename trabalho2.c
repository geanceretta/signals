#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h> //bool type
#include <ctype.h> //tolower()
#include <unistd.h> //alarm()

void handle_SIGINT();
void handle_SIGTSTP();
void handle_SIGALRM();

typedef void (*sighandler_t) (int);
sighandler_t signal(int signum, sighandler_t handler);

int count_SIGINT = 0;
bool exit_decision[2] = {true, false};
bool alarm_flag;
char user_input[3];

int main(void) {
	signal(SIGINT, handle_SIGINT);
	signal(SIGTSTP, handle_SIGTSTP);
	signal(SIGALRM, handle_SIGALRM);
	do {
		if (count_SIGINT == 10){
			do {
				fflush(stdin);
				printf("\nReally exit (Y/n)? \n");
				alarm(5); //sets an alarm in 5 seconds
				alarm_flag = true;
				fgets(user_input, 3, stdin);
				alarm_flag = false;
				switch (tolower(user_input[0])) {
					case 'y':
						kill(getpid(), SIGKILL);
						break;
					case 'n':
						count_SIGINT = 0;
						break;
					default:
						printf("\nInvalid option: %s", user_input);
						break;
				}
			} while (tolower(user_input[0]) != 'y' && tolower(user_input[0]) != 'n');
		}
	} while (true);
}

void handle_SIGINT(int signum){
	count_SIGINT++;
}

void handle_SIGTSTP(int signum){
	printf("\nSIGINT Counter: %d\n", count_SIGINT);
}

void handle_SIGALRM() {
	if (alarm_flag) {
		printf("\nNo input from user in 5 seconds, exiting...\n");
		exit(0);
	}
}
