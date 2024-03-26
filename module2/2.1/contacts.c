#include "contacts.h"

Contacts* SetContacts(Contacts* item, char phone_numbers[][17], int phone_count, char e_mails[][40], int e_mails_count,
                     SocialNetwork social_networks[], int socials_count, Messenger messengers[], int messengers_count)
{
    char temp[100];
    item->phone_count = phone_count;
    item->e_mails_count = e_mails_count;
    item->socials_count = socials_count;
    item->messengers_count = messengers_count;
    for(int i = 0; i < phone_count; i++)
    {
        strncpy(item->phone_numbers[i], phone_numbers[i], 17);
    }
    for(int i = 0; i < e_mails_count; i++)
    {
        strncpy(item->e_mails[i], e_mails[i], 20);
    }
    for(int i = 0; i < socials_count; i++)
    {
        strncpy(item->social_networks[i].link, social_networks[i].link, 20);
        strncpy(item->social_networks[i].name, social_networks[i].name, 20);
    }
    for(int i = 0; i < messengers_count; i++)
    {
        strncpy(item->messengers[i].name, messengers[i].name, 20);
        strncpy(item->messengers[i].tag, messengers[i].tag, 20);
    }
    return item;
}