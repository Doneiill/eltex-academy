#ifndef MENU_H_
#define MENU_H_

#include "tab.h"
#include <stdio.h>
#include <stdlib.h>

int Menu();
void PrintTable(Tab* item);
void PrintInfo(Tab* item, int number);
Tab* AddLine(Tab* item);
Tab* RemLine(Tab* item);
void ChangeLine(Tab* item);
void ChangeName(Line* item);
void ChangeJob(Line* item);
void ChangePhoneNumber(Line* item);
void ChangeEMail(Line* item);
void ChangeSocialNetwork(Line* item);
void ChangeMessenger(Line* item);
Tab* SortedInsert(Tab* head, Line* item);
Tab* InitNode();
void PlusSize(Tab* head);
void MinusSize(Tab* head);
void FreeTab(Tab* head);

#endif