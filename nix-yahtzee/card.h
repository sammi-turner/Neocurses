/* Initialise scores */
int score1s = -1;
int score2s = -1;
int score3s = -1;
int score4s = -1;
int score5s = -1;
int score6s = -1;
int scoreTK = -1;
int scoreFK = -1;
int scoreFH = -1;
int scoreSS = -1;
int scoreLS = -1;
int scoreCH = -1;
int scoreYA = -1;

void scoreCard() {
  clear();
  printw("  SCORE CARD\n");

  if (score1s == -1) {
    printw("\n  Ones               a");
  }
  else {
    printw("\n  Ones               %d", score1s);
  }

  if (score2s == -1) {
    printw("\n  Twos               b");
  }
  else {
    printw("\n  Twos               %d", score2s);
  }

  if (score3s == -1) {
    printw("\n  Threes             c");
  }
  else {
    printw("\n  Threes             %d", score3s);
  }

  if (score4s == -1) {
    printw("\n  Fours              d");
  }
  else {
    printw("\n  Fours              %d", score4s);
  }

  if (score5s == -1) {
    printw("\n  Fives              e");
  }
  else {
    printw("\n  Fives              %d", score5s);
  }

  if (score6s == -1) {
    printw("\n  Sixes              f");
  }
  else {
    printw("\n  Sixes              %d", score6s);
  }

  if (scoreTK == -1) {
    printw("\n  Three of a Kind    g");
  }
  else {
    printw("\n  Three of a Kind    %d", scoreTK);
  }

  if (scoreFK == -1) {
    printw("\n  Four of a Kind     h");
  }
  else {
    printw("\n  Four of a Kind     %d", scoreFK);
  }

  if (scoreFH == -1) {
    printw("\n  Full House         i");
  }
  else {
    printw("\n  Full House         %d", scoreFH);
  }

  if (scoreSS == -1) {
    printw("\n  Small Straight     j");
  }
  else {
    printw("\n  Small Straight     %d", scoreSS);
  }

  if (scoreLS == -1) {
    printw("\n  Large Straight     k");
  }
  else {
    printw("\n  Large Straight     %d", scoreLS);
  }

  if (scoreCH == -1) {
    printw("\n  Chance             l");
  }
  else {
    printw("\n  Chance             %d", scoreCH);
  }

  if (scoreYA == -1) {
    printw("\n  Yahtzee            m");
  }
  else {
    printw("\n  Yahtzee            %d", scoreYA);
  }

  printw("\n\n  DICE HELD\n\n  ");
  printw("%d 1s, ", ones);
  printw("%d 2s, ", twos);
  printw("%d 3s, ", threes);
  printw("%d 4s, ", fours);
  printw("%d 5s, ", fives);
  printw("%d 6s, ", sixes);
  printw("\n\n");
  refresh();
}

/* Loop to insure that a valid input has been entered */
void scoringSelection() {
  string choice;
  bool exitLoop = false;

  while (exitLoop == false) {
    scoreCard();
    printw("  Which scorebox? ");
    refresh();
    choice = nInput(1);

    if ((choice == "a") && (score1s == -1)) {
      score1s = ones;
      exitLoop = true;
    };

    if ((choice == "b") && (score2s == -1)) {
      score2s = (twos * 2);
      exitLoop = true;
    };

    if ((choice == "c") && (score3s == -1)) {
      score3s = (threes * 3);
      exitLoop = true;
    };

    if ((choice == "d") && (score4s == -1)) {
      score4s = (fours * 4);
      exitLoop = true;
    };

    if ((choice == "e") && (score5s == -1)) {
      score5s = (fives * 5);
      exitLoop = true;
    };

    if ((choice == "f") && (score6s == -1)) {
      score6s = (sixes * 6);
      exitLoop = true;
    };

    if ((choice == "g") && (scoreTK == -1)) {
      scoreTK = threeOfAKind();
      exitLoop = true;
    };

    if ((choice == "h") && (scoreFK == -1)) {
      scoreFK = fourOfAKind();
      exitLoop = true;
    };

    if ((choice == "i") && (scoreFH == -1)) {
      scoreFH = fullHouse();
      exitLoop = true;
    };

    if ((choice == "j") && (scoreSS == -1)) {
      scoreSS = smallStraight();
      exitLoop = true;
    };

    if ((choice == "k") && (scoreLS == -1)) {
      scoreLS = largeStraight();
      exitLoop = true;
    };

    if ((choice == "l") && (scoreCH == -1)) {
      scoreCH = chance();
      exitLoop = true;
    };

    if ((choice == "m") && (scoreYA == -1)) {
      scoreYA = yahtzee();
      exitLoop = true;
    };
  }
}
