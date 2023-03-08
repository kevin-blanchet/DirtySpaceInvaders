#pragma once
#include "GameObject.h"
class Laser :
    public GameObject
{
public:
    Laser();
    ~Laser() override = default;

    void Update(PlayField& world) override;

    virtual void Move(PlayField& world);

protected:
    bool m_deleted;
    float m_direction;
    float m_speed;
};

