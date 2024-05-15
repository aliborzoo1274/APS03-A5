#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace sf;
using namespace std;

const int WIDTH = 912;
const int HEIGHT = 600;
const int FRAME_RATE = 144;
const int SCORE_INCREASE = 1000;
const int SUNFLOWER_SUN_MAKE_TIME = 4;

const float TILE_HEIGHT = 95;
const float TILE_WIDTH = 80;

const Vector2f TOP_LEFT_CORNER_OF_GROUND = {135, 95};

const char FIRST_DELIM = ',';
const char SECOND_DELIM = '-';
const char THIRD_DELIM = ' ';

const string PICS_PATH = "./files/pics/", AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/", SETTINGS_PATH = "./files/settings/";

#define error(x) cout << x << endl, exit(0);