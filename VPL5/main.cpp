#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

void countWord(string& lineContent, int& start, int& quant, map<string, int>& words){
    string subStringRaw = lineContent.substr(start, quant);
    string subString = "";

    for(char& c : subStringRaw){
        subString.push_back(tolower(c));
    }
    
    if(subString.compare("\n") != 0 && subString.length() > 0){
        words[subString]++;
    }

}

int main(){
    ifstream fileInput;
    string fileName;
    string lineContent;
    int start, quant;
    map<string, int> words;

    cin >> fileName;

    fileInput.open(fileName);

    if(fileInput.is_open()){
        while(!fileInput.eof()){
            start = 0;
            quant = 0;
            
            getline(fileInput, lineContent);

            for(char& letter : lineContent){
                if(!isalnum(letter) && quant == 0){
                    ++start;
                }
                else if(!isalnum(letter) || letter == '\n'){
                    countWord(lineContent, start, quant, words);

                    start += quant+1;
                    quant = 0;
                }
                else{
                    ++quant;
                }
            }

            countWord(lineContent, start, quant, words);

        }

        for(const auto&word : words){
            cout << word.first << " " << word.second << endl;
        }
    }

    fileInput.close();
    return 0;
}