# Ucurses

[Ncurses](https://en.wikipedia.org/wiki/Ncurses) updated to handle C++ strings and vectors.

This is a Nix (GNU/Linux, MacOS, BSD, etc) specific iteration of the cross-platform [Sugar.hpp](https://github.com/sammi-turner/Sugar-Hpp) repo.

## Programs using Ucurses in this repo

* A todos app.

* A command-line version of Yahtzee.

## Compiler Flag To Remove 'Dead Code'

To remove any unused code before compilation, you can use the following g++ flag.

```
-flto
```

## Compiler Flag For Smallest Binary

```
-Os
```

## Compiler Flag To Optimize Binary For Speed

```
-O
```

## System headers

Required for these and many other functions.

```
#include <ncurses.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <climits>
#include <ratio>
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
```

## Using declarations

So you can use these methods without the 'std::' prefix.

```
using std::ostringstream;
using std::regex_match;
using std::regex;
using std::ofstream;
using std::ifstream;
using std::isdigit;
using std::isdigit;
using std::string;
using std::vector;
using std::cerr;
using std::system;
```

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

## Start Macro

```
START
```

aliases

```
int main() { initscr();
```

Opens the ncurses virtual terminal in conjunction with the End Macro.

## End Macro

```
END
```

aliases

```
getch(); endwin(); }
```

Opens the ncurses virtual terminal in conjunction with the Start Macro.

## Loop Macro

```
LOOP(foo, bar)
```

aliases

```
for (int foo = 0; foo < bar; foo++)
```

## Catch Macro

```
CATCH(foo)
```

aliases

```
catch (std::invalid_argument& foo)
```

## nInput

```
nInput(foo)
```

Takes buffered input of maximum length foo inside the virtual terminal, and stores it as a C++ string.

## rPuts

```
rPuts(foo)
```

Outputs the C++ string foo to the virtual terminal, and performs a 'refresh()' afterwards.

## Type conversion

```
toInt(foo)
```

Converts the C++ string foo to an integer.

```
toString(foo)
```

Converts the integer foo to a C++ string.


## Random numbers

```
seed()
```

Seeds the pseudo-random number generator.

```
pseudo(foo)
```

Generates a pseudo-random number between 1 and the integer foo, provided that foo is greater than 1. Otherwise, it returns 0.

## File IO

```
fileExists(foo)
```

Checks if foo exists in the working directory.

```
fileWrite(foo, bar)
```

Writes the string bar to the file foo.

```
fileAppend(foo, bar)
```

Appends the string bar to the file foo.

```
fileRead(foo)
```

Returns the contents of file foo as a string.

```
fileDelete(foo)
```

Removes the named file foo from the working directory.

## Strings

```
isAlphabetic(foo)
```

Checks if the string foo is purely alphabetic.

```
isPosInt(foo)
```

Checks if the string foo represents a positive integer.

```
isNegInt(foo)
```

Checks if the string foo represents a negative integer.

```
isInt(foo)
```

Checks if the string foo represents an integer.

```
isSignedInt(foo)
```

Checks if the string foo represents a signed integer.

```
isBool(foo)
```

Checks if the string foo represents a boolean value.

## Vectors

```
readStrings(foo, bar)
```

Reads a file, foo, into a vector of strings, bar.

```
overWriteStrings(foo, bar)
```

Over-writes the contents of a file, foo, with a vector of strings, bar.

## Style

For clarity, I would recommend using two spaces instead of tabs as indentation, and placing the opening curly brace on the same line as the function signature.

## C++ basics without Ucurses

[Derek Banas' 2020 C++ Tutorial](https://www.youtube.com/watch?v=6y0bp-mnYU0) on YouTube covers the basics of the language.
