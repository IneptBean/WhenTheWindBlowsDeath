//---------------------------------------------------------
// file:	loadsprites.c
// Authors: Sabine ALiev and Hannah Blank
// Course: GAM100F22
//
// All content � 2022 DigiPen (USA) Corporation, all rights reserved
//---------------------------------------------------------
#include <stdio.h>
#include "cprocessing.h"
#include "loadsprites.h"
#include "animation.h"
#include "gamestate_officemain.h"
#include "gamestate_portfolio.h"
#include "gamestate_win.h"
#include "gamestate_lose.h"
#include "main.h"

int Guess = 3;

float startPos;
CP_Image textBox;

CP_BOOL clickable_coat;
CP_BOOL clickable_necklace;
CP_BOOL clickable_phone;
CP_BOOL clickable_debt;
CP_BOOL clickable_watch;

CP_Image guessImage;
CP_Image hiddenSuspect1;
CP_Image hiddenSuspect2;
CP_Image hiddenSuspect3;
CP_Image hiddenSuspect4;
CP_Image hiddenSuspect5;
CP_Image footprintImage;
CP_Image penImage;

CP_Image redX;

//DECT DUSK SPRITE
void decdusk_sprit(float xPos, float yPos)
{
	duskWalkImage = CP_Image_Load("./Assets/Images/Office/duskOffice.png");
	CP_Image_Draw(duskWalkImage, xPos, yPos, 233, 570, 255);
}

void dusksWalkAnimation(void)
{
	float decX = -233.0f;

	while (decX <= 100.0f)
	{
		decX += 0.3f * 5.0f;
		decdusk_sprit(decX, 500);
	}

     
	if (decX >= 100.0f)
	{
		dusksStandAnimation();
	}

}

void dusksStandAnimation(void)
{
	float timer = 0;

	while (timer < 10)
	{
		timer += 1;
		decdusk_sprit(100, 500);
	}
	
}
void dusksWalkAnimationBack(void)
{

	float decX = 100.0f;
	while (decX > -233.0f)
	{
		decX -= 2.0f * 5.0f;
		decdusk_sprit(decX, 500);
	}

	decdusk_sprit(decX, 500);

}


void draw_guess(void)
{
	guessImage = CP_Image_Load("./Assets/Images/mag.png");
	CP_Color textColor = CP_Color_Create(0, 0, 0, 255);
	CP_Settings_Fill(textColor);
	CP_Settings_TextSize(40.0f);
	CP_Font_DrawText("Guesses:", 75, 25);
	CP_Color buttonColor = CP_Color_Create(0, 0, 250, 255);
	CP_Settings_Fill(buttonColor);
	if (Guess == 3)
	{
		CP_Image_Draw(guessImage, 80, 50, 37, 40, 255);
		CP_Image_Draw(guessImage, 120, 50, 37, 40, 255);
		CP_Image_Draw(guessImage, 160, 50, 37, 40, 255);
	}
	else if (Guess == 2)
	{
		CP_Image_Draw(guessImage, 80, 50, 37, 40, 255);
		CP_Image_Draw(guessImage, 120, 50, 37, 40, 255);
	}
	else if (Guess == 1)
	{
		CP_Image_Draw(guessImage, 80, 50, 37, 40, 255);
	}
}







//GO TO PORTFOLIO
void portfolioButton(void)
{
	if (CP_Input_GetMouseX() > 1750 &&
		CP_Input_GetMouseX() < 1750 + 150 &&
		CP_Input_GetMouseY() > 825 &&
		CP_Input_GetMouseY() < 825 + 200)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameState(gamestate_portfolio_init, gamestate_portfolio_update, gamestate_portfolio_exit);
		}
	}
}

//CLUE STRUCT
Clue createClue(float x, float y, float width, float height, void(*onClick)(void))
{
	Clue clue;
	clue.hover = 0;
	clue.x = x;
	clue.y = y;
	clue.width = width;
	clue.height = height;
	clue.onClick = onClick;
	return clue;
}

void collisionCheck(Clue *clue)
{
	if (CP_Input_GetMouseX() > clue->x &&
		CP_Input_GetMouseX() < clue->x + clue->width &&
		CP_Input_GetMouseY() > clue->y &&
		CP_Input_GetMouseY() < clue->y + clue->height)
	{
		clue->hover = 1;
		if (CP_Input_MouseClicked())
		{
			textDraw = TRUE;
			printf("%i", textDraw);
			clue->onClick();
		}
	}
	else
		clue->hover = 0;
}

