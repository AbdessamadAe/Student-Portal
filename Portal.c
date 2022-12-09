/*
100948
79320
*/
#include <stdio.h>
#include <string.h>
#define SIZE 100
#define LENGTH 100
#define N 3

int mainMenu();
int login(int *index, int id[], char pass[][LENGTH], char security[][LENGTH], char answer[][LENGTH]);
int enroll(int *index, char fname[][LENGTH], char lname[][LENGTH], char email[][LENGTH], char birthday[][LENGTH], char gender[][LENGTH], char cities[][LENGTH], char phones[][LENGTH]);
int portalMenu();
void update(int index, char fname[][LENGTH], char lname[][LENGTH], char email[][LENGTH], char phones[][LENGTH], char pass[][LENGTH], char security[][LENGTH], char answer[][LENGTH]);
void payfees(int index, double balance[]);
void cashwallet(int index, double cbalance[]);
void sort(int id[], char email[][LENGTH], char fname[][LENGTH], char lname[][LENGTH], char pass[][LENGTH], char phones[][LENGTH], double balance[], double cbalance[], char security[][LENGTH], char answer[][LENGTH]);

int main()
{
    FILE *input;
    FILE *enr;
    FILE *output;
    int id[SIZE];
    char email[SIZE][LENGTH], fname[SIZE][LENGTH], lname[SIZE][LENGTH], pass[SIZE][LENGTH], phones[SIZE][LENGTH], security[SIZE][LENGTH], answer[SIZE][LENGTH], birthday[SIZE][LENGTH], gender[SIZE][LENGTH], cities[SIZE][LENGTH];
    double balance[SIZE], cbalance[SIZE];

    int index, enrolled = 3, m1, l, m2, ex = 0;

    input = fopen("input.txt", "r");
    enr = fopen("enroll.txt", "w");
    output = fopen("output.txt", "w");

    for (int i = 0; i < N; i++)
    {
        fscanf(input, "%d %s %s %s %s %s %lf %lf %s %s", &id[i], email[i], fname[i], lname[i], pass[i], phones[i], &balance[i], &cbalance[i], security[i], answer[i]);
    }

    while (ex == 0)
    {
        int success = 0, ex2 = 0, e = 0;
        m1 = mainMenu();
        if (m1 == 3)
        {
            for (int i = 3; i < enrolled; i++)
            {
                fprintf(enr, "%s %s %s %s %s %s %s\n", fname[i], lname[i], email[i], birthday[i], gender[i], cities[i], phones[i]);
            }
            sort(id, email, fname, lname, pass, phones, balance, cbalance, security, answer);
            for (int i = 0; i < 3; i++)
            {
                fprintf(output, "%d %s %s %s %s %s %.0lf %.2lf %s %s\n", id[i], email[i], fname[i], lname[i], pass[i], phones[i], balance[i], cbalance[i], security[i], answer[i]);
            }
            fclose(input);
            fclose(enr);
            fclose(output);
            break;
        }
        else if (m1 == 1)
        {
            while (success == 0)
            {
                l = login(&index, id, pass, security, answer);
                if (l == 1)
                {
                    printf("Logged in successfully.\n\n");
                    success = 1;
                }
                else
                {
                    e = enroll(&enrolled, fname, lname, email, birthday, gender, cities, phones);
                    if (e == 1)
                    {
                        printf("Enrolled successfully.\n\n");
                        success = 1;
                    }
                }
            }
        }
        else if (m1 == 2)
        {
            e = enroll(&enrolled, fname, lname, email, birthday, gender, cities, phones);
            if (e == 0)
            {
                while (success == 0)
                {
                    l = login(&index, id, pass, security, answer);
                    if (l == 1)
                    {
                        printf("Logged in successfully.\n\n");
                        success = 1;
                    }
                    else
                    {
                        e = enroll(&enrolled, fname, lname, email, birthday, gender, cities, phones);
                        if (e == 1)
                        {
                            printf("Enrolled successfully.\n\n");
                            success = 1;
                        }
                    }
                }
            }
            else if (e == 1)
            {
                printf("Enrolled successfully.\n\n");
            }
        }
        if (e == 1)
            continue;
        while (ex2 == 0)
        {
            m2 = portalMenu();
            if (m2 == 4)
                break;
            else if (m2 == 1)
                update(index, fname, lname, email, phones, pass, security, answer);
            else if (m2 == 2)
                payfees(index, balance);
            else if (m2 == 3)
                cashwallet(index, cbalance);
        }
    }

    return 0;
}

int mainMenu()
{
    int choice = 0;
    printf("Welcome to AUI Portal.\n"
           "\n1. Log in"
           "\n2. Enroll"
           "\n3. Exit"
           "\n>>");
    scanf("%d", &choice);

    while (choice <= 0 || choice > 3)
    {
        printf("OUT OF BOUND! Try again"
               "\n>>");
        scanf("%d", &choice);
    }
    if (choice == 1)
        return 1;
    else if (choice == 2)
        return 2;
    else
        return 3;
}

int login(int *index, int id[], char pass[][LENGTH], char security[][LENGTH], char answer[][LENGTH])
{
    int tempid, i, l = 0, stop = 0;

    printf("Please enter the ID: ");
    scanf("%d", &tempid);
    for (int i = 0; i < N; i++)
    {
        if (tempid == id[i])
        {
            *index = i;
            l = 1;
            break;
        }
    }

    if (l == 1)
    {
        char temppass[LENGTH];
        while (strcmp(temppass, pass[*index]) != 0 && stop == 0)
        {
            printf("Please enter the passowrd: ");
            scanf("%s", temppass);
            for (int i = 0; i < strlen(pass[*index]); i++)
            {
                for (int j = 0; j < strlen(temppass) - 1; j++)
                {
                    if (pass[*index][i] == temppass[j] && pass[*index][i] == temppass[j + 1])
                    {

                        strcpy(&temppass[j], &temppass[j + 1]);

                        if (strcmp(temppass, pass[*index]) == 0)
                        {
                            char tempsec[LENGTH];
                            printf("%s ", security[*index]);
                            scanf("%s", &tempsec);
                            while (strcmp(tempsec, answer[*index]) != 0)
                            {
                                printf("Wrong Answer!\n");
                                printf("%s ", security[*index]);
                                scanf("%s", &tempsec);
                            }
                            i += strlen(pass[*index]);
                            stop = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return l;
}

int enroll(int *index, char fname[][LENGTH], char lname[][LENGTH], char email[][LENGTH], char birthday[][LENGTH], char gender[][LENGTH], char cities[][LENGTH], char phones[][LENGTH])
{
    int i, old_user = 0, current_email = 0;
    char firstName[LENGTH], lastName[LENGTH], eMail[LENGTH], birthDay[LENGTH], sex[LENGTH], city[LENGTH], phone[LENGTH];

    printf("\nEnrollement Section\n");

    printf("\nFirst Name: ");
    scanf("%s", firstName);

    printf("Last Name: ");
    scanf("%s", lastName);

    printf("Email: ");
    scanf("%s", eMail);
    for (int i = 0; i < N; i++)
    {
        if (strcmp(eMail, email[i]) == 0)
        {
            old_user = 1;
            break;
        }
    }

    if (old_user == 1)
    {
        int check = -1;

        printf("This email already exist!"
               "\nDo you wishes to enter another email or login to your account?"
               "\n1. [Log in.] 0. [Another email.]"
               "\n>>");
        scanf("%d", &check);

        while (check < 0 || check > 1)
        {
            printf("Choice unrecognized."
                   "\n>>");
            scanf("%d", &check);
        }

        if (check == 0)
        {
            while (current_email == 0)
            {
                current_email = 1;
                printf("Another email: ");
                scanf("%s", eMail);
                for (int i = 0; i < N; i++)
                {
                    if (strcmp(eMail, email[i]) == 0)
                    {
                        current_email = 0;
                        break;
                    }
                }
            }
            strcpy(fname[*index], firstName);
            strcpy(lname[*index], lastName);
            strcpy(email[*index], eMail);

            printf("Date of Birth (dd/mm/yyyy): ");
            scanf("%s", birthDay);
            strcpy(birthday[*index], birthDay);

            printf("Gender: ");
            scanf("%s", sex);
            strcpy(gender[*index], sex);

            printf("City: ");
            scanf("%s", city);
            strcpy(cities[*index], city);

            printf("Phone: ");
            scanf("%s", phone);
            strcpy(phones[*index], phone);
            *index += 1;
            return 1;
        }
        else if (check == 1)
        {
            return 0;
        }
    }
    else if (old_user == 0)
    {
        strcpy(fname[*index], firstName);
        strcpy(lname[*index], lastName);
        strcpy(email[*index], eMail);

        printf("Date of Birth (dd/mm/yyyy): ");
        scanf("%s", birthDay);
        strcpy(birthday[*index], birthDay);

        printf("Gender: ");
        scanf("%s", sex);
        strcpy(gender[*index], sex);

        printf("City: ");
        scanf("%s", city);
        strcpy(cities[*index], city);

        printf("Phone: ");
        scanf("%s", phone);
        strcpy(phones[*index], phone);
        *index += 1;
        return 1;
    }
}

int portalMenu()
{
    int choice = 0;
    printf("Welcome to the Portal."
           "\n1. Change student information"
           "\n2. Pay fees"
           "\n3. Supply Cash wallet"
           "\n4. Logout"
           "\n>>");
    scanf("%d", &choice);

    while (choice <= 0 || choice > 4)
    {
        printf("OUT OF BOUND! Try again"
               "\n>>");
        scanf("%d", &choice);
    }
    if (choice == 1)
        return 1;
    else if (choice == 2)
        return 2;
    else if (choice == 3)
        return 3;
    else
        return 4;
}

void update(int index, char fname[][LENGTH], char lname[][LENGTH], char email[][LENGTH], char phones[][LENGTH], char pass[][LENGTH], char security[][LENGTH], char answer[][LENGTH])
{
    char fName[LENGTH], lName[LENGTH], eMAIL[LENGTH], number[LENGTH], passCode[LENGTH], sQ[LENGTH], sA[LENGTH];
    int choice = 0;
    while (choice != 7)
    {
        printf("Edit Profile"
               "\n1. First Name"
               "\n2. Last Name"
               "\n3. Email"
               "\n4. Phone Number"
               "\n5. Password"
               "\n6. Security Code"
               "\n7. Return"
               "\n>>");
        scanf("%d", &choice);
        while (choice <= 0 || choice > 7)
        {
            printf("OUT OF BOUND! Try again"
                   "\n>>");
            scanf("%d", &choice);
        }

        char tpass[LENGTH] = "";
        while (strcmp(tpass, pass[index]) != 0 && choice != 7)
        {
            printf("Please enter your password to confirm the changes: ");
            scanf("%s", tpass);
        }

        if (choice == 1)
        {
            printf("Enter NEW first name: ");
            scanf("%s", fName);
            strcpy(fname[index], fName);
        }
        else if (choice == 2)
        {
            printf("Enter NEW last name: ");
            scanf("%s", lName);
            strcpy(lname[index], lName);
        }
        else if (choice == 3)
        {
            printf("Enter NEW email: ");
            scanf("%s", eMAIL);
            strcpy(email[index], eMAIL);
        }
        else if (choice == 4)
        {
            printf("Enter NEW phone number: ");
            scanf("%s", number);
            strcpy(phones[index], number);
        }
        else if (choice == 5)
        {
            int valid = 0;
            printf("Password rules: for safety concerns the password must contain at least 9 characters that must include at least each of the following"
                   "\n2 lowercase letters "
                   "\n2 uppercase letters"
                   "\n3 digits"
                   "\n2 characters"
                   "\nYou must make sure the password does not contain the following special characters: @, \\, ;"
                   "\nEnter NEW password: ");
            while (valid == 0)
            {

                scanf("%s", passCode);

                int flag_digit = 0, flag_upper = 0, flag_lower = 0, flag_other = 0;

                for (int i = 0; i < strlen(passCode); i++)
                {
                    if (passCode[i] != '@' && passCode[i] != ';' && passCode[i] != '\\')
                    {
                        if (isdigit(passCode[i]))
                            flag_digit++;
                        else if (islower(passCode[i]))
                            flag_lower++;
                        else if (isupper(passCode[i]))
                            flag_upper++;
                        else
                            flag_other++;
                    }
                }
                if (flag_digit < 3 || flag_lower < 2 || flag_upper < 2 || flag_other < 2 || strlen(passCode) < 9)
                {
                    printf("Enter valid password: ");
                }
                else
                {
                    strcpy(pass[index], passCode);
                    valid = 1;
                }
            }
        }
        else if (choice == 6)
        {
            printf("Enter NEW security question: ");
            scanf("%s", sQ);
            strcat(sQ, "?");
            strcpy(security[index], sQ);
            printf("Enter the answer: ");
            scanf("%s", sA);
            strcpy(answer[index], sA);
        }
    }
}

void payfees(int index, double balance[])
{
    int c, sh, s;
    double t, h, total_price, final_price;
    printf("Paying Fees\n");
    printf("Please enter your number of credits for the semester: ");
    scanf("%d", &c);
    t = c * 2100;
    printf("Choose a housing option: "
           "\n1. Double room: 5880 MAD "
           "\n2. Single room: 12800 MAD"
           "\n3. Triple room: 3570 MAD"
           "\n>>");
    scanf("%d", &sh);
    while (sh <= 0 || sh > 3)
    {
        printf("OUT OF BOUND! Try again"
               "\n>>");
        scanf("%d", &sh);
    }
    if (sh == 1)
        h = 5880;
    else if (sh == 2)
        h = 12800;
    else if (sh == 3)
        h = 3570;

    printf("Enter the percentage of your scholarship (If no, enter 0): ");
    scanf("%d", &s);

    if (s > 0)
        total_price = (h + t) * (1 - (s / 100.0));
    else
        total_price = (h + t);

    final_price = balance[index] - total_price;
    if (final_price >= 0)
    {
        printf("Paid successfully! (%.2lf Deducted from the balance)"
               "\nBalance Update : %.2lf MAD\n",
               total_price,
               final_price);
    }
    else
    {
        printf("You still need to pay %.2lf before the first day of classes to avoid getting a financial hold!\n", -final_price);
    }
    balance[index] = final_price;
}

void cashwallet(int index, double cbalance[])
{
    double supply;
    int op;
    printf("Supply Cash wallet.");
    printf("\nCash wallet Balance: %.2lf MAD", cbalance[index]);
    printf("\n1. Supply Cash Wallet"
           "\n2. Return");
    scanf("%d", &op);
    while (op <= 0 || op > 2)
    {
        printf("OUT OF BOUND! Try again"
               "\n>>");
        scanf("%d", &op);
    }

    if (op == 1)
    {
        printf("Enter the amount to supply: ");
        scanf("%lf", &supply);
        while (supply < 50 || supply > 10000)
        {
            if (supply < 50)
            {
                printf("The amount that you entered is less than then minimum required amount of money to supply your cash wallet, please enter a higher amount: ");
                scanf("%lf", &supply);
            }
            else if (supply > 10000)
            {
                printf("The amount that you entered is more than then maximum allowed amount of money to supply your cash wallet, please enter a lower amount: ");
                scanf("%lf", supply);
            }
        }
        cbalance[index] += supply;
    }
}

void sort(int id[], char email[][LENGTH], char fname[][LENGTH], char lname[][LENGTH], char pass[][LENGTH], char phones[][LENGTH], double balance[], double cbalance[], char security[][LENGTH], char answer[][LENGTH])
{
    int m_id, itemp;
    double dtemp;
    char temp[LENGTH];

    for (int i = 0; i < 3 - 1; i++)
    {
        m_id = i;

        for (int j = i + 1; j < 3; j++)
        {
            if (id[m_id] > id[j])
            {
                m_id = j;
            }
        }
        iswap(&id[i], &id[m_id]);

        cswap(email[i], email[m_id]);
        cswap(fname[i], fname[m_id]);
        cswap(lname[i], lname[m_id]);
        cswap(pass[i], pass[m_id]);
        cswap(phones[i], phones[m_id]);
        dswap(&balance[i], &balance[m_id]);
        cswap(security[i], security[m_id]);
        cswap(answer[i], answer[m_id]);
    }
}

void cswap(char *a, char *b)
{
    char temp[LENGTH];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void iswap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void dswap(double *a, double *b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}