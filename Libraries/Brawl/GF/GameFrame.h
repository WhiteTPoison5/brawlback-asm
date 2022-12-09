//
// Created by johno on 7/20/2020.
//

#ifndef PROJECTMCODES_GAMEFRAME_H
#define PROJECTMCODES_GAMEFRAME_H

#define AS_FLOAT(num) *(float *)&num
#define AS_INT(num) *(int *)&num
#define ACCESS_INT(addr) *(int *)(addr)
#define ACCESS_U8(addr) *(u8 *)(addr)
#define ACCESS_U32(addr) *(u32 *)(addr)
#define ACCESS_PTR(addr) *(void **)(addr)

#include "../../../Globals/stdtypes.h"

struct GameFrame {
    char _spacer[4];
    //4
    u32 frameCounter;
    char _spacer2[0xC - 0x4 - 4];
    //0xC
    float frameDelta;
    char _spacer3[0x14 - 0xC - 4];
    //0x14
    //This counter seems to only be reset when a match starts
    //It continues counting through results and the CSS
    //It is always slightly ahead of the game frame counter
    //When the game first starts, both counters are the same
    //Then, some time after, frameCounter is reset
    //This happens on the same frame startRec is called, so this is probably when the game *really* starts
    u32 persistentFrameCounter;
    // It gets set to 0 at 0x8004e888 on InitGameFrameforReplay
};

#define GAME_FRAMES_INTO_RUNTIME ACCESS_U32(0x805B5014)
#define GAME_FRAME ((GameFrame*) 0x901812a0)

#endif //PROJECTMCODES_GAMEFRAME_H
