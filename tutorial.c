//---------------------------------------------------------
// file:	gamestate_template.c
// Authors: Sabine ALiev and Hannah Blank
// Course: GAM100F22
//
// All content � 2022 DigiPen (USA) Corporation, all rights reserved
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_officemain.h"
#include "tutorial.h"
#include "credits.h"
#include "loadsprites.h"
#include "menu.h"
#include "main.h"

CP_Font myFont;
CP_Image background;
CP_Image clipboard;
CP_Image portfolio;
CP_Image textBox;
CP_Image mouseImage;
float timer;
float decX;
int dialogue;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void tutorial_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
	myFont = CP_Font_Load("./Assets/Fonts/OldStyle/OldStyle/OLDSH___.ttf");
	background = CP_Image_Load("./Assets/Images/Tutorial/TutorialScreen.png");
	portfolio = CP_Image_Load("./Assets/Images/Office/FolderStart.png");
	clipboard = CP_Image_Load("./Assets/Images/Office/Clipboard.png");
	textBox = CP_Image_Load("./Assets/TextBoxes/Tutorial/tortText1.png");
	mouseImage = CP_Image_Load("./Assets/Images/mag.png");
	dialogue = 0;
	decX = -233.0f;
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void tutorial_update(void)
{
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Image_Draw(background, 0, 0, 1900, 1100, 255);
	CP_Image_Draw(clipboard, 1750, 25, 100, 150, 255);
	CP_Image_Draw(portfolio, 1750, 825, 150, 200, 255);
	// check input, update simulation, render etc.
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));

	// dec moving in screen 
	timer += CP_System_GetDt();
	if (decX >= 100.0f)
	{
		decX = 100.0f;
		decdusk_sprit(decX, 500);
	}

	if (timer > 1.0f && decX < 100.0f)
	{
		decX += timer * 5.0f;
		decdusk_sprit(decX, 500);
	}


	if (CP_Input_GetMouseX() > 350 &&
		CP_Input_GetMouseX() < 1600 &&
		CP_Input_GetMouseY() > 830 &&
		CP_Input_GetMouseY() < 1030 && dialogue == 3)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameState(gamestate_officemain_init, gamestate_officemain_update, gamestate_officemain_exit);
		}
	}
	else if (CP_Input_GetMouseX() > 350 &&
		CP_Input_GetMouseX() < 1600 &&
		CP_Input_GetMouseY() > 830 &&
		CP_Input_GetMouseY() < 1030 && dialogue == 0)
	{
		if (CP_Input_MouseClicked())
		{
			textBox = CP_Image_Load("./Assets/TextBoxes/Tutorial/tortText2.png");
			dialogue ++;
		}
	}
	 else if (CP_Input_GetMouseX() > 350 &&
		CP_Input_GetMouseX() < 1600 &&
		CP_Input_GetMouseY() > 830 &&
		CP_Input_GetMouseY() < 1030 && dialogue == 1)
	{
		if (CP_Input_MouseClicked())
		{
			textBox = CP_Image_Load("./Assets/TextBoxes/Tutorial/tortText3.png");
			dialogue++;
		}
	}
	 else if (CP_Input_GetMouseX() > 350 &&
		 CP_Input_GetMouseX() < 1600 &&
		 CP_Input_GetMouseY() > 830 &&
		 CP_Input_GetMouseY() < 1030 && dialogue == 2)
	{
		if (CP_Input_MouseClicked())
		{
			textBox = CP_Image_Load("./Assets/TextBoxes/Tutorial/tortText4.png");
			dialogue++;
		}
	}
	CP_Image_Draw(textBox, 650, 850, 750, 150, 255);

	//DRAW CURSOR
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Image_Draw(mouseImage, CP_Input_GetMouseX(), CP_Input_GetMouseY(), 50, 60, 255);
}

void tutorial_exit(void)
{

}

