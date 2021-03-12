/* Up to two re-rolls are allowed */
void playerReRolls() {
  int dice = -1;
  string userInput;
  
  if (ones > 0) {
    while (dice < 0 || dice > ones) {
      scoreCard();
      printw("  You have %d re-rolls.\n", reRolls);
      printw("\n  How many ones to re-roll? ");
      refresh();
      userInput = nInput(1);
      dice = toInt(userInput);
    }    
    reRolls += dice;
    ones -= dice;
    dice = -1;
  };

  if (twos > 0) {
    while (dice < 0 || dice > twos) {
      scoreCard();
      printw("  You have %d re-rolls.\n", reRolls);
      printw("\n  How many twos to re-roll? ");
      refresh();
      userInput = nInput(1);
      dice = toInt(userInput);
    }    
    reRolls += dice;
    twos -= dice;
    dice = -1;
  };
  
  if (threes > 0) {
    while (dice < 0 || dice > threes) {
      scoreCard();
      printw("  You have %d re-rolls.\n", reRolls);
      printw("\n  How many threes to re-roll? ");
      refresh();
      userInput = nInput(1);
      dice = toInt(userInput);
    }    
    reRolls += dice;
    threes -= dice;
    dice = -1;
  };

  if (fours > 0) {
    while (dice < 0 || dice > fours) {
      scoreCard();
      printw("  You have %d re-rolls.\n", reRolls);
      printw("\n  How many fours to re-roll? ");
      refresh();
      userInput = nInput(1);
      dice = toInt(userInput);
    }    
    reRolls += dice;
    fours -= dice;
    dice = -1;
  };

  if (fives > 0) {
    while (dice < 0 || dice > fives) {
      scoreCard();
      printw("  You have %d re-rolls.\n", reRolls);
      printw("\n  How many fives to re-roll? ");
      refresh();
      userInput = nInput(1);
      dice = toInt(userInput);
    }    
    reRolls += dice;
    fives -= dice;
    dice = -1;
  };

   if (sixes > 0) {
    while (dice < 0 || dice > sixes) {
      scoreCard();
      printw("  You have %d re-rolls.\n", reRolls);
      printw("\n  How many sixes to re-roll? ");
      refresh();
      userInput = nInput(1);
      dice = toInt(userInput);
    }    
    reRolls += dice;
    sixes -= dice;
    dice = -1;
  }; 
}
