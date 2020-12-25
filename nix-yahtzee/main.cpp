#include "ucurses.h"
#include "dice.h"
#include "card.h"
#include "rerolls.h"
#include "final.h"

#define BOXES 13

START
  defaultCard();
  LOOP(count, BOXES) {
    defaultDice();
    diceCount();
    playerReRolls();
    if (reRolls > 0) {
      diceCount();
      playerReRolls();
    };
    diceCount();
    scoreCard();
    scoringSelection();
  };
  clear();
  outPutScores();
  rPuts(" Press any key to close... ");
END
