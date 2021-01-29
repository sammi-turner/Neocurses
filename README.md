# Neocurses

[Ncurses](https://en.wikipedia.org/wiki/Ncurses) updated to handle C++ strings and vectors.

This is a Nix (GNU/Linux, MacOS, BSD, etc) specific iteration of the cross-platform [Sugar.hpp](https://github.com/sammi-turner/Sugar-Hpp) repo.

## Programs using Neocurses in this repo

* A todos app.

* A command-line version of Yahtzee.

## Bash aliases to simplify workflow

```
# GNU Compile Ncurses C++20
alias c20='g++ -lncurses main.cpp -flto -O -std=c++20'

# Run Binary With Default Name
alias run='./a.out'
```

## System headers

Required for these and many other functions.

```
#include <unistd.h>
#include <signal.h>
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

## SCROLL Macro

```
SCROLL
```

aliases

```
int main() { initscr(); signal (SIGWINCH, NULL); scrollok(stdscr, TRUE);
```

Sets up a scrolling virtual terminal in conjunction with the End Macro.

## FIXED Macro

```
FIXED
```

aliases

```
int main() { initscr(); signal (SIGWINCH, NULL);
```

Sets up a non-scrolling virtual terminal in conjunction with the End Macro.

## END Macro

```
END
```

aliases

```
getch(); endwin(); }
```

Works in conjunction with either the Scroll or the Fixed Macro.

## KEYPAD Macro

```
KEYPAD
```

aliases

```
keypad(stdscr, TRUE);
```

Allows the 'getch()' function to recognise input from keys that are not echoed to the virtual terminal.

## NO_CURSOR Macro

```
NO_CURSOR
```

aliases

```
curs_set(0);
```

Stops the cursor from being shown in the virtual terminal.

## NO_KEYS Macro

```
NO_KEYS
```

aliases

```
noecho();
```

Stops character keypresses from being shown in the virtual terminal.

## CURSOR Macro

```
CURSOR
```

aliases

```
curs_set(1);
```

Reverses the effect of the 'NO_CURSOR' macro.

## KEYS Macro

```
KEYS
```

aliases

```
echo();
```

Reverses the effect of the 'NO_KEYS' macro.

## LOOP Macro

```
LOOP(foo, bar)
```

aliases

```
for (int foo = 0; foo < bar; foo++)
```

## CATCH Macro

```
CATCH(foo)
```

aliases

```
catch (std::invalid_argument& foo)
```

## System calls

```
systemCall(foo)
```

Native system calls in C/C++ take a C-string (null-terminated char array) as their argument. This function takes a C++ string as its parameter
instead.

## Terminal Rows And Columns

```
tRows()
```

Function returns an integer corresponding to the number of rows in the terminal.

```
rColumns()
```

Function returns an integer corresponding to the number of columns in the terminal.

## Fixed length input

```
nInput(foo)
```

Takes buffered input of maximum length foo inside the virtual terminal, and stores it as a C++ string.

## Output text

```
rPuts(foo)
```

Outputs the C++ string foo to the virtual terminal, and performs a 'refresh()' afterwards.

```
centerText(foo)
```

Like 'rPuts', but outputs the string foo to the horizontal center of the virtual terminal.

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

## Parsing Strings

```
superString(foo, bar)
```

Returns '1' if the string foo, contains the string bar, or '0' if it does not.

```
firstWord(foo)
```

Returns the first word of a string, foo, minus any whitespace.

```
otherWords(foo)
```

Returns the string, foo, minus initial whitespace and the first word of the string.

```
wordCount(foo)
```

Returns an integer corresponding to the number of words in the string, foo.

```
nthWord(foo, bar)
```

Returns a word taken from the string, foo, corresponding to the zero-index, bar.

```
wordFromSentence(foo, bar)
```

Returns '1' if the string foo, occurs as a space-delimited word in the sentence string, bar. Returns '0' if it does not.

```
spaceToDelim(foo, bar)
```

Returns the string obtained by replacing every space in the string foo, with the string, bar.

```
delimToSpace(foo, bar)
```

Returns the string obtained by replacing every instance of the string bar, in the string foo, with a space.

## Alphabetic Strings

```
isAlphabetic(foo)
```

Checks if the string foo is purely alphabetic.

```
isLowerCase(foo)
```

Checks if the string foo is purely lower case.

```
isUpperCase(foo)
```

Checks if the string foo is purely upper case.

## Numeric Strings

```
isInt(foo)
```

Checks if the string foo represents an integer.

```
isDouble(foo)
```

Checks if the string foo represents a double.

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

## Menu Helper Functions

```
renderMenu(foo, bar, baz)
```

Required by the 'selectOption' function.

```
selectOption(foo, bar)
```

Once the 'KEYPAD', 'NO_CURSOR' and 'NO_KEYS' macros have been called, this function takes an array of strings, foo, of integer size, bar.

It prints a menu from the array of strings and allows the user to select a non-zero indexed item from the menu using the 'up' and 'down' arrow keys, with
'enter' to select.

This function returns the index of the selected item.

An example of this function in use is shown in 'fruit.png'.

## Indented Menu Helper Functions

```
indentRenderMenu(foo, bar, baz)
```

Required by the 'indentSelectOption' function.

```
indentSelectOption(foo, bar)
```

Works in the same way as 'selectOption' but with the 0th element of the array being an indent that is applied to every line in the menu.

## Style

For clarity, I would recommend using two spaces instead of tabs as indentation, and placing the opening curly brace on the same line as the function signature.

## C++ basics without Neocurses

[Derek Banas' 2020 C++ Tutorial](https://www.youtube.com/watch?v=6y0bp-mnYU0) on YouTube covers the basics of the language.
