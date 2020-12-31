#include "neo.h"
#include "routines.h"

SCROLL
  KEYPAD
  
  int result;
  bool exit = false;
  
  string mainMenu[8] = {"TODOS MENU", "Create", "Read", "Update", "Delete", "Load", "Save", "Exit"};
  
  while (!exit) {
    NO_KEYS
    NO_CURSOR
    
    result = selectOption(mainMenu, 8);
    
    if (result == 1) {
      createRoutine();
    }
    else if (result == 2) {
      readRoutine();
    }
    else if (result == 3) {
      updateRoutine();
    }
    else if (result == 4) {
      deleteRoutine();
    }
    else if (result == 5) {
      loadRoutine();
    }
    else if (result == 6) {
      saveRoutine();
    }
    else {
      exit = true;
    }
  }

  rPuts("\nPress any key to close...");
END
