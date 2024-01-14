#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

const int BUCKET_SIZE = 999883;

struct Word {
  int hashValue;
  string word;
};

template <typename S>
struct Node {
  S data;
  Node* next;
};

template <typename S>
class Stack{
private:

  Node<S>* head;
  int length;
  
public:

  Stack(){
    length = 0;
    head = nullptr;
  }

  void add(S input){
    Node<S>* push = new Node<S>;
    push->data = input;
    if(head==nullptr){
      head = push;
    }
    else{
      Node<S>* current = head;
        while(current->next){
          current = current->next;
        }
      current->next = push;
    }
    length++;
  }

  S pop(){
    if(head ==  nullptr){
      return S();
    }
    else if (length == 1){
      Node<S>* temp = head;
      head = nullptr;
      length--;
      return temp->data;
    }
    else{
      Node<S>* current = head;
      while(current->next->next){
        current = current->next;
      }
      Node<S>* temp = current->next;
      current->next = nullptr;
      length--;
      return temp->data;
    }   
  }

  S top(){
    if (head == nullptr){
      return S();
    }
    else{
      Node<S>* current = head;
      while(current->next){
        current = current->next;
      }
      return current->data;
    }
  }

  int size(){
    return length;
  }

  bool empty(){
    if (head ==nullptr){
      return true;
    }
    return false;
  }
};

template <typename S>
void insertionSort(vector<S >& array) {
  int i, j;
  S key;

  for (i = 1; i < array.size(); i++) {
    key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

// Reads a document and indexes each line into a vector.
vector<string> documentIndexing(string document){
  vector<string> index;
  ifstream input;

  input.open(document);
  if(!input.is_open()){
    cout << "Error reading file" << endl;
    return index;
  }

  string line;
  while(getline(input, line)){
    index.push_back(line);
  }
  input.close();
  return index;
}

// Filters each word from the given text and sorts them.
vector<string> extractUniqueWords(const string& text){
  vector<string> uniqueWords;
  istringstream stream(text);
  string currentWord;

  while (stream >> currentWord) {
    string processedWord;
    for (int i = 0; i < currentWord.length(); ++i) {
      char c = currentWord[i];
      if (isalnum(c)) {
        processedWord += tolower(c);
      }
    }
    bool isDupe = false;
    for (int i = 0; i < uniqueWords.size(); ++i){
      if (uniqueWords[i] == processedWord) {
        isDupe = true;
        break;
      }
    }
    if (!isDupe) {
      uniqueWords.push_back(processedWord);
    }
  }
  insertionSort(uniqueWords);
  return uniqueWords;
}

// Removes duplicate words from a vector of strings.
vector<string> removeDupes(vector<string>& lines) {
  vector<string> uniqueWords;

  for (int i = 0; i < lines.size(); ++i) {
    istringstream iss(lines[i]);
    string word;
    while (iss >> word) {
      string processedWord;
      for (int i = 0; i < word.length(); ++i) {
        char c = word[i];
        if (isalnum(c)) {
          processedWord += tolower(c);
        }
      }
      if (!processedWord.empty()) {
        bool isDupe = false;
        for (int i = 0; i < uniqueWords.size(); ++i) {
          if (uniqueWords[i] == processedWord) {
            isDupe = true;
            break;
          }
        }
        if (!isDupe) {
          uniqueWords.push_back(processedWord);
        }
      }
    }
  }
  insertionSort(uniqueWords);
  return uniqueWords;
}

int wordHash (int key) {
  return key % BUCKET_SIZE;
}

// Insterts word into our hash table.
void insertWord(Word hashTable[], string wordToInsert){
  int hashSum = 0;
  for (int i = 0; i < wordToInsert.length(); i++){
    hashSum += (int)wordToInsert[i];
  }
  int hashedIndex = wordHash(hashSum);
  int i = 0;
  while(hashTable[(hashedIndex + i) % BUCKET_SIZE].hashValue != 0 && hashTable[(hashedIndex + i) % BUCKET_SIZE].word != ""){
      i++;
  }
  hashedIndex = (hashedIndex + i) % BUCKET_SIZE;
  hashTable[hashedIndex].hashValue = hashSum;
  hashTable[hashedIndex].word = wordToInsert;
}

// Searches for a word in the hash table and returns index.
int searchWord(Word hashTable[], string wordToSearch){
  int hashSum = 0;
  for (int i = 0; i < wordToSearch.length(); i++){
    hashSum += (int)(wordToSearch[i]);
  }
  int hashedIndex = wordHash(hashSum);
  int i = 0;
  if(hashTable[hashedIndex].hashValue == hashSum && hashTable[hashedIndex].word == wordToSearch){
    return hashedIndex;
  }
  else{
    while(hashTable[(hashedIndex + i) % BUCKET_SIZE].word != wordToSearch){
      i++;
    }
    return (hashedIndex + i) % BUCKET_SIZE;
  }
}

vector<int> andOperator(const vector<int>& List1, const vector<int>& List2) {
  vector<int> commonElements;
  int First = 0;
  int Second = 0;

  while (First < List1.size() && Second < List2.size()) {
    if (List1[First] == List2[Second]) {
      commonElements.push_back(List1[First]);
      ++First; ++Second;
    } 
    else if (List1[First] < List2[Second]) {
      ++First;
    } 
    else {
      ++Second;
    }
  }
  return commonElements;
}

vector<int> orOperator(vector<int> List1, vector<int> List2){
  vector<int> mergedList;
  int First = 0;
  int Second = 0;

  while (First < List1.size() && Second < List2.size()){
    if (List1[First] == List2[Second]){
      mergedList.push_back(List1[First]);
      ++First;
      ++Second;
    }
    else if (List1[First] < List2[Second]){
      mergedList.push_back(List1[First]);
      ++First;
    }
    else{
      mergedList.push_back(List2[Second]);
      ++Second;
    }
  }
  while (First < List1.size()) {
    mergedList.push_back(List1[First]);
    ++First;
  }
  while (Second < List2.size()) {
    mergedList.push_back(List2[Second]);
    ++Second;
  } 
  return mergedList;
}

vector<int> notOperator(string document, Word hashTable[], string termToExclude){
  
  vector<int> results;
  vector<string> documentLines = documentIndexing(document);
  
  for(int i = 0; i < documentLines.size(); i++){
    results.push_back(i + 1);
    vector<string> vocab = extractUniqueWords(documentLines[i]);

    for(int j = 0; j < vocab.size(); j++){
      int hashedIndex = searchWord(hashTable, vocab.at(j));
      
      if(hashTable[hashedIndex].word == termToExclude){
        results.pop_back();
        break;
      }
    }
  }
  if(results.empty()){
    results.push_back(-1);
  }
  return results;
}

vector<int> andorOperator(string document, Word hashTable[], string wordtoHash){
  vector<int> foundDocuments;
  vector<string> documentLines = documentIndexing(document);

  for(int i = 0; i < documentLines.size(); i++){
    vector<string> vocab = extractUniqueWords(documentLines[i]);
    bool termFound = false;

    for(int j = 0; j < vocab.size(); j++){
      int hashedIndex = searchWord(hashTable, vocab.at(j));
      if(hashTable[hashedIndex].word == wordtoHash){
        termFound = true;
        break;
      }
    }
    if (termFound) {
      foundDocuments.push_back(i + 1);
    }
  }
  return foundDocuments;
}

// Processes search instructions and writes results to new file.
void processSearch(string document, string instruction, string queries, Word hashTable[]) {
  ifstream inputFile;
  ofstream outputFile;

  inputFile.open(instruction);
  outputFile.open(queries);

  vector<string> lines;
  string line;
    
  while (getline(inputFile, line)) {
    lines.push_back(line);
  }

  for (int i = 0; i < lines.size(); i++) {
    vector<string> words;
    istringstream iss(lines[i]);
    string word;

    while (iss >> word) {
      string newWord;
      for (int j = 0; j < word.length(); j++) {
        if (isalnum(word.at(j))) {
          newWord += word.at(j);
        }
      }
      words.push_back(newWord);
    }
        
    if (words.size() == 1) {
      vector<int> foundIndices;
      int hashWord = 0;
      string tempWord = words[0];

      for (int i = 0; i < tempWord.length(); i++) {
        hashWord += (int)tempWord[i];
      }
      vector<string> indices = documentIndexing(document);
      for (int j = 0; j < indices.size(); j++) {
        vector<string> vocab = extractUniqueWords(indices.at(j));
        for (int k = 0; k < vocab.size(); k++) {
          int index = searchWord(hashTable, vocab[k]);
            if (hashTable[index].hashValue == hashWord && hashTable[index].word == words[0]) {
              foundIndices.push_back(j + 1);
            }
          }
      }

    if (foundIndices.empty()) {
      string words = lines[i];
      words += "-->[]";
      outputFile << words;
    } else {
      string words = lines[i];
      words += "-->[";
      for (int i = 0; i < foundIndices.size(); i++) {
        words += to_string(foundIndices[i]);
        words += ", ";
      }
      words.erase(words.size() - 2, 2);
      words += "]";
      outputFile << words;
    }
    if (i != lines.size() - 1) {
      outputFile << endl;
    }
    } else {
      Stack<string> actualWords;
      vector<int> L1, L2, product;
      
      
      for (int i = 0; i < words.size(); i++) {
        if (words[i] == "NOT" || words[i] == "AND" || words[i] == "OR") {
          continue;
        }
        else {
          actualWords.add(words[i]);
        }
      }
      for (int i = 0; i < words.size(); i++) {
        if (words[i] == "NOT" && L1.empty()) {
          L1 = notOperator(document, hashTable, words[i+1]);
        } else if (words[i] == "NOT") {
          L2 = notOperator(document, hashTable, words[i+1]);
        }
      }
      for (int i = 0; i < words.size(); i++) {
        if (words[i] == "AND") {
          string secondWord = actualWords.pop();
          string firstWord = actualWords.pop();
          if (L1.empty()) {
            L1 = andorOperator(document, hashTable, firstWord);
          }
          if (L2.empty()) {
            L2 = andorOperator(document, hashTable, secondWord);
          }
          product = andOperator(L1, L2);
        } else if (words[i] == "OR") {
          string secondWord = actualWords.pop();
          string firstWord = actualWords.pop();
          if (L1.empty()) {
            L1 = andorOperator(document, hashTable, firstWord);
          }
          if (L2.empty()) {
            L2 = andorOperator(document, hashTable, secondWord);
          }
          product = orOperator(L1, L2);
        }
      }
      if (product.empty()) {
        string words = lines[i];
        words += "-->[]";
        outputFile << words;
      } else {
        string words = lines[i];
        words += "-->[";
        for (int i = 0; i < product.size(); i++) {
          if (product[i] != -1) {
            words += to_string(product[i]);
            words += ", ";
          }
        }
        words.erase(words.size() - 2, 2);
        words += "]";
        outputFile << words;
      }
      if (i != lines.size() - 1) {
        outputFile << endl;
      }
    }
  }
  inputFile.close();
  outputFile.close();
}


int main(int argc, char* argv[]){
  if (argc != 5){
    cerr << "Correct Input: <Text_Input_File> <Instruction_Input_File> <Hash_Matrix_Output_File> <Instruction_Result_File>" << endl;
    return 1;
  }
  string documentInput = argv[1];
  string instructionInput = argv[2];
  string docMatrixOutput = argv[3];
  string queryResults = argv[4];
    
  ofstream outputFile;
  outputFile.open(docMatrixOutput);
    
  vector<string> documentLines = documentIndexing(documentInput);
  vector<string> vocab = removeDupes(documentLines);

  Word* hashTable = new Word[BUCKET_SIZE];
  
  for(int i = 0; i < BUCKET_SIZE; i++){
    hashTable[i].word = "";
    hashTable[i].hashValue = 0;
  }
    
  for (int i = 0; i < vocab.size(); ++i){
    insertWord(hashTable, vocab[i]);     
  }
    
  for(int i = 0; i < documentLines.size(); i++){
        vector<string> tempVocab = extractUniqueWords(documentLines[i]);
        vector<int> tempHashTable;
        for(int i = 0; i < tempVocab.size(); ++i){
            int hashIndex = searchWord(hashTable, tempVocab[i]);
            tempHashTable.push_back(hashIndex);
        }
        insertionSort(tempHashTable);
        string words = to_string(i + 1) + "->[";
        for(int i = 0; i < tempVocab.size(); i++){
           words += to_string(tempHashTable[i]) + ", ";
        }
        words.erase(words.size() - 2, 2);
        words += "]";

        outputFile << words << endl;
    }
    outputFile.close();

    processSearch(documentInput, instructionInput, queryResults, hashTable);

    delete[] hashTable;

    return 0;

}
