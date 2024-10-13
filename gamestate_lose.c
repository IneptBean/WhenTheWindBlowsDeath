//---------------------------------------------------------
// file:	gamestate_template.c
// Authors: Sabine ALiev and Hannah Blank
// Course: GAM100F22
// All content � 2022 DigiPen (USA) Corporation, all rights reserved
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_splash.h"
#include "gamestate_officemain.h"
#include "loadsprites.h"
#include "menu.h"

CP_Font myFont;
CP_Image startButton;
CP_Image mouseImage;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_lose_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
	myFont = CP_Font_Load("./Assets/Fonts/OldStyle/OldStyle/OLDSSCH_.ttf");
	startButton = CP_Image_Load("./Assets/Images/Menu/Menu_Button.png");
	mouseImage = CP_Image_Load("./Assets/Images/mag.png");
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_lose_update(void)
{
	// check input, update simulation, render etc.
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));

	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	float buttonWidth = 400.0f;
	float buttonHeight = 200.0f;
	float buttonX = (float)0.5 * CP_System_GetWindowWidth()  - (float) (0.5 * buttonWidth);
	float buttonY = (float)0.5 * CP_System_GetWindowHeight();

	CP_Color textColor = CP_Color_Create(255, 255, 255, 255);
	CP_Settings_Fill(textColor);
	float textSize = 80.0f;
	CP_Settings_TextSize(textSize);
	CP_Font_Set(myFont);
	CP_Font_DrawText("You're Fired!", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 1 / 7);

	if (CP_Input_GetMouseX() > buttonX &&
		CP_Input_GetMouseX() < buttonX + buttonWidth &&
		CP_Input_GetMouseY() > buttonY + 200 &&
		CP_Input_GetMouseY() < buttonY + 200 + buttonHeight)
	{
		if (CP_Input_MouseClicked())
		{
			buttonWidth += 10.0f;
			buttonHeight += 5.0f;
			CP_Engine_SetNextGameState(menu_init, menu_update, menu_exit);
		}
	}
	textColor = CP_Color_Create(0, 0, 0, 255);
	CP_Image_Draw(startButton,buttonX, buttonY + 200, buttonWidth, buttonHeight, 255);
	CP_Settings_Fill(textColor);
	textSize = 40.0f;
	CP_Settings_TextSize(textSize);
	CP_Font_DrawText("Return to menu", buttonX + (float)(0.5 * buttonWidth), buttonY + 300);
	//DRAW CURSOR
	CP_Image_Draw(mouseImage, CP_Input_GetMouseX(), CP_Input_GetMouseY(), 50, 60, 255);
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_lose_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory

}