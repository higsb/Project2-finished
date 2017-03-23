//  Dennis Durant
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
        // TO BE COMPLETED
        
    }
    
    // destructor
    ~TextTool() {
        // TO BE COMPLETED
        
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
        return -1; // TO BE COMPLETED
        
    }
    
    // add entry at the back of the linked list
    void addEntryBack(const string& aword) {
        
        // TO BE COMPLETED
        
    }
    
    // print all words stored in the linked list, separated by a space
    const string listToString() {
        // TO BE COMPLETED
        
    }
    
    // print duplicated words in the linked list
    void printDuplicates() {
        // TO BE COMPLETED
        
    }
    
    // remove duplicated words in the linked
    void removeDuplicates() {
        // TO BE COMPLETED
        
    }
    
    // determine the total number of duplicated words in the list
    int totalDuplicates() {
        // TO BE COMPLETED
        
    }
    
    // check if the list is empty
    bool isEmpty() {
        
        //TBC
    }
    
    // Empty the list
    void makeEmpty() {
        // TO BE COMPLETED
        
    }
    
private:
    
    int n;
    int duplicates;
    
    list<string> *wordlist;
};
