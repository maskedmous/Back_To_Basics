#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "TipSystem.hpp"

TipSystem::TipSystem(Hud * aHud, AudioPlayer * aAudioPlayer)
: hud(aHud), audioPlayer(aAudioPlayer), timer(5)
{
    //ctor
}

TipSystem::~TipSystem()
{
    //dtor
}

void TipSystem::getTip(std::string itemName)
{
    std::string tempTip = "";
    std::string tempItemA = "";
    std::string line = "";
    std::string seperator = ";";

    std::ifstream tipReader ("tips.txt");

    if(tipReader.is_open())
    {
        unsigned int i = 0;
        while(tipReader.good())
        {
            getline(tipReader, line);

            size_t current;
            size_t next = -1;

            do
            {
                current = next + 1;
                next = line.find_first_of( seperator, current );
                i++;
                if(i == 1)
                {
                    tempItemA = line.substr(current, next - current);
                }
                if(i == 2)
                {
                    tempTip = line.substr(current, next - current);
                    //std::cout << "Reading: " << tempTip << std::endl;
                }

                if(tempItemA != "" && tempTip != "")
                {
                    if(tempItemA != itemName)
                    {
                        tempItemA = "";
                        tempTip = "";
                        i = 0;
                    }
                    else
                    {
                        //std::cout << "Using: " << tempTip << std::endl;
                        sendTip(tempTip);
                        tempTip = "";
                        tempItemA = "";
                    }
                }

            }
            while(next != std::string::npos);
        }
        tipReader.close();
    }
}

void TipSystem::getFeedback(std::string itemName)
{
    std::string tempTip = "";
    std::string tempItemA = "";
    std::string line = "";
    std::string seperator = ";";

    std::ifstream tipReader ("feedback.txt");

    if(tipReader.is_open())
    {
        unsigned int i = 0;
        while(tipReader.good())
        {
            getline(tipReader, line);

            size_t current;
            size_t next = -1;

            do
            {
                current = next + 1;
                next = line.find_first_of( seperator, current );
                i++;
                if(i == 1)
                {
                    tempItemA = line.substr(current, next - current);
                }
                if(i == 2)
                {
                    tempTip = line.substr(current, next - current);
                    //std::cout << "Reading: " << tempTip << std::endl;
                }

                if(tempItemA != "" && tempTip != "")
                {
                    if(tempItemA != itemName)
                    {
                        tempItemA = "";
                        tempTip = "";
                        i = 0;
                    }
                    else
                    {
                        std::cout << "Using: " << tempTip << std::endl;
                        sendTip(tempTip);
                        tempTip = "";
                        tempItemA = "";
                    }
                }

            }
            while(next != std::string::npos);
        }
        tipReader.close();
    }
}

void TipSystem::getSecondTip()
{
    //sendTip("this is a test tip");
}

void TipSystem::sendTip(std::string aTip)
{
    //std::cout << aTip << std::endl;
    //send the tip to the hud so the hud shows the tip above the inventory
    hud->setTip(aTip);
    audioPlayer->Play("tip", false);
}

void TipSystem::countdown(float step)
{
    //decrease timer each second and show a 2nd tip if the timer is 0
    if(timer > 0) timer -= step;
    else
    {
        //timer has reached 0 so reset it!
        getSecondTip();
        reset();
    }
}

void TipSystem::reset()
{
    //set the timer back to 2 minutes
    timer = 120;
}
