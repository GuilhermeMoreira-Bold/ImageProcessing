//
// Created by guilherme on 21/11/24.
//

#include "ImagePathNFD.h"

std::string ImagePathNFD::getPath() {
    nfdchar_t *outPath = nullptr;
    nfdresult_t result = NFD_OpenDialog(nullptr,nullptr,&outPath);
    if(result == NFD_OKAY) {
         return outPath;
    }
    if(result == NFD_CANCEL) {
     return "";
    }
    Log::getInstance()->log(ERROR,"Error: %s\n" + static_cast<std::string>(NFD_GetError()));
    return "";
}
