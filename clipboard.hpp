#ifndef CLIP_BOARD_HPP
#define CLIP_BOARD_HPP
#include <windows.h>
#include <string>

void copyToClipBoard(const std::string &str){
    const size_t len = str.length() + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), str.c_str(), len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

void copyToClipBoard(int64_t num){
    copyToClipBoard(std::to_string(num));
}
#endif //CLIP_BOARD_HPP