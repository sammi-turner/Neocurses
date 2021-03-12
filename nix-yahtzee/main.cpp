#include "neo.h"
#include "dice.h"
#include "card.h"
#include "rerolls.h"
#include "final.h"

#define BOXES 13

FIXED
  KEYPAD
  LOOP(count, BOXES) {
    defaultDice();
    diceCount();
    playerReRolls();
    if (reRolls > 0) {
      diceCount();
      playerReRolls();
    };
    diceCount();
    scoringSelection();
  };
  outPutScores();
  printw("  Press any key to close. ");
  refresh();
END
