#include <iostream>
#include <stdlib.h>
using namespace std;


//player stuff
class Player{
	public:
		int x;
		int y;
};

Player player;

//enemy shit
class Zoom{
	public:
		int x;
		int y;	
};

class French {
	public:
		int x;
		int y;	
};

French frenchie;
Zoom zoom;
//I got a feeling that I will murder 3 small, innocent children with no apparant motiv; just for fun

//world stuff
bool gaming = true;
int width = 20;
int height = 10;
int score = 0;

//the yeah
void Setup(){
	srand(time(NULL));
	player.x = width/2;
	player.y = height/2;
	frenchie.x = rand() % width -2;
	frenchie.y = rand() % height - 1;
	zoom.x = rand() % 17;
	zoom.y = rand() % 8;
}

void Draw(){
	system("clear");
	for(int i = 0; i < width; i++){
		cout << "#";
	}
	
	for(int i = 0; i < height; i++){
		cout << endl;
		for(int j = 0; j < width; j++){
			if (j==0 || j==width-1)
				cout << "#";
			else if(j == player.x && i == player.y)
				cout<<"O";
			else if(j == frenchie.x && i == frenchie.y)
				cout << "F";
			else if(j == zoom.x && i ==zoom.y)
				cout<< "Z";
			else if(zoom.x == player.x && zoom.y == player.y){
				zoom.x = rand() % 16;
				zoom.y = rand() % 8;
				score +=10;
			}else if(frenchie.x == player.x && frenchie.y == player.y){
				frenchie.x = rand() % 16;
				frenchie.y = rand() % 8;
				score +=10;
			}else
				cout << " ";
		}
	}
	cout <<endl;
	for (int i=0; i<width; i++){
		cout << "#";
	}
	cout <<endl;
	cout<<"Points: "<<score <<endl;

}

void Input(char in){
	switch(in){
		case 'a':
			player.x--;
			break;
		case 'd':
			player.x++;
			break;
		case 'w':
			player.y--;
			break;
		case 's':
			player.y++;
			break;
	}
}

void Logic(){
	if(player.x < 1){
		player.x = width -2;
	}else if(player.x > width - 2){
		player.x = 1;
	}

	if(player.y < 0){
		player.y = height -1;
	}else if(player.y > height -1){
		player.y = 0;
	}
}

int main(){
	Setup();
	while(gaming){
		Draw();
		char rand;
		cin >> rand;
		Input(rand);
		Logic();
	}
}
