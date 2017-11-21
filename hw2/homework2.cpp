// Program helps teach math skills to people between the grade levels of 1, 2 or 3. 
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main () {

  int answer, grade;
  char name[50] ;
  int start1 = 0;
  int end1 = 9;
  int start2 = 10;
  int end2 = 99;
  int start3 = 100;
  int end3 = 999;
  int num11 = rand()%(end1-start1+1)+start1;
  int num12 = rand()%(end1-start1+1)+start1;
  int num21 = rand()%(end2-start2+1)+start2;
  int num22 = rand()%(end2-start2+1)+start2;
  int num31 = rand()%(end3-start3+1)+start3;
  int num32 = rand()%(end3-start3+1)+start3;
  int problem = 1; 
  double average; 
  int correct = 0;

  cout << "Welcome to the Math Tutor.\n";

  cout << "\n What's your name?" << endl;
  cin >> name;

  cout << "\n Enter your grade(1, 2, or 3): ";
  cin >> grade;

  cout << "Please enter the following problem " << name << ".\n";

  while (grade != 3 && grade != 2 && grade != 1) {

    cout << "Sorry, but your choices are 1, 2, or 3.\n"; 

    cout << "Please enter your grade ( 1, 2, or  3): ";
    cin >> grade;

    cout << "Please enter the following problem " << name << ".\n"; 
  }
  
  if (grade == 1) { 

    while (problem <= 5) {
    
     num11 = rand()%(end1-start1+1)+start1;
     num12 = rand()%(end1-start1+1)+start1;

     cout << "Problem " << problem << " : " << setw(2) << num11 << endl;
    
    cout << setw(11) << "+" << setw(3) << num12 << endl; 
    
    cout << setw(15) << "------" << endl;
    
    cout << "Answer: ";
    cin >> answer;
    problem++;
    
    if ((num11+num12) == answer) {
      
      cout << "Congradulations " << name << " you are right!" << endl; 
      correct++;
    }
    
    else {
      
      cout << "Sorry " << name << ", but you are incorrect. Be sure to add a 1 before your numbers if your answer is greater than 9!!" << endl; 
    }
    }
  }
  else if (grade == 2) { 

    while (problem <= 7){
    
     num21 = rand()%(end2-start2+1)+start2;
      num22 = rand()%(end2-start2+1)+start2;

      cout << "Problem " << problem << " : " << setw(3) << num21 << endl;
    
    cout << setw(12) << "+" << setw(3) << num22 << endl;
    
    cout << setw(15) << "-----" << endl;
    cout << "Answer: " << setw(15);
    cin >> answer; 
    problem++;
    if ((num21+num22) == answer) {
      
      cout << "Congradulations " << name << ", your answer is correct!" << endl; 
      correct++;
    }
    
    else  {      
      cout << "Sorry " << name << ", but you are incorrect. Be sure to carry the 1 above the next column of" << endl;
      cout << "         lines each time you get a numbeer 10 or greater in the first column." << endl;
    }
    }
  }
  else if (grade == 3) { 

    while (problem <= 10){

     num31 = rand()%(end3-start3+1)+start3;
     num32 = rand()%(end3-start3+1)+start3;

     cout << "Problem "<< problem << " : " << setw(6) << num31 << endl;
    
    cout << setw(14) << "+" << setw(4) << num32 << endl;
    
    cout << setw(18) << "-----" << endl;
    
    cout << "Answer: "; 
    cin >> answer; 
    problem++; 

    if ((num31+num32) == answer) {
      
      cout << "Congradulations " << name << ", you are correct!" << endl;
    }
  
  else  { 
    
    cout << "Sorry " << name << ", but you are incorrect. Be sure to carry the 1 above the next column of lines" << endl;
    cout << " each time you get a number 10 or greater in the previous column of added numbers." << endl; 
  }
    }
  }

  cout << "================================================================================" << endl; 

  average = static_cast<float>(correct)/10*100;

  cout << fixed << setprecision(1) << right << "Your grade percentage is: " << average << endl;
  
return 0;

} // End Main
//


