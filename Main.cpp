// Multiple entry clipboard
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
HWND hwnd;


const string FilePath = "C:/Users/koda1/Desktop/Payload.txt";

vector<string> FillVector(string currLine, vector<string> vectorBuffer){
    vectorBuffer.push_back(currLine);
    return vectorBuffer;
}

void PopulateClipboard(string currItem){
    const char* output = currItem.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}


//For testing vector
void print(std::vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}


int main( int argc, char *argv[] ){
    int count = 0;
    vector<string> vectorList;
    string currLine;
    ifstream fileIn;
    fileIn.open(FilePath);
    if(!fileIn) 
        {
            cout<<"Error opening input file"<<endl;
            system("pause");
            return -1;
        }
    while(!fileIn.eof()){
        getline(fileIn, currLine);
        vectorList = FillVector(currLine,vectorList);
        //For testing clipboard
        //PopulateClipboard(currLine);
        count++;
    }
    //Output testing
    currLine = vectorList[0];
    print(vectorList);
    cout<<currLine;
    return 0;
}