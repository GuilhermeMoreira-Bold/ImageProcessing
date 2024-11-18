//
// Created by guilherme on 18/11/24.
//

#include "Widget.h"

#include <algorithm>

Widget::~Widget() {
}

void Widget::addChild(Widget *child) {
    this->childrens.push_back(child);
}

void Widget::removeChild(Widget *child) {
    auto it = std::find(childrens.begin(), childrens.end(), child);
    if(it != childrens.end()) {
        childrens.erase(it);
    }
}

void Widget::removeAllChildren() {

}

void Widget::removeAllChildrenRecursively() {
}