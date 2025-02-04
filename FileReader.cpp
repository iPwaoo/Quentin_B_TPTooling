#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "single_include/nlohmann/json.hpp"

using json = nlohmann::json;

void FileReader::readUProject(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filepath << std::endl;
        return;
    }

    json projectData;
    file >> projectData;

    // Récupération du nom du projet
    if (projectData.contains("Modules") && projectData["Modules"].is_array() && !projectData["Modules"].empty()) {
        std::string projectName = projectData["Modules"][0]["Name"];
        std::cout << "Nom du jeu : " << projectName << std::endl;
    } else {
        std::cerr << "Erreur : Impossible de récupérer le nom du projet." << std::endl;
    }

    // Affichage de la version Unreal Engine
    if (projectData.contains("EngineAssociation")) {
        std::cout << "Version Unreal : " << projectData["EngineAssociation"] << std::endl;
    }

    // Vérifier si c'est une version "From Source"
    if (projectData.contains("EngineAssociation") && projectData["EngineAssociation"].is_string()) {
        std::string engineVersion = projectData["EngineAssociation"];
        if (engineVersion.find("Source") != std::string::npos) {
            std::cout << "Version : From Source" << std::endl;
        }
    }

    // Affichage des plugins utilisés
    if (projectData.contains("Plugins")) {
        std::cout << "Plugins utilisés :" << std::endl;
        for (const auto& plugin : projectData["Plugins"]) {
            if (plugin.contains("Name")) {
                std::cout << "- " << plugin["Name"] << std::endl;
            }
        }
    }

    file.close();
}
