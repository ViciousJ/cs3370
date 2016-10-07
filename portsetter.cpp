// Jeremy Warren
// CS-3370-001
// Portsetter Project
// 9/19/2016

#include "messages.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

void usage(const string& language) {
    ifstream usageFile("/home/ubuntu/workspace/portsetter/portsetter.usage_" + language + ".txt");
    char c;
    while(usageFile.get(c)) {
        cout << c;
    }
    usageFile.close();
}

void about(const string& language) {
    ifstream aboutFile("/home/ubuntu/workspace/portsetter/portsetter.about_" + language + ".txt");
    char c;
    while(aboutFile.get(c)) {
        cout << c;
    }
    aboutFile.close();
}

int exitStatus(int status, const vector<string>& msg) {
    cout << msg[EXIT_MSG] << status << endl;
    return status;
}

int main(int argc, char* args[]) {
    const string VERSION = "1.1.3a";
    const int MAX_PORT_NUM = 65535;
    vector<string> msg; // a vector to store and print various program messages
    string lang = checkLanguage(msg);
    
    // help/usage case
    if (argc == 1 || (argc == 2 && (!strcmp(args[1], "-h") || !strcmp(args[1], "--help") || !strcmp(args[1], "-?")))) {
        usage(lang);
        return exitStatus(0, msg);
    }
    if (args[1][0] != '-') {
        cout << msg[NO_DASH] << endl;
        usage(lang);
        return exitStatus(1, msg);
    }
    if ((argc == 4 && strcmp(args[2], "-e")) || argc > 4) {
        cout << msg[TOO_MANY_ARGS] << endl;
        usage(lang);
        return exitStatus(1, msg);
    } 
    if (argc == 2 && (!strcmp(args[1], "-!") || !strcmp(args[1], "--about"))) {
        about(lang);
        return exitStatus(0, msg);
    }
    if (argc == 2 && (!strcmp(args[1], "-v") || !strcmp(args[1], "--version"))) {
        cout << VERSION << endl;
        return exitStatus(0, msg);
    }
    if (strcmp(args[1], "-p") && strcmp(args[1], "--port")) {
        cout << msg[INVALID_FLAG] << endl;
        usage(lang);
        return exitStatus(1, msg);
    }
    // Because of the above if statement, now only commands with the 2nd 
    // argument of -p or --port can get through to the code below.
    if (argc == 2) {
        cout << msg[NO_PORT] << endl;
        usage(lang);
        return exitStatus(1, msg);
    }
    // case for -e
    if (argc == 3 && !strcmp(args[2], "-e")) { 
        char* port = getenv("PORT");
        if (port == nullptr || !strcmp(port, "")) {
            cout << msg[NO_ENV_VAR] << endl;
            usage(lang);
            return exitStatus(1, msg);
        }
        if (port[0] == '-') { // possibly a negative number entered
            cout << msg[BAD_PORT_SIZE] << MAX_PORT_NUM << endl;
            usage(lang);
            return exitStatus(1, msg);    
        }
        for (int i = 0; i < strlen(port); ++i) { 
            if (!(isdigit(port[i]))) {
                cout << msg[INTEGER_FORMAT] << endl;
                usage(lang);
                return exitStatus(1, msg);
            }
        }
        cout << msg[LISTENING] << getenv("PORT") << endl;
        return exitStatus(0, msg);
    }
    // case for -e VAR_PORT (user defined environmental variable)
    if (!strcmp(args[2], "-e")) { 
        char* port = getenv(args[3]);
        if (port == nullptr || !strcmp(port, "")) {
            cout << msg[NO_ENV_VAR] << endl;
            usage(lang);
            return exitStatus(1, msg);
        }
        if (port[0] == '-') { // possibly a negative number entered
            cout << msg[BAD_PORT_SIZE] << MAX_PORT_NUM << endl;
            usage(lang);
            return exitStatus(1, msg);    
        }
        for (int i = 0; i < strlen(port); ++i) { 
            if (!(isdigit(port[i]))) {
                cout << msg[INTEGER_FORMAT] << endl;
                usage(lang);
                return exitStatus(1, msg);
            }
        }
        cout << msg[LISTENING] << getenv(args[3]) << endl;
        return exitStatus(0, msg);
    }    
    if (args[2][0] == '-') { // possibly a negative number entered
        cout << msg[BAD_PORT_SIZE] << MAX_PORT_NUM << endl;
        usage(lang);
        return exitStatus(1, msg);     
    }
    for (int i = 0; i < strlen(args[2]); ++i) { 
        if (!(isdigit(args[2][i]))) {
            cout << msg[INTEGER_FORMAT] << endl;
            usage(lang);
            return exitStatus(1, msg);
        }
    }
    int portNum = stoi(args[2]);
    if (portNum < 1 || portNum > MAX_PORT_NUM) {
        cout << msg[BAD_PORT_SIZE] << MAX_PORT_NUM << endl;
        usage(lang);
        return exitStatus(1, msg);
    }
    // looks like the input is all good at this point for -p [PORT] and --port [PORT]
    cout << msg[LISTENING] << args[2] << endl;
    return exitStatus(0, msg);
}