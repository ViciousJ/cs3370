// Jeremy Warren
// CS-3370-001
// Portsetter Project
// 10/7/2016
// Description: Test program for the portsetter/setport program.
//   Requires the many .txt test files to work properly.

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
    
    // return 1 if there was an error, or 0 if there were no errors
    return (statusCode1 || statusCode2) ? 1 : 0; 
}

int main(int argc, char* args[]) {
    int numErrors = 0;
    
    // POSITIVE TESTS
    numErrors += test("setport", 0, "usage.txt");
    numErrors += test("setport -h", 0, "usage.txt");
    numErrors += test("setport --help", 0, "usage.txt");
    numErrors += test("setport -p 4040", 0, "listening.txt");
    numErrors += test("setport --port 4040", 0, "listening.txt");
    numErrors += test("setport -?", 0, "usage.txt");
    numErrors += test("setport -!", 0, "about.txt");
    numErrors += test("setport --about", 0, "about.txt");
    numErrors += test("setport -v", 0, "version.txt");
    numErrors += test("setport --version", 0, "version.txt");
    // Can't create test success cases for setport -p -e, setport --port -e, 
    //   setport -p -e MY_PORT, and setport --port -e MY_PORT
    //   because environment variables may be different or non-existant from 
    //   system to system. Manual testing only for those four success cases. 
    //   However, negative tests can be made, as below.
    
    // NEGATIVE TESTS
    numErrors += test("setport help", 1, "noDash.txt");
    numErrors += test("setport -help", 1, "invalidFlag.txt");
    numErrors += test("setport --help me!", 1, "invalidFlag.txt");
    numErrors += test("setport --h", 1, "invalidFlag.txt");
    numErrors += test("setport -h --help", 1, "invalidFlag.txt");
    numErrors += test("setport -hs", 1, "invalidFlag.txt");
    numErrors += test("setport -p --port 9", 1, "tooMany.txt");
    numErrors += test("setport -p 77 33", 1, "tooMany.txt");
    numErrors += test("setport -p -21", 1, "portSize.txt");
    numErrors += test("setport -p 0", 1, "portSize.txt");
    numErrors += test("setport --port", 1, "noPort.txt");
    numErrors += test("setport -p 90-642", 1, "integerFormat.txt");
    numErrors += test("setport -p 202 --port", 1, "tooMany.txt");
    numErrors += test("setport -p 123456", 1, "portSize.txt");
    numErrors += test("setport -pp", 1, "invalidFlag.txt");
    numErrors += test("setport -p twelve", 1, "integerFormat.txt");
    numErrors += test("setport 12 -p", 1, "noDash.txt");
    numErrors += test("setport -p 151.2", 1, "integerFormat.txt");
    numErrors += test("setport -p 00009.0", 1, "integerFormat.txt");
    numErrors += test("setport --portugal", 1, "invalidFlag.txt");
    numErrors += test("setport 906", 1, "noDash.txt");
    numErrors += test("setport -x 45321", 1, "invalidFlag.txt");
    numErrors += test("setport -P 714", 1, "invalidFlag.txt");
    numErrors += test("setport --?", 1, "invalidFlag.txt");
    numErrors += test("setport -? 12", 1, "invalidFlag.txt");
    numErrors += test("setport -! -h", 1, "invalidFlag.txt");
    numErrors += test("setport -!!", 1, "invalidFlag.txt");
    numErrors += test("setport --about to get crayzee, yo", 1, "tooMany.txt");
    numErrors += test("setport -about", 1, "invalidFlag.txt");
    numErrors += test("setport -v.", 1, "invalidFlag.txt");
    numErrors += test("setport v-8", 1, "noDash.txt");
    numErrors += test("setport -version", 1, "invalidFlag.txt");
    numErrors += test("setport --version v", 1, "invalidFlag.txt");
    numErrors += test("setport -p --e", 1, "portSize.txt");
    numErrors += test("setport --p -e", 1, "invalidFlag.txt");
    numErrors += test("setport -port -e", 1, "invalidFlag.txt");
    numErrors += test("setport --port -e 256", 1, "noEnvVar.txt");
    numErrors += test("setport --port e", 1, "integerFormat.txt");
    numErrors += test("setport -p -e Pants", 1, "noEnvVar.txt");
    
    cout << "Test complete. " << numErrors << " errors were found.\n";
    return 0;
}