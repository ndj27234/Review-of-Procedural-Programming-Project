#include <iostream>
#include <random>
#include <string>
using namespace std;

int computerChoice();
int humanChoice();


int main() {

  cout << "Welcome to Rock, Paper, Scissors Tournament!" << endl;
  cout << "--------------------------------------------" << endl;

  int humScore = 0;
  int compScore = 0;
  int rounds = 0;
  
  while (true) {  
    
    cout << endl;
    cout << "Round " << rounds + 1 << endl;
    cout << "Score: " << humScore << " - " << compScore << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Please enter your choice: " << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";

    int compChoice = computerChoice();
    int humChoice = humanChoice();
    cout << endl;
    if (humChoice == 4) {
      if (rounds == 0)
        break;
      else {
        cout << "You quit the game. Final score: " << humScore << " - " << compScore << endl;
        if (humScore > compScore)
          cout << "You win the game!" << endl;
        else if (humScore < compScore)
          cout << "You lose the game!" << endl;
        else
          cout << "It's a tie!" << endl;
        break;
      }
    }
    if (compChoice == 1)
      cout << "Computer chose Rock." << endl;
    else if (compChoice == 2)
      cout << "Computer chose Paper." << endl;
    else
      cout << "Computer chose Scissors." << endl;
    if (humChoice == 1)
      cout << "You chose Rock." << endl;
    else if (humChoice == 2)
      cout << "You chose Paper." << endl;
    else if (humChoice == 3)
      cout << "You chose Scissors." << endl;
    else {
      cout << "Invalid input. Please try again." << endl;
      continue;
    }
    if (compChoice == humChoice)
      cout << "It's a tie!" << endl;
    else if (compChoice == 1 && humChoice == 2) { humScore++;
      cout << "You win! Paper covers Rock!" << endl; }
      
    else if (compChoice == 1 && humChoice == 3) { compScore++;
      cout << "You lose! Rock smashes Scissors!" << endl; }
    else if (compChoice == 2 && humChoice == 1) { compScore++;
      cout << "You lose! Paper covers Rock!" << endl; }
    else if (compChoice == 2 && humChoice == 3) { humScore++;
      cout << "You win! Scissors cuts Paper!" << endl; }
    else if (compChoice == 3 && humChoice == 1) { humScore++;
      cout << "You win! Rock smashes Scissors!" << endl;  }
    else if (compChoice == 3 && humChoice == 2) { compScore++;
      cout << "You lose! Scissors cuts Paper!" << endl; }
    else { rounds -= 1;
      cout << "Invalid input. Please try again." << endl; }
    rounds++;
    }
  }




int computerChoice() {
  const int MINIMUM = 1;
  const int MAXIMUM = 3;

  random_device myEngine;
  uniform_int_distribution<int> rpsValue(MINIMUM, MAXIMUM);
  
  return rpsValue(myEngine);
  
}

int humanChoice() {
  int userChoice;
  cin >> userChoice;
  return userChoice;
}

  