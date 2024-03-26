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


void PrintTable(Tab item)
{
    for(int i = 0; i < item.length; i++)
    {
        printf("%d - %s - %s - %s\n", i+1, item.table[i].person.first_name, item.table[i].person.second_name, 
                item.table[i].person.father_name);
    }
}

void PrintInfo(Tab item, int number)
{
    printf("First name: %s\n", item.table[number-1].person.first_name);
    printf("Second name: %s\n", item.table[number-1].person.second_name);
    printf("Father name: %s\n", item.table[number-1].person.father_name);
    if(item.table[number-1].job.company != NULL)
    {
        printf("Job company: %s\n", item.table[number-1].job.company);
        printf("Job position: %s\n", item.table[number-1].job.position);
    }
    if(item.table[number-1].contacts.phone_count != 0)
    {
        for(int i = 0; i < item.table[number-1].contacts.phone_count; i++)
        {
            printf("%dth phone number: %s\n", i+1, item.table[number-1].contacts.phone_numbers[i]);
        }
    }
    if(item.table[number-1].contacts.e_mails_count != 0)
    {
        for(int i = 0; i < item.table[number-1].contacts.e_mails_count; i++)
        {
            printf("%dth e-mail: %s\n", i+1, item.table[number-1].contacts.e_mails[i]);
        }
    }
    if(item.table[number-1].contacts.socials_count != 0)
    {
        for(int i = 0; i < item.table[number-1].contacts.socials_count; i++)
        {
            printf("%dth social network: %s\t%s\n", i+1, item.table[number-1].contacts.social_networks[i].name, item.table[number-1].contacts.social_networks[i].link);
        }
    }
    if(item.table[number-1].contacts.messengers_count != 0)
    {
        for(int i = 0; i < item.table[number-1].contacts.messengers_count; i++)
        {
            printf("%dth social network: %s\t%s\n", i+1, item.table[number-1].contacts.messengers[i].name, item.table[number-1].contacts.messengers[i].tag);
        }
    }
}


void AddLine(Tab* item)
{
    if(item->length > 20)
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
        CopyLine(&(item->table[item->length]), &line);
        //item->table[item->length] = line;
        item->length++;
    }
}

void RemLine(Tab* item)
{
    int number_line;
    printf("Enter number of line for remooving: ");
    scanf("%d", &number_line);
    for (int i = number_line - 1; i < item->length - 1; i++)
    {
        item->table[i] = item->table[i+1];
    }
    item->length--;
}


void ChangeLine(Tab* item)
{
    int line_number, choise;
    PrintTable(*item);
    printf("Enter number of line for change: ");
    scanf("%d", &line_number);
    PrintInfo(*item, line_number);

    printf("1. Name\n");
    printf("2. Job\n");
    printf("3. Phone number\n");
    printf("4. e-mail\n");
    printf("5. Social Network\n");
    printf("6. Messenger\n");
    printf("Choose field for change: ");
    scanf("%d", &choise);
    switch (choise)
    {
        case 1:
            ChangeName(&item->table[line_number-1]);
            break;
        case 2:
            ChangeJob(&item->table[line_number-1]);
            break;
        case 3:
            ChangePhoneNumber(&item->table[line_number-1]);
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
