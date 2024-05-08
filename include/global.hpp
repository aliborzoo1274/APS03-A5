#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <random>

using namespace sf;
using namespace std;

const int WIDTH = 912;
const int HEIGHT = 600;
const int FRAME_RATE = 144;

const string PICS_PATH = "./files/pics/", AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/";

#define error(x) cout << x << endl, exit(0);