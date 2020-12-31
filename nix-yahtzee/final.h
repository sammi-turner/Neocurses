/* Total of the upper section */
int upperTotal() {
  return toInt(score1s) + toInt(score2s) + toInt(score3s) + toInt(score4s) + toInt(score5s) + toInt(score6s);
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
  return upperTotal() + upperBonus() + toInt(scoreTK) + toInt(scoreFK) + toInt(scoreFH)
  + toInt(scoreSS) + toInt(scoreLS) + toInt(scoreCH) + toInt(scoreYA);
}

/* Scores written to both the file "final.txt", and the screen */
void outPutScores() {
  clear();
  string nextLine = "";
  string outPut[22];
  
  outPut[0] = "  FINAL SCORE CARD";
  outPut[1] = "";
  outPut[2] = "  Ones                " + score1s;
  outPut[3] = "  Twos                " + score2s;
  outPut[4] = "  Threes              " + score3s;
  outPut[5] = "  Fours               " + score4s;
  outPut[6] = "  Fives               " + score5s;
  outPut[7] = "  Sixes               " + score6s;
  outPut[8] = "";
  outPut[9] = "  Upper Total         " + toString(upperTotal());
  outPut[10] = "  Upper Bonus         " + toString(upperBonus());
  outPut[11] = "";
  outPut[12] = "  Three of a kind     " + scoreTK;
  outPut[13] = "  Four of a kind      " + scoreFK;
  outPut[14] = "  Full House          " + scoreFH;
  outPut[15] = "  Small Straight      " + scoreSS;
  outPut[16] = "  Large Straight      " + scoreLS;
  outPut[17] = "  Chance              " + scoreCH;
  outPut[18] = "  Yahtzee             " + scoreYA;
  outPut[19] = "";
  outPut[20] = "  GRAND TOTAL         " + toString(grandTotal());
  outPut[21] = "";

  LOOP(line, 22) {
    nextLine = outPut[line] + "\n";
    fileAppend("final.txt", nextLine);
    rPuts(nextLine);
  }
}