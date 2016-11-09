// Jeremy Warren
// CS-3370-001
// Portsetter Project
// 10/7/2016
// Description: Language spike for portsetter.cpp

#include <iostream>
#include <cstring>
#include <regex>

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

std::string checkLanguage(std::vector<std::string>& msg) {
    std::string language = "en"; // default to English
    int test = 1;
    char* envVar;
    while (test < 5) {
        if (test == 1) envVar = getenv("LANGUAGE");
        else if (test == 2) envVar = getenv("LC_ALL");
        else if (test == 3) envVar = getenv("LC_MESSAGES");
        else envVar = getenv("LANG");
        if (envVar == nullptr || !strcmp(envVar, "")) { // environment variable doesn't exist or isn't set
            ++test;
            continue;
        }
        // compare environment variable to the below regex statement to see if it is a valid language
        if (std::regex_match (envVar, std::regex("^[a-z]{2}((_[A-Z]{2})|(\\..+))?(\\..+)?"))) { 
            language = envVar[0]; // copy the two letter language code into "language"
            language += envVar[1]; 
            break; // we've found an acceptable language; no need to continue
        }
        ++test;
    }
    
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
        if (language != "en") {
            std::cout << "Missing " << language << " translation files. Using English." << std::endl;
            language = "en";
        }
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
