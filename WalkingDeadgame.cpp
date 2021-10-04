#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int createZombie() {
    if (rand() % 67 < 10)
        return 11;

    else
        return rand() % 10 + 1;
}
nt gmode = DETECT, gdriver , area ;
initgraph ( &gmode, &gdriver, "c:\tc\bgi\" ) ;
setbkcolor(1);
start();
int maxx = getmaxx() ;
int maxy = getmaxy() ;
int p=400,q=300,m=100,n=100,x=m,y=n,key,score=0,finish=0,level=1,l_flag=1;
char score1[5],ch,cnt_ball[5],char_level[2];

	rectangle ( 0, 0, maxx, maxy - 10 ) ;

	draw_burst(200,300);
	area=imagesize(0,0,32,24);
	burst=malloc(area);
	getimage(200-16,300-12,200+16,300+12,burst);
	putimage(200-16,300-12,burst,XOR_PUT);

	draw_balloon(p,q);

area=imagesize(p-4*BALLOON_SIZE,q-5*BALLOON_SIZE,p+4*BALLOON_SIZE,q+7*BALLOON_SIZE);
balloon=malloc(area);

getimage(p-4*BALLOON_SIZE,q-5*BALLOON_SIZE,p+4*BALLOON_SIZE,q+7*BALLOON_SIZE,balloon);
	putimage(p-4*BALLOON_SIZE, q-5*BALLOON_SIZE, balloon, COPY_PUT);

	draw_arrow(x ,y  );
	area = imagesize(x, y-ARROW_SIZE, x+(6*ARROW_SIZE), y+ARROW_SIZE);
	arrow=malloc(area);
	getimage(x, y-ARROW_SIZE, x+(6*ARROW_SIZE), y+ARROW_SIZE,arrow);
	putimage(x, y-ARROW_SIZE,arrow,XOR_PUT);

	draw_bow(x,y);
	area=imagesize(x+25,y-65,x+66,y+65);
	bow=malloc(area);
	getimage(x+25,y-65,x+66,y+65,bow);

	if ( balloon == NULL || burst == NULL || bow == NULL )
	{
		printf( "
Insufficient memory... Press any key " ) ;
		getch() ;
		closegraph() ;
		restorecrtmode() ;
		exit( 0 ) ;
	}
int main() {
    srand(time(NULL));
    char enter;

    // game stats
    int playerAlive = true;
    int playerSkill = 9;
    int playerScore = 1;
    string playerName = "";
    int zombieCount = 0;
    int zombiesKilled = 0;

    // title
    cout << "Welcome to Zombie War." << endl << "Press [ENTER] to start.";
    cin.get();

    // player name
    cout << "Please enter your name: ";
    cin >> playerName;

    // ask how many zombies
    cout << "How many zombies do you wish to fight? ";
    cin >> zombieCount;

    cout << "Get ready to fight for your life, " << playerName << "!" << endl;

    // main game loop
    while (playerAlive && zombiesKilled < zombieCount) {
        // create a random zombie
        int zombieSkill = createZombie();

        // battle sequence
        if (zombieSkill > 10) {
            cout << endl << "Here comes a huge zombie!" << endl;
        }
        else {
            cout << endl << "Here comes zombie " << zombiesKilled + 1 << endl;
        }

        cout << "Fighting..." << endl;
        //sleep(2);

        // zombie killed the player
        if (playerSkill < zombieSkill) {
            playerAlive = false;
            cout << "You have died." << endl;
        }

        // player killed the zombie
        else {
            if (playerSkill - zombieSkill > 7) {
                cout << "You wasted the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else if (playerSkill - zombieSkill > 5) {
                cout << "You decapitated the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else if (playerSkill - zombieSkill > 0) {
                cout << "You killed the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else {
                cout << "You killed the zombie, but suffered injuries." << endl;
            }

            zombiesKilled++;
        }

        cout << endl;
        //sleep(1);
    }

    // end game
    if (zombiesKilled == zombieCount) {
        // victory
        cout << "You have survived the onslaught!" << endl;
    }
    else {
        // lost
        cout << "You did not survive the zombie war." << endl;
    }

    cout << "Zombies killed: " << zombiesKilled << endl;
    cout << "Final score: " << playerScore << endl << endl;
}

