#include <iostream> 
#include <algorithm>//std::random_shuffle
#include <ctime>	//std::time
#include <cstdlib>  //std::rand, std::srand
#include <termios.h>
#include <cstdio>
#define SPECIAL_KEY 0x1b
#define A_KEY 97
#define D_KEY 100 
#define S_KEY 115
#define W_KEY 119
#define LEFT_ARROW_KEY 68 //0x25 ...0x28 
#define UP_ARROW_KEY 65
#define RIGHT_ARROW_KEY 67
#define DOWN_ARROW_KEY 66
using namespace std;
static struct termios old, nw;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
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
char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) {
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
  return getch_(1);
}

void print_2d_array(int a[4][4]){
	//PRINT ARRAY 2D 4x4
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout << a[i][j] << "\t" ;
		};
		cout << endl;
	};
}
void find_0(int matrix[4][4], int *x, int *y){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(matrix[i][j]==0){
				*x=i++;
				*y=j++;
				break;
			};
		};
	};
}
int aRandomValue(int i){return rand()%i;}
int main(){	
	int *mtx = new int[16]{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int ctrl_matrix[4][4]={{mtx[0],mtx[1],mtx[2],mtx[3]},{mtx[4],mtx[5],mtx[6],mtx[7]}
		,{mtx[8],mtx[9],mtx[10],mtx[11]},{mtx[12],mtx[13],mtx[14],mtx[15]},};
	srand(unsigned(time(0)));
	random_shuffle(&mtx[0], &mtx[16]);
	random_shuffle(&mtx[0], &mtx[16],aRandomValue);
	int matrix[4][4]={{mtx[0],mtx[1],mtx[2],mtx[3]},{mtx[4],mtx[5],mtx[6],mtx[7]}
		,{mtx[8],mtx[9],mtx[10],mtx[11]},{mtx[12],mtx[13],mtx[14],mtx[15]},};
	delete [] mtx;
	int x=0,y=0,temp=0;
	int * ptr_x=&x;
	int * ptr_y=&y;
	int moves=0;
	find_0(matrix,ptr_x,ptr_y);
	//HERE STARTS USER INTERFACE
	cout << "This is the initial playground"<< endl;
	print_2d_array(ctrl_matrix);
	cout << "Now the playground have changed, you are the '0' and have to move \
		to restore the playground to its initial arrangement\n";
	print_2d_array(matrix);	
	cout << "Press the arrow keys or 'WASD' to move and <ESC> to quit\n";
	while(true){
		char life = 0x00,chr_1 = 0x00, chr_2 = 0x00;
		life = getch();
		chr_1 = getch();
		cher2 = getch();
	/*	switch(life){
			case DOWN_ARROW_KEY:
			case S_KEY:
				if(x==3)break;
				temp=matrix[x+1][y];
				matrix[x+1][y]=0;
				matrix[x][y]=temp;
				x+=1;
				moves++;
				break;
			case UP_ARROW_KEY:
			case W_KEY:
				if(x==0)break;
				temp=matrix[x-1][y];
				matrix[x-1][y]=0;
				matrix[x][y]=temp;
				x-=1;
				moves++;
				break;
			case LEFT_ARROW_KEY:
			case A_KEY:
				if(y==0)break;
				temp=matrix[x][y-1];
				matrix[x][y-1]=0;
				matrix[x][y]=temp;
				y-=1;
				moves++;
				break;
			case RIGHT_ARROW_KEY:
			case D_KEY:
				if(y==3)break;
				temp=matrix[x][y+1];
				matrix[x][y+1]=0;
				matrix[x][y]=temp;
				y+=1;
				moves++;
				break;
			case ESC_KEY:
				cout << "I'm sorry you want to end this amazing game...\n";
				return 0;
			default:
				cout << "Sorry don't know\n";
				int a=0x00;
				cin >> a;
				break;
		}*/
		system("clear");//Clear the screen
		cout << "0 is in coordinates x: " << x+1 << " ; y: " << y+1 << endl;
		cout << "Player moves: "<< moves << endl;	
		print_2d_array(matrix);
			
	}
	return 0;
}
