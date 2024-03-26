#include "line.h"

void LineInit(Line* item)
{
    item->contacts.phone_count = 0;
    item->contacts.e_mails_count = 0;
    item->contacts.socials_count = 0;
    item->contacts.messengers_count = 0;
}

void CopyLine(Line* item, Line* second)
{
    SetPerson(&(item->person), second->person.first_name, second->person.second_name, second->person.father_name);
    SetJob(&(item->job), second->job.company, second->job.position);
    SetContacts(&(item->contacts), second->contacts.phone_numbers, second->contacts.phone_count, second->contacts.e_mails, second->contacts.e_mails_count,
                second->contacts.social_networks, second->contacts.socials_count, second->contacts.messengers, second->contacts.messengers_count);
    
}