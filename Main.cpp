// Multiple entry clipboard
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string FilePath = "C:/Users/koda1/Desktop/Payload.txt";



vector<string> FillVector(string currItem, vector<string> vectorBuffer){
    // fill vector using string from string builder
    //vector<string> clipboard = {null, null, null};
    vectorBuffer.push_back(currItem);
    return vectorBuffer;
}

//For testing vector
void print(std::vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}


int main( int argc, char *argv[] ){
    int count = 1;
    vector<string> vectorList;
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
        vectorList = FillVector(currItem,vectorList);
        count++;
    }
    //print(vectorList);
}