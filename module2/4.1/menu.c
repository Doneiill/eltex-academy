#include "menu.h"

int Menu()
{
    int choise;
    printf("\nSelect an action:\n");
    printf("1. Show full table\n");
    printf("2. Show full info\n");
    printf("3. Add new line\n");
    printf("4. Change line\n");
    printf("5. Remove line\n");
    printf("6. Exit\n");
    scanf("%d", &choise);
    return choise;
}


void PrintTable(Tab* item)
{
    for(Tab* temp = item; temp != NULL; temp = temp->next)
    {
        printf("%d - %s - %s - %s\n", temp->pos, temp->item.person.first_name, temp->item.person.second_name, 
                temp->item.person.father_name);
    }
}

void PrintInfo(Tab* item, int number)
{
    Tab* temp = item;
    while(temp->pos != number && temp != NULL) temp = temp->next;
    printf("First name: %s\n", temp->item.person.first_name);
    printf("Second name: %s\n", temp->item.person.second_name);
    printf("Father name: %s\n", temp->item.person.father_name);
    if(temp->item.job.company != NULL)
    {
        printf("Job company: %s\n", temp->item.job.company);
        printf("Job position: %s\n", temp->item.job.position);
    }
    if(temp->item.contacts.phone_count != 0)
    {
        for(int i = 0; i < temp->item.contacts.phone_count; i++)
        {
            printf("%dth phone number: %s\n", i+1, temp->item.contacts.phone_numbers[i]);
        }
    }
    if(temp->item.contacts.e_mails_count != 0)
    {
        for(int i = 0; i < temp->item.contacts.e_mails_count; i++)
        {
            printf("%dth e-mail: %s\n", i+1, temp->item.contacts.e_mails[i]);
        }
    }
    if(temp->item.contacts.socials_count != 0)
    {
        for(int i = 0; i < temp->item.contacts.socials_count; i++)
        {
            printf("%dth social network: %s\t%s\n", i+1, temp->item.contacts.social_networks[i].name, temp->item.contacts.social_networks[i].link);
        }
    }
    if(temp->item.contacts.messengers_count != 0)
    {
        for(int i = 0; i < temp->item.contacts.messengers_count; i++)
        {
            printf("%dth social network: %s\t%s\n", i+1, temp->item.contacts.messengers[i].name, temp->item.contacts.messengers[i].tag);
        }
    }
}


Tab* AddLine(Tab* item)
{
    if(item->size > 20)
    {
        printf("So many lines in table!");
    }
    else
    {
        Line line;
        LineInit(&line);
        printf("Enter first name: ");
        scanf("%s", line.person.first_name);
        printf("Enter second name: ");
        scanf("%s", line.person.second_name);
        printf("Enter father name: ");
        scanf("%s", line.person.father_name);
        char choise = 'n';
        printf("\nDo you want to enter job information?[y/n]: ");
        scanf("%s", &choise);
        if(choise == 'y')
        {
            printf("\nEnter company name: ");
            scanf("%s", line.job.company);
            printf("Enter position in company: ");
            scanf("%s", line.job.position);
        }
        choise = 'n';
        char small_choise[2] = "n\n";
        small_choise[0] = 'n';

        printf("\nDo you want to enter phone number?[y/n]: ");
        scanf("%s", &choise);
        if(choise == 'y')
        {
            printf("\nEnter phone number: ");
            scanf("%s", line.contacts.phone_numbers[0]);
            line.contacts.phone_count++;
            for(int j = 1; j < 5; j++)
            {
                printf("\nDo you want to enter another phone numer?[y/n]: ");
                scanf("%s", small_choise);
                
                if (small_choise[0] == 'y')
                {
                    printf("Enter %dth phone number: ", j+1);
                    scanf("%s", line.contacts.phone_numbers[j]);
                    line.contacts.phone_count++;
                    small_choise[0] = 'n';
                }
                else break;
            }
        }
        choise = 'n';
        small_choise[0] = 'n';

        printf("\nDo you want to enter e-mail?[y/n]: ");
        scanf("%s", &choise);
        if(choise == 'y')
        {
            printf("\nEnter e-mail: ");
            scanf("%s", line.contacts.e_mails[0]);
            line.contacts.e_mails_count++;
            for(int i = 1; i < 5; i++)
            {
                printf("Do you want to enter another e-mail?[y/n]: ");
                scanf("%s", small_choise);
                if (small_choise[0] == 'y')
                {
                    printf("Enter %dth e-mail: ", i+1);
                    scanf("%s", line.contacts.e_mails[i]);
                    line.contacts.e_mails_count++;
                    small_choise[0] = 'n';
                }
                else break;
            }
        }
        choise = 'n';
        small_choise[0] = 'n';

        printf("\nDo you want to enter social network?[y/n]: ");
        scanf("%s", &choise);
        if(choise == 'y')
        {
            printf("Enter social network name: ");
            scanf("%s", line.contacts.social_networks[0].name);
            printf("Enter social network link: ");
            scanf("%s", line.contacts.social_networks[0].link);
            line.contacts.socials_count++;
            for(int i = 1; i < 5; i++)
            {
                printf("Do you want to enter another social network?[y/n]: ");
                scanf("%s", small_choise);
                if (small_choise[0] == 'y')
                {
                    printf("Enter %dth social network name: ", i+1);
                    scanf("%s", line.contacts.social_networks[i].name);
                    printf("Enter %dth social network link: ", i+1);
                    scanf("%s", line.contacts.social_networks[i].link);
                    line.contacts.socials_count++;
                    small_choise[0] = 'n';
                }
                else break;
            }
        }
        choise = 'n';
        small_choise[0] = 'n';

        printf("\nDo you want to enter messenger?[y/n]: ");
        scanf("%s", &choise);
        if(choise == 'y')
        {
            printf("Enter messenger name: ");
            scanf("%s", line.contacts.messengers[0].name);
            printf("Enter messenger tag: ");
            scanf("%s", line.contacts.messengers[0].tag);
            line.contacts.messengers_count++;
            for(int i = 1; i < 5; i++)
            {
                printf("Do you want to enter another messenger?[y/n]: ");
                scanf("%s", small_choise);
                if (small_choise[0] == 'y')
                {
                    printf("Enter %dth messenger name: ", i+1);
                    scanf("%s", line.contacts.messengers[i].name);
                    printf("Enter %dth messenger link: ", i+1);
                    scanf("%s", line.contacts.messengers[i].tag);
                    line.contacts.messengers_count++;
                    small_choise[0] = 'n';
                }
                else break;
            }
        }
        choise = 'n';
        small_choise[0] = 'n';
        item = SortedInsert(item, &line);
    }
    return item;
}

Tab* SortedInsert(Tab* head, Line* item)
{
    int result = 0;
    Tab* temp = head;
    if(head->size == 0)
    {
        CopyLine(&(head->item), item);
        head->size = 1;
        head->pos = 1;
        return head;
    }
    while(temp != NULL)
    {
        if(strcmp(temp->item.person.first_name, item->person.first_name) > 0)
        {
            result = -1;
            break;
        }
        else if(strcmp(temp->item.person.first_name, item->person.first_name) == 0)
        {
            if(strcmp(temp->item.person.second_name, item->person.second_name) > 0)
            {
                result = -1;
                break;
            }
            else if(strcmp(temp->item.person.second_name, item->person.second_name) == 0)
            {
                if(strcmp(temp->item.person.father_name, item->person.father_name) > 0)
                {
                    result = -1;
                    break;
                }
                else 
                {
                    result = 1;
                    if(temp->next != NULL)
                        temp = temp->next;
                    else break;
                }
            }
            else 
            {
                result = 1;
                if(temp->next != NULL)
                    temp = temp->next;
                else break;
            }
        }
        else 
        {
            result = 1;
            if(temp->next != NULL)
                temp = temp->next;
            else break;
        }
    }
    Tab* node = InitNode();
    if(result == -1)
    {
        if(temp->prev == NULL)
        {
            node->next = temp;
            node->size = temp->size;
            node->pos = temp->pos;
            temp->prev = node;
            head = node;
            while(temp != NULL)
            {
                temp->pos += 1;
                temp = temp->next;
            }          
        }
        else
        {
            node->next = temp;
            node->prev = temp->prev;
            temp->prev->next = node;
            temp->prev = node;
            node->pos = temp->pos;
            while(temp != NULL)
            {
                temp->pos += 1;
                temp = temp->next;
            }
        }
    }
    else
    {
        temp->next = node;
        node->prev = temp;
        node->pos = temp->pos + 1;
        node->size = temp->size;
    }
    PlusSize(head);
    CopyLine(&(node->item), item);
    return head;
}

void PlusSize(Tab* head)
{
    Tab* temp = head;
    while(temp != NULL)
    {
        temp->size += 1;
        temp = temp->next;
    }
}

void MinusSize(Tab* head)
{
    Tab* temp = head;
    while(temp != NULL)
    {
        temp->size += 1;
        temp = temp->next;
    }
}

Tab* InitNode()
{
    Tab* node = malloc(sizeof(Tab));
    node->size = 0;
    node->pos = 0;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Tab* RemLine(Tab* item)
{
    int number_line;
    printf("Enter number of line for remove: ");
    scanf("%d", &number_line);
    Tab* temp = item;
    if(temp->pos == number_line)
    {
        temp->next->prev = NULL;
        item = temp->next;
    }
    else
    {
        while(temp->pos != number_line && temp != NULL)
        {
            printf("asdasdad\n");
            temp = temp->next;
        }
        if(temp->next != NULL)
            temp->next->prev = temp->prev;
        if(temp->prev != NULL)
            temp->prev->next = temp->next;
    }
    
    Tab* s_temp = temp->next;
    while(s_temp != NULL)
    {
        s_temp->pos -= 1;
        s_temp = s_temp->next;
    }
    free(temp);
    MinusSize(item);
    return item;
}


void ChangeLine(Tab* item)
{
    int line_number, choise;
    PrintTable(item);
    printf("Enter number of line for change: ");
    scanf("%d", &line_number);
    PrintInfo(item, line_number);

    printf("1. Name\n");
    printf("2. Job\n");
    printf("3. Phone number\n");
    printf("4. e-mail\n");
    printf("5. Social Network\n");
    printf("6. Messenger\n");
    printf("Choose field for change: ");
    scanf("%d", &choise);
    Tab* temp = item;
    while(temp->pos != line_number)
    {
        temp = temp->next;
    }
    switch (choise)
    {
        case 1:
            ChangeName(&(temp->item));
            break;
        case 2:
            ChangeJob(&(temp->item));
            break;
        case 3:
            ChangePhoneNumber(&(temp->item));
            break;

        default:
            printf("Wrong choise!");
    }
}


void ChangeName(Line* item)
{
    int choise;
    char string[20];
    printf("1. First Name\n");
    printf("2. Second Name\n");
    printf("3. Father Name\n");
    printf("Choose Field: \n");
    scanf("%d", &choise);
    switch(choise)
    {
        case 1:
            printf("Enter new name: ");
            scanf("%s", string);
            strncpy(item->person.first_name, string, 20);
            break;
        case 2:
            printf("Enter new name: ");
            scanf("%s", string);
            strncpy(item->person.second_name, string, 20);
            break;
        case 3:
            printf("Enter new name: ");
            scanf("%s", string);
            strncpy(item->person.father_name, string, 20);
            break;
        default:
            printf("Wrong choise!");
    }
}


void ChangeJob(Line* item)
{
    int choise;
    char string[20];
    printf("1. Job company\n");
    printf("2. Job position\n");
    printf("Choose Field: \n");
    scanf("%d", &choise);
    switch(choise)
    {
        case 1:
            printf("Enter new Job company: ");
            scanf("%s", string);
            strncpy(item->job.company, string, 20);
            break;
        case 2:
            printf("Enter new Job position: ");
            scanf("%s", string);
            strncpy(item->job.position, string, 20);
            break;
        default:
            printf("Wrong choise!");
    }
}

void ChangePhoneNumber(Line* item)
{
    int choise;
    char string[17];
    for(int i = 0; i < item->contacts.phone_count; i++)
    {
        printf("%d. %s", i+1, item->contacts.phone_numbers[i]);
    }
    printf("Choose phone number: ");
    scanf("%d", &choise);
    if(choise <= item->contacts.phone_count && choise > 0)
    {
        printf("Enter new phone number: ");
        scanf("%s", string);
        strncpy(item->contacts.phone_numbers[choise-1], string, 17);
    }
    else printf("Wrong choise!");
}


void ChangeEMail(Line* item)
{
    int choise;
    char string[40];
    for(int i = 0; i < item->contacts.e_mails_count; i++)
    {
        printf("%d. %s", i+1, item->contacts.e_mails[i]);
    }
    printf("Choose e-mail: ");
    scanf("%d", &choise);
    if(choise <= item->contacts.e_mails_count && choise > 0)
    {
        printf("Enter new e-mil: ");
        scanf("%s", string);
        strncpy(item->contacts.e_mails[choise-1], string, 40);
    }
    else printf("Wrong choise!");
}


void ChangeSocialNetwork(Line* item)
{
    int choise, small_choise;
    char string[40];
    for(int i = 0; i < item->contacts.socials_count; i++)
    {
        printf("%d. %s - %s", i+1, item->contacts.social_networks[i].name, item->contacts.social_networks[i].link);
    }
    printf("Choose social network: ");
    scanf("%d", &choise);
    if(choise <= item->contacts.socials_count && choise > 0)
    {
        printf("Do you wont to change name of social network[1] or link[2]?\n");
        printf("Choose an action: ");
        scanf("%d", &small_choise);
        switch(small_choise)
        {
            case 1:
                printf("Enter new name of social network: ");
                scanf("%s", string);
                strncpy(item->contacts.social_networks[choise].name, string, 20);
                break;
            case 2:
                printf("Enter new link: ");
                scanf("%s", string);
                strncpy(item->contacts.social_networks[choise].link, string, 40);
                break;
            default:
                printf("Wrong choise!");
        }
    }
}

void ChangeMessenger(Line* item)
{
    int choise, small_choise;
    char string[40];
    for(int i = 0; i < item->contacts.messengers_count; i++)
    {
        printf("%d. %s - %s", i+1, item->contacts.messengers[i].name, item->contacts.messengers[i].tag);
    }
    printf("Choose messenger: ");
    scanf("%d", &choise);
    if(choise <= item->contacts.messengers_count && choise > 0)
    {
        printf("Do you wont to change name of messenger[1] or tag[2]?\n");
        printf("Choose an action: ");
        scanf("%d", &small_choise);
        switch(small_choise)
        {
            case 1:
                printf("Enter new name of messenger: ");
                scanf("%s", string);
                strncpy(item->contacts.social_networks[choise].name, string, 20);
                break;
            case 2:
                printf("Enter new tag: ");
                scanf("%s", string);
                strncpy(item->contacts.social_networks[choise].link, string, 40);
                break;
            default:
                printf("Wrong choise!");
        }
    }
}


void FreeTab(Tab* head)
{
    Tab* temp = head;
    while(temp != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
}
