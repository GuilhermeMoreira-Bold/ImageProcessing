//
// Created by guilherme on 20/11/24.
//

#ifndef FILEMENUBAR_H
#define FILEMENUBAR_H
#include "../Widget.h"
#include "../imageManipulation/ImageViewerCreator.h"

class FileMenuBar : public Widget {
    ImageViewerCreator* viewerCreator;

    public:
    void render() override;
    template<typename ...Args>
    FileMenuBar(ImageViewerCreator* viewer_creator,Args... args) : Widget(args ...), viewerCreator(viewer_creator) {}
};
#endif //FILEMENUBAR_H