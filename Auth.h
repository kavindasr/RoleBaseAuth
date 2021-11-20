#include <iostream>
#include <string>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <crypto++/md5.h>
#include <crypto++/hex.h>
#include "PasswdReader.h"

/*
* Handle Auth
* MD5 hash generation function
* Required crytopp library (https://cryptopp.com/)
*/
class Auth {
    private:
        PasswdReader passwdReader;
        map<string, User> users;

        string hashValue(string password) {
            byte digest[ CryptoPP::Weak::MD5::DIGESTSIZE ];
            std::string message = password;

            CryptoPP::Weak::MD5 hash;
            hash.CalculateDigest( digest, (byte*) message.c_str(), message.length() );
            
            CryptoPP::HexEncoder encoder;
            std::string output;

            encoder.Attach( new CryptoPP::StringSink( output ) );
            encoder.Put( digest, sizeof(digest) );
            encoder.MessageEnd();

            //std::cout<<output;
            return output;
        }

    public:
        Auth() {
            passwdReader.readPasswdFile();
            users = passwdReader.getUsers();
        }

        User login(string username, string password) {
            string hashPassword = this->hashValue(password);
            if(users.find(username) == users.end()) {
                throw invalid_argument("User not found");
            }
            User user = users.at(username);
            if(user.getPassword() != hashPassword) {
                throw invalid_argument("Password incorrect");
            }
            return user;
        }

};