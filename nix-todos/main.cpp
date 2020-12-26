#include "neo.h"
#include "routines.h"

SCROLL
  string userInput = "";
  rPuts("\n  TERMINAL TODOS\n");
  while (userInput != "e") {
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
