#include "Interperter.hpp"


#include "Mesh.hpp"
#include "Texture.hpp"
#include "Behaviours/TextureSwappingBehaviour.hpp"

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

void Interperter::readFile(std::string fileName, World * aWorld){

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
        getline(level,line);
        std::cout << line << level <<std::endl;


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

            if( i == 4){
                float sumx = atof( line.substr( current, next - current ).c_str() );
                countX = sumx;
            }

            if( i == 5){
                float sumy = atof( line.substr( current, next - current ).c_str() );
                countY = sumy;
            }

            if( i == 6){
                float sumz = atof( line.substr( current, next - current ).c_str() );
                countZ = sumz;

                GameObject * loadedObj = new GameObject(objectName, glm::vec3( countX, countY, countZ ));
                loadedMesh = Mesh::load( ("models/" + modelName + ".obj").c_str() );
                loadedObj->setMesh( loadedMesh );
                loadedTextue = Texture::load( ("models/" + textureName).c_str() );
                loadedObj->setColorMap( loadedTextue );
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


