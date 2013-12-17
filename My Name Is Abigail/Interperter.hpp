#ifndef INTERPERTER_H
#define INTERPERTER_H

#include "World.hpp"
#include <string>


class Interperter
{
    public:
        Interperter(World *);

        void readFile(std::string aName = NULL, World * = NULL);

        virtual ~Interperter();
    protected:
    private:


        int stringSize;

        int countX;
        int countZ;
        int countY;

        std::string line;
        std::string delimiters;
        std::string objectNmb;

        std::string objectName;
        std::string modelName;
        std::string textureName;

        Mesh * loadedMesh;
        Texture * loadedTextue;

};

#endif // INTERPERTER_H
