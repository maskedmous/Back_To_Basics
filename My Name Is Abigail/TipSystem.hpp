#ifndef TIPSYSTEM_HPP
#define TIPSYSTEM_HPP

#include "AudioPlayer.hpp"
#include "Hud.hpp"

class TipSystem
{
    public:
        TipSystem(Hud * aHud);
        virtual ~TipSystem();
        void getTip(std::string itemName);
        void countdown(float step);
        void sendTip(std::string aTip);
        void getFeedback(std::string aTip);

    protected:

    private:
        void getSecondTip();
        void reset();

        Hud * hud;
        float timer;
};

#endif // TIPSYSTEM_HPP
