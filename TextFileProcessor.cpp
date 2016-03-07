//
// Created by Benny Franco Dennis on 06/03/16.
//

#include "TextFileProcessor.h"

int TextFileProcessor::transformTextFile(){
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{mongoURI}};

    auto collection = conn[database][collectionName];

    string headerLine;
    bool isFirstLine=true;

    vector<string> headersVector;
    vector<string> dataLineVector;

    vector<string>::const_iterator j;
    vector<string>::const_iterator k;

    ifstream inFile(fileName);


    if (!inFile) {
        cerr << "File not found." << endl;
        return -1;
    }

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

        bsoncxx::builder::stream::document document{};

        for(std::size_t i=0;i<dataTempVector.size();++i){
            document << headersVector[i] << dataTempVector[i];
        }
        collection.insert_one(document.view());
    }

    /*auto cursor = collection.find({});

    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }*/

    return 0;
}