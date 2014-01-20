#ifndef INTERPERTER_H
#define INTERPERTER_H

#include "World.hpp"
#include "Inventory.hpp"
#include "TipSystem.hpp"
#include "AudioPlayer.hpp"
#include <string>


class Interperter
{
    public:
        Interperter(World *);

        void readFile(std::string aName = NULL, World * = NULL, Inventory * = NULL, TipSystem * = NULL, AudioPlayer * = NULL);

        virtual ~Interperter();
    protected:
    private:


        int stringSize;

        bool setBehaviour;

        float countX;
        float countZ;
        float countY;

        std::string line;
        std::string delimiters;
        std::string delimiter2;

        std::string objectNmb;

        std::string objectName;
        std::string modelName;
        std::string textureName;
        std::string behaviourName;
        std::string BehaviourId;
        std::string BehaviourArgument1;
        std::string BehaviourArgument2;
        std::string BehaviourArgument3;
        std::string BehaviourArgument4;


        Mesh * loadedMesh;
        Texture * loadedTextue;

};

#endif // INTERPERTER_H
