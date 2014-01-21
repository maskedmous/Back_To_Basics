#include "Interperter.hpp"


#include "Mesh.hpp"
#include "Texture.hpp"
#include "Behaviours/TextureSwappingBehaviour.hpp"
#include "Behaviours/ItemBehaviour.hpp"
#include "Behaviours/DoorBehaviour.hpp"
#include "Behaviours/BlockWallBehaviour.hpp"
#include "Behaviours/StairsBehaviour.h"
#include "Behaviours/TriggerBehaviour.hpp"
#include "Behaviours/InvadableBehaviour.hpp"
#include "Collider.hpp"

#include <cstdio>

#include <iostream>
#include <fstream>
#include <string>


Interperter::Interperter(World * aWorld)
{
//    myWorld = aWorld;
}

Interperter::~Interperter()
{
    //dtor
}

void Interperter::readFile(std::string fileName, World * aWorld, Inventory* aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer){

    //Mesh * suzanna = Mesh::load( "models/suzanna.obj");
    //Mesh * wallPlaceHolder = Mesh::load( "models/PlaceHolderWall.obj");
        //Mesh * wallPlaceHolder = Mesh::load( "models/WallPlaceHolder.obj");


    std::ifstream level ("levelOne.txt");
    //std::ifstream levelFloor ("levelFloor.txt");

    countX = -10;
    countZ = 0;
    countY = 0;

if(level.is_open()){
    unsigned int i = 0;
    while(level.good()){

        if (level.peek() == '\n') {
        // in.get(buf, SZ) won't read newlines
        level.get();
        }
        getline(level,line);
       // std::cout << line << level <<std::endl;


        delimiters = " ,";
        size_t current;
        size_t next = -1;
        do
        {
            current = next + 1;
            next = line.find_first_of( delimiters, current );
            i++;

            if(i == 1){
                objectName = line.substr( current, next - current);
            }

            if(i == 2){
                modelName = line.substr( current, next - current);
            }

            if(i == 3){
                textureName = line.substr( current, next - current);
            }

            if(i == 4){
                behaviourName = line.substr( current, next - current);
                if(behaviourName != "0"){

                    setBehaviour = true;
                    std::cout << behaviourName << std::endl;
                }
            }

            if( i == 5){
                float sumx = atof( line.substr( current, next - current ).c_str() );
                countX = sumx;
            }

            if( i == 6){
                float sumy = atof( line.substr( current, next - current ).c_str() );
                countY = sumy;
            }

            if( i == 7){
                float sumz = atof( line.substr( current, next - current ).c_str() );
                countZ = sumz;

                GameObject * loadedObj = new GameObject(objectName, glm::vec3( countX, countY, countZ ));
                if(modelName != "0"){
                    loadedMesh = Mesh::load( ("models/" + modelName + ".obj").c_str() );
                    loadedObj->setMesh( loadedMesh );
                }
                if(textureName != "0"){
                    loadedTextue = Texture::load( ("models/" + textureName).c_str() );
                    loadedObj->setColorMap( loadedTextue );
                }

                if(setBehaviour == true){
                    loadedObj->setCollider( new Collider(0.0f, 2.0f, loadedObj) );

                    delimiter2 = " !";
                    unsigned int j = 0;
                    size_t currentBehaviour;
                    size_t nextBehaviour = -1;
                    do
                    {
                        currentBehaviour = nextBehaviour + 1;
                        nextBehaviour = behaviourName.find_first_of( delimiter2, currentBehaviour );
                        j++;
                        if(j == 1){
                            BehaviourId = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                            //std::cout << behaviourName << "fuuuuuuuuuuuuuuuuuuuuuuuuuu" <<std::endl;
                            //std::cout << BehaviourId << "loooooooooooooooooooooooooo" <<std::endl;

                            if(BehaviourId == "Item"){
                                loadedObj->setBehaviour( new ItemBehaviour(loadedObj, aWorld, aInventory, aTipsystem, aAudioPlayer) );
                            }
                            if(BehaviourId == "Block"){
                                loadedObj->setBehaviour( new BlockWallBehaviour(loadedObj, aWorld, aInventory, aTipsystem, aAudioPlayer) );
                            }

                            if(BehaviourId == "Swaping"){
                            //loadedObj->setCollider( new Collider(1.0f, 1.0f, loadedObj) );                            //loadedObj->setBehaviour( new TextureSwappingBehaviour(loadedObj,loadedObj, "StorageRoomDARK.png", "StorageRoomLIGHT.png") );
                            std::cout << "Swaping" << "triggered if swappingbehaviour is called========================" << std::endl;
                            }


                        }

                        if(j == 2){
                            if(BehaviourId == "ReqItem"){
                                BehaviourArgument1 = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                                loadedObj->setBehaviour( new DoorBehaviour(loadedObj, aWorld, aInventory, aTipsystem, BehaviourArgument1) );

                            }
                             if(BehaviourId == "Trigger"){
                                BehaviourArgument1 = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                                //loadedObj->setBehaviour( new TriggerBehaviour(loadedObj, aWorld, aInventory, aTipsystem, aAudioPlayer, BehaviourArgument1) );
                            }


                            if(BehaviourId == "Npc"){
                                BehaviourArgument1 = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                                loadedObj->setBehaviour( new InvadableBehaviour(loadedObj, aWorld, aInventory, aTipsystem, aAudioPlayer, BehaviourArgument1) );
                            }
                            if(BehaviourId == "Stairs"){
                                BehaviourArgument1 = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                                loadedObj->setBehaviour( new StairsBehaviour(loadedObj, aWorld, aInventory, aAudioPlayer , BehaviourArgument1) );
                            }

                            if(BehaviourId == "Swaping"){
                                BehaviourArgument1 = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                                std::cout << BehaviourArgument1 << "first argument========================" << std::endl;
                            }
                        }
                        if(j == 3){
                            if(BehaviourId == "Swaping"){
                                BehaviourArgument2 = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                                std::cout << BehaviourArgument2 << "SECOND argument========================" << std::endl;
                                loadedObj->setBehaviour( new TextureSwappingBehaviour(loadedObj,loadedObj, BehaviourArgument1, BehaviourArgument2) );
                            }

                            if(BehaviourId == "Trigger"){
                                int value = atoi(BehaviourArgument1.c_str());
                                BehaviourArgument2 = behaviourName.substr( currentBehaviour, nextBehaviour - currentBehaviour);
                                loadedObj->setBehaviour( new TriggerBehaviour(loadedObj, aWorld, aInventory, aTipsystem, aAudioPlayer, value , BehaviourArgument2) );
                            }


                        }

                    }
                    while (nextBehaviour != std::string::npos);



  /*
                    if(behaviourName == "1"){
                        loadedObj->setCollider( new Collider(1.0f, 1.0f, loadedObj) );
                        loadedObj->setBehaviour( new ItemBehaviour(loadedObj, aWorld, aInventory) );
                    }else if(behaviourName == "Swaping"){
                        //loadedObj->setCollider( new Collider(1.0f, 1.0f, loadedObj) );
                        loadedObj->setBehaviour( new TextureSwappingBehaviour(loadedObj,loadedObj, "StorageRoomDARK.png", "StorageRoomLIGHT.png") );

                    }else{
                        loadedObj->setCollider( new Collider(1.0f, 1.0f, loadedObj) );
                        loadedObj->setBehaviour( new DoorBehaviour(loadedObj, aWorld, aInventory, behaviourName) );
                    }
*/
                }setBehaviour = false;


                aWorld->add( loadedObj  );
                i = 0;
            }
        }
        while (next != std::string::npos);



    }
    level.close();
}



/*
        if(level.is_open()){
            while(level.good()){
                getline(level,line);
                stringSize = line.size();
                for(int i = 0; i < stringSize; i += 2 ){
                    countX += 4;
                    objectNmb = line.substr(i, 1);

                    if(objectNmb == "9"){
                        countZ += 10;
                        countX = -10;
                    }
                    if(objectNmb == "1"){
                        countY = 1;

                        //std::cout << " X" << countX << " Y" << countY << " Z" << countZ << level <<std::endl;

                        //std::cout << scanf(line, 1) <<std::endl;

                        GameObject * player = new GameObject("Player", glm::vec3( countX, countY, countZ ));

                        player->setBehaviour( new TextureSwappingBehaviour(aWorld, player, "bricks.jpg" , "monkey.jpg" ) );

                        //player->setMesh( suzanna );

                        player->setMesh( wallPlaceHolder );


                        player->setColorMap( Texture::load("models/bricks.jpg") );
                        aWorld->add( player  );



                    }

                    if(objectNmb == "2"){
                        for(int j = i; j < stringSize; ++j ){
                            objectNmb = line.substr(j, 1);
                            if(objectNmb == ";"){
                                std::cout << j - i <<std::endl;
                                objectNmb = line.substr(i + 2, j - 6);
                                std::cout << objectNmb <<std::endl;

                                GameObject * player = new GameObject("Player", glm::vec3( countX, countY, countZ ));

                                player->setBehaviour( new TextureSwappingBehaviour(aWorld, player, "bricks.jpg" , "monkey.jpg" ) );



                                Mesh * wallPlaceHolder = Mesh::load( ("models/" + std::string(objectNmb) + ".obj").c_str() );


                                //player->setMesh( suzanna )

                                player->setMesh( wallPlaceHolder );


                                player->setColorMap( Texture::load("models/bricks.jpg") );
                                aWorld->add( player  );

                                i = j;
                            }
                        }
                    }

                    if(objectNmb ==  "0"){



                    }
                }
            }
        level.close();


        //else std::cout << "Unable to open file " << level <<std::endl;

    }
*/
}


