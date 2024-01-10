#ifndef LireRoman_H
#define LireRoman_H

using namespace std;

class LireRoman
{
  private:
    ifstream book;
    map<string, vector<unsigned long>> roman;
    
    string wordCleaner(string &word);

  public:
    LireRoman(const string &);
    ~LireRoman();
    void showroman();
    unsigned long getWordCount(const string &);
    vector<unsigned long> getWordLines(const string &);
};

LireRoman::LireRoman(const string &filename)
{
  book.open(filename);
  if (!book.is_open())
    throw "Error opening file " + filename;
  string line, word;
  for (unsigned long lineNum = 1; getline(book, line); lineNum++) {
    istringstream iss(line);
    while (iss >> word) {
      word = wordCleaner(word);
      if (!word.empty())
        roman[word].push_back(lineNum);
    }
  }
}

LireRoman::~LireRoman()
{
  if (book.is_open())
    book.close();
}

string LireRoman::wordCleaner(string &word)
{
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  if (!word.empty()) {
    while (!word.empty() && !isalnum(word.front()))
      word.erase(0, 1);
    while (!word.empty() && !isalnum(word.back()))
      word.pop_back();
  }
  return word;
}

void LireRoman::showroman()
{
  for (auto &word : roman) {
    cout << word.first << ": ";
    for (auto &line : word.second)
      cout << line << " - ";
    cout << endl;
  }
}

unsigned long LireRoman::getWordCount(const string &word)
{
  return roman[word].size();
}

vector<unsigned long> LireRoman::getWordLines(const string &word) {
  if (roman.find(word) != roman.end())
    return roman[word];
  return {};
}



#endif // LireRoman_H