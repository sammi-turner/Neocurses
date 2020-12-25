/* Up to two re-rolls are allowed */
void playerReRolls() {
  int dice = 0;
  string userInput;
  
  if (ones > 0) {
    scoreCard();
    rPuts("\n  How many ones to re-roll? ");
    userInput = nInput(1);
    if (isInt(userInput)) {
      dice = toInt(userInput);
      if (dice >= 0 && dice <= ones) {     
        reRolls += dice;
        ones -= dice;
      };
    };
  };

  if (twos > 0) {
    scoreCard();
    rPuts("\n  How many twos to re-roll? ");
    userInput = nInput(1);
    if (isInt(userInput)) {
      dice = toInt(userInput);
      if (dice >= 0 && dice <= twos) {     
        reRolls += dice;
        twos -= dice;
      };
    };
  };
  
  if (threes > 0) {
    scoreCard();
    rPuts("\n  How many threes to re-roll? ");
    userInput = nInput(1);
    if (isInt(userInput)) {
      dice = toInt(userInput);
      if (dice >= 0 && dice <= threes) {     
        reRolls += dice;
        threes -= dice;
      };
    };
  };

  if (fours > 0) {
    scoreCard();
    rPuts("\n  How many fours to re-roll? ");
    userInput = nInput(1);
    if (isInt(userInput)) {
      dice = toInt(userInput);
      if (dice >= 0 && dice <= fours) {     
        reRolls += dice;
        fours -= dice;
      };
    };
  };

  if (fives > 0) {
    scoreCard();
    rPuts("\n  How many fives to re-roll? ");
    userInput = nInput(1);
    if (isInt(userInput)) {
      dice = toInt(userInput);
      if (dice >= 0 && dice <= fives) {     
        reRolls += dice;
        fives -= dice;
      };
    };
  };

  if (sixes > 0) {
    scoreCard();
    rPuts("\n  How many sixes to re-roll? ");
    userInput = nInput(1);
    if (isInt(userInput)) {
      dice = toInt(userInput);
      if (dice >= 0 && dice <= sixes) {     
        reRolls += dice;
        sixes -= dice;
      };
    };
  };  
}
