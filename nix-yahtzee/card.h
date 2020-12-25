/* Initialise scores */
string score1s, score2s, score3s, score4s, score5s, score6s,
  scoreTK, scoreFK, scoreFH, scoreSS, scoreLS, scoreCH, scoreYA;

/* Applied at the start of each game */
void defaultCard() {
  score1s = "a";
  score2s = "b";
  score3s = "c";
  score4s = "d";
  score5s = "e";
  score6s = "f";
  scoreTK = "g";
  scoreFK = "h";
  scoreFH = "i";
  scoreSS = "j";
  scoreLS = "k";
  scoreCH = "l";
  scoreYA = "m";
}

/* Showing the dice rolled by the player */
void displayDice() {
  rPuts("\n  DICE HELD\n");
  rPuts("\n  Ones               " + toString(ones));
  rPuts("\n  Twos               " + toString(twos));
  rPuts("\n  Threes             " + toString(threes));
  rPuts("\n  Fours              " + toString(fours));
  rPuts("\n  Fives              " + toString(fives));
  rPuts("\n  Sixes              " + toString(sixes));
  rPuts("\n");
  rPuts("\n  Re-rolls           " + toString(reRolls));
  rPuts("\n");
}

void scoreCard() {
  clear();
  rPuts("\n  SCORE CARD\n");
  rPuts("\n  Ones               " + score1s);
  rPuts("\n  Twos               " + score2s);
  rPuts("\n  Thress             " + score3s);
  rPuts("\n  Fours              " + score4s);
  rPuts("\n  Fives              " + score5s);
  rPuts("\n  Sixes              " + score6s);
  rPuts("\n");
  rPuts("\n  Three of a Kind    " + scoreTK);
  rPuts("\n  Four of a Kind     " + scoreFK);
  rPuts("\n  Full House         " + scoreFH);
  rPuts("\n  Small Straight     " + scoreSS);
  rPuts("\n  Large Straight     " + scoreLS);
  rPuts("\n  Chance             " + scoreCH);
  rPuts("\n  Yahtzee            " + scoreYA);
  rPuts("\n");
  displayDice();
}

/* Loop to insure that a valid input has been entered */
void scoringSelection() {
  string choice;
  int num;
  bool exitLoop = false;

  while (exitLoop == false) {
    scoreCard();
    rPuts("\n  Which scorebox? ");
    choice = nInput(1);

    if ((choice == "a") && (score1s == "a")) {
      num = ones;
      score1s = toString(num);
      exitLoop = true;
    };

    if ((choice == "b") && (score2s == "b")) {
      num = (twos * 2);
      score2s = toString(num);
      exitLoop = true;
    };

    if ((choice == "c") && (score3s == "c")) {
      num = (threes * 3);
      score3s = toString(num);
      exitLoop = true;
    };

    if ((choice == "d") && (score4s == "d")) {
      num = (fours * 4);
      score4s = toString(num);
      exitLoop = true;
    };

    if ((choice == "e") && (score5s == "e")) {
      num = (fives * 5);
      score5s = toString(num);
      exitLoop = true;
    };

    if ((choice == "f") && (score6s == "f")) {
      num = (sixes * 6);
      score6s = toString(num);
      exitLoop = true;
    };

    if ((choice == "g") && (scoreTK == "g")) {
      num = threeOfAKind();
      scoreTK = toString(num);
      exitLoop = true;
    };

    if ((choice == "h") && (scoreFK == "h")) {
      num = fourOfAKind();
      scoreFK = toString(num);
      exitLoop = true;
    };

    if ((choice == "i") && (scoreFH == "i")) {
      num = fullHouse();
      scoreFH = toString(num);
      exitLoop = true;
    };

    if ((choice == "j") && (scoreSS == "j")) {
      num = smallStraight();
      scoreSS = toString(num);
      exitLoop = true;
    };

    if ((choice == "k") && (scoreLS == "k")) {
      num = largeStraight();
      scoreLS = toString(num);
      exitLoop = true;
    };

    if ((choice == "l") && (scoreCH == "l")) {
      num = chance();
      scoreCH = toString(num);
      exitLoop = true;
    };

    if ((choice == "m") && (scoreYA == "m")) {
      num = yahtzee();
      scoreYA = toString(num);
      exitLoop = true;
    };
  }
}
