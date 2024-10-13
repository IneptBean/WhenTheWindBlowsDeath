//---------------------------------------------------------
// file:	gamestate_portfolio.c
// Authors: Sabine ALiev and Hannah Blank
// Course: GAM100F22
//
// All content � 2022 DigiPen (USA) Corporation, all rights reserved
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_portfolio.h"
#include "loadsprites.h"
#include "cprocessing_common.h"
#include "gamestate_officemain.h"
#include "gamestate_win.h"
#include "gamestate_lose.h"
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program


CP_BOOL page1;
CP_BOOL page2;
CP_BOOL page3;
CP_BOOL breakpoint;
CP_Image background;
CP_Image arrow1;
CP_Image arrow2t3;
CP_Image arrow2;
CP_Image mouseImage;
CP_Image portfolioText;
CP_Image exitButton;

void gamestate_portfolio_init(void)
{
	page1 = TRUE;
	page2 = FALSE;
	page3 = FALSE;
	breakpoint = TRUE;
	background = CP_Image_Load("./Assets/Images/Portfolio/portfoliobg.png");
	arrow1 = CP_Image_Load("./Assets/Images/Portfolio/portfolioArrow1.png");
	arrow2t3 = CP_Image_Load("./Assets/Images/Portfolio/portfolioArrow1.png");
	arrow2 = CP_Image_Load("./Assets/Images/Portfolio/portfolioArrow2.png");
	exitButton = CP_Image_Load("./Assets/Images/Menu/Menu_Button.png");
}
void gamestate_portfolio_update(void)
{
	// check input, update simulation, render etc.
	CP_Graphics_ClearBackground(CP_Color_Create(249, 234, 229, 255));
	CP_Image_Draw(background, 0, 0, 1900, 1100, 255);
	mouseImage = CP_Image_Load("./Assets/Images/mag.png");
	walked = TRUE;

	if (Guess < 1)
	{
		CP_Engine_SetNextGameState(gamestate_lose_init, gamestate_lose_update, gamestate_lose_exit);
	}

	//EXIT BUTTON
	CP_Image_Draw(exitButton, 1700, 20, 150, 75, 255);
	CP_Color textColor = CP_Color_Create(0, 0, 0, 255);
	CP_Settings_TextSize(25.0f);
	CP_Settings_Fill(textColor);
	CP_Font_DrawText("Back to office", 1720, 60);
	if (CP_Input_GetMouseX() > 1700 &&
		CP_Input_GetMouseX() < 1700 + 150 &&
		CP_Input_GetMouseY() > 20 &&
		CP_Input_GetMouseY() < 20 + 75)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameState(gamestate_officemain_init, gamestate_officemain_update, gamestate_officemain_exit);
		}
	}


	// arrow on page 1
	if (CP_Input_GetMouseX() > 1640 &&
		CP_Input_GetMouseX() < 1640 + 200 &&
		CP_Input_GetMouseY() > 925 &&
		CP_Input_GetMouseY() < 925 + 100)
	{
		if (CP_Input_MouseClicked() && page1 == TRUE && breakpoint == TRUE)
		{
			page1 = FALSE;
			page2 = TRUE;
			page3 = FALSE;
			
		}
	}

	// arrow on page 2 to 1
	if (CP_Input_GetMouseX() > 60 &&
		CP_Input_GetMouseX() < 60 + 200 &&
		CP_Input_GetMouseY() > 925 &&
		CP_Input_GetMouseY() < 925 + 100)
	{
		if (CP_Input_MouseClicked() && page2 == TRUE )
		{
			page1 = TRUE;
			page2 = FALSE;
			
		}
	}

	// arrow on page 2 to 3
	if (CP_Input_GetMouseX() > 1640 &&
		CP_Input_GetMouseX() < 1640 + 200 &&
		CP_Input_GetMouseY() > 925 &&
		CP_Input_GetMouseY() < 925 + 100)
	{
		if (CP_Input_MouseClicked() && page2 == TRUE && breakpoint == FALSE)
		{
			page3 = TRUE;
			page2 = FALSE;
			page1 = FALSE;
			
		}
	}

	// arrow on page 3 
	if (CP_Input_GetMouseX() > 60 &&
		CP_Input_GetMouseX() < 60 + 200 &&
		CP_Input_GetMouseY() > 925 &&
		CP_Input_GetMouseY() < 925 + 100)
	{
		if (CP_Input_MouseClicked() && page3 == TRUE && page1 == FALSE && page2 == FALSE)
		{
			
			page2 = TRUE;
			page3 = FALSE;
			
		}

	}

	if (page1 == TRUE)
	{
		breakpoint = TRUE;
		suspectOneBox();
		suspectTwoBox();
		CP_Image_Draw(arrow1, 1620, 900, 225, 150, 255);
	}
	if (page2 == TRUE)
	{
		breakpoint = FALSE;
		suspectThreeBox();
		suspectFourBox();
		suspectFiveBox();

		CP_Image_Draw(arrow2t3, 1620, 900, 225, 150, 255);
		CP_Image_Draw(arrow2, 45, 900, 225, 150, 255);
	}
	if (page3 == TRUE)
	{
		duskFootBox();
		duskPenBox();
		CP_Image_Draw(arrow2, 45, 900, 225, 150, 255);
	}

	CP_Image_Draw(portfolioText, 650, 850, 750, 150, 255);
	//DRAW CURSOR
	CP_Image_Draw(mouseImage, CP_Input_GetMouseX(), CP_Input_GetMouseY(), 50, 60, 255);
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_portfolio_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
