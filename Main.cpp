// Multiple entry clipboard
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string FilePath = "C:/Users/koda1/Desktop/Payload.txt";



 string MakeString(string currItem, string list){
    //Take each line and place it into a single comma separated string to populate vector
    string vectorList;
    vectorList = list + currItem + ", ";
    
    return vectorList;
}

vector<string> FillVector(string vectorList){
    // fill vector using string from string builder
    //vector<string> clipboard = {null, null, null};
    vector<string> test2 = {"a", "b"};
    return test2;
}

int main( int argc, char *argv[] ){
    int count = 1;
    char data[100];
    string currList;
    string currItem;
    ifstream fileIn;
    fileIn.open(FilePath);
    if(!fileIn) 
        {
            cout<<"Error opening output file"<<endl;
            system("pause");
            return -1;
        }
    while(!fileIn.eof()){
        getline(fileIn, currItem);
        currList = MakeString(currItem, currList);
    }
    


}