#ifndef WOUNDS_H
#define WOUNDS_H

enum class WoundType{
    BADLY_HURT,
    BROKEN_LEG,
    BROKEN_ARM,
    BROKEN_NECK,
    NIGGLING_INJURY,
    DEATH
};

class Wounds {

    private:
        WoundType wound_;
        
    public:
        Wounds();   
        ~Wounds();

};


#endif