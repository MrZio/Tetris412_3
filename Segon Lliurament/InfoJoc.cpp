#include "InfoJoc.h"

void dibuixaQuadrat(const ColorFigura color, int posX, int posY)
{
    IMAGE_NAME grafic;

    switch (color)
    {
    case COLOR_GROC:
        grafic = GRAFIC_QUADRAT_GROC;
        break;
    case COLOR_BLAUCEL:
        grafic = GRAFIC_QUADRAT_BLAUCEL;
        break;
    case COLOR_MAGENTA:
        grafic = GRAFIC_QUADRAT_MAGENTA;
        break;
    case COLOR_TARONJA:
        grafic = GRAFIC_QUADRAT_TARONJA;
        break;
    case COLOR_BLAUFOSC:
        grafic = GRAFIC_QUADRAT_BLAUFOSC;
        break;
    case COLOR_VERMELL:
        grafic = GRAFIC_QUADRAT_VERMELL;
        break;
    case COLOR_VERD:
        grafic = GRAFIC_QUADRAT_VERD;
        break;
    }

    GraphicManager::getInstance()->drawSprite(grafic, posX, posY, false);
}