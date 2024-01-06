#include <functions.h>
#include "chadjustment.h"
#include "bgadjustment.h"
#include "video.h"


//#include "testImage.c"
extern BYTE AdjustmentScreenTiles[];
extern BYTE AdjustmentScreenMap[];

//extern const unsigned int testImageTiles[];
//extern const unsigned short testImageMap[];
extern const unsigned int testImageTiles[];
extern const unsigned short testImageMap[];

extern const unsigned int* allTiles[];
extern const unsigned short* allMaps[];

extern void initializeAllMaps();
extern void initializeAllTiles();

/*int main()
{
    initSystem();

	precautionScreen();
	adjustmentScreen();
	languageSelectionScreen();

    gameLoop();

    return 0;
}*/

int tiles_length(const unsigned int arr[])
{
    int i;
    int count = 0;
    for(i=0; arr[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}

int map_length(const unsigned short arr[])
{
    int i;
    int count = 0;
    for(i=0; arr[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}



void drawimage(void* drawtiles, void* drawmap) {
	//load characters
	copymem((void*)CharSeg0, (void*)(drawtiles), 5000);  //dest, src, num
	int row;
	for(row = 0; row < 28; ++row){
		//load a row of the map
		copymem((void*)(BGMap(0) + row*128), (void*)(drawmap + row*96), 128);
		//copymem((void*)(BGMap(1) + row*128), (void*)(drawmap + row*96), 128);
    }
}
int main()
{
	initializeAllMaps();
	initializeAllTiles();
    //Initial setup
    vbDisplayOn();
	

    //Setup worlds
    WA[31].head = (WRLD_LON|WRLD_OVR);
    WA[31].w = 384;
    WA[31].h = 224;

    WA[30].head = (WRLD_RON|WRLD_OVR);
    WA[30].my = 224;
    WA[30].w = 384;
    WA[30].h = 224;

    WA[29].head = WRLD_END;
		
    
	//Set brightness registers
    vbDisplayShow();
	
	int i;
	for(i = 0; i < 476; ++i){
		drawimage((void*)(allTiles[i]), (void*)(allMaps[i]));
		vbWaitFrame(1);
	}
	

    return 0;
}

