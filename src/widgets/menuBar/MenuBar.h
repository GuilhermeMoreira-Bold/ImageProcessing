//
// Created by guilherme on 20/11/24.
//

#ifndef MENUBAR_H
#define MENUBAR_H
#include "../Widget.h"


class MenuBar : public Widget {

public:
    template<typename ...Args>
    MenuBar(Args... args) : Widget(args...){}

    void render() override;
};



#endif //MENUBAR_H
