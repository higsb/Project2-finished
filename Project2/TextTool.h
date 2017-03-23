//  Dennis Durant
//  3-21-17
//  TextTool.h
#pragma once
#pragma once

#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

class TextTool {
public:
    // default constructor
    TextTool() {
        n = duplicates = 0;
        wordlist = new list<string>();
    }
    
    // destructor
    ~TextTool() {
        wordlist->clear();
     
        
    }
    
    // Load information from a text file with the given filename.
    void loadListFromTextfile(string filename) {
        ifstream ifs;
        ifs.open(filename);
        
        if (ifs.is_open()) {
            string aword;
            while (ifs >> aword) {
                addEntryBack(aword);
            }
            ifs.close();
        }
        else
            throw invalid_argument("Could not open file " + filename);
    }
    
    // return the number of words in the linked list
    int totalWords() {
        return n;
        
    }
    
    // add entry at the back of the linked list
    void addEntryBack(const string& aword) {
        
        
        wordlist->push_back(aword);
        n++;
    }
    
    // print all words stored in the linked list, separated by a space
    const string listToString() {
        string words = "";
        list<string>::iterator i;
        for (i = wordlist->begin(); i != wordlist->end(); i++)
        {
            words += *i + " ";
        }
        return words;
        
    }
    
    // print duplicated words in the linked list
    void printDuplicates() {
        list<string>::iterator i;
        list<string>::iterator j;
        for (i = wordlist->begin(); i != wordlist->end(); ++i)
        {
            int count = 0;
            for (j = i; j != wordlist->end(); ++j)
            {
                if (count == 0)
                {
                    count = 1;
                    continue;
                }
                string a = *i;
                string b = *j;
                if (a.compare(b) == 0)
                {
                    cout << *i << " ";
                }
                break;
            }
        }
    }
    
    // remove duplicated words in the linked
    void removeDuplicates() {
        wordlist->unique();
        calculateDuplicates();
    }
    
    // determine the total number of duplicated words in the list
    int totalDuplicates() {
        //cout << endl << duplicates << endl;
        calculateDuplicates();
        return duplicates;
    }
    
    // check if the list is empty
    bool isEmpty() {
        return wordlist->empty();
    }
    
    // Empty the list
    void makeEmpty() {
        wordlist->clear();
        n = 0;
        duplicates = 0;
    }
    
    void calculateDuplicates()
    {
        duplicates = 0;
        list<string>::iterator i;
        list<string>::iterator j;
        
        for (i = wordlist->begin(); i != wordlist->end(); ++i)
        {
            int count = 0;
            for (j = i; j != wordlist->end(); ++j)
            {
                if (count == 0)
                {
                    count = 1;
                    continue;
                }
                string a = *i;
                string b = *j;
                if (a.compare(b) == 0)
                {
                    duplicates++;
                }
                break;
            }
        }
    }
    
private:
    
    int n;
    int duplicates;
    
    list<string> *wordlist;
};
