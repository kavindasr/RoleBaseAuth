#include <map>
#include <string>
#include "Reader.h"
#include "User.h"

#define PASSWD "passwd"
#define DEL ":"

/*
* Convert raw config file into an object
* and store in a hashMap
*/
class PasswdReader {
    private:
        map<string, User> users;
    public:
        void readPasswdFile() {
            Reader reader;
            reader.readFile(PASSWD,DEL);
            // reader.readFile("passwd",":");
            this->convertToUser(reader.getRows());
        }
        void convertToUser(vector< vector<string> > rows) {
            for(auto i = rows.begin(); i != rows.end(); ++i) {
                vector<string> row = *i;
                try {
                    User user(row.at(0),row.at(1),row.at(2),row.at(3));
                    users.insert(pair<string, User>(row.at(0), user));
                } catch(out_of_range &e){
                    cout<<"Invalid data record"<<endl;
                }
            }
        } 

        map<string, User> getUsers() {
            return this->users;
        }
};