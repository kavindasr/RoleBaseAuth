#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

#ifndef CSVFILEHANDLER_H
#define CSVFILEHANDLER_H
class CSVfileHandler {
    private:
        vector< vector<string> > rows;
    public:
        void read_record() {
            fstream infile("data.csv");

            string line, word;
            vector<string> row;
            while (getline(infile, line)) {
                istringstream iss(line);
                row.clear();
                while( getline(iss, word, ',') ) {

                    // add all the column data
                    // of a row to a vector
                    row.push_back(word);
                }
                rows.push_back(row);
            }
        }

        void create(){
            // file pointer
            fstream fout;

            // opens an existing csv file or creates a new file.
            fout.open("dataNew.csv", ios::out | ios::app);

            // Read the input
            for (auto i = this->rows.begin(); i != this->rows.end(); ++i) {
                vector<string> row = *i;
                // Insert the data to file
                fout<< row.at(0) << ","
                    << row.at(1) << ","
                    << row.at(2) << ","
                    << row.at(3) << ","
                    << row.at(4) << ","
                    << row.at(5)
                    << "\n";
            }
            fout.close();
            // removing the existing file
            remove("data.csv");
        
            // renaming the updated file with the existing file name
            rename("dataNew.csv", "data.csv");
        }

        vector< vector<string> > getRows() { return this->rows; }

        void setRows(vector< vector<string> > newRows) { this->rows = newRows; }

        void print() {
            for(auto i = this->rows.begin(); i != this->rows.end(); ++i) {
                vector<string> row = *i;
                for(auto j = row.begin(); j != row.end(); ++j) {
                    cout<<*j;
                }
                cout<<endl;
            }
        }
};
#endif
