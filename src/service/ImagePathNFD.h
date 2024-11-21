//
// Created by guilherme on 21/11/24.
//

#ifndef IMAGEPATHNFD_H
#define IMAGEPATHNFD_H
#include "../adpaters/ImagePathAdapter.h"
#include <nfd.h>
#include "../log/Log.h"

class ImagePathNFD : public ImagePathAdapter  {

public:
    ImagePathNFD() = default;
    std::string getPath() override;
};
#endif //IMAGEPATHNFD_H
