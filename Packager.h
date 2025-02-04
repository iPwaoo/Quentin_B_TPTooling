#ifndef PACKAGER_H
#define PACKAGER_H

#include <string>

class Packager {
public:
    static void packageProject(const std::string& uprojectPath, const std::string& buildType);
};

#endif // PACKAGER_H
