#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std; 

int main(){
  int num;
  int start=10;
  int end=80; 
  int num1 = rand()%(end-start+1)+start;
  int num2 = rand()%(end-start+1)+start;
  int answer;
  int problem = 0;
  int correct = 0; 
  double average; 
  int grade;
  
    cout << "please enter some  grade" << endl;
    cin >> grade;
  
    if ( grade = 1){

  while (problem < 10) {
    
    num1 = rand()%(end-start+1)+start;
    num2 = rand()%(end-start+1)+start;

    cout << "Problem " << problem << endl; 
    cout << num1 << endl;
    cout << "+" << num2 << endl;
    cout << "======" << endl; 
    cout << (num1+num2) << endl; 
    cin >> answer;
    problem++;
  
  if ((num1+num2)== answer){
      cout << "you are correct sir" << endl; 
      correct++;
  } 
  else { 
      cout << "Sorry but you are incorrect" << endl; 
    }
  }
  average = static_cast<float>(correct)/10*100;

  cout << fixed << setprecision(1) << right << average << endl; 
    }
  return 0; 
}
