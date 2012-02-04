// ROBERT DUNN
// functions.cpp
// LOLCODE translator
//
// Robert Dunn and Ben Finley


#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

//A NOTE ON CONSTANTS:
// As you may have noticed, all of the keywords are hardcoded.
// There is a very good reason for this seemingly bad code. It
// has been suggested that the use of a const string array is in 
// order, but I feel that this would make the code very difficult 
// to read. Adding a constant for each word would be just plain 
// stupid. Therefore, all keywords are hardcoded. 


void getWordAndPick(ifstream & fin, ofstream & fout, const string & indexWord)
{
  
  if (indexWord == "HAI")
  {
    //unspecified
  }
  else if (indexWord == "CAN")
  {
    startBlock(fin, fout);
  }
  else if (indexWord == "VISIBLE")
  {
    output(fin, fout);
  }
  else if (indexWord == "IM")
  {
    loop(fin, fout);
  }
  else if (indexWord == "BTW")
  {
    comment(fin, fout);
  }
  else if (indexWord == "I")
  {
    declareVariable(fin, fout);
  }
  else if (indexWord == "KTHXBYE")
  {
    endCodeBlock(fin, fout);
  }
  else if (indexWord == "UPZ")
  {
    increment(fin, fout);
  }
  else if (indexWord == "IZ")
  {
    //comparator
  }
  else if (indexWord == "GIMMEH")
  {
    readin(fin, fout);
  }
  else if (indexWord == "OBTW")
  {
    commentBlock(fin, fout);
  }
  
  
}

void startBlock(ifstream & fin, ofstream & fout)
{
  string words;
  fin >> words;
  if (words == "HAZ")
  {
    fin>> words;
    if (words == "STDIO?")
    {
      fout<< "#include <iostream>"<<endl
          << "#include <fstream>"<<endl    
          << "using namespace std;"<<endl<<endl
          << "int main()" <<endl<< "{"<<endl;
    }
  }
  else
  {
    cerr<< "OH NOES! Syntax error for \"CAN HAS STDIO?\""<<endl;
    exit(2);
  }
}

void output(ifstream & fin, ofstream & fout)
{
  string waste, output;
  char readin, variableReadin;
  bool keepGoing = true;
  

  fout<< "cout <<";
  
  do
  {
    fin.get(readin);
    switch (readin) 
    {
      case '"':
      output = readBetweenQuotes(fin, fout);
        fout<< " \"" << output << "\" "; 
        break;
      case 'V':
        fin.get(variableReadin);
        if (variableReadin == 'A')
        {
          fin.get(variableReadin);
          if (variableReadin == 'R')
          {
            fout << "var"; 
          }
        }
        break;
      case 'N':
        fout << " << ";
        break;
      case '\n':
        fout << "<< endl;" << endl;
        keepGoing = false;
        break;  
    }
  }while (keepGoing);
}

string readBetweenQuotes(ifstream & fin, ofstream & fout)
{
  char readin;
  string stringLiteral = "";
  do
  {
    fin.get(readin);
    if (readin != '"')
      stringLiteral += readin;
  }while (readin != '"');
  
  return stringLiteral;
}

void loop(ifstream & fin, ofstream & fout)
{
  string input, input2, input3;
  string readin;
  bool keepGoing = true;
  
  fin >> input >> input2;
  if (input == "IN")
  {
    if (input2 == "YR")
    {
      fout << "while(true)" << endl << "{" << endl;
      do
      {
        fin >> readin;
        if (readin != "KTHX")
          getWordAndPick(fin, fout, readin);
        else
          keepGoing = false;
      }while (keepGoing);
      fout << "}" << endl;
    }
  }
  else
  {
    cerr<< "OH NOES! Syntax error in a loop structure."<<endl;
    exit(3);
  }
}

void comment(ifstream & fin, ofstream & fout)
{
  string readin;
  fout<< "//";
  getline(fin, readin, '\n');
  fout<< readin <<endl;
}

void declareVariable(ifstream & fin, ofstream & fout)
{
  string input, input2, input3, input4;
  
  fin>> input >> input2 >> input3 >> input4;
  if (input == "HAZ")
  {
    if (input2 == "A")
    {
      if (input3 == "VAR")
      {
         if (input4 == "ITZ")
         {
           fout<< "double var ";
           fin >> input;
           fout<< "= " << input << ";" << endl;
         }
         else
         {
           cerr<< "OH NOES! Syntax error in variable declaration."<<endl;
           exit(4);
         }
      }
      else
      {
        cerr<< "OH NOES! Syntax error in variable declaration."<<endl;
        exit(4);
      }
    }
    else
    { 
      cerr<< "OH NOES! Syntax error in variable declaration."<<endl;
      exit(4);
    }  
  }
  else
  {
    cerr<< "OH NOES! Syntax error in variable declaration."<<endl;
    exit(4);
  }
    
}

void endCodeBlock(ifstream & fin, ofstream & fout)
{
  fout<< "return 0;"<< endl << "}" << endl;
}

void increment(ifstream & fin, ofstream & fout)
{
  string input;
  int incrementNum;
  
  fout<< "var += ";
  fin >> input;
  if (input == "VAR")
  {
    fin >> input;
    if (input == "!!")
    {
      fin >> incrementNum;
      
      fout<< incrementNum << ";" << endl;
    }
    else
    {
      cerr << "OH NOES! Syntax error in variable increment."<<endl;
      exit(5);
    }
  }
  else
  {
    cerr << "OH NOES! Syntax error in variable increment."<<endl;
    exit(5);
  }
}

//CHANGE LATER TO USE REAL VARIABLES
void readin(ifstream & fin, ofstream & fout)
{
  fout<< "cin >> var;" << endl;
}

void commentBlock(ifstream & fin, ofstream & fout)
{
  bool keepGoing = true;
  char fromFile, check, check2, check3;
  fout << "/*";
  do
  {
    fin.get(fromFile);
    if (fromFile == 'T')
    {
      fin.get(check);
      if (check == 'L')
      {
        fin.get(check2);
        if (check2 == 'D')
        {
          fin.get(check3);
          if (check3 == 'R')
          {
            fout<< "*/" << endl;
            keepGoing = false;
          }
          else
          {
            fout << fromFile << check << check2 << check3;
          }
        }
        else
        {
          fout << fromFile << check << check2;
        }
      }
      else
      {
        fout << fromFile << check;
      }
    }
    else
    {
      fout << fromFile;
    }
  }while(keepGoing);
}

