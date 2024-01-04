#include <functions.h>
#include <components.h>
#include "chadjustment.h"
#include "bgadjustment.h"
#include "video.h"
#include "adjustmentScreen.h"
//#include "testImage.c"
extern BYTE AdjustmentScreenTiles[];
extern BYTE AdjustmentScreenMap[];

//extern const unsigned int testImageTiles[];
//extern const unsigned short testImageMap[];
extern const unsigned int testImageTiles[];
extern const unsigned short testImageMap[];
/*int main()
{
    initSystem();

	precautionScreen();
	adjustmentScreen();
	languageSelectionScreen();

    gameLoop();

    return 0;
}*/
void drawimage(void* drawtiles, void* drawmap) {
	copymem((void*)CharSeg0, (void*)(drawtiles), 2688);  //dest, src, num
	int row;
	for(row = 0; row < 28; ++row){
		copymem((void*)(BGMap(0) + row*128), (void*)(drawmap + row*96), 128);
    }
}
int main()
{
    //Initial setup
    vbDisplayOn();

    //Copy tileset and tilemap into memory
    //copymem((void*)CharSeg0, (void*)CHADJUSTMENT, 256*16);  //dest, src, num
    //copymem((void*)BGMap(0), (void*)BGADJUSTMENT, 450*16);

	//copymem((void*)CharSeg0, (void*)(testImageTiles), 2688);  //dest, src, num
    //copymem((void*)(BGMap(0)), (void*)(testImageMap), 2688);
	drawimage((void*)(testImageTiles), (void*)(testImageMap));

    //Setup worlds
    //(This uses structs to access world data, the old method using functions is commented out)
    WA[31].head = (WRLD_LON|WRLD_OVR);
    WA[31].w = 384;
    WA[31].h = 224;

    WA[30].head = (WRLD_RON|WRLD_OVR);
    WA[30].my = 224;
    WA[30].w = 384;
    WA[30].h = 224;

    WA[29].head = WRLD_END;
		
	/*u32 srcData = 12345;	
	u32* source = &srcData;
	copymem((void*)L_FRAME0, (void*)source, 32);*/
    
	//Set brightness registers
    vbDisplayShow();

    //Main loop
	while(1){

	}

    return 0;
}

