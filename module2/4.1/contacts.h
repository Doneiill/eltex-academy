#ifndef CONTACTS_H_
#define CONTACTS_H_

#include <string.h>

typedef struct SocialNetwork
{
    char name[20];
    char link[40];
} SocialNetwork;

typedef struct Messenger
{
    char name[20];
    char tag[20];
} Messenger;

typedef struct Contacts
{
    char phone_numbers[5][17];
    int phone_count;
    char e_mails[5][40];
    int e_mails_count;
    SocialNetwork social_networks[5];
    int socials_count;
    Messenger messengers[5];
    int messengers_count;
} Contacts;

Contacts* SetContacts(Contacts* item, char phone_numbers[][17], int phone_count, char e_mails[][40], int e_mails_count,
                     SocialNetwork social_networks[], int socials_count, Messenger messengers[], int messengers_count);

#endif