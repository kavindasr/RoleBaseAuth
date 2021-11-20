#include <vector>
#include <string>
#include "CSVfileHandler.h"
#include "DataRow.h"

using namespace std;

#ifndef DATAROWHANDLER_H
#define DATAROWHANDLER_H

class DataRowHandler {
    private:
        CSVfileHandler csvHandler;
        vector<DataRow> dataRows;
    public:
        void loadDataRows() {
            csvHandler.read_record();
            vector< vector<string> > data = csvHandler.getRows();
            for(auto i = data.begin(); i != data.end(); ++i) {
                vector<string> row = *i;
                try {
                    DataRow dataRow(stoi(row.at(0)), row.at(1), stoi(row.at(2)), row.at(3), row.at(4), row.at(5));
                    dataRows.push_back(dataRow);
                } catch(out_of_range &e) {
                    continue;
                }
            }
        }

        void updateRows() {
            vector< vector<string> > strRows;
            for(auto i = this->dataRows.begin(); i != this->dataRows.end(); ++i) {
                DataRow row = *i;
                vector<string> strRow = {
                    to_string(row.getId()),
                    row.getName(),
                    to_string(row.getAge()),
                    row.getSickness(),
                    row.getDrugs(),
                    row.getTests()
                };
                strRows.push_back(strRow);
            }
            csvHandler.setRows(strRows);
            csvHandler.create();
        }

        vector<DataRow> getDataRows() { return this->dataRows; }

        void setDataRows(vector<DataRow> dataRowsNew) { this->dataRows = dataRowsNew; }

        void print() {
            for(auto i = this->dataRows.begin(); i != this->dataRows.end(); ++i) {
                DataRow dataRow = *i;
                cout<<dataRow.getName()<<" "<<dataRow.getAge()<<endl;
            }
        }
};
#endif
