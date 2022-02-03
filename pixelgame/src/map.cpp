#include "map.h"

namespace max
{
    map::~map()
    {
        DeleteAllGameObjects();
    }

    void map::DeleteAllGameObjects()
    {
        for (auto& i : GameObjects)
        {
            if (i.empty())
            {
                for (auto& x : i)
                {
                    delete x;
                }
                i.clear();
            }
        }
    }

    max::GameObject* map::FindGameObject(std::string& name)
    {
        for (const auto& a : GameObjects)
        {
            for (const auto& x : a)
            {
                if (x->name == name) return x;
            }
        }
        return nullptr;
    }
}