
// Created by guilherme on 18/11/24.
//

#ifndef WIDGET_H
#define WIDGET_H
#include <c++/11/vector>


class Widget {

    public:
    std::vector<Widget*> childrens;
    template<typename  ...Args>
    Widget(Args... args) {

       (childrens.emplace_back(args), ...);
    };
    virtual ~Widget();
    void addChild(Widget* child);
    void removeChild(Widget* child);
    void removeAllChildren();
    void removeAllChildrenRecursively();
    virtual void render() = 0;
};



#endif //WIDGET_H
