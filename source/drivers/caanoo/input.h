#ifndef _aosdfjk02fmasf
#define _aosdfjk02fmasf

#include "../common/configSys.h"
#include "../common/config.h"
#include "../common/args.h"
#include "../../git.h"

#define MAXBUTTCONFIG   4
typedef struct {
        uint8  ButtType[MAXBUTTCONFIG];
        uint8  DeviceNum[MAXBUTTCONFIG];
        uint16 ButtonNum[MAXBUTTCONFIG];
        uint32 NumC;
	//uint64 DeviceID[MAXBUTTCONFIG];	/* TODO */
} ButtConfig;

extern CFGSTRUCT InputConfig[];
extern ARGPSTRUCT InputArgs[];
void ParseGIInput(FCEUGI *GI);
int ButtonConfigBegin();
void ButtonConfigEnd();
void ConfigButton(char *text, ButtConfig *bc);

#define BUTTC_KEYBOARD          0x00
#define BUTTC_JOYSTICK          0x01
#define BUTTC_MOUSE             0x02

#define FCFGD_GAMEPAD   1
#define FCFGD_POWERPAD  2
#define FCFGD_HYPERSHOT 3
#define FCFGD_QUIZKING  4

void InitInputInterface(void);
void InputUserActiveFix(void);

extern bool replaceP2StartWithMicrophone;
extern ButtConfig GamePadConfig[4][10];
extern ButtConfig powerpadsc[2][12];
extern ButtConfig QuizKingButtons[6];
extern ButtConfig FTrainerButtons[12];

void IncreaseEmulationSpeed(void);
void DecreaseEmulationSpeed(void);

int DTestButtonJoy(ButtConfig *bc);

void FCEUD_UpdateInput(void);

void UpdateInput(Config *config);
void InputCfg(const std::string &);

std::string GetUserText(const char* title);

#endif
