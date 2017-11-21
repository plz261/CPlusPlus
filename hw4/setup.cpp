// This program allows you to play a game of poker using dice. It allows you to change your hand twice in each game you decide to play.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void splitLineByCharacter(string myLine, char delimiter, string substrings[], int & substringCount);

const int SIZE = 10;

int main(){

  // Defines the variables to be used throughout the program.

  srand(time(0));
  int numOfDice;
  numOfDice = 5;
  int erase;
  int rollAgain;
  int dice[6];
  char count; 
  int counter = 0;
  int counter2 = 0;
  int counter3 = 0;
  int counter4 = 0;
  int counter5 = 0;
  int counter6 = 0;
  int money = 100;
  int k;
  int q;
  int one, two, three, four, five, six;
  
  // Prompts you to answer whether you want to play video poker or not. 

  cout << "Welcoooooome, tooo Poooker!!!!" << endl;
  
  cout << "You start with $100 to play with, each round is $10." << endl;
  
  cout << "Would you like to play? Enter 1 for yes and 0 for no." << endl;
  
  cin >> rollAgain; 
  
  cin.ignore(20, '\n');
  
  while(rollAgain == 1)
    {
      money -= 10;
      count++;
      for(k = 0; k < numOfDice; k++)
	{
	  dice[k] = rand() % 6 + 1;
	}
      for (int rollNum = 1; rollNum < 3; rollNum++) {
	for(k = 0; k < numOfDice; k++)
	  {
	    cout << dice[k] << " ";
	  }
	cout << endl;
	
	cout << "Please enter which dice you want to remove, you may remove 2.\n" << endl;
	cout << "EX: enter '1' if you want to remove a dice '1', press ENTER to exit." << endl;
	
	// This part allows the user to delete and replace the rolls of dice wanted. 	

	string newString;
	string sArray[10];
	int count;
	int diceIndex;
	getline(cin, newString);

	splitLineByCharacter(newString, ' ', sArray, count);
	
	// Rerandomizes the rolls needed.   

	for (int index = 0; index < count; index++) {
	  
	  diceIndex = atoi(  sArray[index].c_str())-1;
	  
	  dice[diceIndex] = rand() % 6 +1;
	  
	  
	}
	
      }
      for(k = 0; k < numOfDice; k++)
	{
	  cout << dice[k] << " ";
	}
      cout << endl;
      
      for(k = 0; k < numOfDice; k++)
	{
	  if(dice[k] == 1)
	    {
	      counter++;
	    }
	}
      
      for(k = 0; k < numOfDice; k++)
	{
	  if(dice[k] == 2)
	    {
	      counter2++;
	    }
	}
      
      for(k = 0; k < numOfDice; k++)
	{
	  if(dice[k] == 3)
	    {
	      counter3++;
	    }
	}
      
      for(k = 0; k < numOfDice; k++)
	{
	  if(dice[k] == 4)
	    {
	      counter4++;
	    }
	}
      
      for(k = 0; k < numOfDice; k++)
	{
	  if(dice[k] == 5)
	    {
	      counter5++;
	    }
	}
      
      for(k = 0; k < numOfDice; k++)
	{
	  if(dice[k] == 6)
	    {
	      counter6++;
	    }
	}
      
      // Thios shows the amount of times the user got a specific side on the dice.

      cout << "The first die(1) " << counter << endl;
      cout << "The second die(2) " << counter2 << endl;
      cout << "The third die(3) " << counter3 << endl;
      cout << "The fourth die(4) " << counter4 << endl;
      cout << "The fifth die(5) " << counter5 << endl;
      cout << "The sixth die(6) " << counter6 << endl;
      
      // These functions allow the user to check and see if they have won anything in the game.       
      if ( counter == 5 || counter2 == 5 || counter3 == 5 || counter4 == 5 || counter5 == 5) {
	
	cout << "Congradulations you have Five of a kind, you win $20." << endl; 
	money += 30;
      }
      else if ( counter2 == 1 && counter3 == 1 && counter4 == 1 && counter5 == 1 && counter6 == 1) {
	cout << "Congradulations you have a straight, you win  $20." << endl;
	money += 20;
	
      }
      else if ( counter2 == 1 && counter3 == 1 && counter4 == 1 && counter5 == 1 && counter == 1) {
	cout << "Congradulations you have a straight, you win  $20." << endl;
	money += 20;
	
      }
      else if (counter==4 || counter2==4 || counter3==4 || counter4==4 || counter5==4 || counter6==4) {
	
	cout << "Congradulations you have Four of a Kind, you win $15" << endl; 
	money += 15;
      }
      else if ( counter==3 || counter2==3 || counter3==3 || counter4==3 || counter5==3 || counter6==3) {
	
	if ( counter==2 || counter2==2 || counter3==2 || counter4==2 || counter5==2 || counter6==2) {
	  
	  cout << "Congradulations you have a Full House, you win $12." << endl;
	  money += 12;
	}
	else if ( counter==3 || counter2==3 || counter3==3 || counter4==3 || counter5==3 || counter6==3) 
	  { cout << "Congradulations you have three of a kind, you win $8." << endl;
	    money += 8;
	  }
	
	else if (counter == 2) {
	  if (counter2==2 || counter3==2 || counter4==2 || counter5==2 || counter6 == 2) {
	    cout << "You have Two Pairs, you win $5" << endl;
	    money += 5;
	  }
	}
	else if (counter2 == 2) {
	  if ( counter==2 || counter3==2 || counter4==2 || counter5==2 || counter6==2) {
	    cout << "You have Two Pairs, you win $5" << endl;
	    money += 5;
	  }
	}
	else if ( counter3 == 2) {
	  if (counter==2 || counter2==2 || counter4==2 || counter5==2 || counter6==2) {
	    cout << "You have Two Pairs, you win $5" << endl;
	    money += 5;
	  }
	}
	else if ( counter4 == 2) {
	  if ( counter==2 || counter2==2 || counter3==2 || counter5==2 || counter6==2) {
	    cout << "You have Two Pairs, you win $5" << endl;
	    money += 5;
	  }
	}
	else if (counter5 == 2) {
	  if (counter==2 || counter2==2 || counter3==2 || counter4==2 || counter6==2) {
	    cout << "You have Two Pairs, you win $5" << endl;
	    money += 5;
	  }
	}
	else if (counter6 == 2) {
	  if (counter==2 || counter2==2 || counter3==2 || counter4==2 || counter5==2) {
	    cout << "You have Two Pairs, you win $5" << endl;
	    money += 5;
	  }
	}
	else { 
	  cout << "Sorry, you have an empty hand, you lose." << endl;
	}
      	
      }
      
      cout << "You have " << money << " dollars." << endl;
      cout << "Would you like to play again?( 1 for yes 0 for no)" << endl;
      cin >> q;

      if (q == 1) {
	counter = 0;
	counter2 = 0;
	counter3 = 0;
	counter4 = 0;
	counter5 = 0;
	counter6 = 0;

	cin.ignore(20, '\n');

      }
   else if (q == 0) {

	exit(0);

      }
      else {

	cout << "Please enter 1 or 0" << endl;

	cin >> q;

	cin.ignore(20, '\n');

      }
    }
  return 0;
  
}

// This function cuts up the users input in the getline function used to get userRoll above.
void splitLineByCharacter(string myLine, char delimiter, string substrings[], int & substringCount) { 
  
  int startOfSubstring;
  int endOfSubstring;
  
  substringCount = 0;
  startOfSubstring = 0;
  
  while (true) {
    if (substringCount == SIZE) {
      cout << "Array full:  string entered was not all processed!" << endl;
      return;
    } else {
      endOfSubstring = myLine.find(delimiter, startOfSubstring);
      if (endOfSubstring >=0) {
	substrings[substringCount] = myLine.substr(startOfSubstring,
						   (endOfSubstring - startOfSubstring));
	substringCount++;
	startOfSubstring = endOfSubstring + 1;
      } else {
	endOfSubstring = myLine.length();
	substrings[substringCount] = myLine.substr(startOfSubstring, (endOfSubstring - startOfSubstring));
	substringCount++;
	return;
	
      } // end if
    } // end if
  } // end while
  
  
} // end splitLineByCharacter
