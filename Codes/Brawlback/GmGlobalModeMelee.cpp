#include "GmGlobalModeMelee.h"
#include "Netplay.h"

#include <cstring>

// size is 0x320

// this is a 4 stock, 8 minute vs match with p1 being falco (default costume), and p2 being wolf (default costume) on FD
const u8 defaultGmGlobalModeMelee[] = {0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2a, 0x81, 0x8, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x78, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0x7, 0x57, 0xff, 0xf1, 0xff, 0x87, 0xf1, 0xff, 0x0, 0x3, 0xf0, 0x2f, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x28, 0x1d, 0x2, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0x0, 0x1, 0x0, 0x4, 0x0, 0x0, 0x2, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0x3, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0x3, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0x3, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0x3, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0x3, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

namespace GMMelee {

    bool isMatchChoicesPopulated = false;
    int charChoices[MAX_NUM_PLAYERS] = {-1, -1, -1, -1};
    int stageChoice = -1;

    void PopulateMatchSettings(int chars[MAX_NUM_PLAYERS], int stageID) {
        for (int i = 0; i < MAX_NUM_PLAYERS; i++) {
            charChoices[i] = chars[i];
        }
        stageChoice = stageID;
        isMatchChoicesPopulated = true;
    }
    // called on match end
    void ResetMatchChoicesPopulated() { isMatchChoicesPopulated = false; }

    // TODO: fill out the gmGlobalModeMelee struct with these
    #define P1_CHAR_ID_IDX 152
    #define P2_CHAR_ID_IDX 244
    #define STAGE_ID_IDX 27

    SIMPLE_INJECTION(postSetupMelee, 0x806dd03c, "addi	sp, sp, 48") {
        _OSDisableInterrupts();
        OSReport("postSetupMelee\n");

        #ifdef NETPLAY_IMPL
        Netplay::StartMatching(); // start netplay logic
        #endif

        // falco, wolf, battlefield
        //PopulateMatchSettings( {0x15, 0x29, -1, -1}, 0x1 );

        if (isMatchChoicesPopulated) {
            OSReport("postSetupMelee stage: 0x%x p1: 0x%x p2: 0x%x\n", stageChoice, charChoices[0], charChoices[1]);

            memcpy(GM_GLOBAL_MODE_MELEE, defaultGmGlobalModeMelee, 0x320);
            u8* melee = (u8*)GM_GLOBAL_MODE_MELEE;

            melee[P1_CHAR_ID_IDX] = charChoices[0];
            melee[P2_CHAR_ID_IDX] = charChoices[1];
            melee[P1_CHAR_ID_IDX+1] = 0; // Set player type to human
            melee[P2_CHAR_ID_IDX+1] = 0;
            // melee[STAGE_ID_IDX] = stageChoice;
            melee[STAGE_ID_IDX] = 0x01; // TODO uncomment and use above line, just testing with battlefield
        }

        _OSEnableInterrupts();
    }


}