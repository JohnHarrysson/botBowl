#ifndef WOUNDS_H
#define WOUNDS_H

enum class WoundType{
    BADLY_HURT,
    BROKEN_JAW,
    BROKEN_RIBS,
    BROKEN_LEG,
    BROKEN_ARM,
    SMASHED_HAND,
    GOUGED_EYE,
    GROIN_STRAIN,
    PINCHED_NERVE,
    DAMAGED_BACK,
    SMASHED_KNEE,
    SMASHED_ANKLE,
    SMASHED_HIP,
    FRACTURED_SKULL,
    SERIOUS_CONCUSSION,
    BROKEN_NECK,
    SMASHED_COLLARBONE,
    NIGGLING_INJURY,
    DEATH
};

class Wound {

    private:
        WoundType woundType_;
        
    public:
        Wound(WoundType woundType) : woundType_(woundType) {}
        ~Wound() {}

        const WoundType getWoundType() { return woundType_; }
};

#endif