#ifndef MENU_H_
#define MENU_H_

#include "tab.h"
#include <stdio.h>

int Menu();
void PrintTable(Tab item);
void PrintInfo(Tab item, int number);
void AddLine(Tab* item);
void RemLine(Tab* item);
void ChangeLine(Tab* item);
void ChangeName(Line* item);
void ChangeJob(Line* item);
void ChangePhoneNumber(Line* item);
void ChangeEMail(Line* item);
void ChangeSocialNetwork(Line* item);
void ChangeMessenger(Line* item);

#endif