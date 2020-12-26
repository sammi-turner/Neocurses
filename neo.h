// System headers
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
#define FIXED int main() { initscr();

// SCROLL macro
#define SCROLL int main() { initscr(); scrollok(stdscr, TRUE);

// END macro
#define END getch(); endwin(); }

// LOOP macro
#define LOOP(X, Y) for (int X = 0; X < Y; X++)

// CATCH macro
#define CATCH(X) catch (std::invalid_argument& X)

// User input
string nInput(int arg) {
  char cstring[arg + 1];
  getnstr(cstring, arg);
  return string(cstring);
}

// Text output with autorefresh
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

// Strings
bool isAlphabetic(string arg) {
  return regex_match(arg, regex("^[A-Za-z]+$"));
}

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
