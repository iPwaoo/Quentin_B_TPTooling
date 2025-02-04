#include <iostream>
#include <cstdlib>
#include "Packager.h"

void Packager::packageProject(const std::string& uprojectPath, const std::string& packagePath)
{
    std::string command = "\\UnrealEngine\\Engine\\Build\\BatchFiles\\RunUAT.bat BuildCookRun -project=" + uprojectPath +
                          " -noP4 -clientconfig=Development -serverconfig=Development "
                          "-nocompileeditor -installed -utf8output -stage -package -archive -archivedirectory=" + packagePath;

    std::cout << "Packaging en cours...\n";
    int result = std::system(command.c_str());

    if (result == 0)
    {
        std::cout << "Packaging terminé avec succès !\n";
    } else
    {
        std::cerr << "Erreur lors du packaging !\n";
    }
}
