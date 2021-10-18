#ifndef HERO_H
#define HERO_H

#include "Character.h"

class Hero: public Character {
    public:
        Hero(Properties props);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    protected:

    private:
};

#endif // HERO_H
