#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    string headerLine;
    bool isFirstLine=true;
    std::vector<string> a;
    std::vector<string>::const_iterator i;

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

    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = headerLine.find(delimiter)) != std::string::npos) {
        token = headerLine.substr(0, pos);
       // std::cout << token << std::endl;
        headerLine.erase(0, pos + delimiter.length());
        a.push_back(token);
    }
    a.push_back(headerLine);
    //std::cout << headerLine << std::endl;

    for(i=a.begin(); i!=a.end(); ++i){
        std::cout<<(*i)<<std::endl;
    }

    return 0;
}