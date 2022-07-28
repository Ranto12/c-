#include <iostream.h>
#include <fstream.h>
#include <vector.h>
#include <set.h>
#include <map.h>

using namespace std;

//****
//   Exception is a simple class that enables printing error messages when invalid conditions arise.
//****

class Exception
{
  public:
   Exception(const string& exceptionString) : ExceptionString(exceptionString) {};
   virtual void print() const;
  private:
   string ExceptionString;
};

void
Exception::print() const
{
  cout << ExceptionString << endl;
}

//****
//   AdjChecker is an abstract base class that specifies an interface for determining if two specified words are adjacent.
//****

class AdjChecker
{
  public:
   AdjChecker() {};
   virtual bool isAdjacent(const string& s1, const string& s2) const = 0;
};

//****
//   AdjWordDiffLengthChecker is a singleton class that determines if two words that differ in length by one are adjacent.
//****

class AdjWordDiffLengthChecker : public AdjChecker
{
  public:
    static AdjWordDiffLengthChecker& getInstance();
    bool isAdjacent(const string& s1, const string& s2) const;
  private:
    AdjWordDiffLengthChecker() : AdjChecker() {};
    AdjWordDiffLengthChecker(const AdjWordDiffLengthChecker&) {};
    AdjWordDiffLengthChecker& operator=(const AdjWordDiffLengthChecker&) { return *this; };
    static AdjWordDiffLengthChecker* TheAdjWordDiffLengthChecker;
};

AdjWordDiffLengthChecker&
AdjWordDiffLengthChecker::getInstance()
{
    if ( TheAdjWordDiffLengthChecker == 0 )
    {
        TheAdjWordDiffLengthChecker = new AdjWordDiffLengthChecker;
    }
    return *TheAdjWordDiffLengthChecker;
};

bool
AdjWordDiffLengthChecker::isAdjacent(const string& word1, const string& word2) const
{
   // Adjacent words include words that can be made by adding or removing one letter to make a new word.
   // To determine if two words of different length are adjacent, find the longer word and progressively
   // remove each letter and compare the subsequent word with the shorter word. If the two words are the same,
   // they are adjacent.
   std::string longerWord(word1);
   std::string shorterWord(word2);
   bool adjacent = false;
   if ( word2.length() > word1.length() )
   {
       longerWord = word2;
       shorterWord = word1;
   }
   unsigned int i = 0;
   // Stop when determine that the words are adjacent or run out of permutations 
   while ( adjacent == false && i < longerWord.length() )
   {
       std::string newWord = longerWord.substr(0,i) + longerWord.substr(i+1,longerWord.size()-1);
       adjacent = (newWord == shorterWord);
       i++;
   }
   return adjacent;
};

//****
//   AdjWordSameLengthChecker is a singleton class that determines if two words of equal length are adjacent.
//****

class AdjWordSameLengthChecker : public AdjChecker
{
  public:
    static AdjWordSameLengthChecker& getInstance();
    bool isAdjacent(const string& s1, const string& s2) const;
  private:
    AdjWordSameLengthChecker() : AdjChecker() {};
    AdjWordSameLengthChecker(const AdjWordSameLengthChecker&) {};
    AdjWordSameLengthChecker& operator=(const AdjWordSameLengthChecker&) { return *this; };
    static AdjWordSameLengthChecker* TheAdjWordSameLengthChecker;
};

AdjWordSameLengthChecker&
AdjWordSameLengthChecker::getInstance()
{
    if ( TheAdjWordSameLengthChecker == 0 )
    {
        TheAdjWordSameLengthChecker = new AdjWordSameLengthChecker;
    }
    return *TheAdjWordSameLengthChecker;
};

bool
AdjWordSameLengthChecker::isAdjacent(const std::string& word1, const std::string& word2) const
{
  // Two words of the same length are adjacent if all the letters are the same in each position except one.
  // Compare the corresponding letters in the specified words, and if only one difference is found, they
  // are adjacent.
   unsigned int numDiff = 0;
   for (unsigned int i = 0; i < word1.length(); i++)
   {
      if ( word1[i] != word2[i] )
      {
         numDiff++;
      }
   }
   return (numDiff == 1);
}

//****
//   AdjWordCheckerFactory is a singleton class responsible for determining if two words are adjacent to one another.
//   This class encapsulates the details about how adjacency is determined from any class that uses it.
//****

class AdjWordCheckerFactory
{
   public:
      static AdjWordCheckerFactory& getInstance();
      bool isAdjacent(const string& word1, const string& word2) const;
   private:
      AdjWordCheckerFactory() { };
      AdjWordCheckerFactory(const AdjWordCheckerFactory&) {};
      AdjWordCheckerFactory& operator=(const AdjWordCheckerFactory&) { return *this; };
      static AdjWordCheckerFactory* TheAdjWordCheckerFactory;
};

// Initialize the static data members
AdjWordCheckerFactory* AdjWordCheckerFactory::TheAdjWordCheckerFactory = 0;
AdjWordSameLengthChecker* AdjWordSameLengthChecker::TheAdjWordSameLengthChecker = 0;
AdjWordDiffLengthChecker* AdjWordDiffLengthChecker::TheAdjWordDiffLengthChecker = 0;

AdjWordCheckerFactory&
AdjWordCheckerFactory::getInstance()
{
    if ( TheAdjWordCheckerFactory == 0 )
    {
        TheAdjWordCheckerFactory = new AdjWordCheckerFactory;
    }
    return *TheAdjWordCheckerFactory;
};

bool
AdjWordCheckerFactory::isAdjacent(const std::string& word1, const std::string& word2) const
{
    // Use the appropriate AdjChecker subclass to determine the adjacency of two words
    bool adjacent = false;
    int lengthDiff = abs(word1.length()-word2.length());
    switch (lengthDiff)
    {
        case 0:
            adjacent = AdjWordSameLengthChecker::getInstance().isAdjacent(word1,word2);
            break;
        case 1:  
            adjacent = AdjWordDiffLengthChecker::getInstance().isAdjacent(word1,word2);
            break; 
        // If the words differ in length by 2 or more, they cannot be adjacent by definition.
        default:
            break;
    }
    return adjacent;
}

//****
//   Dictionary reads a file with one word per line and builds a associative array between each word and its adjacent words.
//****

class Dictionary
{
   public:
      Dictionary(const string& filename);
      const string& getDictName() const { return DictName; };
      unsigned int getNumWords() const { return Words.size(); };
      bool exists(const string& word) const;
      const set<string>& getWords() const { return Words; };
      void add(const string& s1, const string& s2);
      vector<string>& getAssociations(const string& s, vector<string>& assns) const;
   protected:
      void add(const string& s1, const string& s2, map<string,vector<string>* >::const_iterator& iter);
      
   private:
      string DictName;
      set<string> Words;
      map<string,vector<string>* > TheAssociationMap;
};

Dictionary::Dictionary(const std::string& filename)
 : DictName(filename)
{
   ifstream dictionary;
   dictionary.open(filename.data(), ios::nocreate);
   if (dictionary.fail() == true)
   {
      string exceptionString = "Dictionary File: " + DictName + " not found!";
      throw Exception(exceptionString);
   }
   // Read each word and add it to the word list
   string word;
   while ( dictionary.eof() == false )
   {
      dictionary >> word;
     
      // Find the adjacent words to the current word from the words read from the Dictionary so far
      set<string>::const_iterator iter = Words.begin();
      while ( iter != Words.end() )
      {
         if ( AdjWordCheckerFactory::getInstance().isAdjacent(*iter,word) == true )
         {
            add(*iter,word); // Add an association between the two words
         }
         iter++;
      }
      Words.insert(word);
   }
};

bool
Dictionary::exists(const std::string& word) const
{
   std::set<std::string>::const_iterator iter;
   if ( (iter = Words.find(word)) == Words.end() )
   {
      return false;
   }
   return true;
};

vector<string>&
Dictionary::getAssociations(const string& s, vector<string>& assns) const
{
   map<string,vector<string>* >::const_iterator iter = TheAssociationMap.find(s);
   if ( iter != TheAssociationMap.end() )
   {
      assns = *(iter->second);
   }
   return assns;
};

void
Dictionary::add(const string& s1, const string& s2)
{
   // Make sure adjacent words are associated with each other bidirectionally
   map<string,vector<string>* >::const_iterator iter1 = TheAssociationMap.find(s1);
   map<string,vector<string>* >::const_iterator iter2 = TheAssociationMap.find(s2);
   add(s1,s2,iter1);
   add(s2,s1,iter2);
};

void
Dictionary::add(const string& s1, const string& s2, map<string,vector<string>* >::const_iterator& iter)
{
   if ( iter == TheAssociationMap.end() )
   {
      // For a new word, add it and allocate space for its list of adjacent words
      vector<string>* strs = new vector<string>();
      strs->push_back(s2);
      TheAssociationMap[s1] = strs;
   }
   else
   {
      // For existing words, add the adjacent word to its list
      iter->second->push_back(s2);
   }
};

//****
//   ChainGenerator finds and prints a viable path between the specified words, first and last, if one exists;
//   otherwise, an Exception is thrown. The path found is not guaranteed to be the shortest path.
//****

class ChainGenerator
{
  public:
    ChainGenerator(Dictionary& dict, const string& first, const string& last);
  protected:
    void printPath() const;
    void validateWord(const string& word) const;
    void swapWords();
    void addPath(map<string,string>& links);
    void buildChain(const string& currWord, set<string>& usedWords, map<string,string>& links);
  private:
       vector<string> BestPaths;
       bool Finished;
       Dictionary& TheDictionary;
       string FirstWord;
       string LastWord;
};

ChainGenerator::ChainGenerator(Dictionary& dict, const string& first, const string& last)
 : TheDictionary(dict)
 , FirstWord(first)
 , LastWord(last)
 , Finished(false)
{
   // Check existence of both words in Dictionary
   validateWord(FirstWord);
   validateWord(LastWord);
   // For efficiency, start with the word that has the fewest adjacent words
   swapWords();
   set<string> usedWords;
   map<string,string> links;
   links[FirstWord] = "*"; // Add a Terminating link for the FirstWord
   buildChain(FirstWord, usedWords, links);
   printPath();
}

/****
  buildChain is a recursive function that searches the adjacent words of the current word until the
  LastWord is found or there are no more adjacent words to traverse
***/

void
ChainGenerator::buildChain(const string& currWord, set<string>& usedWords, map<string,string>& links)
{
   vector<string> adjWords;
   TheDictionary.getAssociations(currWord, adjWords); // Get current word's adjacencies
   if ( adjWords.size() > 0 ) // When there are no more adjacencies, that chain ends
   {
      usedWords.insert(currWord); // Keep the current chain to avoid duplication
      for ( vector<string>::const_iterator iter = adjWords.begin(); iter != adjWords.end(); iter++ )
      {
         string adjWord(*iter);
         // Keep building chain if LastWord is not found and not repeating a word already in chain
         if ( Finished == false && usedWords.find(adjWord) == usedWords.end() )
         {
            
            links[adjWord] = currWord;
            if ( adjWord != LastWord )
            {
               buildChain(adjWord,usedWords,links); // Keep looking for end of chain
            }
            else
            {
               // When end of chain is found, save the chain
               Finished = true;
               addPath(links);
            }
         }
      }
      if ( Finished == false )
      {
         usedWords.erase(currWord); // Done with a chain when all adjacencies traversed
      }
   }
}

void
ChainGenerator::swapWords()
{
   vector<string> firstAssns;
   vector<string> lastAssns;
   // For efficiency, ensure the FirstWord has the fewest adjacent words
   if ( TheDictionary.getAssociations(FirstWord,firstAssns).size() >
        TheDictionary.getAssociations(LastWord,lastAssns).size() )
   {
      string tmp(LastWord);
      LastWord = FirstWord;
      FirstWord = tmp;
   }
}

void
ChainGenerator::validateWord(const string& word) const
{
   if ( TheDictionary.exists(word) == false )
   {
      string exceptionString = "Word: " + word + " not found in " + TheDictionary.getDictName();
      throw Exception(exceptionString);
   }
}

void
ChainGenerator::addPath(map<string,string>& links)
{
    string s(LastWord);
    string chain(LastWord);
    // Build the path from the LastWord to the FirstWord
    // Print the solution. Note that for simplicity, no attempt is made to reverse the
    // path if FirstWord and LastWord were swapped.    
    while ( links.find(s)->first != FirstWord )
    {
       s = links.find(s)->second;
       chain = s + "-" + chain;
    } 
    BestPaths.push_back(chain);
}

void
ChainGenerator::printPath() const
{
    // Throw Exception is no connection exists
    if ( BestPaths.size() == 0 )
    {
       string exceptionString = "No Connection Found: " + FirstWord + "/" + LastWord;
       throw Exception(exceptionString);
    }
    // Print out the best paths    
    for ( unsigned int i = 0; i < BestPaths.size(); i++ )
    {
       cout << BestPaths[i] << endl;
    } 
}

int 
main(int argc, char** argv)
{
   try
   {
      if ( argc < 4 )
      {
         string exceptionString("Usage: rkg <Dictionary Filename> <Start Word> <End Word>");
         throw Exception(exceptionString);
      }
      string dictName(argv[1]);
      string firstWord(argv[2]);
      string lastWord(argv[3]);
 
      Dictionary dict(dictName);
      ChainGenerator cg(dict,firstWord,lastWord);
   }
   catch (const Exception& e)
   {
      e.print();
   }
   return 0;
}