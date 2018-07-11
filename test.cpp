#include <termios.h>
#include <cstdio>
static struct termios old, nw;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
	  tcgetattr(0, &old); /* grab old terminal i/o settings */
	    nw = old; /* make new settings same as old settings */
		  nw.c_lflag &= ~ICANON; /* disable buffered i/o */
		    if (echo) {
				      nw.c_lflag |= ECHO; /* set echo mode */
					    } else {
							      nw.c_lflag &= ~ECHO; /* set no echo mode */
								    }
			  tcsetattr(0, TCSANOW, &nw); /* use these new terminal i/o
											  settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
	  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
	  char ch;
	    initTermios(echo);
		  ch = getchar();
		    resetTermios();
			  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
	  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
	  return getch_(1);
}

/* Let's test it out */
int main(void) {
	 wchar_t c;
     printf("(getche example) please type a letter: ");
 	 c = getche();
 	 printf("\nYou typed: %c\n", c);
	 printf("(getch example) please type a letter...");
	 c = getch();
	 printf("\nYou typed: %c\n", c);
	 
	 return 0;

}
