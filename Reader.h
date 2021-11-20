#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#ifndef READER_H
#define READER_H

/*
* Read configuration file
* Config File name - passwd
*/
class Reader {
    private:
        vector<vector<string>> rows;
    public:
        void readFile(string fileName, string del) {
            fstream infile(fileName);
            string line;
            while (getline(infile, line)) {
                istringstream iss(line);
                vector<string> row = this->tokenize(line, del);
                rows.push_back(row);
            }
            
        }
        // Spliting function
        vector<string> tokenize(string s, string del = ":") {
            vector<string> args;
            int start = 0;
            int end = s.find(del);
            while (end != -1) {
                args.push_back(s.substr(start, end - start));
                start = end + del.size();
                end = s.find(del, start);
            }
            args.push_back(s.substr(start, end - start));
            return args;
        }
    
        vector<vector<string>> getRows() {
            return this->rows;
        }
};
#endif
