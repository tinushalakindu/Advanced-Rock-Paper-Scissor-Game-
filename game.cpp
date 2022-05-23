#include <iostream>
#include <time.h>
#include <string> 
using namespace std;


//Function Prototype Declaration
string userDetails();					// Get User Details
int playingRounds();					// Get How many rounds ( as know as levels) player like to play
char getUserChoice();					// Get User Choice 
char getComputerChoice();				// Get Computer Choice 
void showChoice(char choice);			// Check which choice user and player choose
int chooseWinner(char player, char computer);	// Choose who is winner 
void gameIntro();
void thankYou();


int main() {

	char player; //playerChoise save here 
	char computer; //computerChoise save here 
	string username; //player userName from userDetails()
	int rounds; //rounds save here
	int counter = 1;  // for While loop
	int winner; // 
	int playerWin = 0;
	int comWin = 0;
	int tie = 0; 

	gameIntro(); //for introduction and rules

	username = userDetails(); // user details

	rounds = playingRounds(); // assign rounds value here
	cout << endl << endl;

	while (counter <= rounds) { //this can repeat the levels (rounds)
		cout << "= = = = Round " << counter << " Start = = = =" << endl << endl;
		player = getUserChoice();
		cout << "Your Choice: ";
		showChoice(player);

		computer = getComputerChoice();
		cout << endl << "Computer Choice: ";
		showChoice(computer);

		cout << endl;
		winner = chooseWinner(player, computer); //delete
		// original chooseWinner(player, computer);
		cout << endl;


		if (winner == 0)
		{
			tie = tie + 1;

		}
		else if (winner == 1)
		{
			comWin = comWin + 1;
		}
		else
		{
			playerWin = playerWin + 1;
		}

		cout << "= = = = Round " << counter << " Over = = = =" << endl;
		cout << "//////////////////////////////// " << endl << endl;

		counter++;

	}



	cout << "Player Name: - " << username << endl << "Player Level: -" << rounds << endl <<
		"Tied Count: - " << tie << endl << "Player Lost Count: - " << comWin << endl << "Player Won Count: - " << playerWin << endl << endl;


	cout << "$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
	if (playerWin > comWin)
	{
		cout << username << " Win the Game" << endl << endl;
	}
	else
	{
		cout << username << " Loose the Game" << endl << endl;
	}

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

	thankYou();

	return 0;

}


string userDetails() {
	//Get userName 
	string userName;
	cout << "Enter Your Name to Start the Game: - ";
	//cin >> userName; 
	getline(cin, userName); //If user type his sername or another words program might crash. This can avoide it
	return userName;
}
char getUserChoice() {
	// Let user to choose their choice 
	char player;
	//validate their choice by following requirments
	do {
		cout << "Choose one of following" << endl;
		cout << "- - - - - - - - - - - -" << endl;
		cout << "(r) for Rock" << endl << "(p) for Paper" << endl
			<< "(s) for Scissor" << endl;
		cin >> player;
		//cout << player;

	} while (player != 'r' && player != 'p' && player != 's');

	return player;
}
char getComputerChoice() {
	// Get random computer Choice 
	srand(time(0)); 

	int computer = rand() % 3 + 1; // Ex: - 1000 % 3 +1 = 2
	if (computer == 1) return 'r';
	if (computer == 2) return 'p';
	if (computer == 3) return 's';

}
void showChoice(char choice) {

	// Check User and Computer choices and show what they are 
	switch (choice)
	{
	case 'r': cout << "Rock";
		break;
	case 'p': cout << "Paper";
		break;
	case 's': cout << "Scissor";
		break;
	}
}
int chooseWinner(char player, char computer) { 

	// 0 = tie
	// 1 = comWin
	// 2 = UserWin
	int winner;
	int playerWin;
	int comWin;
	int tie;

	switch (player)
	{
		//when player choice (r)
	case 'r': if (computer == 'r') {
		cout << "It's a tie! Same item is formed " << endl;
		return winner = 0;
		
	}

			else if (computer == 'p') {
		cout << "You lose!" << endl;
		return winner = 1;
		
	}
			else {
		cout << "You Win!" << endl;
		return winner = 2;
		
	}
			//when player choice (p)
	case 'p': if (computer == 'r') {
		cout << "You Win!" << endl;
		return winner = 2;
		
	}

			else if (computer == 'p') {
		cout << "It's a tie! Same item is formed " << endl;
		return winner = 0;
		
	}
			else {
		cout << "You lose!" << endl;
		return winner = 1;
		
	} 
			//when player choice (s)
	case 's': if (computer == 'r') {
		cout << "You lose!" << endl;
		return winner = 1;
		
	}
			else if (computer == 'p') {
		cout << "You Win!" << endl;
		return winner = 2;
		
	}
			else {
		cout << "It's a tie! Same item is formed " << endl;
		return winner = 0;
		
	}

	}
}
int playingRounds() {
	// Let user to choose which level he want to play (How many rounds) 
	int rounds;

	do
	{
		// Validate enter data
		cout << endl << endl << "Select one of following player level: -  " << endl << endl << "	#To Play one Round type (1)" << endl
			<< "	#To Play five Rounds type (5)" << endl << "	#To Play eleven Rounds type (11)" << endl
			<< "	#To Play twenty one Rouns type (21)" << endl << endl << "Type your level here: - ";
		cin >> rounds;

	} while (rounds != 1 && rounds != 5 && rounds != 11 && rounds != 21);


	return rounds; // return to main

}
void gameIntro() {
	cout << endl << endl << endl << endl <<




		"					 _ _ _     _                      _____     " << endl <<
		"					| | | |___| |___ ___ _____ ___   |_   _|___ " << endl <<
		"					| | | | -_| |  _| . |     | -_|    | | | . |" << endl <<
		"					|_____|___|_|___|___|_|_|_|___|    |_| |___|" << endl << endl <<


		"######                          ######                                  #####                                     " << endl <<
		"#     #  ####   ####  #    #    #     #   ##   #####  ###### #####     #     #  ####  #  ####   ####   ####  #####" << endl <<
		"#     # #    # #    # #   #     #     #  #  #  #    # #      #    #    #       #    # # #      #      #    # #    #" << endl <<
		"######  #    # #      ####      ######  #    # #    # #####  #    #     #####  #      #  ####   ####  #    # #    #" << endl <<
		"#   #   #    # #      #  #      #       ###### #####  #      #####           # #      #      #      # #    # #####" << endl <<
		"#    #  #    # #    # #   #     #       #    # #      #      #   #     #     # #    # # #    # #    # #    # #   #" << endl <<
		"#     #  ####   ####  #    #    #       #    # #      ###### #    #     #####   ####  #  ####   ####   ####  #    #" << endl;
	cout <<
		"						 #####                                      " << endl <<
		"						#     #   ##   #    # ######                " << endl <<
		"						#        #  #  ##  ## #                     " << endl <<
		"						#  #### #    # # ## # #####                 " << endl <<
		"						#     # ###### #    # #                     " << endl <<
		"						#     # #    # #    # #                     " << endl <<
		"						 #####  #    # #    # ######                " << endl;

	//Introduce Games Ruls 
	cout << "Rock Paper Scissor Game Terms" << endl << endl;

	cout << "# If the same item is formed, it's a tie. " << endl <<
		"	# If a rock and scissors are formed, the rock wins, because a rock can smash scissors. " << endl <<
		"	# If scissors and paper are formed, the scissors win, because scissors can cut paper. " << endl <<
		"	# If paper and a rock are formed, the paper wins, because a sheet of paper can cover a rock. " << endl << endl;

}
void thankYou() {
	cout <<endl << endl << "Thank You for playing the Game!!!" << endl<< endl;
}
