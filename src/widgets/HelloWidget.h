//
// Created by guilherme on 18/11/24.
//

#ifndef HELLOWIDGET_H
#define HELLOWIDGET_H
#include "Widget.h"


class HelloWidget : public Widget {
public:
    HelloWidget() = default;
    void render() override;
};



#endif //HELLOWIDGET_H
