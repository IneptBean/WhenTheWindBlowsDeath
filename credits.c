//---------------------------------------------------------
// file:	gamestate_template.c
// Authors: Sabine ALiev and Hannah Blank
// Course: GAM100F22
//
// All content � 2022 DigiPen (USA) Corporation, all rights reserved
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_splash.h"
#include "gamestate_officemain.h"
#include "loadsprites.h"
#include "menu.h"

CP_Font myFont;
CP_Image menuButton;
CP_Image mouseImage;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void credits_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
	myFont = CP_Font_Load("./Assets/Fonts/OldStyle/OldStyle/OLDSH___.ttf");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_BASELINE);
	mouseImage = CP_Image_Load("./Assets/Images/mag.png");
	menuButton = CP_Image_Load("./Assets/Images/Menu/Menu_Button.png");
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void credits_update(void)
{
	// check input, update simulation, render etc.
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	
	
	CP_Color textColor = CP_Color_Create(255, 255, 255, 255);

	CP_Settings_Fill(textColor);
	float textSize = 80.0f;
	CP_Settings_TextSize(textSize);
	CP_Font_Set(myFont);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Font_DrawText("CREDITS", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 1 / 16);
	
	textSize = 45.0f;
	CP_Settings_TextSize(textSize);
	CP_Font_DrawText("DEVELOPER/PROGRAMMER/PRODUCER/UX", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 30 / 160);
	CP_Font_DrawText("DEVELOPER/PROGRAMMER/ARTIST/UI", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 40 / 160);
	CP_Font_DrawText("SPECIAL THANKS/OUTSIDE HELP", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 53 / 160);
	CP_Font_DrawText("MUSIC", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 60 / 160);
	CP_Font_DrawText("PIXEL ART", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 70 / 160);
	CP_Font_DrawText("INSTRUCTOR", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 80 / 160);
	
	textSize = 37.0f;
	CP_Settings_TextSize(textSize);
	CP_Font_DrawText("PRESIDENT: CLAUDEE COMAIR", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 95 / 160);
	CP_Font_DrawText("All DigiPen students, faculty, and staff who supported this project", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 110 / 160);
	CP_Font_DrawText("Made with FMOD Studio by Firelight Technologies Pty Ltd", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 115 / 160);
	CP_Font_DrawText("Copyright (c) 2015, Christian Thalmann and the Cormorant Project Authors (github.com/CatharsisFonts/Cormorant)d", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 120 / 160);

	CP_Font_DrawText("___________________________________", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 31 / 160);
	CP_Font_DrawText("__________________________________", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 41 / 160);
	CP_Font_DrawText("________________________________", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 54 / 160);
	CP_Font_DrawText("_______", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 61 / 160);
	CP_Font_DrawText("_________", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 71 / 160);
	CP_Font_DrawText("___________", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 81 / 160);

	textColor = CP_Color_Create(218, 211, 203, 255);
	CP_Settings_Fill(textColor);
	textSize = 40.0f;
	CP_Settings_TextSize(textSize);
	CP_Font_DrawText("HANNAH BLANK", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 35 / 160);
	CP_Font_DrawText("SABINE ALIEV", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 45 / 160);
	CP_Font_DrawText("DAVID RUST", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 65 / 160);
	CP_Font_DrawText("VIM KUEHN", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 75 / 160);
	CP_Font_DrawText("ANDY ELLINGER", ((float)CP_System_GetWindowWidth() * 1 / 2), (float)CP_System_GetWindowHeight() * 85 / 160);

	

	if (CP_Input_GetMouseX() > 800 &&
		CP_Input_GetMouseX() < 1100 &&
		CP_Input_GetMouseY() > 900 &&
		CP_Input_GetMouseY() < 1000)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameState(menu_init, menu_update, menu_exit);
		}
	}
	textColor = CP_Color_Create(0, 0, 0, 255);
	CP_Image_Draw(menuButton, (float)(CP_System_GetDisplayWidth() * 0.5 - 150), 900, 300, 100, 255);
	CP_Settings_Fill(textColor);
	textSize = 40.0f;
	CP_Settings_TextSize(textSize);
	CP_Font_DrawText("Home", (float) (CP_System_GetDisplayWidth() * 0.5) , 950);

	//DRAW CURSOR
	CP_Image_Draw(mouseImage, CP_Input_GetMouseX(), CP_Input_GetMouseY(), 50, 60, 255);
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void credits_exit(void)
{
	
}