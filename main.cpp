#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using namespace std;

int main() {

    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{"mongodb://127.0.0.1/ClimaPIEAES?"}};

    auto collection = conn["ClimaPIEAES"]["JAZMIN"];

    string headerLine;
    bool isFirstLine=true;

    vector<string> headersVector;
    vector<string> dataLineVector;

    //vector<string>::const_iterator i;
    vector<string>::const_iterator j;
    vector<string>::const_iterator k;

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
        }else {
            dataLineVector.push_back(line);
        }
    }

    inFile.close();


    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = headerLine.find(delimiter)) != string::npos) {
        token = headerLine.substr(0, pos);
        token.replace(token.begin(),token.begin()+1,"");
        token.replace(token.end()-1,token.end(),"");
        headerLine.erase(0, pos + delimiter.length());
        headersVector.push_back(token);
    }
    headerLine.replace(headerLine.begin(),headerLine.begin()+1,"");
    headerLine.replace(headerLine.end()-1,headerLine.end(),"");
    headerLine.replace(headerLine.end()-1,headerLine.end(),"");
    headersVector.push_back(headerLine);

        for(j=dataLineVector.begin(); j!=dataLineVector.end(); ++j){
            string temp = (*j);
            vector<string> dataTempVector;
            while ((pos = temp.find(delimiter)) != string::npos) {
                token = temp.substr(0, pos);
                temp.erase(0, pos + delimiter.length());
                token.replace(token.begin(),token.begin()+1,"");
                token.replace(token.end()-1,token.end(),"");
                dataTempVector.push_back(token);
            }

            temp.replace(temp.begin(),temp.begin()+1,"");
            temp.replace(temp.end()-1,temp.end(),"");
            temp.replace(temp.end()-1,temp.end(),"");
            dataTempVector.push_back(temp);

            /*for(i=headersVector.begin(),k=dataTempVector.begin(); k!=dataTempVector.end(); ++i,++k) {
                document << headersVector.at(k) << (*k);
            }*/

            bsoncxx::builder::stream::document document{};

            for(std::size_t i=0;i<dataTempVector.size();++i){
                document << headersVector[i] << dataTempVector[i];
            }
            collection.insert_one(document.view());
        }

    //cout << headersVector.size() << endl;
    auto cursor = collection.find({});

    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    return 0;
}