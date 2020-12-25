#include "ucurses.h"
#include "routines.h"

START
  string userInput = "";
  while (userInput != "e") {
    clear();
    rPuts("\n  TERMINAL TODOS\n");
    rPuts("\n  Create (c), read (r), update (u), delete (d), load (l), save (s) or exit (e)? ");
    userInput = nInput(1);
    
    if (userInput == "c") {
      createRoutine();
    }
    else if (userInput == "r") {
      readRoutine();
    }
    else if (userInput == "u") {
      updateRoutine();
    }
    else if (userInput == "d") {
      deleteRoutine();
    }
    else if (userInput == "l") {
      loadRoutine();
    }
    else if (userInput == "s") {
      saveRoutine();
    }
    else {
      rPuts("\n  Press any key to close... ");
    }
  }
END
