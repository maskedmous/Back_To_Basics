#include "TipSystem.hpp"

TipSystem::TipSystem(Hud * aHud)
: hud(aHud), timer(5)
{
    //ctor
}

TipSystem::~TipSystem()
{
    //dtor
}

void TipSystem::getTip(std::string itemName)
{
    std::string tip = "this is a tip.";
    //get the tip from the .txt

    //send it to the hud

    sendTip(tip);
}

void TipSystem::getSecondTip()
{
    sendTip("this is a test tip");
}

void TipSystem::sendTip(std::string aTip)
{
    //send the tip to the hud so the hud shows the tip above the inventory
    hud->setTip(aTip);
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
