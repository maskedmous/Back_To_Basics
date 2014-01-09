#ifndef TIPSYSTEM_HPP
#define TIPSYSTEM_HPP

#include "Hud.hpp"

class TipSystem
{
    public:
        TipSystem(Hud * aHud);
        virtual ~TipSystem();
        void getTip(std::string itemName);
        void countdown(float step);
    protected:

    private:
        void getSecondTip();
        void sendTip(std::string aTip);
        void reset();

        Hud * hud;
        float timer;
};

#endif // TIPSYSTEM_HPP
