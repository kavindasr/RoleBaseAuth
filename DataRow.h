#include <string>
#include "User.h"
using namespace std;

#ifndef DATAROW_H
#define DATAROW_H

class DataRow {
    private:
        string name,sickness,drugs,tests;
        int id,age;
    public:
        DataRow(int id, string name, int age, string sickness, string drugs, string tests){
            this->id = id;
            this->name = name;
            this->age = age;
            this->sickness = sickness;
            this->drugs = drugs;
            this->tests = tests;
        }
        void setName(string name) {
            this->name = name;
        }
        void setAge(int age) {
            this->age = age;
        }
        void setSickness(string sickness) {
            this->sickness = sickness;
        }
        void setDrugs(string drugs) {
            this->drugs = drugs;
        }
        void setTests(string tests) {
            this->tests = tests;
        }

        int getId() {
            return this->id;
        }
        string getName() {
            return this->name;
        }
        int getAge() {
            return this->age;
        }
        string getSickness() {
            return this->sickness;
        }
        string getDrugs() {
            return this->drugs;
        }

        string getTests() {
            return this->tests;
        }
};

#endif
