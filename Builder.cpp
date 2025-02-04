#include <iostream>
#include <cstdlib>  // Pour system()
#include "Builder.h"

void Builder::buildProject(const std::string& uprojectPath) {
    // Récupérer le nom du projet depuis le chemin du .uproject
    size_t lastSlash = uprojectPath.find_last_of("/\\");
    std::string projectName = (lastSlash != std::string::npos) ? uprojectPath.substr(lastSlash + 1) : uprojectPath;
    
    // Retirer l'extension .uproject
    size_t dotPos = projectName.find_last_of(".");
    if (dotPos != std::string::npos) {
        projectName = projectName.substr(0, dotPos);
    }

    // Définir les paramètres de build
    std::string target = "Editor";  // Peut être modifié selon le besoin
    std::string optimization = "Win64 Development";  // Peut être modifié aussi

    // Construire la commande
    std::string command = "\\UnrealEngine\\Engine\\Build\\BatchFiles\\Build.bat " + projectName + target + " " + optimization + " -Project=\"" + uprojectPath + "\" -waitmutex";
    //chemin du build.bat + " " + nom du projet + "Editor Win64 Development -Project="" + chemin vers le uproject + "" -waitmutex";

    // Affichage de la commande générée
    std::cout << "Execution de la commande : " << command << std::endl;

    // Exécuter la commande
    int result = system(command.c_str());

    // Vérifier le retour
    if (result != 0) {
        std::cerr << "Erreur : La compilation du projet a echoue." << std::endl;
    } else {
        std::cout << "Compilation reussie !" << std::endl;
    }
}
