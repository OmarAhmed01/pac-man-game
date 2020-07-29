#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <thread>
#include <ctime>
#include <fstream>
#include "mapdata.h"
#include "Main_Menu.h"
#include "skinnig.h"

using namespace std;
using namespace sf;

struct user
{
	string name = "Player 1";

	int time[10];
	int levelscore[10];
	int totalscore;
}user1;

RenderWindow window(VideoMode(448, 526), "Pac-Man");

Sprite
player,
Blinky, Pinky, Inky, Clyde, Greeney, Lemoney, Magentey, Turquoisey,
background, backgroundinv,
livs1, livs2, livs3,
lvlpac, lvlgst, prtlI, prtlII,
pwr1, pwr2, pwr3, pwr4;

Texture pacman, sarscov, 
blinky, pinky, inky, clyde, greeney, lemoney, magentey, turquoisey,
blinkysars, pinkysars, inkysars, clydesars, greeneysars, lemoneysars, magenteysars, turquoiseysars,
gstlytxt, scrd, dead,
texture, textureinv, pallet,
death, deathsars,
paclvl, gstlvl, prtltxtr;

Music start, pausemusc, lose, dth, scared, ghosts;

Main_Menu menu;
skinnig skn;

Image icon;

Text Gameover;

RectangleShape portala(Vector2f(1.f, 32.f)), portalb(Vector2f(1.f, 32.f));

VertexArray
px1(Points, 25), px2(Points, 25), px3(Points, 25),
px4(Points, 25), px5(Points, 25), px6(Points, 25),
px7(Points, 25),
py1(Points, 15), py2(Points, 15), py3(Points, 15),
py4(Points, 15), py5(Points, 15), py6(Points, 15);

int y = 0, x = 24, i = 0, c = 0;

int
timer2 = 0,
trgtX = rand() % 448, trgtY = rand() % 496,
ptrgtX = rand() % 448, ptrgtY = rand() % 496,
itrgtX = rand() % 448, itrgtY = rand() % 496,
ctrgtX = rand() % 448, ctrgtY = rand() % 496,
gtrgtX = rand() % 448, gtrgtY = rand() % 496,
ltrgtX = rand() % 448, ltrgtY = rand() % 496,
mtrgtX = rand() % 448, mtrgtY = rand() % 496,
ttrgtX = rand() % 448, ttrgtY = rand() % 496;

double vecU = 0, vecD = 0, vecL = 0, vecR = 0;

int timer[15];

int score = 0, Lives = 3, lvl = 1;
Text Score, SCR;

bool 
ghstly = false,
sars = false,
pac = true,
eatabl = false;

void dotting()
{
	x = 24;

	while (x < 448)
	{
		if ((int)mapdata[24][x] == (int)'2')
		{
			px1[i].position = Vector2f(x, 24);

			i++;
		}
		x += 20;
	}
	x = 24;
	i = 0;

	while (x < 448)
	{
		if ((int)mapdata[88][x] == (int)'2')
		{
			px2[i].position = Vector2f(x, 88);

			i++;
		}
		x += 20;
	}
	x = 24;
	i = 0;

	while (x < 448)
	{
		if ((int)mapdata[136][x] == (int)'2')
		{
			px3[i].position = Vector2f(x, 136);

			i++;
		}
		x += 20;
	}
	x = 24;
	i = 0;

	while (x < 448)
	{
		if ((int)mapdata[328][x] == (int)'2')
		{
			px4[i].position = Vector2f(x, 328);

			i++;
		}
		x += 20;
	}
	x = 24;
	i = 0;

	while (x < 448)
	{
		if ((int)mapdata[375][x] == (int)'2')
		{
			px5[i].position = Vector2f(x, 375);

			i++;
		}
		x += 20;
	}
	x = 24;
	i = 0;

	while (x < 448)
	{
		if ((int)mapdata[424][x] == (int)'2')
		{
			px6[i].position = Vector2f(x, 424);

			i++;
		}
		x += 20;
	}
	x = 24;
	i = 0;

	while (x < 435)
	{
		if ((int)mapdata[473][x] == (int)'2')
		{
			px7[i].position = Vector2f(x, 473);

			i++;
		}
		x += 20;
	}
	y = 24;
	i = 0;

	py1[6].position = Vector2f(200, 24);
	py1[7].position = Vector2f(247, 24);

	while (y <= 448)
	{
		if ((int)mapdata[56][y] == (int)'2')
		{
			py1[i].position = Vector2f(y, 56);

			i++;
		}
		y += 1;
	}
	y = 24;
	i = 0;

	py2[6].position = Vector2f(200, 136);
	py2[7].position = Vector2f(247, 136);
	py2[8].position = Vector2f(151, 136);
	py2[9].position = Vector2f(296, 136);

	while (y <= 448)
	{
		if ((int)mapdata[112][y] == (int)'2')
		{
			py2[i].position = Vector2f(y, 112);

			i++;
		}
		y += 1;
	}
	y = 24;
	i = 0;

	py3[6].position = Vector2f(200, 328);
	py3[7].position = Vector2f(247, 328);

	while (y <= 448)
	{
		if ((int)mapdata[352][y] == (int)'2')
		{
			py3[i].position = Vector2f(y, 352);

			i++;
		}
		y += 1;
	}
	y = 24;
	i = 0;

	py4[6].position = Vector2f(344, 375);

	while (y <= 448)
	{
		if ((int)mapdata[400][y] == (int)'2')
		{
			py4[i].position = Vector2f(y, 400);

			i++;
		}
		y += 1;
	}
	y = 24;
	i = 0;

	py5[6].position = Vector2f(200, 424);
	py5[7].position = Vector2f(247, 424);
	py5[8].position = Vector2f(151, 424);
	py5[9].position = Vector2f(296, 424);

	while (y <= 448)
	{
		if ((int)mapdata[448][y] == (int)'2')
		{
			py5[i].position = Vector2f(y, 448);

			i++;
		}
		y += 1;
	}
	y = 24;
	i = 0;

	py6[0].position = Vector2f(104, 160);
	py6[1].position = Vector2f(342, 160);

	py6[2].position = Vector2f(104, 232);
	py6[3].position = Vector2f(342, 232);

	py6[4].position = Vector2f(104, 304);
	py6[5].position = Vector2f(342, 304);

	py6[7].position = Vector2f(104, 204);
	py6[8].position = Vector2f(342, 204);

	py6[9].position = Vector2f(104, 260);
	py6[10].position = Vector2f(342, 260);

	py6[11].position = Vector2f(104, 184);
	py6[12].position = Vector2f(342, 184);

	py6[13].position = Vector2f(104, 280);
	py6[14].position = Vector2f(342, 280);

}

void collision(int &tmr)
{
	if ((timer[lvl] >= 15 && timer[lvl] < 30) || (timer[lvl] >= 60 && timer[lvl] < 65))
	{
		if ((player.getPosition().x >= (px1[0].position.x) - 20 && player.getPosition().x <= (px1[0].position.x) + 20) && player.getPosition().y == px1[0].position.y)
		{
			px1[0].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		if ((player.getPosition().x >= (px7[20].position.x) - 20 && player.getPosition().x <= (px7[20].position.x) + 20) && player.getPosition().y == px7[20].position.y)
		{
			px7[20].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
	}
	else if ((timer[lvl] >= 40 && timer[lvl] < 45) || (timer[lvl] >= 80 && timer[lvl] < 95))
	{
		if ((player.getPosition().x >= (px3[13].position.x) - 20 && player.getPosition().x <= (px3[13].position.x) + 20) && player.getPosition().y == px3[13].position.y)
		{
			px3[13].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		if ((player.getPosition().x >= (px4[0].position.x) - 20 && player.getPosition().x <= (px4[0].position.x) + 20) && player.getPosition().y == px4[0].position.y)
		{
			px4[0].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
	}
	
	c = 0;
	while (c < 25)
	{
		if ((player.getPosition().x >= (px1[c].position.x) - 7 && player.getPosition().x <= (px1[c].position.x) + 7) && player.getPosition().y == px1[c].position.y)
		{
			px1[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 25)
	{
		if ((player.getPosition().x >= (px2[c].position.x) - 7 && player.getPosition().x <= (px2[c].position.x) + 7) && player.getPosition().y == px2[c].position.y)
		{
			px2[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 25)
	{
		if ((player.getPosition().x >= (px3[c].position.x) - 7 && player.getPosition().x <= (px3[c].position.x) + 7) && player.getPosition().y == px3[c].position.y)
		{
			px3[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 25)
	{
		if ((player.getPosition().x >= (px4[c].position.x) - 5 && player.getPosition().x <= (px4[c].position.x) + 5) && player.getPosition().y == px4[c].position.y)
		{
			px4[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 25)
	{
		if ((player.getPosition().x >= (px5[c].position.x) - 5 && player.getPosition().x <= (px5[c].position.x) + 5) && player.getPosition().y == px5[c].position.y)
		{
			px5[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 25)
	{
		if ((player.getPosition().x >= (px6[c].position.x) - 5 && player.getPosition().x <= (px6[c].position.x) + 5) && player.getPosition().y == px6[c].position.y)
		{
			px6[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 25)
	{
		if ((player.getPosition().x >= (px7[c].position.x) - 5 && player.getPosition().x <= (px7[c].position.x) + 5) && player.getPosition().y == px7[c].position.y)
		{
			px7[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 15)
	{
		if ((player.getPosition().x >= (py1[c].position.x) - 5 && player.getPosition().x <= (py1[c].position.x) + 5) && player.getPosition().y == py1[c].position.y)
		{
			py1[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 15)
	{
		if ((player.getPosition().x >= (py2[c].position.x) - 5 && player.getPosition().x <= (py2[c].position.x) + 5) && player.getPosition().y == py2[c].position.y)
		{
			py2[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 15)
	{
		if ((player.getPosition().x >= (py3[c].position.x) - 5 && player.getPosition().x <= (py3[c].position.x) + 5) && player.getPosition().y == py3[c].position.y)
		{
			py3[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 15)
	{
		if ((player.getPosition().x >= (py4[c].position.x) - 5 && player.getPosition().x <= (py4[c].position.x) + 5) && player.getPosition().y == py4[c].position.y)
		{
			py4[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 15)
	{
		if ((player.getPosition().x >= (py5[c].position.x) - 5 && player.getPosition().x <= (py5[c].position.x) + 5) && player.getPosition().y == py5[c].position.y)
		{
			py5[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}

	c = 0;
	while (c < 15)
	{
		if ((player.getPosition().x >= (py6[c].position.x) - 5 && player.getPosition().x <= (py6[c].position.x) + 5) && player.getPosition().y == py6[c].position.y)
		{
			py6[c].position = Vector2f(-5, -5);
			score += 10;
			user1.totalscore += 10;
		}
		c++;
	}
}

void powerpallet(Clock &clk, Time &tm)
{
	if ((player.getGlobalBounds().intersects(pwr1.getGlobalBounds())) || (player.getGlobalBounds().intersects(pwr2.getGlobalBounds())) || (player.getGlobalBounds().intersects(pwr3.getGlobalBounds())) || (player.getGlobalBounds().intersects(pwr4.getGlobalBounds())))
		eatabl = true;
	if (player.getGlobalBounds().intersects(pwr1.getGlobalBounds()))
		{
			pwr1.setPosition(-10, -10);

			Blinky.setTexture(scrd);
			Pinky.setTexture(scrd);
			Inky.setTexture(scrd);
			Clyde.setTexture(scrd);
			Greeney.setTexture(scrd);
			Lemoney.setTexture(scrd);
			Magentey.setTexture(scrd);
			Turquoisey.setTexture(scrd);

			user1.levelscore[lvl] += 10;
			user1.totalscore += 10;
	}
	if (player.getGlobalBounds().intersects(pwr2.getGlobalBounds()))
		{
			pwr2.setPosition(-10, -10);
			Blinky.setTexture(scrd);
			Pinky.setTexture(scrd);
			Inky.setTexture(scrd);
			Clyde.setTexture(scrd);
			Greeney.setTexture(scrd);
			Lemoney.setTexture(scrd);
			Magentey.setTexture(scrd);
			Turquoisey.setTexture(scrd);

			user1.levelscore[lvl] += 10;
			user1.totalscore += 10;
	}
	if (player.getGlobalBounds().intersects(pwr3.getGlobalBounds()))
		{
			pwr3.setPosition(-10, -10);
			Blinky.setTexture(scrd);
			Pinky.setTexture(scrd);
			Inky.setTexture(scrd);
			Clyde.setTexture(scrd);
			Greeney.setTexture(scrd);
			Lemoney.setTexture(scrd);
			Magentey.setTexture(scrd);
			Turquoisey.setTexture(scrd);

			user1.levelscore[lvl] += 10;
			user1.totalscore += 10;
	}
	if (player.getGlobalBounds().intersects(pwr4.getGlobalBounds()))
		{
			pwr4.setPosition(-10, -10);
			Blinky.setTexture(scrd);
			Pinky.setTexture(scrd);
			Inky.setTexture(scrd);
			Clyde.setTexture(scrd);
			Greeney.setTexture(scrd);
			Lemoney.setTexture(scrd);
			Magentey.setTexture(scrd);
			Turquoisey.setTexture(scrd);

			user1.levelscore[lvl] += 10;
			user1.totalscore += 10;
	}

	if (eatabl)
	{
		tm = clk.getElapsedTime();
		timer2 = tm.asSeconds();
	}
	if (timer2 >= 25)
	{
		eatabl = false;

		if (pac)
		{
			Blinky.setTexture(blinky);
			Pinky.setTexture(pinky);
			Inky.setTexture(inky);
			Clyde.setTexture(clyde);
			Greeney.setTexture(greeney);
			Lemoney.setTexture(lemoney);
			Magentey.setTexture(magentey);
			Turquoisey.setTexture(turquoisey);
		}
		else if (sars)
		{
			Blinky.setTexture(blinkysars);
			Pinky.setTexture(pinkysars);
			Inky.setTexture(inkysars);
			Clyde.setTexture(clydesars);
			Greeney.setTexture(greeneysars);
			Lemoney.setTexture(lemoneysars);
			Magentey.setTexture(magenteysars);
			Turquoisey.setTexture(turquoiseysars);

		}
		else if (ghstly)
		{
			Blinky.setTexture(gstlytxt);
			Pinky.setTexture(gstlytxt);
			Inky.setTexture(gstlytxt);
			Clyde.setTexture(gstlytxt);
			Greeney.setTexture(gstlytxt);
			Lemoney.setTexture(gstlytxt);
			Magentey.setTexture(gstlytxt);
			Turquoisey.setTexture(gstlytxt);
		}

		clk.restart();
	}
}

bool
skins = false,
rtn = false,
sound = true,
gamebool = false,
ext = false,

U = false,
D = false,
L = false,
R = false,

BU = false,
BD = false,
BL = false,
BR = false,

PU = false,
PD = false,
PL = false,
PR = false,

IU = false,
ID = false,
IL = false,
IR = false,

CU = false,
CD = false,
CL = false,
CR = false,

GU = false,
GD = false,
GL = false,
GR = false,

LU = false,
LD = false,
LL = false,
LR = false,

MU = false,
MD = false,
ML = false,
MR = false,

TU = false,
TD = false,
TL = false,
TR = false;

int
cntrx = 0, cntry = 0,
prtlx = 0,

ghstx = 0, ghsty = 0,
pnkyx = 0, pnkyy = 0,
inkyx = 0, inkyy = 0,
clydx = 0, clydy = 0,
grnyx = 0, grnyy = 0,
lmnyx = 0, lmnyy = 0,
mgntx = 0, mgnty = 0,
trqox = 0, trqoy = 0;

void Up()
{
	if (U && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y - 2][(int)player.getPosition().x] == (int)'1'))
	{
		player.move(Vector2f(0.0, -1.f));

		cntrx++;
		cntry = 2;

		if (pac || ghstly)
		{
			if (cntrx == 8)cntrx = 0;
		}
		else if (sars)
		{
			if (cntrx == 6)cntrx = 0;
		}

		player.setTextureRect(IntRect(32 * cntrx, 32 * cntry, 32, 32));

		if (L && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x - 2] == (int)'1'))
		{
			U = false;
		}

		if (R && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x + 2] == (int)'1'))
		{
			U = false;
		}
	}
	else if (!R && !L && ((int)mapdata[(int)player.getPosition().y - 2][(int)player.getPosition().x] == (int)'1'))
		U = false;
}
void Down()
{
	if (D && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y + 2][(int)player.getPosition().x] == (int)'1'))
	{
		player.move(Vector2f(0.0, 1.f));

		cntrx++;
		cntry = 3;

		if (pac || ghstly)
		{
			if (cntrx == 8)cntrx = 0;
		}
		else if (sars)
		{
			if (cntrx == 6)cntrx = 0;
		}

		player.setTextureRect(IntRect(32 * cntrx, 32 * cntry, 32, 32));

		if (L && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x - 2] == (int)'1'))
		{
			D = false;
		}

		if (R && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x + 2] == (int)'1'))
		{
			D = false;
		}
	}
	else if (!R && !L && ((int)mapdata[(int)player.getPosition().y + 2][(int)player.getPosition().x] == (int)'1'))
		D = false;
}
void Left()
{
	if (L && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x - 2] == (int)'1'))
	{
		player.move(Vector2f(-1., 0.f));

		cntrx++;
		cntry = 1;

		if (pac || ghstly)
		{
			if (cntrx == 8)cntrx = 0;
		}
		else if (sars)
		{
			if (cntrx == 6)cntrx = 0;
		}

		player.setTextureRect(IntRect(32 * cntrx, 32 * cntry, 32, 32));

		if (D && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y + 2][(int)player.getPosition().x] == (int)'1'))
		{
			L = false;
		}

		if (U && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y - 2][(int)player.getPosition().x] == (int)'1'))
		{
			L = false;
		}
	}
	else if (!U && !D && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x - 2] == (int)'1'))
		L = false;
}
void Right()
{
	if (R && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x + 2] == (int)'1'))
	{
		player.move(Vector2f(1., 0.f));

		cntrx++;
		cntry = 0;

		if (pac || ghstly)
		{
			if (cntrx == 8)cntrx = 0;
		}
		else if (sars)
		{
			if (cntrx == 6)cntrx = 0;
		}

		player.setTextureRect(IntRect(32 * cntrx, 32 * cntry, 32, 32));

		if (D && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y + 2][(int)player.getPosition().x] == (int)'1'))
		{
			R = false;
		}

		if (U && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x] == (int)'2') && !((int)mapdata[(int)player.getPosition().y - 2][(int)player.getPosition().x] == (int)'1'))
		{
			R = false;
		}
	}
	else if (!U && !D && ((int)mapdata[(int)player.getPosition().y][(int)player.getPosition().x + 2] == (int)'1'))
		R = false;
}

void BlinkyUp()
{
	if (BU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		Blinky.move(Vector2f(0.0, -1.f));

		ghstx++;
		ghsty = 2;

		if (ghstx == 4)ghstx = 0;
		Blinky.setTextureRect(IntRect(32 * ghstx, 32 * ghsty, 32, 32));
	}
}
void BlinkyDown()
{
	if (BD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		Blinky.move(Vector2f(0.0, 1.f));

		ghstx++;
		ghsty = 3;

		if (ghstx == 4)ghstx = 0;
		Blinky.setTextureRect(IntRect(32 * ghstx, 32 * ghsty, 32, 32));
	}
}
void BlinkyLeft()
{
	if (BL && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		Blinky.move(Vector2f(-1., 0.f));

		ghstx++;
		ghsty = 1;

		if (ghstx == 4)ghstx = 0;
		Blinky.setTextureRect(IntRect(32 * ghstx, 32 * ghsty, 32, 32));
	}
}
void BlinkyRight()
{
	if (BR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		Blinky.move(Vector2f(1., 0.f));

		ghstx++;
		ghsty = 0;

		if (ghstx == 4)ghstx = 0;
		Blinky.setTextureRect(IntRect(32 * ghstx, 32 * ghsty, 32, 32));
	}
}

void PinkyUp()
{
	if (PU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		Pinky.move(Vector2f(0.0, -1.f));

		pnkyx++;
		pnkyy = 2;

		if (pnkyx == 4)pnkyx = 0;
		Pinky.setTextureRect(IntRect(32 * pnkyx, 32 * pnkyy, 32, 32));
	}
}
void PinkyDown()
{
	if (PD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		Pinky.move(Vector2f(0.0, 1.f));

		pnkyx++;
		pnkyy = 3;

		if (pnkyx == 4)pnkyx = 0;
		Pinky.setTextureRect(IntRect(32 * pnkyx, 32 * pnkyy, 32, 32));
	}
}
void PinkyLeft()
{
	if (PL && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		Pinky.move(Vector2f(-1., 0.f));

		pnkyx++;
		pnkyy = 1;

		if (pnkyx == 4)pnkyx = 0;
		Pinky.setTextureRect(IntRect(32 * pnkyx, 32 * pnkyy, 32, 32));
	}
}
void PinkyRight()
{
	if (PR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		Pinky.move(Vector2f(1., 0.f));

		pnkyx++;
		pnkyy = 0;

		if (pnkyx == 4)pnkyx = 0;
		Pinky.setTextureRect(IntRect(32 * pnkyx, 32 * pnkyy, 32, 32));
	}
}

void InkyUp()
{
	if (IU && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		Inky.move(Vector2f(0.0, -1.f));

		inkyx++;
		inkyy = 2;

		if (inkyx == 4)inkyx = 0;
		Inky.setTextureRect(IntRect(32 * inkyx, 32 * inkyy, 32, 32));
	}
}
void InkyDown()
{
	if (ID && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		Inky.move(Vector2f(0.0, 1.f));

		inkyx++;
		inkyy = 3;

		if (inkyx == 4)inkyx = 0;
		Inky.setTextureRect(IntRect(32 * inkyx, 32 * inkyy, 32, 32));
	}
}
void InkyLeft()
{
	if (IL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		Inky.move(Vector2f(-1., 0.f));

		inkyx++;
		inkyy = 1;

		if (inkyx == 4)inkyx = 0;
		Inky.setTextureRect(IntRect(32 * inkyx, 32 * inkyy, 32, 32));
	}
}
void InkyRight()
{
	if (IR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		Inky.move(Vector2f(1., 0.f));

		inkyx++;
		inkyy = 0;

		if (inkyx == 4)inkyx = 0;
		Inky.setTextureRect(IntRect(32 * inkyx, 32 * inkyy, 32, 32));
	}
}

void ClydeUp()
{
	if (CU && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		Clyde.move(Vector2f(0.0, -1.f));

		clydx++;
		clydy = 2;

		if (clydx == 4)clydx = 0;
		Clyde.setTextureRect(IntRect(32 * clydx, 32 * clydy, 32, 32));
	}
}
void ClydeDown()
{
	if (CD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		Clyde.move(Vector2f(0.0, 1.f));

		clydx++;
		clydy = 3;

		if (clydx == 4)clydx = 0;
		Clyde.setTextureRect(IntRect(32 * clydx, 32 * clydy, 32, 32));
	}
}
void ClydeLeft()
{
	if (CL && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		Clyde.move(Vector2f(-1., 0.f));

		clydx++;
		clydy = 1;

		if (clydx == 4)clydx = 0;
		Clyde.setTextureRect(IntRect(32 * clydx, 32 * clydy, 32, 32));
	}
}
void ClydeRight()
{
	if (CR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		Clyde.move(Vector2f(1., 0.f));

		clydx++;
		clydy = 0;

		if (clydx == 4)clydx = 0;
		Clyde.setTextureRect(IntRect(32 * clydx, 32 * clydy, 32, 32));
	}
}

void GreeneyUp()
{
	if (GU && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y - 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		Greeney.move(Vector2f(0.0, -1.f));

		grnyx++;
		grnyy = 2;

		if (grnyx == 4)grnyx = 0;
		Greeney.setTextureRect(IntRect(32 * grnyx, 32 * grnyy, 32, 32));
	}
}
void GreeneyDown()
{
	if (GD && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y + 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		Greeney.move(Vector2f(0.0, 1.f));

		grnyx++;
		grnyy = 3;

		if (grnyx == 4)grnyx = 0;
		Greeney.setTextureRect(IntRect(32 * grnyx, 32 * grnyy, 32, 32));
	}
}
void GreeneyLeft()
{
	if (GL && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x - 2] == (int)'1'))
	{
		Greeney.move(Vector2f(-1., 0.f));

		grnyx++;
		grnyy = 1;

		if (grnyx == 4)grnyx = 0;
		Greeney.setTextureRect(IntRect(32 * grnyx, 32 * grnyy, 32, 32));
	}
}
void GreeneyRight()
{
	if (GR && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x + 2] == (int)'1'))
	{
		Greeney.move(Vector2f(1., 0.f));

		grnyx++;
		grnyy = 0;

		if (grnyx == 4)grnyx = 0;
		Greeney.setTextureRect(IntRect(32 * grnyx, 32 * grnyy, 32, 32));
	}
}

void LemoneyUp()
{
	if (LU && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y - 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		Lemoney.move(Vector2f(0.0, -1.f));

		lmnyx++;
		lmnyy = 2;

		if (lmnyx == 4)lmnyx = 0;
		Lemoney.setTextureRect(IntRect(32 * lmnyx, 32 * lmnyy, 32, 32));
	}
}
void LemoneyDown()
{
	if (LD && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y + 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		Lemoney.move(Vector2f(0.0, 1.f));

		lmnyx++;
		lmnyy = 3;

		if (lmnyx == 4)lmnyx = 0;
		Lemoney.setTextureRect(IntRect(32 * lmnyx, 32 * lmnyy, 32, 32));
	}
}
void LemoneyLeft()
{
	if (LL && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x - 2] == (int)'1'))
	{
		Lemoney.move(Vector2f(-1., 0.f));

		lmnyx++;
		lmnyy = 1;

		if (lmnyx == 4)lmnyx = 0;
		Lemoney.setTextureRect(IntRect(32 * lmnyx, 32 * lmnyy, 32, 32));
	}
}
void LemoneyRight()
{
	if (LR && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x + 2] == (int)'1'))
	{
		Lemoney.move(Vector2f(1., 0.f));

		lmnyx++;
		lmnyy = 0;

		if (lmnyx == 4)lmnyx = 0;
		Lemoney.setTextureRect(IntRect(32 * lmnyx, 32 * lmnyy, 32, 32));
	}
}

void MagenteyUp()
{
	if (MU && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y - 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		Magentey.move(Vector2f(0.0, -1.f));

		mgntx++;
		mgnty = 2;

		if (mgntx == 4)mgntx = 0;
		Magentey.setTextureRect(IntRect(32 * mgntx, 32 * mgnty, 32, 32));
	}
}
void MagenteyDown()
{
	if (MD && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y + 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		Magentey.move(Vector2f(0.0, 1.f));

		mgntx++;
		mgnty = 3;

		if (mgntx == 4)mgntx = 0;
		Magentey.setTextureRect(IntRect(32 * mgntx, 32 * mgnty, 32, 32));
	}
}
void MagenteyLeft()
{
	if (ML && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x - 2] == (int)'1'))
	{
		Magentey.move(Vector2f(-1., 0.f));

		mgntx++;
		mgnty = 1;

		if (mgntx == 4)mgntx = 0;
		Magentey.setTextureRect(IntRect(32 * mgntx, 32 * mgnty, 32, 32));
	}
}
void MagenteyRight()
{
	if (MR && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x + 2] == (int)'1'))
	{
		Magentey.move(Vector2f(1., 0.f));

		mgntx++;
		mgnty = 0;

		if (mgntx == 4)mgntx = 0;
		Magentey.setTextureRect(IntRect(32 * mgntx, 32 * mgnty, 32, 32));
	}
}

void TurquoiseyUp()
{
	if (TU && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y - 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		Turquoisey.move(Vector2f(0.0, -1.f));

		trqox++;
		trqoy = 2;

		if (trqox == 4)trqox = 0;
		Turquoisey.setTextureRect(IntRect(32 * trqox, 32 * trqoy, 32, 32));
	}
}
void TurquoiseyDown()
{
	if (TD && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y + 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		Turquoisey.move(Vector2f(0.0, 1.f));

		trqox++;
		trqoy = 3;

		if (trqox == 4)trqox = 0;
		Turquoisey.setTextureRect(IntRect(32 * trqox, 32 * trqoy, 32, 32));
	}
}
void TurquoiseyLeft()
{
	if (TL && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x - 2] == (int)'1'))
	{
		Turquoisey.move(Vector2f(-1., 0.f));

		trqox++;
		trqoy = 1;

		if (trqox == 4)trqox = 0;
		Turquoisey.setTextureRect(IntRect(32 * trqox, 32 * trqoy, 32, 32));
	}
}
void TurquoiseyRight()
{
	if (TR && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x + 2] == (int)'1'))
	{
		Turquoisey.move(Vector2f(1., 0.f));

		trqox++;
		trqoy = 0;

		if (trqox == 4)trqox = 0;
		Turquoisey.setTextureRect(IntRect(32 * trqox, 32 * trqoy, 32, 32));
	}
}

void portals()
{
	if (L && player.getGlobalBounds().intersects(portala.getGlobalBounds()))
		player.setPosition(Vector2f(446.f, 232.f));
	if (R && player.getGlobalBounds().intersects(portalb.getGlobalBounds()))
		player.setPosition(Vector2f(13.f, 232.f));

	if (BL && Blinky.getGlobalBounds().intersects(portala.getGlobalBounds()))
		Blinky.setPosition(Vector2f(446.f, 232.f));
	if (BR && Blinky.getGlobalBounds().intersects(portalb.getGlobalBounds()))
		Blinky.setPosition(Vector2f(13.f, 232.f));

	if (PL && Pinky.getGlobalBounds().intersects(portala.getGlobalBounds()))
		Pinky.setPosition(Vector2f(446.f, 232.f));
	if (PR && Pinky.getGlobalBounds().intersects(portalb.getGlobalBounds()))
		Pinky.setPosition(Vector2f(13.f, 232.f));

	if (IL && Inky.getGlobalBounds().intersects(portala.getGlobalBounds()))
		Inky.setPosition(Vector2f(446.f, 232.f));
	if (IR && Inky.getGlobalBounds().intersects(portalb.getGlobalBounds()))
		Inky.setPosition(Vector2f(13.f, 232.f));

	if (CL && Clyde.getGlobalBounds().intersects(portala.getGlobalBounds()))
		Clyde.setPosition(Vector2f(446.f, 232.f));
	if (CR && Clyde.getGlobalBounds().intersects(portalb.getGlobalBounds()))
		Clyde.setPosition(Vector2f(13.f, 232.f));

	if (player.getGlobalBounds().intersects(prtlI.getGlobalBounds()))
	{
		if (U)
		{
			player.setPosition(prtlII.getPosition().x, prtlII.getPosition().y - 10);
		}
		if (L)
		{
			player.setPosition(prtlII.getPosition().x - 10, prtlII.getPosition().y);
		}
	}
	if (player.getGlobalBounds().intersects(prtlII.getGlobalBounds()))
	{
		if (D)
		{
			player.setPosition(prtlI.getPosition().x, prtlI.getPosition().y + 10);
		}
		if (R)
		{
			player.setPosition(prtlI.getPosition().x + 10, prtlI.getPosition().y);
		}
	}
}

void BlinkyDisplacement()
{
	if (Blinky.getPosition().x < trgtX)
	{
		if (Blinky.getPosition().y > trgtY)
		{
			vecU = sqrt(pow((trgtX - Blinky.getPosition().x), 2) + pow(((Blinky.getPosition().y - 10) - trgtY), 2));
			vecR = sqrt(pow((trgtX - (Blinky.getPosition().x + 10)), 2) + pow((Blinky.getPosition().y - trgtY), 2));
			vecD = sqrt(pow((trgtX - Blinky.getPosition().x), 2) + pow(((Blinky.getPosition().y + 10) - trgtY), 2));
			vecL = sqrt(pow((trgtX - (Blinky.getPosition().x - 10)), 2) + pow((Blinky.getPosition().y - trgtY), 2));
		}
		else if (Blinky.getPosition().y < trgtY)
		{
			vecU = sqrt(pow((trgtX - Blinky.getPosition().x), 2) + pow((trgtY - (Blinky.getPosition().y - 10)), 2));
			vecR = sqrt(pow((trgtX - (Blinky.getPosition().x + 10)), 2) + pow((trgtY - Blinky.getPosition().y), 2));
			vecD = sqrt(pow((trgtX - Blinky.getPosition().x), 2) + pow((trgtY - (Blinky.getPosition().y + 10)), 2));
			vecL = sqrt(pow((trgtX - (Blinky.getPosition().x - 10)), 2) + pow((trgtY - Blinky.getPosition().y), 2));
		}
	}
	else if (Blinky.getPosition().x > trgtX)
	{
		if (Blinky.getPosition().y > trgtY)
		{
			vecU = sqrt(pow((Blinky.getPosition().x - trgtX), 2) + pow(((Blinky.getPosition().y - 10) - trgtY), 2));
			vecR = sqrt(pow(((Blinky.getPosition().x + 10) - trgtX), 2) + pow((Blinky.getPosition().y - trgtY), 2));
			vecD = sqrt(pow((Blinky.getPosition().x - trgtX), 2) + pow(((Blinky.getPosition().y + 10) - trgtY), 2));
			vecL = sqrt(pow(((Blinky.getPosition().x - 10) - trgtX), 2) + pow((Blinky.getPosition().y - trgtY), 2));
		}
		else if (Blinky.getPosition().y < trgtY)
		{
			vecU = sqrt(pow((Blinky.getPosition().x - trgtX), 2) + pow((trgtY - (Blinky.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Blinky.getPosition().x + 10) - trgtX), 2) + pow((trgtY - Blinky.getPosition().y), 2));
			vecD = sqrt(pow((Blinky.getPosition().x - trgtX), 2) + pow((trgtY - (Blinky.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Blinky.getPosition().x - 10) - trgtX), 2) + pow((trgtY - Blinky.getPosition().y), 2));
		}
	}
}
void Blinky_fn()
{
	BlinkyDisplacement();

	if (!BD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}
	else if (!BD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}
	else if (!BD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}

	else if (!BU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BD = true;
		BU = false;
		BL = false;
		BR = false;
	}
	else if (!BU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BD = true;
		BU = false;
		BL = false;
		BR = false;
	}
	else if (!BU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BD = true;
		BU = false;
		BL = false;
		BR = false;
	}

	else if (!BR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BL = true;
		BD = false;
		BU = false;
		BR = false;
	}
	else if (!BR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BL = true;
		BD = false;
		BU = false;
		BR = false;
	}
	else if (!BR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BL = true;
		BD = false;
		BU = false;
		BR = false;
	}

	else if (!BL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BR = true;
		BD = false;
		BL = false;
		BU = false;
	}
	else if (!BL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BR = true;
		BD = false;
		BL = false;
		BU = false;
	}
	else if (!BL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BR = true;
		BD = false;
		BL = false;
		BU = false;
	}

	else if (!BU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = false;
		BD = true;
		BL = false;
		BR = false;
	}
	else if (!BD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}
	else if (!BL && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BU = false;
		BD = false;
		BL = false;
		BR = true;
	}
	else if (!BR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BU = false;
		BD = false;
		BL = true;
		BR = false;
	}

	else if (!BU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = false;
		BD = true;
		BL = false;
		BR = false;
	}

	BlinkyUp();
	BlinkyDown();
	BlinkyLeft();
	BlinkyRight();
}
void Blinky_chase()
{
	BlinkyDisplacement();

	if (!BD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}
	else if (!BD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}
	else if (!BD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}

	else if (!BU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BD = true;
		BU = false;
		BL = false;
		BR = false;
	}
	else if (!BU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BD = true;
		BU = false;
		BL = false;
		BR = false;
	}
	else if (!BU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BD = true;
		BU = false;
		BL = false;
		BR = false;
	}

	else if (!BR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BL = true;
		BD = false;
		BU = false;
		BR = false;
	}
	else if (!BR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BL = true;
		BD = false;
		BU = false;
		BR = false;
	}
	else if (!BR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BL = true;
		BD = false;
		BU = false;
		BR = false;
	}

	else if (!BL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BR = true;
		BD = false;
		BL = false;
		BU = false;
	}
	else if (!BL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BR = true;
		BD = false;
		BL = false;
		BU = false;
	}
	else if (!BL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BR = true;
		BD = false;
		BL = false;
		BU = false;
	}

	else if (!BU && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y + 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = false;
		BD = true;
		BL = false;
		BR = false;
	}
	else if (!BD && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y - 2][(int)Blinky.getPosition().x] == (int)'1'))
	{
		BU = true;
		BD = false;
		BL = false;
		BR = false;
	}
	else if (!BL && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x + 2] == (int)'1'))
	{
		BU = false;
		BD = false;
		BL = false;
		BR = true;
	}
	else if (!BR && ((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Blinky.getPosition().y][(int)Blinky.getPosition().x - 2] == (int)'1'))
	{
		BU = false;
		BD = false;
		BL = true;
		BR = false;
	}

	if (Blinky.getPosition().x < trgtX - 64 || Blinky.getPosition().x < trgtX + 64 && Blinky.getPosition().y < trgtY - 64 || Blinky.getPosition().y < trgtY + 64)
	{
		trgtX = rand() % 448;
		trgtY = rand() % 496;
	}

	BlinkyUp();
	BlinkyDown();
	BlinkyLeft();
	BlinkyRight();
}

void PinkyDisplacement()
{
	if (Pinky.getPosition().x < ptrgtX)
	{
		if (Pinky.getPosition().y > ptrgtY)
		{
			vecU = sqrt(pow((ptrgtX - Pinky.getPosition().x), 2) + pow(((Pinky.getPosition().y - 10) - ptrgtY), 2));
			vecR = sqrt(pow((ptrgtX - (Pinky.getPosition().x + 10)), 2) + pow((Pinky.getPosition().y - ptrgtY), 2));
			vecD = sqrt(pow((ptrgtX - Pinky.getPosition().x), 2) + pow(((Pinky.getPosition().y + 10) - ptrgtY), 2));
			vecL = sqrt(pow((ptrgtX - (Pinky.getPosition().x - 10)), 2) + pow((Pinky.getPosition().y - ptrgtY), 2));
		}
		else if (Pinky.getPosition().y < ptrgtY)
		{
			vecU = sqrt(pow((ptrgtX - Pinky.getPosition().x), 2) + pow((ptrgtY - (Pinky.getPosition().y - 10)), 2));
			vecR = sqrt(pow((ptrgtX - (Pinky.getPosition().x + 10)), 2) + pow((ptrgtY - Pinky.getPosition().y), 2));
			vecD = sqrt(pow((ptrgtX - Pinky.getPosition().x), 2) + pow((ptrgtY - (Pinky.getPosition().y + 10)), 2));
			vecL = sqrt(pow((ptrgtX - (Pinky.getPosition().x - 10)), 2) + pow((ptrgtY - Pinky.getPosition().y), 2));
		}
	}
	else if (Pinky.getPosition().x > ptrgtX)
	{
		if (Pinky.getPosition().y > ptrgtY)
		{
			vecU = sqrt(pow((Pinky.getPosition().x - ptrgtX), 2) + pow(((Pinky.getPosition().y - 10) - ptrgtY), 2));
			vecR = sqrt(pow(((Pinky.getPosition().x + 10) - ptrgtX), 2) + pow((Pinky.getPosition().y - ptrgtY), 2));
			vecD = sqrt(pow((Pinky.getPosition().x - ptrgtX), 2) + pow(((Pinky.getPosition().y + 10) - ptrgtY), 2));
			vecL = sqrt(pow(((Pinky.getPosition().x - 10) - ptrgtX), 2) + pow((Pinky.getPosition().y - ptrgtY), 2));
		}
		else if (Pinky.getPosition().y < ptrgtY)
		{
			vecU = sqrt(pow((Pinky.getPosition().x - ptrgtX), 2) + pow((ptrgtY - (Pinky.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Pinky.getPosition().x + 10) - ptrgtX), 2) + pow((ptrgtY - Pinky.getPosition().y), 2));
			vecD = sqrt(pow((Pinky.getPosition().x - ptrgtX), 2) + pow((ptrgtY - (Pinky.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Pinky.getPosition().x - 10) - ptrgtX), 2) + pow((ptrgtY - Pinky.getPosition().y), 2));
		}
	}
}
void Pinky_fn()
{
	PinkyDisplacement();

	if (!PD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}
	else if (!PD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}
	else if (!PD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}

	else if (!PU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PD = true;
		PU = false;
		PL = false;
		PR = false;
	}
	else if (!PU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PD = true;
		PU = false;
		PL = false;
		PR = false;
	}
	else if (!PU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PD = true;
		PU = false;
		PL = false;
		PR = false;
	}

	else if (!PR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PL = true;
		PD = false;
		PU = false;
		PR = false;
	}
	else if (!PR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PL = true;
		PD = false;
		PU = false;
		PR = false;
	}
	else if (!PR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PL = true;
		PD = false;
		PU = false;
		PR = false;
	}

	else if (!PL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PR = true;
		PD = false;
		PL = false;
		PU = false;
	}
	else if (!PL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PR = true;
		PD = false;
		PL = false;
		PU = false;
	}
	else if (!PL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PR = true;
		PD = false;
		PL = false;
		PU = false;
	}

	else if (!PU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = false;
		PD = true;
		PL = false;
		PR = false;
	}
	else if (!PD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}
	else if (!PR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PU = false;
		PD = false;
		PL = true;
		PR = false;
	}
	else if (!PL && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PU = false;
		PD = false;
		PL = false;
		PR = true;
	}

	else if (!PU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = false;
		PD = true;
		PL = false;
		PR = false;
	}

	PinkyUp();
	PinkyDown();
	PinkyLeft();
	PinkyRight();
}
void Pinky_chase()
{
	PinkyDisplacement();

	if (!PD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}
	else if (!PD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}
	else if (!PD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}

	else if (!PU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PD = true;
		PU = false;
		PL = false;
		PR = false;
	}
	else if (!PU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PD = true;
		PU = false;
		PL = false;
		PR = false;
	}
	else if (!PU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PD = true;
		PU = false;
		PL = false;
		PR = false;
	}

	else if (!PR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PL = true;
		PD = false;
		PU = false;
		PR = false;
	}
	else if (!PR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PL = true;
		PD = false;
		PU = false;
		PR = false;
	}
	else if (!PR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PL = true;
		PD = false;
		PU = false;
		PR = false;
	}

	else if (!PL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PR = true;
		PD = false;
		PL = false;
		PU = false;
	}
	else if (!PL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PR = true;
		PD = false;
		PL = false;
		PU = false;
	}
	else if (!PL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PR = true;
		PD = false;
		PL = false;
		PU = false;
	}

	else if (!PU && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y + 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = false;
		PD = true;
		PL = false;
		PR = false;
	}
	else if (!PD && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y - 2][(int)Pinky.getPosition().x] == (int)'1'))
	{
		PU = true;
		PD = false;
		PL = false;
		PR = false;
	}
	else if (!PR && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x + 2] == (int)'1'))
	{
		PU = false;
		PD = false;
		PL = true;
		PR = false;
	}
	else if (!PL && ((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x - 2] == (int)'1'))
	{
		PU = false;
		PD = false;
		PL = false;
		PR = true;
	}

	if (Pinky.getPosition().x < ptrgtX - 64 || Pinky.getPosition().x < ptrgtX + 64 && Pinky.getPosition().y < ptrgtY - 64 || Pinky.getPosition().y < ptrgtY + 64)
	{
		ptrgtX = rand() % 448;
		ptrgtY = rand() % 496;
	}

	PinkyUp();
	PinkyDown();
	PinkyLeft();
	PinkyRight();
}

void InkyDisplacement()
{
	if (Inky.getPosition().x < itrgtX)
	{
		if (Inky.getPosition().y > itrgtY)
		{
			vecU = sqrt(pow((itrgtX - Inky.getPosition().x), 2) + pow(((Inky.getPosition().y - 10) - itrgtY), 2));
			vecR = sqrt(pow((itrgtX - (Inky.getPosition().x + 10)), 2) + pow((Inky.getPosition().y - itrgtY), 2));
			vecD = sqrt(pow((itrgtX - Inky.getPosition().x), 2) + pow(((Inky.getPosition().y + 10) - itrgtY), 2));
			vecL = sqrt(pow((itrgtX - (Inky.getPosition().x - 10)), 2) + pow((Inky.getPosition().y - itrgtY), 2));
		}
		else if (Inky.getPosition().y < itrgtY)
		{
			vecU = sqrt(pow((itrgtX - Inky.getPosition().x), 2) + pow((itrgtY - (Inky.getPosition().y - 10)), 2));
			vecR = sqrt(pow((itrgtX - (Inky.getPosition().x + 10)), 2) + pow((itrgtY - Inky.getPosition().y), 2));
			vecD = sqrt(pow((itrgtX - Inky.getPosition().x), 2) + pow((itrgtY - (Inky.getPosition().y + 10)), 2));
			vecL = sqrt(pow((itrgtX - (Inky.getPosition().x - 10)), 2) + pow((itrgtY - Inky.getPosition().y), 2));
		}
	}
	else if (Inky.getPosition().x > itrgtX)
	{
		if (Inky.getPosition().y > itrgtY)
		{
			vecU = sqrt(pow((Inky.getPosition().x - itrgtX), 2) + pow(((Inky.getPosition().y - 10) - itrgtY), 2));
			vecR = sqrt(pow(((Inky.getPosition().x + 10) - itrgtX), 2) + pow((Inky.getPosition().y - itrgtY), 2));
			vecD = sqrt(pow((Inky.getPosition().x - itrgtX), 2) + pow(((Inky.getPosition().y + 10) - itrgtY), 2));
			vecL = sqrt(pow(((Inky.getPosition().x - 10) - itrgtX), 2) + pow((Inky.getPosition().y - itrgtY), 2));
		}
		else if (Inky.getPosition().y < itrgtY)
		{
			vecU = sqrt(pow((Inky.getPosition().x - itrgtX), 2) + pow((itrgtY - (Inky.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Inky.getPosition().x + 10) - itrgtX), 2) + pow((itrgtY - Inky.getPosition().y), 2));
			vecD = sqrt(pow((Inky.getPosition().x - itrgtX), 2) + pow((itrgtY - (Inky.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Inky.getPosition().x - 10) - itrgtX), 2) + pow((itrgtY - Inky.getPosition().y), 2));
		}
	}
}
void Inky_fn()
{
	InkyDisplacement();

	if (!ID && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}
	else if (!ID && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}
	else if (!ID && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}

	else if (!IU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		ID = true;
		IU = false;
		IL = false;
		IR = false;
	}
	else if (!IU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		ID = true;
		IU = false;
		IL = false;
		IR = false;
	}
	else if (!IU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		ID = true;
		IU = false;
		IL = false;
		IR = false;
	}

	else if (!IR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IL = true;
		ID = false;
		IU = false;
		IR = false;
	}
	else if (!IR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IL = true;
		ID = false;
		IU = false;
		IR = false;
	}
	else if (!IR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IL = true;
		ID = false;
		IU = false;
		IR = false;
	}

	else if (!IL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IR = true;
		ID = false;
		IL = false;
		IU = false;
	}
	else if (!IL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IR = true;
		ID = false;
		IL = false;
		IU = false;
	}
	else if (!IL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IR = true;
		ID = false;
		IL = false;
		IU = false;
	}

	else if (!ID && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}
	else if (!IU && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = false;
		ID = true;
		IL = false;
		IR = false;
	}
	else if (!IR && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IU = false;
		ID = false;
		IL = true;
		IR = false;
	}
	else if (!IL && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IU = false;
		ID = false;
		IL = false;
		IR = true;
	}

	else if (!IU && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = false;
		ID = true;
		IL = false;
		IR = false;
	}

	InkyUp();
	InkyDown();
	InkyLeft();
	InkyRight();
}
void Inky_chase()
{
	InkyDisplacement();

	if (!ID && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}
	else if (!ID && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}
	else if (!ID && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}

	else if (!IU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		ID = true;
		IU = false;
		IL = false;
		IR = false;
	}
	else if (!IU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		ID = true;
		IU = false;
		IL = false;
		IR = false;
	}
	else if (!IU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		ID = true;
		IU = false;
		IL = false;
		IR = false;
	}

	else if (!IR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IL = true;
		ID = false;
		IU = false;
		IR = false;
	}
	else if (!IR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IL = true;
		ID = false;
		IU = false;
		IR = false;
	}
	else if (!IR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IL = true;
		ID = false;
		IU = false;
		IR = false;
	}

	else if (!IL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IR = true;
		ID = false;
		IL = false;
		IU = false;
	}
	else if (!IL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IR = true;
		ID = false;
		IL = false;
		IU = false;
	}
	else if (!IL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IR = true;
		ID = false;
		IL = false;
		IU = false;
	}

	else if (!ID && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}
	else if (!IU && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = false;
		ID = true;
		IL = false;
		IR = false;
	}
	else if (!IR && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IU = false;
		ID = false;
		IL = true;
		IR = false;
	}
	else if (!IL && vecU < vecL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IU = false;
		ID = false;
		IL = false;
		IR = true;
	}

	else if (!ID && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y - 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = true;
		ID = false;
		IL = false;
		IR = false;
	}
	else if (!IU && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y + 2][(int)Inky.getPosition().x] == (int)'1'))
	{
		IU = false;
		ID = true;
		IL = false;
		IR = false;
	}
	else if (!IR && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x + 2] == (int)'1'))
	{
		IU = false;
		ID = false;
		IL = true;
		IR = false;
	}
	else if (!IL && ((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2') && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x - 2] == (int)'1'))
	{
		IU = false;
		ID = false;
		IL = false;
		IR = true;
	}


	if (Inky.getPosition().x < itrgtX - 64 || Inky.getPosition().x < itrgtX + 64 && Inky.getPosition().y < itrgtY - 64 || Inky.getPosition().y < itrgtY + 64)
	{
		itrgtX = rand() % 448;
		itrgtY = rand() % 496;
	}

	InkyUp();
	InkyDown();
	InkyLeft();
	InkyRight();
}

void ClydeDisplacement()
{
	if (Clyde.getPosition().x < ctrgtX)
	{
		if (Clyde.getPosition().y > ctrgtY)
		{
			vecU = sqrt(pow((ctrgtX - Clyde.getPosition().x), 2) + pow(((Clyde.getPosition().y - 10) - ctrgtY), 2));
			vecR = sqrt(pow((ctrgtX - (Clyde.getPosition().x + 10)), 2) + pow((Clyde.getPosition().y - ctrgtY), 2));
			vecD = sqrt(pow((ctrgtX - Clyde.getPosition().x), 2) + pow(((Clyde.getPosition().y + 10) - ctrgtY), 2));
			vecL = sqrt(pow((ctrgtX - (Clyde.getPosition().x - 10)), 2) + pow((Clyde.getPosition().y - ctrgtY), 2));
		}
		else if (Clyde.getPosition().y < ctrgtY)
		{
			vecU = sqrt(pow((ctrgtX - Clyde.getPosition().x), 2) + pow((ctrgtY - (Clyde.getPosition().y - 10)), 2));
			vecR = sqrt(pow((ctrgtX - (Clyde.getPosition().x + 10)), 2) + pow((ctrgtY - Clyde.getPosition().y), 2));
			vecD = sqrt(pow((ctrgtX - Clyde.getPosition().x), 2) + pow((ctrgtY - (Clyde.getPosition().y + 10)), 2));
			vecL = sqrt(pow((ctrgtX - (Clyde.getPosition().x - 10)), 2) + pow((ctrgtY - Clyde.getPosition().y), 2));
		}
	}
	else if (Clyde.getPosition().x > ctrgtX)
	{
		if (Clyde.getPosition().y > ctrgtY)
		{
			vecU = sqrt(pow((Clyde.getPosition().x - ctrgtX), 2) + pow(((Clyde.getPosition().y - 10) - ctrgtY), 2));
			vecR = sqrt(pow(((Clyde.getPosition().x + 10) - ctrgtX), 2) + pow((Clyde.getPosition().y - ctrgtY), 2));
			vecD = sqrt(pow((Clyde.getPosition().x - ctrgtX), 2) + pow(((Clyde.getPosition().y + 10) - ctrgtY), 2));
			vecL = sqrt(pow(((Clyde.getPosition().x - 10) - ctrgtX), 2) + pow((Clyde.getPosition().y - ctrgtY), 2));
		}
		else if (Inky.getPosition().y < itrgtY)
		{
			vecU = sqrt(pow((Clyde.getPosition().x - ctrgtX), 2) + pow((ctrgtY - (Clyde.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Clyde.getPosition().x + 10) - ctrgtX), 2) + pow((ctrgtY - Clyde.getPosition().y), 2));
			vecD = sqrt(pow((Clyde.getPosition().x - ctrgtX), 2) + pow((ctrgtY - (Clyde.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Clyde.getPosition().x - 10) - ctrgtX), 2) + pow((ctrgtY - Clyde.getPosition().y), 2));
		}
	}
}
void Clyde_fn()
{
	ClydeDisplacement();

	if (!CD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}
	else if (!CD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}
	else if (!CD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}

	else if (!CU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CD = true;
		CU = false;
		CL = false;
		CR = false;
	}
	else if (!CU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CD = true;
		CU = false;
		CL = false;
		CR = false;
	}
	else if (!CU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CD = true;
		CU = false;
		CL = false;
		CR = false;
	}

	else if (!CR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CL = true;
		CD = false;
		CU = false;
		CR = false;
	}
	else if (!CR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CL = true;
		CD = false;
		CU = false;
		CR = false;
	}
	else if (!CR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CL = true;
		CD = false;
		CU = false;
		CR = false;
	}

	else if (!CL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CR = true;
		CD = false;
		CL = false;
		CU = false;
	}
	else if (!CL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CR = true;
		CD = false;
		CL = false;
		CU = false;
	}
	else if (!CL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CR = true;
		CD = false;
		CL = false;
		CU = false;
	}

	else if (!CD && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}
	else if (!CU && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = false;
		CD = true;
		CL = false;
		CR = false;
	}
	else if (!CR && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CU = false;
		CD = false;
		CL = true;
		CR = false;
	}
	else if (!CL && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CU = false;
		CD = false;
		CL = false;
		CR = true;
	}

	else if (!CU && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = false;
		CD = true;
		CL = false;
		CR = false;
	}

	ClydeUp();
	ClydeDown();
	ClydeLeft();
	ClydeRight();
}
void Clyde_chase()
{
	ClydeDisplacement();

	if (!CD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}
	else if (!CD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}
	else if (!CD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}

	else if (!CU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CD = true;
		CU = false;
		CL = false;
		CR = false;
	}
	else if (!CU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CD = true;
		CU = false;
		CL = false;
		CR = false;
	}
	else if (!CU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CD = true;
		CU = false;
		CL = false;
		CR = false;
	}

	else if (!CR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CL = true;
		CD = false;
		CU = false;
		CR = false;
	}
	else if (!CR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CL = true;
		CD = false;
		CU = false;
		CR = false;
	}
	else if (!CR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CL = true;
		CD = false;
		CU = false;
		CR = false;
	}

	else if (!CL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CR = true;
		CD = false;
		CL = false;
		CU = false;
	}
	else if (!CL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CR = true;
		CD = false;
		CL = false;
		CU = false;
	}
	else if (!CL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CR = true;
		CD = false;
		CL = false;
		CU = false;
	}

	else if (!CD && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y - 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = true;
		CD = false;
		CL = false;
		CR = false;
	}
	else if (!CU && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y + 2][(int)Clyde.getPosition().x] == (int)'1'))
	{
		CU = false;
		CD = true;
		CL = false;
		CR = false;
	}
	else if (!CR && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x + 2] == (int)'1'))
	{
		CU = false;
		CD = false;
		CL = true;
		CR = false;
	}
	else if (!CL && vecU < vecR && ((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2') && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x - 2] == (int)'1'))
	{
		CU = false;
		CD = false;
		CL = false;
		CR = true;
	}

	if (Clyde.getPosition().x < ctrgtX - 64 || Clyde.getPosition().x < ctrgtX + 64 && Clyde.getPosition().y < ctrgtY - 64 || Clyde.getPosition().y < ctrgtY + 64)
	{
		ctrgtX = rand() % 448;
		ctrgtY = rand() % 496;
	}

	ClydeUp();
	ClydeDown();
	ClydeLeft();
	ClydeRight();
}

void GreeneyDisplacement()
{
	if (Greeney.getPosition().x < gtrgtX)
	{
		if (Greeney.getPosition().y > gtrgtY)
		{
			vecU = sqrt(pow((gtrgtX - Greeney.getPosition().x), 2) + pow(((Greeney.getPosition().y - 10) - gtrgtY), 2));
			vecR = sqrt(pow((gtrgtX - (Greeney.getPosition().x + 10)), 2) + pow((Greeney.getPosition().y - gtrgtY), 2));
			vecD = sqrt(pow((gtrgtX - Greeney.getPosition().x), 2) + pow(((Greeney.getPosition().y + 10) - gtrgtY), 2));
			vecL = sqrt(pow((gtrgtX - (Greeney.getPosition().x - 10)), 2) + pow((Greeney.getPosition().y - gtrgtY), 2));
		}
		else if (Greeney.getPosition().y < gtrgtY)
		{
			vecU = sqrt(pow((gtrgtX - Greeney.getPosition().x), 2) + pow((gtrgtY - (Greeney.getPosition().y - 10)), 2));
			vecR = sqrt(pow((gtrgtX - (Greeney.getPosition().x + 10)), 2) + pow((gtrgtY - Greeney.getPosition().y), 2));
			vecD = sqrt(pow((gtrgtX - Greeney.getPosition().x), 2) + pow((gtrgtY - (Greeney.getPosition().y + 10)), 2));
			vecL = sqrt(pow((gtrgtX - (Greeney.getPosition().x - 10)), 2) + pow((gtrgtY - Greeney.getPosition().y), 2));
		}
	}
	else if (Greeney.getPosition().x > gtrgtX)
	{
		if (Greeney.getPosition().y > gtrgtY)
		{
			vecU = sqrt(pow((Greeney.getPosition().x - gtrgtX), 2) + pow(((Greeney.getPosition().y - 10) - gtrgtY), 2));
			vecR = sqrt(pow(((Greeney.getPosition().x + 10) - gtrgtX), 2) + pow((Greeney.getPosition().y - gtrgtY), 2));
			vecD = sqrt(pow((Greeney.getPosition().x - gtrgtX), 2) + pow(((Greeney.getPosition().y + 10) - gtrgtY), 2));
			vecL = sqrt(pow(((Greeney.getPosition().x - 10) - gtrgtX), 2) + pow((Greeney.getPosition().y - gtrgtY), 2));
		}
		else if (Greeney.getPosition().y < gtrgtY)
		{
			vecU = sqrt(pow((Greeney.getPosition().x - gtrgtX), 2) + pow((gtrgtY - (Greeney.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Greeney.getPosition().x + 10) - gtrgtX), 2) + pow((gtrgtY - Greeney.getPosition().y), 2));
			vecD = sqrt(pow((Greeney.getPosition().x - gtrgtX), 2) + pow((gtrgtY - (Greeney.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Greeney.getPosition().x - 10) - gtrgtX), 2) + pow((gtrgtY - Greeney.getPosition().y), 2));
		}
	}
}
void Greeney_chase()
{
	GreeneyDisplacement();

	if (!GD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y - 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GU = true;
		GD = false;
		GL = false;
		GR = false;
	}
	else if (!GD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y - 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GU = true;
		GD = false;
		GL = false;
		GR = false;
	}
	else if (!GD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y - 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GU = true;
		GD = false;
		GL = false;
		GR = false;
	}

	else if (!GU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y + 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GD = true;
		GU = false;
		GL = false;
		GR = false;
	}
	else if (!GU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y + 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GD = true;
		GU = false;
		GL = false;
		GR = false;
	}
	else if (!GU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y + 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GD = true;
		GU = false;
		GL = false;
		GR = false;
	}

	else if (!GR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x - 2] == (int)'1'))
	{
		GL = true;
		GD = false;
		GU = false;
		GR = false;
	}
	else if (!GR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x - 2] == (int)'1'))
	{
		GL = true;
		GD = false;
		GU = false;
		GR = false;
	}
	else if (!GR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x - 2] == (int)'1'))
	{
		GL = true;
		GD = false;
		GU = false;
		GR = false;
	}

	else if (!GL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x + 2] == (int)'1'))
	{
		GR = true;
		GD = false;
		GL = false;
		GU = false;
	}
	else if (!GL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x + 2] == (int)'1'))
	{
		GR = true;
		GD = false;
		GL = false;
		GU = false;
	}
	else if (!GL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x + 2] == (int)'1'))
	{
		GR = true;
		GD = false;
		GL = false;
		GU = false;
	}

	else if (!GU && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y + 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GU = false;
		GD = true;
		GL = false;
		GR = false;
	}
	else if (!GD && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y - 2][(int)Greeney.getPosition().x] == (int)'1'))
	{
		GU = true;
		GD = false;
		GL = false;
		GR = false;
	}
	else if (!GL && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x + 2] == (int)'1'))
	{
		GU = false;
		GD = false;
		GL = false;
		GR = true;
	}
	else if (!GR && ((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Greeney.getPosition().y][(int)Greeney.getPosition().x - 2] == (int)'1'))
	{
		GU = false;
		GD = false;
		GL = true;
		GR = false;
	}

	if (Greeney.getPosition().x < gtrgtX - 64 || Greeney.getPosition().x < gtrgtX + 64 && Greeney.getPosition().y < gtrgtY - 64 || Greeney.getPosition().y < gtrgtY + 64)
	{
		gtrgtX = rand() % 448;
		gtrgtY = rand() % 496;
	}

	GreeneyUp();
	GreeneyDown();
	GreeneyLeft();
	GreeneyRight();
}

void LemoneyDisplacement()
{
	if (Lemoney.getPosition().x < ltrgtX)
	{
		if (Lemoney.getPosition().y > ltrgtY)
		{
			vecU = sqrt(pow((ltrgtX - Lemoney.getPosition().x), 2) + pow(((Lemoney.getPosition().y - 10) - ltrgtY), 2));
			vecR = sqrt(pow((ltrgtX - (Lemoney.getPosition().x + 10)), 2) + pow((Lemoney.getPosition().y - ltrgtY), 2));
			vecD = sqrt(pow((ltrgtX - Lemoney.getPosition().x), 2) + pow(((Lemoney.getPosition().y + 10) - ltrgtY), 2));
			vecL = sqrt(pow((ltrgtX - (Lemoney.getPosition().x - 10)), 2) + pow((Lemoney.getPosition().y - ltrgtY), 2));
		}
		else if (Lemoney.getPosition().y < ltrgtY)
		{
			vecU = sqrt(pow((ltrgtX - Lemoney.getPosition().x), 2) + pow((ltrgtY - (Lemoney.getPosition().y - 10)), 2));
			vecR = sqrt(pow((ltrgtX - (Lemoney.getPosition().x + 10)), 2) + pow((ltrgtY - Lemoney.getPosition().y), 2));
			vecD = sqrt(pow((ltrgtX - Lemoney.getPosition().x), 2) + pow((ltrgtY - (Lemoney.getPosition().y + 10)), 2));
			vecL = sqrt(pow((ltrgtX - (Lemoney.getPosition().x - 10)), 2) + pow((ltrgtY - Lemoney.getPosition().y), 2));
		}
	}
	else if (Lemoney.getPosition().x > ltrgtX)
	{
		if (Lemoney.getPosition().y > ltrgtY)
		{
			vecU = sqrt(pow((Lemoney.getPosition().x - ltrgtX), 2) + pow(((Lemoney.getPosition().y - 10) - ltrgtY), 2));
			vecR = sqrt(pow(((Lemoney.getPosition().x + 10) - ltrgtX), 2) + pow((Lemoney.getPosition().y - ltrgtY), 2));
			vecD = sqrt(pow((Lemoney.getPosition().x - ltrgtX), 2) + pow(((Lemoney.getPosition().y + 10) - ltrgtY), 2));
			vecL = sqrt(pow(((Lemoney.getPosition().x - 10) - ltrgtX), 2) + pow((Lemoney.getPosition().y - ltrgtY), 2));
		}
		else if (Lemoney.getPosition().y < ltrgtY)
		{
			vecU = sqrt(pow((Lemoney.getPosition().x - ltrgtX), 2) + pow((ltrgtY - (Lemoney.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Lemoney.getPosition().x + 10) - ltrgtX), 2) + pow((ltrgtY - Lemoney.getPosition().y), 2));
			vecD = sqrt(pow((Lemoney.getPosition().x - ltrgtX), 2) + pow((ltrgtY - (Lemoney.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Lemoney.getPosition().x - 10) - ltrgtX), 2) + pow((ltrgtY - Lemoney.getPosition().y), 2));
		}
	}
}
void Lemoney_chase()
{
	LemoneyDisplacement();

	if (!LD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y - 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LU = true;
		LD = false;
		LL = false;
		LR = false;
	}
	else if (!LD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y - 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LU = true;
		LD = false;
		LL = false;
		LR = false;
	}
	else if (!LD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y - 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LU = true;
		LD = false;
		LL = false;
		LR = false;
	}

	else if (!LU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y + 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LD = true;
		LU = false;
		LL = false;
		LR = false;
	}
	else if (!LU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y + 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LD = true;
		LU = false;
		LL = false;
		LR = false;
	}
	else if (!LU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y + 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LD = true;
		LU = false;
		LL = false;
		LR = false;
	}

	else if (!LR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x - 2] == (int)'1'))
	{
		LL = true;
		LD = false;
		LU = false;
		LR = false;
	}
	else if (!LR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x - 2] == (int)'1'))
	{
		LL = true;
		LD = false;
		LU = false;
		LR = false;
	}
	else if (!LR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x - 2] == (int)'1'))
	{
		LL = true;
		LD = false;
		LU = false;
		LR = false;
	}

	else if (!LL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x + 2] == (int)'1'))
	{
		LR = true;
		LD = false;
		LL = false;
		LU = false;
	}
	else if (!LL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x + 2] == (int)'1'))
	{
		LR = true;
		LD = false;
		LL = false;
		LU = false;
	}
	else if (!LL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x + 2] == (int)'1'))
	{
		LR = true;
		LD = false;
		LL = false;
		LU = false;
	}

	else if (!LU && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y + 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LU = false;
		LD = true;
		LL = false;
		LR = false;
	}
	else if (!LD && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y - 2][(int)Lemoney.getPosition().x] == (int)'1'))
	{
		LU = true;
		LD = false;
		LL = false;
		LR = false;
	}
	else if (!LL && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x + 2] == (int)'1'))
	{
		LU = false;
		LD = false;
		LL = false;
		LR = true;
	}
	else if (!LR && ((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x] == (int)'2') && !((int)mapdata[(int)Lemoney.getPosition().y][(int)Lemoney.getPosition().x - 2] == (int)'1'))
	{
		LU = false;
		LD = false;
		LL = true;
		LR = false;
	}

	if (Lemoney.getPosition().x < ltrgtX - 64 || Lemoney.getPosition().x < ltrgtX + 64 && Lemoney.getPosition().y < ltrgtY - 64 || Lemoney.getPosition().y < ltrgtY + 64)
	{
		ltrgtX = rand() % 448;
		ltrgtY = rand() % 496;
	}

	LemoneyUp();
	LemoneyDown();
	LemoneyLeft();
	LemoneyRight();
}

void MagenteyDisplacement()
{
	if (Magentey.getPosition().x < mtrgtX)
	{
		if (Magentey.getPosition().y > mtrgtY)
		{
			vecU = sqrt(pow((mtrgtX - Magentey.getPosition().x), 2) + pow(((Magentey.getPosition().y - 10) - mtrgtY), 2));
			vecR = sqrt(pow((mtrgtX - (Magentey.getPosition().x + 10)), 2) + pow((Magentey.getPosition().y - mtrgtY), 2));
			vecD = sqrt(pow((mtrgtX - Magentey.getPosition().x), 2) + pow(((Magentey.getPosition().y + 10) - mtrgtY), 2));
			vecL = sqrt(pow((mtrgtX - (Magentey.getPosition().x - 10)), 2) + pow((Magentey.getPosition().y - mtrgtY), 2));
		}
		else if (Magentey.getPosition().y < mtrgtY)
		{
			vecU = sqrt(pow((mtrgtX - Magentey.getPosition().x), 2) + pow((mtrgtY - (Magentey.getPosition().y - 10)), 2));
			vecR = sqrt(pow((mtrgtX - (Magentey.getPosition().x + 10)), 2) + pow((mtrgtY - Magentey.getPosition().y), 2));
			vecD = sqrt(pow((mtrgtX - Magentey.getPosition().x), 2) + pow((mtrgtY - (Magentey.getPosition().y + 10)), 2));
			vecL = sqrt(pow((mtrgtX - (Magentey.getPosition().x - 10)), 2) + pow((mtrgtY - Magentey.getPosition().y), 2));
		}
	}
	else if (Magentey.getPosition().x > mtrgtX)
	{
		if (Magentey.getPosition().y > mtrgtY)
		{
			vecU = sqrt(pow((Magentey.getPosition().x - mtrgtX), 2) + pow(((Magentey.getPosition().y - 10) - mtrgtY), 2));
			vecR = sqrt(pow(((Magentey.getPosition().x + 10) - mtrgtX), 2) + pow((Magentey.getPosition().y - mtrgtY), 2));
			vecD = sqrt(pow((Magentey.getPosition().x - mtrgtX), 2) + pow(((Magentey.getPosition().y + 10) - mtrgtY), 2));
			vecL = sqrt(pow(((Magentey.getPosition().x - 10) - mtrgtX), 2) + pow((Magentey.getPosition().y - mtrgtY), 2));
		}
		else if (Magentey.getPosition().y < mtrgtY)
		{
			vecU = sqrt(pow((Magentey.getPosition().x - mtrgtX), 2) + pow((mtrgtY - (Magentey.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Magentey.getPosition().x + 10) - mtrgtX), 2) + pow((mtrgtY - Magentey.getPosition().y), 2));
			vecD = sqrt(pow((Magentey.getPosition().x - mtrgtX), 2) + pow((mtrgtY - (Magentey.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Magentey.getPosition().x - 10) - mtrgtX), 2) + pow((mtrgtY - Magentey.getPosition().y), 2));
		}
	}
}
void Magentey_chase()
{
	MagenteyDisplacement();

	if (!MD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y - 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MU = true;
		MD = false;
		ML = false;
		MR = false;
	}
	else if (!MD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y - 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MU = true;
		MD = false;
		ML = false;
		MR = false;
	}
	else if (!MD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y - 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MU = true;
		MD = false;
		ML = false;
		MR = false;
	}

	else if (!MU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y + 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MD = true;
		MU = false;
		ML = false;
		MR = false;
	}
	else if (!MU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y + 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MD = true;
		MU = false;
		ML = false;
		MR = false;
	}
	else if (!MU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y + 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MD = true;
		MU = false;
		ML = false;
		MR = false;
	}

	else if (!MR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x - 2] == (int)'1'))
	{
		ML = true;
		MD = false;
		MU = false;
		MR = false;
	}
	else if (!MR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x - 2] == (int)'1'))
	{
		ML = true;
		MD = false;
		MU = false;
		MR = false;
	}
	else if (!MR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x - 2] == (int)'1'))
	{
		ML = true;
		MD = false;
		MU = false;
		MR = false;
	}

	else if (!ML && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x + 2] == (int)'1'))
	{
		MR = true;
		MD = false;
		ML = false;
		MU = false;
	}
	else if (!ML && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x + 2] == (int)'1'))
	{
		MR = true;
		MD = false;
		ML = false;
		MU = false;
	}
	else if (!ML && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x + 2] == (int)'1'))
	{
		MR = true;
		MD = false;
		ML = false;
		MU = false;
	}

	else if (!MU && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y + 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MU = false;
		MD = true;
		ML = false;
		MR = false;
	}
	else if (!MD && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y - 2][(int)Magentey.getPosition().x] == (int)'1'))
	{
		MU = true;
		MD = false;
		ML = false;
		MR = false;
	}
	else if (!ML && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x + 2] == (int)'1'))
	{
		MU = false;
		MD = false;
		ML = false;
		MR = true;
	}
	else if (!MR && ((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Magentey.getPosition().y][(int)Magentey.getPosition().x - 2] == (int)'1'))
	{
		MU = false;
		MD = false;
		ML = true;
		MR = false;
	}

	if (Magentey.getPosition().x < mtrgtX - 64 || Magentey.getPosition().x < mtrgtX + 64 && Magentey.getPosition().y < mtrgtY - 64 || Magentey.getPosition().y < mtrgtY + 64)
	{
		mtrgtX = rand() % 448;
		mtrgtY = rand() % 496;
	}

	MagenteyUp();
	MagenteyDown();
	MagenteyLeft();
	MagenteyRight();
}

void TurquoiseyDisplacement()
{
	if (Turquoisey.getPosition().x < ttrgtX)
	{
		if (Turquoisey.getPosition().y > ttrgtY)
		{
			vecU = sqrt(pow((ttrgtX - Turquoisey.getPosition().x), 2) + pow(((Turquoisey.getPosition().y - 10) - ttrgtY), 2));
			vecR = sqrt(pow((ttrgtX - (Turquoisey.getPosition().x + 10)), 2) + pow((Turquoisey.getPosition().y - ttrgtY), 2));
			vecD = sqrt(pow((ttrgtX - Turquoisey.getPosition().x), 2) + pow(((Turquoisey.getPosition().y + 10) - ttrgtY), 2));
			vecL = sqrt(pow((ttrgtX - (Turquoisey.getPosition().x - 10)), 2) + pow((Turquoisey.getPosition().y - ttrgtY), 2));
		}
		else if (Turquoisey.getPosition().y < ttrgtY)
		{
			vecU = sqrt(pow((ttrgtX - Turquoisey.getPosition().x), 2) + pow((ttrgtY - (Turquoisey.getPosition().y - 10)), 2));
			vecR = sqrt(pow((ttrgtX - (Turquoisey.getPosition().x + 10)), 2) + pow((ttrgtY - Turquoisey.getPosition().y), 2));
			vecD = sqrt(pow((ttrgtX - Turquoisey.getPosition().x), 2) + pow((ttrgtY - (Turquoisey.getPosition().y + 10)), 2));
			vecL = sqrt(pow((ttrgtX - (Turquoisey.getPosition().x - 10)), 2) + pow((ttrgtY - Turquoisey.getPosition().y), 2));
		}
	}
	else if (Turquoisey.getPosition().x > ttrgtX)
	{
		if (Turquoisey.getPosition().y > ttrgtY)
		{
			vecU = sqrt(pow((Turquoisey.getPosition().x - ttrgtX), 2) + pow(((Turquoisey.getPosition().y - 10) - ttrgtY), 2));
			vecR = sqrt(pow(((Turquoisey.getPosition().x + 10) - ttrgtX), 2) + pow((Turquoisey.getPosition().y - ttrgtY), 2));
			vecD = sqrt(pow((Turquoisey.getPosition().x - ttrgtX), 2) + pow(((Turquoisey.getPosition().y + 10) - ttrgtY), 2));
			vecL = sqrt(pow(((Turquoisey.getPosition().x - 10) - ttrgtX), 2) + pow((Turquoisey.getPosition().y - ttrgtY), 2));
		}
		else if (Turquoisey.getPosition().y < ttrgtY)
		{
			vecU = sqrt(pow((Turquoisey.getPosition().x - ttrgtX), 2) + pow((ttrgtY - (Turquoisey.getPosition().y - 10)), 2));
			vecR = sqrt(pow(((Turquoisey.getPosition().x + 10) - ttrgtX), 2) + pow((ttrgtY - Turquoisey.getPosition().y), 2));
			vecD = sqrt(pow((Turquoisey.getPosition().x - ttrgtX), 2) + pow((ttrgtY - (Turquoisey.getPosition().y + 10)), 2));
			vecL = sqrt(pow(((Turquoisey.getPosition().x - 10) - ttrgtX), 2) + pow((ttrgtY - Turquoisey.getPosition().y), 2));
		}
	}
}
void Turquoisey_chase()
{
	TurquoiseyDisplacement();

	if (!TD && vecU < vecL && vecU < vecR && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y - 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TU = true;
		TD = false;
		TL = false;
		TR = false;
	}
	else if (!TD && vecU < vecD && vecU < vecR && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y - 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TU = true;
		TD = false;
		TL = false;
		TR = false;
	}
	else if (!TD && vecU < vecD && vecU < vecL && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y - 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TU = true;
		TD = false;
		TL = false;
		TR = false;
	}

	else if (!TU && vecD < vecL && vecD < vecR && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y + 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TD = true;
		TU = false;
		TL = false;
		TR = false;
	}
	else if (!TU && vecD < vecU && vecD < vecR && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y + 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TD = true;
		TU = false;
		TL = false;
		TR = false;
	}
	else if (!TU && vecD < vecU && vecD < vecL && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y + 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TD = true;
		TU = false;
		TL = false;
		TR = false;
	}

	else if (!TR && vecL < vecU && vecL < vecD && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x - 2] == (int)'1'))
	{
		TL = true;
		TD = false;
		TU = false;
		TR = false;
	}
	else if (!TR && vecL < vecR && vecL < vecD && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x - 2] == (int)'1'))
	{
		TL = true;
		TD = false;
		TU = false;
		TR = false;
	}
	else if (!TR && vecL < vecR && vecL < vecU && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x - 2] == (int)'1'))
	{
		TL = true;
		TD = false;
		TU = false;
		TR = false;
	}

	else if (!TL && vecR < vecU && vecR < vecD && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x + 2] == (int)'1'))
	{
		TR = true;
		TD = false;
		TL = false;
		TU = false;
	}
	else if (!TL && vecR < vecL && vecR < vecD && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x + 2] == (int)'1'))
	{
		TR = true;
		TD = false;
		TL = false;
		TU = false;
	}
	else if (!TL && vecR < vecL && vecR < vecU && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x + 2] == (int)'1'))
	{
		TR = true;
		TD = false;
		TL = false;
		TU = false;
	}

	else if (!TU && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y + 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TU = false;
		TD = true;
		TL = false;
		TR = false;
	}
	else if (!TD && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y - 2][(int)Turquoisey.getPosition().x] == (int)'1'))
	{
		TU = true;
		TD = false;
		TL = false;
		TR = false;
	}
	else if (!TL && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x + 2] == (int)'1'))
	{
		TU = false;
		TD = false;
		TL = false;
		TR = true;
	}
	else if (!TR && ((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x] == (int)'2') && !((int)mapdata[(int)Turquoisey.getPosition().y][(int)Turquoisey.getPosition().x - 2] == (int)'1'))
	{
		TU = false;
		TD = false;
		TL = true;
		TR = false;
	}

	if (Turquoisey.getPosition().x < ttrgtX - 64 || Turquoisey.getPosition().x < ttrgtX + 64 && Turquoisey.getPosition().y < ttrgtY - 64 || Turquoisey.getPosition().y < ttrgtY + 64)
	{
		ttrgtX = rand() % 448;
		ttrgtY = rand() % 496;
	}

	TurquoiseyUp();
	TurquoiseyDown();
	TurquoiseyLeft();
	TurquoiseyRight();
}

void levels()
{
	if (lvl > 1)
	{
		int ani1 = 0, ani2 = 0;

		lvlpac.setPosition(Vector2f(472, 263));
		lvlgst.setPosition(Vector2f(568, 263));

		paclvl.loadFromFile("textures/lvltrans-pac.png");
		gstlvl.loadFromFile("textures/lvltrans-gst.png");

		lvlpac.setTexture(paclvl);
		lvlpac.setTextureRect(IntRect(0, 64, 64, 64));
		lvlpac.setOrigin(32, 32);

		lvlgst.setTexture(gstlvl);
		lvlgst.setTextureRect(IntRect(0, 0, 64, 64));
		lvlgst.setOrigin(32, 32);

		ghosts.play();

		while (lvlgst.getPosition().x > -22)
		{
			lvlpac.move(Vector2f(-5, 0));
			lvlpac.setTextureRect(IntRect(64 * ani1, 64, 64, 64));
			ani1++;
			if (ani1 == 7) ani1 = 0;

			lvlgst.move(Vector2f(-5, 0));
			lvlgst.setTextureRect(IntRect(64 * ani2, 0, 64, 64));
			ani2++;
			if (ani2 == 3) ani2 = 0;

			window.clear();
			window.draw(lvlpac);
			window.draw(lvlgst);
			window.display();
		}
		ghosts.stop();
		scared.play();
		while (lvlpac.getPosition().x < 472)
		{
			lvlpac.move(Vector2f(+5, 0));
			lvlpac.setTextureRect(IntRect(64 * ani1, 0, 64, 64));
			ani1++;
			if (ani1 == 7) ani1 = 0;

			lvlgst.move(Vector2f(+5, 0));
			lvlgst.setTextureRect(IntRect(64 * ani2, 64, 64, 64));
			ani2++;
			if (ani2 == 3) ani2 = 0;

			window.clear();
			window.draw(lvlpac);
			window.draw(lvlgst);
			window.display();
		}
		scared.stop();
	}

	U = false,
		D = false,
		L = false,
		R = false,

		BU = false,
		BD = false,
		BL = false,
		BR = false,

		PU = false,
		PD = false,
		PL = false,
		PR = false,

		IU = false,
		ID = false,
		IL = false,
		IR = false,

		CU = false,
		CD = false,
		CL = false,
		CR = false;
}

void game(Clock & clock, Time & tmr)
{
	if (sound)
		start.play();
	Clock clock2;
	Time tmr2 = clock2.getElapsedTime();
Restart:
	window.setTitle("Pac-Man");
	score = 0;

	clock.restart();
	clock2.restart();

	dotting();

	player.setTextureRect(IntRect(0, 0, 32, 32));
	player.setPosition(Vector2f(223, 279));

	player.setScale(.8f, .8f);

	Blinky.setScale(.8f, .8f);
	Pinky.setScale(.8f, .8f);
	Inky.setScale(.8f, .8f);
	Clyde.setScale(.8f, .8f);
	Greeney.setScale(.8f, .8f);
	Lemoney.setScale(.8f, .8f);
	Magentey.setScale(.8f, .8f);
	Turquoisey.setScale(.8f, .8f);

	livs1.setScale(.8f, .8f);
	livs2.setScale(.8f, .8f);
	livs3.setScale(.8f, .8f);

	prtlI.setScale(.9f, .9f);
	prtlII.setScale(.9f, .9f);

	pwr1.setPosition(20, 51);
	pwr2.setPosition(420, 51);
	pwr3.setPosition(20, 370);
	pwr4.setPosition(420, 370);

	pwr1.setTexture(pallet);
	pwr2.setTexture(pallet);
	pwr3.setTexture(pallet);
	pwr4.setTexture(pallet);

	Blinky.setTextureRect(IntRect(0, 0, 32, 32));
	Blinky.setPosition(Vector2f(223, 184));

	Pinky.setTextureRect(IntRect(0, 0, 32, 32));
	Pinky.setPosition(Vector2f(223, 232));

	Inky.setTextureRect(IntRect(0, 0, 32, 32));
	Inky.setPosition(Vector2f(189, 232));

	Clyde.setTextureRect(IntRect(0, 0, 32, 32));
	Clyde.setPosition(Vector2f(257, 232));

	Greeney.setTextureRect(IntRect(0, 0, 32, 32));
	if (lvl > 3)
		Greeney.setPosition(24, 56);
	else
		Greeney.setPosition(223, 232);

	Lemoney.setTextureRect(IntRect(0, 0, 32, 32));
	if (lvl > 4)
		Lemoney.setPosition(424, 56);
	else
		Lemoney.setPosition(223, 232);

	Magentey.setTextureRect(IntRect(0, 0, 32, 32));
	if (lvl > 5)
		Magentey.setPosition(24, 375);
	else
		Magentey.setPosition(223, 232);

	Turquoisey.setTextureRect(IntRect(0, 0, 32, 32));
	if (lvl > 6)
		Turquoisey.setPosition(424, 375);
	else
		Turquoisey.setPosition(223, 232);

	portala.setPosition(Vector2f(-2.f, 216.f));
	portalb.setPosition(Vector2f(450.f, 216.f));

	livs1.setTextureRect(IntRect(0, 0, 32, 32));
	livs1.setPosition(Vector2f(376, 512));

	livs2.setTextureRect(IntRect(0, 0, 32, 32));
	livs2.setPosition(Vector2f(400, 512));

	livs3.setTextureRect(IntRect(0, 0, 32, 32));
	livs3.setPosition(Vector2f(425, 512));

	prtlI.setTextureRect(IntRect(0, 0, 37, 37));
	prtlI.setPosition(Vector2f(-30, -30));
	prtlII.setTextureRect(IntRect(0, 0, 37, 37));
	prtlII.setPosition(Vector2f(-30, -30));


	while (window.isOpen())
	{
		stringstream ss;
		ss << user1.totalscore;

		tmr = clock.getElapsedTime();
		timer[lvl] = tmr.asSeconds();

		powerpallet(clock2, tmr2);

		prtlx++;
		if (prtlx == 9)prtlx = 0;
		prtlI.setTextureRect(IntRect((37 * prtlx), 0, 37, 37));
		prtlII.setTextureRect(IntRect((37 * prtlx), 0, 37, 37));

		Score.setString(ss.str().c_str());

		if (timer[lvl] > 10 && !((int)mapdata[(int)Pinky.getPosition().y][(int)Pinky.getPosition().x] == (int)'2'))
		{
			Pinky.move(Vector2f(0, -2));
			if (Inky.getPosition().x <224 && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2'))
				Inky.move(Vector2f(2, 0));
		}
		if (timer[lvl] > 25 && !((int)mapdata[(int)Inky.getPosition().y][(int)Inky.getPosition().x] == (int)'2'))
		{
			Inky.move(Vector2f(0, -2));
			if (Clyde.getPosition().x > 222 && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2'))
				Clyde.move(Vector2f(-2, 0));
		}
		if (timer[lvl] > 35 && !((int)mapdata[(int)Clyde.getPosition().y][(int)Clyde.getPosition().x] == (int)'2'))
		{
			Clyde.move(Vector2f(0, -2));
		}

		if (lvl > 4 && lvl < 10)
		{
			if ((timer[lvl] >= 15 && timer[lvl] < 30) || (timer[lvl] >= 60 && timer[lvl] < 65))
			{
				prtlI.setPosition(Vector2f(24, 24));
				prtlII.setPosition(Vector2f(424, 473));
			}
			else if (lvl > 6 && ((timer[lvl] >= 40 && timer[lvl] < 45) || (timer[lvl] >= 80 && timer[lvl] < 95)))
			{
				prtlI.setPosition(Vector2f(24, 328));
				prtlII.setPosition(Vector2f(424, 136));
			}
			else
			{
				prtlI.setPosition(Vector2f(-30, -30));
				prtlII.setPosition(Vector2f(-30, -30));
			}
		}

		if (score == 1770)
		{
			Gameover.setFillColor(Color::Blue);
			Gameover.setOutlineColor(Color::White);
			Gameover.setPosition(Vector2f(112, 197));

			Gameover.setString("Winner");

			window.clear();

			window.draw(backgroundinv);
			window.draw(Gameover);
			window.draw(Score);
			window.draw(SCR);
			window.display();

			window.setTitle("Level Complete!");

			if (sound)
			{
				pausemusc.stop();
				pausemusc.play();
			}
			this_thread::sleep_for(5750ms);

			if (sars)
			{
				Gameover.setString("Stay Home \nStay Safe");
				Gameover.setFillColor(Color::White);

				window.clear();
				window.draw(Gameover);
				window.display();
				this_thread::sleep_for(3250ms);
			}

			lvl++;

			if (lvl > 10)
				break;

			window.setFramerateLimit(30);

			levels();

			window.setFramerateLimit(60);

			goto Restart;
		}

		if (!eatabl)
		{
			if (player.getGlobalBounds().intersects(Blinky.getGlobalBounds()) || player.getGlobalBounds().intersects(Pinky.getGlobalBounds()) || player.getGlobalBounds().intersects(Inky.getGlobalBounds()) || player.getGlobalBounds().intersects(Clyde.getGlobalBounds()) || player.getGlobalBounds().intersects(Greeney.getGlobalBounds()) || player.getGlobalBounds().intersects(Lemoney.getGlobalBounds()) || player.getGlobalBounds().intersects(Magentey.getGlobalBounds()) || player.getGlobalBounds().intersects(Turquoisey.getGlobalBounds()))
			{
				Gameover.setFillColor(Color::Red);
				Gameover.setOutlineColor(Color::White);
				Gameover.setPosition(Vector2f(70, 197));

				Gameover.setString("Game Over");

				this_thread::sleep_for(1500ms);

				if (sound)
					dth.play();

				window.clear();

				if (pac || ghstly)
					player.setTexture(death);
				else if (sars)
				{
					player.setTexture(deathsars);
					player.setScale(.6f, .6f);
				}
				player.setTextureRect(IntRect(0, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(32, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(64, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(96, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(128, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(160, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.clear();

				this_thread::sleep_for(135ms);

				player.setTextureRect(IntRect(192, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(224, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(256, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(288, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				player.setTextureRect(IntRect(320, 0, 32, 32));

				window.draw(background);
				window.draw(player);

				window.draw(px1); window.draw(px2); window.draw(px3);
				window.draw(px4); window.draw(px5); window.draw(px6);
				window.draw(px7);

				window.draw(py1); window.draw(py2); window.draw(py3);
				window.draw(py4); window.draw(py5); window.draw(py6);

				window.display();

				this_thread::sleep_for(135ms);

				window.clear();

				dth.stop();

				Lives--;

				if (Lives == 0)
				{
					window.draw(backgroundinv);
					window.draw(Gameover);
					window.draw(Score);
					window.draw(SCR);
					window.display();

					window.setTitle("Game Over!");

					if (sound)
					{
						pausemusc.stop();
						pausemusc.play();
					}
					this_thread::sleep_for(5750ms);

					if (sars)
					{
						Gameover.setString("Stay Home \nStay Safe");
						Gameover.setFillColor(Color::White);
						window.clear();
						window.draw(Gameover);
						window.display();
						this_thread::sleep_for(3250ms);
					}

					break;
				}
				else
				{
					if (pac || ghstly)
						player.setTexture(pacman);
					else if (sars)
						player.setTexture(sarscov);

					player.setScale(.8f, .8f);
					player.setPosition(Vector2f(223, 279));
					player.setTextureRect(IntRect(0, 0, 32, 32));

					Blinky.setPosition(Vector2f(223, 184));

					Pinky.setPosition(Vector2f(223, 232));

					Inky.setPosition(Vector2f(189, 232));

					Clyde.setPosition(Vector2f(257, 232));

					if (lvl > 3)
						Greeney.setPosition(24, 56);
					else
						Greeney.setPosition(223, 232);

					if (lvl > 4)
						Lemoney.setPosition(424, 56);
					else
						Lemoney.setPosition(223, 232);

					if (lvl > 5)
						Magentey.setPosition(24, 375);
					else
						Magentey.setPosition(223, 232);

					if (lvl > 6)
						Turquoisey.setPosition(424, 375);
					else
						Turquoisey.setPosition(223, 232);

					U = false;
					D = false;
					L = false;
					R = false;
				}
			}
		}
		else 
		{
			if (player.getGlobalBounds().intersects(Blinky.getGlobalBounds()))
			{
				Blinky.setTexture(dead);
				this_thread::sleep_for(450ms);
				Blinky.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
			if (player.getGlobalBounds().intersects(Pinky.getGlobalBounds()))
			{
				Pinky.setTexture(dead);
				this_thread::sleep_for(450ms);
				Pinky.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
			if (player.getGlobalBounds().intersects(Inky.getGlobalBounds()))
			{
				Inky.setTexture(dead);
				this_thread::sleep_for(450ms);
				Inky.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
			if (player.getGlobalBounds().intersects(Clyde.getGlobalBounds()))
			{
				Clyde.setTexture(dead);
				this_thread::sleep_for(450ms);
				Clyde.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
			if (player.getGlobalBounds().intersects(Greeney.getGlobalBounds()))
			{
				Greeney.setTexture(dead);
				this_thread::sleep_for(450ms);
				Greeney.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
			if (player.getGlobalBounds().intersects(Lemoney.getGlobalBounds()))
			{
				Lemoney.setTexture(dead);
				this_thread::sleep_for(450ms);
				Lemoney.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
			if (player.getGlobalBounds().intersects(Magentey.getGlobalBounds()))
			{
				Magentey.setTexture(dead);
				this_thread::sleep_for(450ms);
				Magentey.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
			if (player.getGlobalBounds().intersects(Turquoisey.getGlobalBounds()))
			{
				Turquoisey.setTexture(dead);
				this_thread::sleep_for(450ms);
				Turquoisey.setPosition(Vector2f(223, 184));
				user1.levelscore[lvl] += 200;
				user1.totalscore += 200;
			}
		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				ext = true;
			}

			if (event.key.code == Keyboard::Up)
			{
				U = true;
				D = false;
			}

			if (event.key.code == Keyboard::Down)
			{
				D = true;
				U = false;
			}

			if (event.key.code == Keyboard::Right)
			{
				R = true;
				L = false;
			}

			if (event.key.code == Keyboard::Left)
			{
				L = true;
				R = false;
			}
		}

		Up();
		Down();
		Left();
		Right();

		if ((timer[lvl] >= 0 && timer[lvl] < 30) || (timer[lvl] >= 50 && timer[lvl] < 80) || (timer[lvl] >= 100 && timer[lvl] < 120) || (timer[lvl] >= 140 && timer[lvl] < 185) || timer[lvl] >= 210)
		{
			Blinky_chase();
			Pinky_chase();
			Inky_chase();
			Clyde_chase();
		}

		if ((timer[lvl] >= 30 && timer[lvl] < 50) || (timer[lvl] >= 80 && timer[lvl] < 100) || (timer[lvl] >= 120 && timer[lvl] < 140) || (timer[lvl] >= 185 && timer[lvl] < 210))
		{
			trgtX = 365, trgtY = 4,
				ptrgtX = 83, ptrgtY = 4,
				itrgtX = 365, itrgtY = 492,
				ctrgtX = 63, ctrgtY = 492;

			if ((Blinky.getPosition().x > 325 && Blinky.getPosition().x < 448) && (Blinky.getPosition().y > 0 && Blinky.getPosition().y < 105))
				Blinky_fn();
			else
				Blinky_chase();

			if ((Pinky.getPosition().x > 0 && Pinky.getPosition().x < 120) && (Pinky.getPosition().y > 0 && Pinky.getPosition().y < 105))
				Pinky_fn();
			else
				Pinky_chase();

			if ((Inky.getPosition().x > 230 && Inky.getPosition().x < 448) && (Inky.getPosition().y > 360 && Inky.getPosition().y < 496))
				Inky_fn();
			else
				Inky_chase();

			if ((Clyde.getPosition().x > 0 && Clyde.getPosition().x < 215) && (Clyde.getPosition().y > 360 && Clyde.getPosition().y < 496))
				Clyde_fn();
			else
				Clyde_chase();
		}
		Greeney_chase();
		Lemoney_chase();
		Magentey_chase();
		Turquoisey_chase();

		portals();

		collision(timer[lvl]);

		user1.levelscore[lvl] = score;

		window.setFramerateLimit(60);

		window.clear();
		window.draw(background);

		window.draw(px1); window.draw(px2); window.draw(px3);
		window.draw(px4); window.draw(px5); window.draw(px6);
		window.draw(px7);
		
		window.draw(py1); window.draw(py2); window.draw(py3);
		window.draw(py4); window.draw(py5); window.draw(py6);

		window.draw(pwr1); window.draw(pwr2); window.draw(pwr3); window.draw(pwr4);

		window.draw(player);

		window.draw(prtlI);
		window.draw(prtlII);

		window.draw(Blinky);
		window.draw(Pinky);
		window.draw(Inky);
		window.draw(Clyde);
		if (lvl > 3)
			window.draw(Greeney);
		if (lvl > 4)
			window.draw(Lemoney);
		if (lvl > 5)
			window.draw(Magentey);
		if (lvl > 6)
			window.draw(Turquoisey);

		if (Lives == 3)
			window.draw(livs1);
		if (Lives >= 2)
			window.draw(livs2);
		if (Lives >= 1)
			window.draw(livs3);

		window.draw(Score);
		window.draw(SCR);

		window.display();

		user1.time[lvl] = timer[lvl];
	}
}

void mMenu(RenderWindow & win)
{
	while (win.isOpen())
	{
		menu.draw(win, sound);

		Event event;
		while (win.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Up:

					menu.up();
					break;

				case Keyboard::Down:

					menu.down();
					break;

				case Keyboard::Enter:

					menu.enter(sound, gamebool, ext, skins);
					break;
				}

			}
		}
		if (gamebool)
			break;
		if (ext)
			break;
		if (skins)
			break;
	}
}

void sMenu(RenderWindow & wndw)
{
	while (wndw.isOpen())
	{
		skn.draw(wndw, pac, sars, ghstly);

		Event event;
		while (wndw.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Up:

					skn.up();
					break;

				case Keyboard::Down:

					skn.down();
					break;

				case Keyboard::Enter:

					skn.enter(pac, sars, ghstly, rtn);
					break;
				}

			}
		}
		if (rtn)
		{
			rtn = !rtn;
			skins = !skins;
			break;
		}
	}
}

void Menu(RenderWindow & wndo)
{
	if (!skins)
		mMenu(wndo);
	if (skins)
		sMenu(wndo);
}

int main()
{
	srand((unsigned)time(0));

	pausemusc.openFromFile("soundtrack/pause.wav");
	pausemusc.setVolume(75);

	start.openFromFile("soundtrack/start.wav");
	start.setVolume(75);

	dth.openFromFile("soundtrack/gameover.wav");

	scared.openFromFile("soundtrack/scared.ogg");
	ghosts.openFromFile("soundtrack/ghost.ogg");

	icon.loadFromFile("textures/icon.png");

	window.setVerticalSyncEnabled(true);
	window.setIcon(50, 50, icon.getPixelsPtr());

	Font sfont;
	sfont.loadFromFile("fonts/Joystix.ttf");

	Score.setFont(sfont);
	Score.setFillColor(Color::White);
	Score.setOutlineColor(Color::Blue);
	Score.setPosition(Vector2f(100, 496));
	Score.setCharacterSize(25);

	SCR.setFont(sfont);
	SCR.setFillColor(Color::White);
	SCR.setOutlineColor(Color::Blue);
	SCR.setPosition(Vector2f(0, 496));
	SCR.setString("Score:");
	SCR.setCharacterSize(25);

	Gameover.setFont(sfont);
	Gameover.setCharacterSize(50);

	pacman.loadFromFile("textures/PacManIIII.png");
	sarscov.loadFromFile("textures/sarscov-pac.png");

	death.loadFromFile("textures/death.png");
	deathsars.loadFromFile("textures/deathsars.png");

	blinky.loadFromFile("textures/blinkyII.png");
	pinky.loadFromFile("textures/pinkyII.png");
	inky.loadFromFile("textures/inkyII.png");
	clyde.loadFromFile("textures/clydeII.png");
	greeney.loadFromFile("textures/greeney.png");
	lemoney.loadFromFile("textures/lemoney.png");
	magentey.loadFromFile("textures/magentey.png");
	turquoisey.loadFromFile("textures/turquoisey.png");

	blinkysars.loadFromFile("textures/blinkyII-sars.png");
	pinkysars.loadFromFile("textures/pinkyII-sars.png");
	inkysars.loadFromFile("textures/inkyII-sars.png");
	clydesars.loadFromFile("textures/clydeII-sars.png");
	greeneysars.loadFromFile("textures/greeney-sars.png");
	lemoneysars.loadFromFile("textures/lemoney-sars.png");
	magenteysars.loadFromFile("textures/magentey-sars.png");
	turquoiseysars.loadFromFile("textures/turquoisey-sars.png");

	gstlytxt.loadFromFile("textures/ghostly-ghost.png");

	scrd.loadFromFile("textures/ghost-scared.png");
	dead.loadFromFile("textures/eyes.png");

	texture.loadFromFile("textures/MazeIV.png");
	textureinv.loadFromFile("textures/MazeIV-invert.png");

	prtltxtr.loadFromFile("textures/portalIII.png");

	pallet.loadFromFile("textures/pallet.png");

	player.setOrigin(16, 16);

	Blinky.setOrigin(16, 16);
	Pinky.setOrigin(16, 16);
	Inky.setOrigin(16, 16);
	Clyde.setOrigin(16, 16);
	Greeney.setOrigin(16, 16);
	Lemoney.setOrigin(16, 16);
	Magentey.setOrigin(16, 16);
	Turquoisey.setOrigin(16, 16);

	livs1.setOrigin(16, 16);
	livs2.setOrigin(16, 16);
	livs3.setOrigin(16, 16);

	prtlI.setOrigin(18.5, 18.5);
	prtlII.setOrigin(18.5, 18.5);

	background.setTexture(texture);
	backgroundinv.setTexture(textureinv);

	prtlI.setTexture(prtltxtr);
	prtlII.setTexture(prtltxtr);

	menu.art(window);
	this_thread::sleep_for(3500ms);

menuhelper:
	Menu(window);
	if (!gamebool && !ext)
		goto menuhelper;

	if (pac)
	{
		player.setTexture(pacman);

		Blinky.setTexture(blinky);
		Pinky.setTexture(pinky);
		Inky.setTexture(inky);
		Clyde.setTexture(clyde);
		Greeney.setTexture(greeney);
		Lemoney.setTexture(lemoney);
		Magentey.setTexture(magentey);
		Turquoisey.setTexture(turquoisey);

		livs1.setTexture(pacman);
		livs2.setTexture(pacman);
		livs3.setTexture(pacman);
	}
	else if (sars)
	{
		player.setTexture(sarscov);

		Blinky.setTexture(blinkysars);
		Pinky.setTexture(pinkysars);
		Inky.setTexture(inkysars);
		Clyde.setTexture(clydesars);
		Greeney.setTexture(greeneysars);
		Lemoney.setTexture(lemoneysars);
		Magentey.setTexture(magenteysars);
		Turquoisey.setTexture(turquoiseysars);

		livs1.setTexture(sarscov);
		livs2.setTexture(sarscov);
		livs3.setTexture(sarscov);
	}
	else if (ghstly)
	{
		player.setTexture(pacman);

		Blinky.setTexture(gstlytxt);
		Pinky.setTexture(gstlytxt);
		Inky.setTexture(gstlytxt);
		Clyde.setTexture(gstlytxt);
		Greeney.setTexture(gstlytxt);
		Lemoney.setTexture(gstlytxt);
		Magentey.setTexture(gstlytxt);
		Turquoisey.setTexture(gstlytxt);

		livs1.setTexture(pacman);
		livs2.setTexture(pacman);
		livs3.setTexture(pacman);
	}

	Clock clock;
	Time tmr = clock.getElapsedTime();

	if (gamebool)
	{
		game(clock, tmr);

		ofstream out_file;
		out_file.open("Highscores.txt");
		out_file << user1.name << "\t\t\t" << "Total Score: " << user1.totalscore << endl << endl;
		out_file << "Level :" << "\t\t\t" << "Score :" << "\t\t\t" << "Time :" << endl;

		for (int j = 1; ; j++)
			if (lvl <= 10)
			{
				if (j <= lvl)
					out_file << j << "\t\t\t" << user1.levelscore[j] << "\t\t\t" << user1.time[j] << endl;
				else break;
			}
			else if (lvl > 10)
			{
				if (j <= 10)
					out_file << j << "\t\t\t" << user1.levelscore[j] << "\t\t\t" << user1.time[j] << endl;
				else if (j < 10)
					break;
			}
		gamebool = false;

		U = false;
		D = false;
		L = false;
		R = false;

		Lives = 3;

		goto menuhelper;

	}
}