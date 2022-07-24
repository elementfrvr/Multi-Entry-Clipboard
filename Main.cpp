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
    // fill vector using string from string builder
    //vector<string> clipboard = {null, null, null};
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
    int count = 1;
    vector<string> vectorList;
    string currLine;
    ifstream fileIn;
    fileIn.open(FilePath);
    if(!fileIn) 
        {
            cout<<"Error opening output file"<<endl;
            system("pause");
            return -1;
        }
    while(!fileIn.eof()){
        getline(fileIn, currLine);
        vectorList = FillVector(currLine,vectorList);
        PopulateClipboard(currLine);
        count++;
    }
    print(vectorList);
    return 0;
}