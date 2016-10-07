// Jeremy Warren
// CS-3370-001
// Portsetter Project CO1
// 9/14/2016
// Description: Test program for the portsetter/setport program.

#include <iostream>
#include <cstring>
using namespace std;

int test(const char* commandLine, const int expectedCode, const char* compFile) {
    char command[80];
    
    // test to make sure the portsetter command is recognized
    strcpy(command, commandLine);
    strcat(command, " >test.txt");
    int statusCode1 = system(command) / 256;
    if (statusCode1 != expectedCode) cout << "Test failed: " << commandLine << endl;
    else statusCode1 = 0;
    
    // test to make sure the predicted message is given
    strcpy(command, "diff test.txt ");
    strcat(command, compFile);
    int statusCode2 = system(command) / 256;
    if (statusCode2 != 0) cout << "Message test failed: " << commandLine << endl;
    
    return (statusCode1 || statusCode2) ? 1 : 0; 
    // return 1 if there was an error, or 0 if there were no errors
}

int main(int argc, char* args[]) {
    int numErrors = 0;
    
    // positive tests
    numErrors += test("setport", 0, "usage.txt");
    numErrors += test("setport -h", 0, "usage.txt");
    numErrors += test("setport --help", 0, "usage.txt");
    numErrors += test("setport -p 4040", 0, "listening.txt");
    numErrors += test("setport --port 4040", 0, "listening.txt");
    
    // negative tests
    numErrors += test("setport help", 1, "noDash.txt");
    numErrors += test("setport -help", 1, "invalidFlag.txt");
    numErrors += test("setport --h", 1, "invalidFlag.txt");
    numErrors += test("setport -h --help", 1, "invalidFlag.txt");
    numErrors += test("setport -hs", 1, "invalidFlag.txt");
    numErrors += test("setport -p --port 9", 1, "tooMany.txt");
    numErrors += test("setport -p 77 33", 1, "tooMany.txt");
    numErrors += test("setport -p -21", 1, "portSize.txt");
    numErrors += test("setport -p 0", 1, "portSize.txt");
    numErrors += test("setport --port", 1, "noPort.txt");
    numErrors += test("setport -p 90642", 1, "portSize.txt");
    numErrors += test("setport -x 45321", 1, "invalidFlag.txt");
    numErrors += test("setport -P 714", 1, "invalidFlag.txt");
    
    cout << "Test complete. " << numErrors << " errors were found.\n";
    return 0;
}