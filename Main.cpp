// Multiple entry clipboard
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

 const string FilePath = "C:/Users/koda1/Desktop/Payload.txt";

int main( int argc, char *argv[] ){
    char data[100];
    ifstream fileIn;
    fileIn.open(FilePath);
   fileIn >> data; 

   // write the data at the screen.
   cout << data << endl;


}

string Stringbuilder(string currItem){
    //Take each line and place it into a single comma separated string to populate vector
    string fake = currItem;
    return fake;
}

vector<string> FillVector(string vectorList){
    // fill vector using string from string builder
    //vector<string> clipboard = {null, null, null};
    vector<string> test2 = {"a", "b"};
    return test2;
}