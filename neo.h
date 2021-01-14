// System headers
#include <unistd.h>
#include <signal.h>
#include <ncurses.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <string>
#include <regex>
#include <limits>
#include <vector>
#include <functional>
#include <stdexcept>

// Declarations
using std::ostringstream;
using std::regex_match;
using std::regex;
using std::ofstream;
using std::ifstream;
using std::isdigit;
using std::string;
using std::vector;
using std::cerr;
using std::system;

// FIXED macro
#define FIXED int main() { initscr(); signal (SIGWINCH, NULL);

// SCROLL macro
#define SCROLL int main() { initscr(); signal (SIGWINCH, NULL); scrollok(stdscr, TRUE);

// END macro
#define END getch(); endwin(); }

// KEYPAD macro
#define KEYPAD keypad(stdscr, TRUE);

// NO_CURSOR macro
#define NO_CURSOR curs_set(0);

// NO_KEYS macro
#define NO_KEYS noecho();

// CURSOR macro
#define CURSOR curs_set(1);

// KEYS macro
#define KEYS echo();

// LOOP macro
#define LOOP(X, Y) for (int X = 0; X < Y; X++)

// CATCH macro
#define CATCH(X) catch (std::invalid_argument& X)

// Terminal Rows And Columns
int tRows() {
  int row;
  int col;
  getmaxyx(stdscr, row, col);
  return row;
}

int tColumns() {
  int row;
  int col;
  getmaxyx(stdscr, row, col);
  return col;
}

// Fixed length input
string nInput(int arg) {
  char cstring[arg + 1];
  getnstr(cstring, arg);
  return string(cstring);
}

// Text output
void rPuts(string arg) {
  int num = arg.length();
  char char_array[num + 1];
  strcpy(char_array, arg.c_str());
  addstr(char_array);
  refresh();
}

// Type conversion
int toInt(string arg) {
  return std::stoi(arg);
}

string toString(int arg) {
  return std::to_string(arg);
}

// Random numbers
void seed() {
  srand((int)time(0));
}

int pseudo(int arg) {
  int result = 0;
  if (arg > 1) {
    result = (rand() % arg) + 1;    
  }
  return result;
}

// File IO
bool fileExists(string name) {
  bool value = false;
  ifstream f(name);
  if(f) {
    value = true;
  }
  return value;
}

int fileWrite(string name, string text) {
  ofstream myfile;
  myfile.open(name);
  if (myfile.is_open()) {
   myfile << text;
   myfile.close();
   return 0;
  }
  else {
    return 1;
  }
}

int fileAppend(string name, string text) {  
  ofstream outfile;
  outfile.open(name, std::ios_base::app);
  outfile << text; 
  return 0;
}

string fileRead(string name) {
  string str = "";
  ifstream f(name);
  if(f) {
    ostringstream ss;
    ss << f.rdbuf();
    str = ss.str();
  }
  return str;
}

void fileDelete(string arg) {
  int len = arg.size() + 1;
  char fileName[len];
  for (int i = 0; i < len; i++) {
    fileName[i] = arg[i];
  }
  remove(fileName);
}

// Parsing strings
string firstWord(string arg) {
  string result = arg;

  while (result[0] == ' ') {
    result = result.substr(1, result.length());
  }

  int index = result.find(" ");
  result = result.substr(0, index);

  return result;
}

string otherWords(string arg) {
  string result = arg;

  while (result[0] == ' ') {
    result = result.substr(1, result.length());
  }

  int index = result.find(" ");
  result = result.substr((index + 1), result.length());

  return result;
}

int wordCount(string arg) {
  string first = firstWord(arg);
  string final = otherWords(arg);
  int count = 0;
  
  while (first != final) {
    count++;
    first = firstWord(final);
    final = otherWords(final);
  }

  count += (final != "");
  return count;
}

string nthWord(string arg, int index) {
  int count = 0;
  string first = "";
  string final = "";

  if (wordCount(arg) > index) {
    first = firstWord(arg);
    final = otherWords(arg);
  }
  
  while (count < index) {
    count++;
    first = firstWord(final);
    final = otherWords(final);
  }

  return first;
}

// Alphabtic strings
bool isAlphabetic(string arg) {
  return regex_match(arg, regex("^[A-Za-z]+$"));
}

// Numeric strings
bool isPosInt(string arg) {
  bool value = true;
  int len = arg.length();
  if (arg[0] == '0' || len == 0) {
	value = false;
  }
  for (int i = 0; i < len; i++) {
    if (isdigit(arg[i]) == false) {
      value = false;
    }
  }
  return value;   
}

bool isNegInt(string arg) {
  string num = "";
  bool value = true;
  int len = arg.length();
  if (arg[0] != '-') {
	value = false;
  }
  if (len > 1) {
    num = arg.substr(1, (len - 1));
  }
  if (isPosInt(num) == false) {
	value = false;
  }
  return value;
}

bool isInt(string arg) {
  return (isPosInt(arg) || arg == "0" || isNegInt(arg));
}

bool isSignedInt(string arg) {
  return (isPosInt(arg) || isNegInt(arg));
}

bool isBool(string arg) {
  return (arg == "0" || arg == "1");
}

// Vectors
vector<string> readStrings(string fileName, vector<string> & vecOfStrs) {
  ifstream in(fileName.c_str());
  if(!in) {
    cerr << "Cannot open the File : " << fileName << "\n";
  }
  string str;
  while (getline(in, str)) {
    if(str.size() > 0)
    vecOfStrs.push_back(str);
  }
  in.close();
  return vecOfStrs;
}

void overWriteStrings(string file, vector<string> data) {
  fileDelete(file);
  string toAdd = "";
  int sizeNum = data.size();
  for (int i = 0; i < sizeNum; i++) {
    toAdd = data[i] + "\n";
    fileAppend(file, toAdd);
  }
}

// Menu Helper Functions
void renderMenu(string menu[], int size, int count) {
  clear();
  rPuts("   " + menu[0] + "\n\n");
  for (int i = 1; i < size; i++) {
    if (i == count) {
      rPuts(" > " + menu[i] + "\n");
    }
    else {
      rPuts("   " + menu[i] + "\n");
    }
  };
}

int selectOption(string menu[], int size) {
  int value = 1;
  int keyPress;
  do {
    renderMenu(menu, size, value);
    keyPress = getch();
    switch(keyPress) {
      case KEY_DOWN:
        value++;
        if (value == size) {
          value = 1;
        }
        renderMenu(menu, size, value);
        break;
      case KEY_UP:
        value--;
        if (value == 0) {
          value = (size - 1);
        }
        renderMenu(menu, size, value);
      default:
        break;
    }
  } while (keyPress != '\n');
  return value;
}

// Indented Menu Helper Functions
void indentRenderMenu(string menu[], int size, int count) {
  clear();
  rPuts(menu[0] + "   " + menu[1] + "\n\n");
  for (int i = 2; i < size; i++) {
    if (i == count) {
      rPuts(menu[0] + " > " + menu[i] + "\n");
    }
    else {
      rPuts(menu[0] + "   " + menu[i] + "\n");
    }
  };
}

int indentSelectOption(string menu[], int size) {
  int value = 2;
  int keyPress;
  do {
    indentRenderMenu(menu, size, value);
    keyPress = getch();
    switch(keyPress) {
      case KEY_DOWN:
        value++;
        if (value == size) {
          value = 2;
        }
        indentRenderMenu(menu, size, value);
        break;
      case KEY_UP:
        value--;
        if (value == 1) {
          value = (size - 1);
        }
        indentRenderMenu(menu, size, value);
      default:
        break;
    }
  } while (keyPress != '\n');
  return value;
}