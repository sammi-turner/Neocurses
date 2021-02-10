/* Initialise variables */
int reRolls, ones, twos, threes, fours, fives, sixes;

/* Applied at the start of each round */
void defaultDice() {
  reRolls = 5;
  ones = 0;
  twos = 0;
  threes = 0;
  fours = 0;
  fives = 0;
  sixes = 0;
}

/* Rolling the dice and recording the results */
void diceCount() {
  seed();
  while (reRolls > 0) {
    int roll = random(6);
    reRolls--;
    switch (roll) {
      case 1:
        ones++;
        break;
      case 2:
        twos++;
        break;
      case 3:
        threes++;
        break;
      case 4:
        fours++;
        break;
      case 5:
        fives++;
        break;
      case 6:
        sixes++;
        break;
    };
  };
}

/* Three of a kind score function */
int threeOfAKind() {
  int value = 0;
  if (ones > 2 || twos > 2 || threes > 2 || fours > 2 || fives > 2 || sixes > 2) {
    value = ones + (twos * 2) + (threes * 3) + (fours * 4) + (fives * 5) + (sixes * 6);
  };
  return value;
}

/* Four of a kind score function */
int fourOfAKind() {
  int value = 0;
  if (ones > 3 || twos > 3 || threes > 3 || fours > 3 || fives > 3 || sixes > 3) {
    value = ones + (twos * 2) + (threes * 3) + (fours * 4) + (fives * 5) + (sixes * 6);
  };
  return value;
}

/* Full house score function */
int fullHouse() {
  int value = 0;
  bool tripleTest = false;
  bool pairTest = false;

  if (ones == 3 || twos == 3 || threes == 3 || fours == 3 || fives == 3 || sixes == 3) {
    tripleTest = true;
  };

  if (ones == 2 || twos == 2 || threes == 2 || fours == 2 || fives == 2 || sixes == 2) {
    pairTest = true;
  };

  if (tripleTest && pairTest) {
    value = 25;
  };

  if (ones == 5 || twos == 5 || threes == 5 || fours == 5 || fives == 5 || sixes == 5) {
    value = 25;
  };
  
  return value;
}

/* Small straight score function */
int smallStraight() {
  int value = 0;

  if (ones > 0 && twos > 0 && threes > 0 && fours > 0) {
    value = 30;
  };

  if (twos > 0 && threes > 0 && fours > 0 && fives > 0) {
    value = 30;
  };

  if (threes > 0 && fours > 0 && fives > 0 && sixes > 0) {
    value = 30;
  };

  return value;
}

/* Large straight score function */
int largeStraight() {
  int value = 0;

  if (ones > 0 && twos > 0 && threes > 0 && fours > 0 && fives > 0) {
    value = 40;
  };

  if (twos > 0 && threes > 0 && fours > 0 && fives > 0 && sixes > 0) {
    value = 40;
  };
  return value;
}

/* The total of all dice. Regardless of arrangement */
int chance() {
  return ones + (twos * 2) + (threes * 3) + (fours * 4) + (fives * 5) + (sixes * 6);
}

/* Yahtzee score function */
int yahtzee() {
  int value = 0;
  if (ones == 5 || twos == 5 || threes == 5 || fours == 5 || fives == 5 || sixes == 5) {
    value = 50;
  };
  return value;
}