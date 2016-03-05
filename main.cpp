#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string headerLine;
    bool isFirstLine=true;
    ifstream inFile("../../data/Jazmin/20150201.txt");
    if (!inFile) {
        cerr << "File not found." << endl;
        return -1;
    }

    // Using getline() to read one line at a time.
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        if(isFirstLine){
            headerLine = line;
            isFirstLine=false;
        }
        //cout<<line<<endl;
    }

    inFile.close();

    cout<<headerLine<<endl;
    return 0;
}