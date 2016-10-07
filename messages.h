#include <iostream>
#include <vector>
//#include <regex>

enum {
    LISTENING,
    EXIT_MSG,
    NO_DASH,
    TOO_MANY_ARGS,
    INVALID_FLAG,
    NO_PORT,
    NO_ENV_VAR,
    BAD_PORT_SIZE,
    INTEGER_FORMAT
};

/*
std::string testEnvVars() {
    // NEED TO TEST FOR EMPTY STRING, NO ENV VAR, AND OTHER THINGS FIRST
    int envVar = 1;
    std::string lang = getenv("LC_ALL");
    if ((lang[0] >= 'a' && lang[0] <= 'z') &&
        (lang[1] >= 'a' && lang[1] <= 'a')
        
}
*/

std::string checkLanguage(std::vector<std::string>& msg) {
    
    // Note: I spent 3.5 hours trying to get regEx to work on cloud9 but couldn't. One thing in particular,
    //   I discovered that it would not take the brackets, such as [a-z]. Setting cloud9 to compile with 
    //   g++-5 didn't work either. My regEx comparison string, which worked just fine in Visual Studio, was: 
    //   "^[a-z]{2}((_[A-Z]{2})|\\..+)?(\\..+)?"

    std::string language = "en"; // default to English
//    std::string language = testEnvVars();
    
    // Spanish messages
    if (language == "es") {
        msg.push_back("Escucha en el puerto ");
        msg.push_back("Proceso salió con el código: ");
        msg.push_back("El primer argumento debe comenzar con un guión.");
        msg.push_back("Demasiados argumentos introducidos, o indicador -e no se han introducido correctamente.");
        msg.push_back("Bandera válida.");
        msg.push_back("Se ha introducido ningún número de puerto.");
        msg.push_back("No existe la variable ambiental.");
        msg.push_back("Número de puerto debe ser un número entero entre 1 y ");
        msg.push_back("Número de puerto debe estar en formato de número entero.");
    }

    // English messages
    else {
        msg.push_back("Listening on port ");
        msg.push_back("Process exited with code: ");
        msg.push_back("First argument must start with a dash.");
        msg.push_back("Too many arguments entered, or -e flag not entered correctly.");
        msg.push_back("Invalid flag.");
        msg.push_back("No port number was entered.");
        msg.push_back("Environmental variable does not exist.");
        msg.push_back("Port number must be an integer between 1 and ");
        msg.push_back("Port number must be in integer format.");
    }
            
    return language;
}
