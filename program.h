#include "User.h"
#include "RefMonitor.h"
#include "DataRowHandler.h"
#include "CSVfileHandler.h"
using namespace std;

/*
* Main program
*/
void program(User user) {
    while (true){
        int inp;
        RefMonitor refMonitor;
        cout<<"#######################################\n";
        cout<<"Press 0 to exit\n";
        cout<<"Press 1 to view patient details\n";
        cout<<"Press 2 to update patient details\n";
        cout<<"#######################################\n";
        cin>>inp;
        if(inp == 0){
            cout<<"Bye!\n";
            break;
        }
        else if(inp == 1) {
            vector<string> dataRows = refMonitor.viewRowData(user);
            for(auto i = dataRows.begin(); i != dataRows.end(); ++i) {
                cout<<*i<<endl;
            }
        } else if(inp == 2) {
            int id, age;
            string sickness, drugs, tests;
            cout<<"****Enter 0 if you do not want to change the value****\n";
            cout<<"Enter patient id: ";
            cin>>id;
            cout<<"Age: ";
            cin>>age;
            cout<<"Sickness: ";
            cin>>sickness;
            cout<<"Drugs: ";
            cin>>drugs;
            cout<<"Test results: ";
            cin>>tests;
            try {
                string updatedRow = refMonitor.updateRecord(user, id, age, sickness, drugs, tests);
                cout<<updatedRow<<endl;
            } catch(invalid_argument &e) {
                cerr<<e.what()<<endl;
            }
            
            
        }
    }   
}
