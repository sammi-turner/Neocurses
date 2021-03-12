/* Total of the upper section */
int upperTotal() {
  return (score1s + score2s + score3s + score4s + score5s + score6s);
}

/* If the upper section total is greater than 62, then a bonus of 35 is awarded */
int upperBonus() {
  int value = 0;
  if (upperTotal() > 62) {
    value = 35;
  }
  return value;
}

/* Total of all scores */
int grandTotal() {
  return (upperTotal() + upperBonus() + scoreTK + scoreFK + scoreFH + scoreSS + scoreLS + scoreCH + scoreYA);
}

/* Scores written to both the file "final.txt", and the screen */
void outPutScores() {
  clear();
  string nextLine = "";
  string outPut[22];
  
  outPut[0] = "  FINAL SCORE CARD";
  outPut[1] = "";
  outPut[2] = "  Ones                " + to_string(score1s);
  outPut[3] = "  Twos                " + to_string(score2s);
  outPut[4] = "  Threes              " + to_string(score3s);
  outPut[5] = "  Fours               " + to_string(score4s);
  outPut[6] = "  Fives               " + to_string(score5s);
  outPut[7] = "  Sixes               " + to_string(score6s);
  outPut[8] = "";
  outPut[9] = "  Upper Total         " + to_string(upperTotal());
  outPut[10] = "  Upper Bonus         " + to_string(upperBonus());
  outPut[11] = "";
  outPut[12] = "  Three of a kind     " + to_string(scoreTK);
  outPut[13] = "  Four of a kind      " + to_string(scoreFK);
  outPut[14] = "  Full House          " + to_string(scoreFH);
  outPut[15] = "  Small Straight      " + to_string(scoreSS);
  outPut[16] = "  Large Straight      " + to_string(scoreLS);
  outPut[17] = "  Chance              " + to_string(scoreCH);
  outPut[18] = "  Yahtzee             " + to_string(scoreYA);
  outPut[19] = "";
  outPut[20] = "  GRAND TOTAL         " + to_string(grandTotal());
  outPut[21] = "";

  LOOP(line, 22) {
    nextLine = outPut[line] + "\n";
    fileAppend("final.txt", nextLine);
    rPuts(nextLine);
  }
}
