#include <iostream>
#include "FileReader.h"
#include "Builder.h"
#include "Packager.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage:\n"
                  << "  " << argv[0] << " [CHEMIN_DU_UPROJECT] show-infos\n"
                  << "  " << argv[0] << " [CHEMIN_DU_UPROJECT] build\n"
                  << "  " << argv[0] << " [CHEMIN_DU_UPROJECT] package [CHEMIN_DU_PACKAGE]\n";
        return 1;
    }

    std::string uprojectPath = argv[1];
    std::string command = argv[2];

    if (command == "show-infos") {
        FileReader::readUProject(uprojectPath);
    } else if (command == "build") {
        Builder::buildProject(uprojectPath);
    } else if (command == "package") {
        if (argc < 4) {
            std::cerr << "Erreur : vous devez spécifier le chemin du package !\n";
            return 1;
        }
        std::string packagePath = argv[3];
        Packager::packageProject(uprojectPath, packagePath);
    } else {
        std::cerr << "Commande inconnue : " << command << "\n";
        return 1;
    }

    return 0;
}
