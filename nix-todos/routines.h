vector<string> vecList;

void createRoutine() {
  string cInput = "";
  while (cInput != "b") {
    rPuts("\n  Enter the item text, or 'b' to go back? ");
    cInput = nInput(60);
    if (cInput != "b") {
      vecList.push_back(cInput);
    }
  }
}

void readRoutine() {
  int count = 0;
  rPuts("\n");
  for(string & line : vecList) {
    count ++;
    rPuts("  " + toString(count) + ". " + line + "\n");
  }
}

void updateItem(int arg) {
  string itemText = "";
  rPuts("\n  Enter the item text, or 'b' to go back? ");
  itemText = nInput(60);
  if (itemText != "b") {
    vecList[arg - 1] = itemText;
    rPuts("\n  Item updated.\n");
  }
}

void updateRoutine() {
  string uInput = "";
  int itemNum;
  rPuts("\n  Number of the item to update? ");
  uInput = nInput(2);
	
  if (isInt(uInput)) {
    itemNum = toInt(uInput);
    if (itemNum > 0 && itemNum <= vecList.size()) {
      updateItem(itemNum);
    }
  }
}

void deleteRoutine() {
  string dInput = "";
  int dNum;
  rPuts("\n  File or item to delete? ");
  dInput = nInput(30);
  if (!isInt(dInput)) {
    fileDelete(dInput);
    rPuts("\n  File deleted.\n");   
  }
  else {
    dNum = toInt(dInput);
    if (dNum > 0 && dNum <= vecList.size()) {
      dNum--;
      vecList.erase(vecList.begin() + dNum);
      rPuts("\n  Item deleted.\n");
    }
  }
}

void loadRoutine() {
  string lInput = "";
  int listSize = vecList.size();
    
  rPuts("\n  File to load? ");
  lInput = nInput(30);
  if (fileExists(lInput)) {
    LOOP(count, listSize) {
      vecList.erase(vecList.begin() + count);
    }

    readStrings(lInput, vecList);
    rPuts("\n  File loaded.\n");
  }
  else {
    rPuts("\n  File loading failed.\n");
  }
}

void saveRoutine() {
  string sInput = "";
  string toAdd = "";
  rPuts("\n  Name of file to save or overwrite? ");
  sInput = nInput(30);
  if (sInput != "\n") {
    overWriteStrings(sInput, vecList);
    rPuts("\n  File saved.\n");
  }
}
