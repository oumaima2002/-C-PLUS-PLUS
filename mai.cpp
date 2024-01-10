#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include <chrono>

#include "LireRoman.h"

using namespace chrono;
 
int main()
{
  cout << "--------------------------------------------------" << endl;
  cout << "|\tRomans " << endl;
  cout << "|\t\tBy R. H. BARROW" << endl;
  cout << "--------------------------------------------------" << endl << endl;
  
  high_resolution_clock::time_point start, end;

  cout << "Reading book..." << endl;
  start = high_resolution_clock::now();
  LireRoman LireRoman("The_romans.txt");
  end = high_resolution_clock::now();

  cout << "Time taken to read book : " << duration_cast<milliseconds>(end - start).count() << " milliseconds" << endl;

  // Menu loop
  int choice;
  string word;
  vector<unsigned long> lines;
  do {
    cout << "--------------------------------------------------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Show dictionary" << endl;
    cout << "2. Get word count" << endl;
    cout << "3. Find word" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {
      case 0:
        break;
      case 1:
        LireRoman.showroman();
        break;
      case 2:
        cout << "Enter word: ";
        cin >> word;
        cout << "Word count: " << LireRoman.getWordCount(word) << endl;
        break;
      case 3:
        cout << "Enter word: ";
        cin >> word;
        lines = LireRoman.getWordLines(word);
        if (lines.empty())
          cout << "Word not found" << endl;
        else {
          cout << "Word found on lines: ";
          for (auto &line : lines)
            cout << line << " - ";
          cout << endl;
        }
        break;
      default:
        cout << "Invalid choice" << endl;
    }
  } while (choice != 0);

  return 0; 
}