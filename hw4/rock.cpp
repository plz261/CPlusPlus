// This program allows the user to play a game of rock paper scissors against the computer until a clear winner is decided.
#include <iostream>
#include <cstdlib>

using namespace std;

int user;
char rock = 0;
char paper = 1;
char scissors = 2;
int computerChoice = rand() % 3;
int  again; 
char Y = 1;
char N = 0;
int wins = 0;
int loses = 0;
int matches = 1;
int drawed = 0;
double average;
double gestures;

// This will display that the user won the game. 
void you_win()
  
{
  cout << "Congradultions, you win!" << endl;
  matches++;
  wins++;
  cout << "Would you like to play again? Please enter 1 for Yes and 0 for No." << endl;
  cin >> again;
  if (again == 0)
    {
      return;
    }
}

// This will tell the number of time the computer won and the number of times the user lost. 
void you_lose() 
  
{
  cout << "Sorry, you lose..." << endl;
  matches++;
  loses++;
  cout << "Would you like to play again? Please enter 1 for Yes and 0 for No." << endl;
  cin >> again;
  if ( again == 0)
    {
      return;
    }
}

// This will send out the number of matches niether the computer or user won. 
void draw()
  
{
  cout << "The match was a draw." << endl;
  matches++;
  drawed++;
}

int main() { 
  
  do {
    
    cout << "Please select 0 for rock, 1 for paper or 2 for scissors." << endl;
    cin >> user;
    
    computerChoice = rand() % 3;
  
    // This will let the user play the game while choice are 0, 1, 2. 
    while (user == 0 || user == 1 || user == 2)
      {
	
	cout << "Your choice is " << user << endl;
	
	cout << "The computers choice is: " << computerChoice << endl;
	
	// This will allow for a draw and replay of the game. 
	if ( user == computerChoice)
	  {
	    draw();
	    
	    cout << "Please select 0 for rock, 1 for paper or 2 for scissors." << endl;
	    cin >> user;
	    
	    computerChoice = rand() % 3;
	    
	    continue;
	  } 
	
	// This will display what will happen if user selects rock. 
	if ( user == 0) {
	  
	  if (computerChoice == 1) {
	    you_lose();
	    break;
	  }
	  if (computerChoice == 2) {
	    you_win();
	    break;
	  }
	}

	// This displays what will happen if user selects paper. 
	if (user ==  1) {
	  
	  if (computerChoice == 0) {
	    you_win();
	    break;
	  }
	  if (computerChoice == 2) {
	    you_lose();
	    break;
	  }
	}

	// This displays what will happen if user selects scissors. 
	if (user == 2) {
	  
	  if (computerChoice == 0) { 
	    you_lose();
	    break;
	  }
	  if (computerChoice == 1) {
	    you_win();
	    break;
	  }
	}
      }

    // If not a valid choice of rock paper scissors for the user, it will ask again. 
    if (user != 0 && user != 1 && user != 2) { 
      cout << "Sorry that is not a valid choice. Please try again," ;
      cout << " your choices are 0 for rock, 1 for paper and 2 for scissors." << endl;
      cout << "Your choice is: ";
      cin >> user;
      
    } 
  }

  // Will dispaly int main as long as again equalled 0. 
  while ( again == 1);
  
  // Displays the numbers of user wins.
  cout << " The number of times the user won was: "; 
  cout << wins << endl;
  
  // Displays the numbers of user loses. 
  cout << "The number of times the computer won was: "; 
  cout << loses << endl;
  
  // Displays the percent of computer wins. 
  cout << "The percentage of times the computer won was: ";
  average = static_cast<float>(loses) / matches;
  cout << average << "%" << endl; 
  
  // Displays gestures average. 
  cout << "The average number of gestures to determine a winner was: "; 
  gestures = static_cast<double>(matches) / (wins + loses);
  cout << gestures << endl;
  
  return 0;
} // End Main
