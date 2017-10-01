#include <stdio.h>
#include <stdlib.h>

#define ADD 0
#define MODIFY 1
#define PRINT 2
#define Id 3

void menu (void);
void action (void);
void add_modify(int x,int add_mod);
void delete_node (int node_number);
void print_search(int node_number,int id);

//Global varibles contribute in mutiple functions
char state;
int employee_no;
char flag = 0;


typedef struct emplyee_data
{
    unsigned int ID;
    unsigned char age;
    unsigned char salary;
    unsigned char experience;
    char name[30];
    struct Data* Next;
}Data;

Data *Head;
Data *End;


int main()
{
   // Varibles initializations
    state = 1 ;
    employee_no = 0 ;
    Head = NULL;
    End = NULL;
    // Welcome Screen
    printf("\n \n \n \n \t \t \t ***WELCOME***");
    getch();
    system("cls");
    int ch;
    menu();
    while (ch = getch()) /* 27 = Esc key */
    {
        if(ch == 13) //ASCII of Enter Key
            {
                if(state == 7)
                {
                    system("cls");
                    printf("                Thanks\n");
                    break; // to treminate the program
                }
                action();
            }
        else if (ch == 0 || ch == 224)
        {
            ch = getch();
            if(ch == 72)//ASCII of UP Key
            {
                if(state == 1) state = 7;
                else state--;
            }
            else if (ch==80)//ASCII of Down key
            {
                if(state == 7) state = 1;
                else state++;
            }
        }
        else if(ch == 27)//ASCII of Esc Key
            {

            }
        menu();
    }

    return 0;
}

void action (void)
{
    char x;
    int ch;

   switch(state)
   {

   case 1 : // Enter Number of Employee
       system("cls");
       printf("Enter Number of Employees = ");
       scanf("%d",&employee_no);
       printf("\nThank you,the number of Employees : %d\
\nplease press \"Esc\" to back or \"Enter\" to enter another",employee_no);
    break;
///////////////////////////////////////////////////
///////////////////////////////////////////////////
   case 2 :
       system("cls");
       // Check if Number of Employees == Zero
       if(employee_no == 0)
            {
                printf(" Number of Emplyee is Zero\n");
                printf("\n Please Press \"Esc\" to Enter The Number of Employees Firstly");
                break;
            }
        flag = 1;
        for(x = 0; x < employee_no; x++)
            {
                add_modify(x+1,ADD);
            }
        printf("\n Please Press \"Esc\" or \"Enter\" to reEnter Employees ");
    break;
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
   case 3:
        system("cls");
        if(employee_no == 0)
            {
                printf(" Number of Emplyee is Zero\n");
                printf("\n Please Press \"Esc\" to Enter The Number of Employees Firstly");
                break;
            }
        else if(flag == 0)
            {
                printf(" Enter Data First\n");
                printf("\n Please Press \"Esc\" to Enter The Data of Employees Firstly");
                break;
            }

        for(x = 0; x < employee_no; x++)
            {
                print_search(x,PRINT);
            }
        printf("\n Please Press \"Esc\" or \"Enter\" to rePrint Employees ");
    break;
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

   case 4:
       system("cls");
       // Check if Number of Employees == Zero
       if(employee_no == 0)
            {
                printf(" Number of Emplyee is Zero\n");
                printf("\n Please Press \"Esc\" to Enter The Number of Employees Firstly");
                break;
            }
        printf("Enter Employ's Number to Delete : ");
        scanf("%d",&x);
        delete_node(x);
        printf("\n Please Press \"Esc\" or \"Enter\" to Delete another Employee ");
    break;
    /////////////////////////////
    /////////////////////////////
   case 5 :
       system("cls");
       // Check if Number of Employees == Zero
       if(employee_no == 0)
            {
                printf(" Number of Emplyee is Zero\n");
                printf("\n Please Press \"Esc\" to Enter The Number of Employees Firstly");
                break;
            }
        printf("Enter Employ's Number to Modify : ");
        scanf("%d",&x);
        add_modify(x,MODIFY);
        printf("\n Please Press \"Esc\" or \"Enter\" to Modify another Employee ");
    break;
    ///////////////////////////////
    ///////////////////////////////
   case 6:
       system("cls");
       // Check if Number of Employees == Zero
       if(employee_no == 0)
            {
                printf(" Number of Emplyee is Zero\n");
                printf("\n Please Press \"Esc\" to Enter The Number of Employees Firstly");
                break;
            }
        printf("Enter Employ's Number to ID : ");
        scanf("%d",&x);
        print_search(x,Id);
        printf("\n Please Press \"Esc\" or \"Enter\" to search another Employee ");

    break;
   }

// change the input or return to main menu
   ch = getch();
   if(ch == 13)
   {
       action();
   }
   else if (ch == 27)
   {
      return;
   }
}

void menu (void)
{
    switch(state)
    {
    case 1 :
        system("cls");
        printf("\n\n\n                --> 1-Enter Number of Employees \n\
               2-Enter Employee Data \n\
               3-Show Employee Data \n\
               4-Delete Employee \n\
               5-Modifiy Employee \n\
               6-Search by ID \n\
               7-Exit");
        break;

    case 2 :
        system("cls");
        printf("\n\n\n               1-Enter Number of Employees\n\
               --> 2-Enter Employee Data\n\
               3-Show Employee Data\n\
               4-Delete Employee\n\
               5-Modifiy Employee\n\
               6-Search by ID\n\
               7-Exit");
        break;

    case 3 :
        system("cls");
        printf("\n\n\n               1-Enter Number of Employees\n\
               2-Enter Employee Data\n\
               --> 3-Show Employee Data\n\
               4-Delete Employee\n\
               5-Modifiy Employee\n\
               6-Search by ID\n\
               7-Exit");
        break;

    case 4 :
        system("cls");
        printf("\n\n\n               1-Enter Number of Employees\n\
               2-Enter Employee Data\n\
               3-Show Employee Data\n\
               --> 4-Delete Employee\n\
               5-Modifiy Employee\n\
               6-Search by ID\n\
               7-Exit");
        break;

    case 5 :
        system("cls");
        printf("\n\n\n               1-Enter Number of Employees\n\
               2-Enter Employee Data\n\
               3-Show Employee Data\n\
               4-Delete Employee\n\
               --> 5-Modifiy Employee\n\
               6-Search by ID\n\
               7-Exit");
        break;

    case 6 :
        system("cls");
        printf("\n\n\n               1-Enter Number of Employees\n\
               2-Enter Employee Data\n\
               3-Show Employee Data\n\
               4-Delete Employee\n\
               5-Modifiy Employee\n\
               --> 6-Search by ID\n\
               7-Exit");
        break;

    case 7 :
        system("cls");
        printf("\n\n\n               1-Enter Number of Employees\n\
               2-Enter Employee Data\n\
               3-Show Employee Data\n\
               4-Delete Employee\n\
               5-Modifiy Employee\n\
               6-Search by ID\n\
               --> 7-Exit");
        break;
    }
}


void add_modify (int x, int add_mod)
{
    char y;
    Data* temp = (Data*) malloc(sizeof(Data));

    if(add_mod == ADD)
    {
        if(Head == NULL)
        {   // If first node in List
            Head = temp;
            End  = temp;
            temp->Next = NULL;
        }
        else
        {
            End->Next = temp ; // assign the address of node to previous node
            temp->Next = NULL ;
            End = temp ;
        }
    }
    else if (add_mod == MODIFY)
    {   if(x>employee_no)
        {
            printf("\nNot Exist");
            return;
        }
        temp = Head;
        for(y=0 ;y < x ; y++ )
        {
            temp = temp->Next;
        }
    }
            printf("Employee \"%d\" Please Enter your ID :",x);
            scanf("%d",&temp->ID);
            printf("Employee \"%d\" Please Enter your Age :",x);
            scanf("%d",&temp->age);
            printf("Employee \"%d\" Please Enter your Salary :",x);
            scanf("%d",&temp->salary);
            printf("Employee \"%d\" Please Enter your Experience :",x);
            scanf("%d",&temp->experience);
            printf("Employee \"%d\" Please Enter your Name :",x);
            getchar();
            gets(&temp->name);
            printf("---------------------------------------------------\n");

}
void delete_node (int node_number)
{
    if(node_number>employee_no)
        {
            printf("\nNot Exist");
            return;
        }
        employee_no--;
    char x = 0 ;
    Data* temp   = (Data*) malloc(sizeof(Data));
    Data* temp_1 = (Data*) malloc(sizeof(Data));
    temp = Head;
    for(x ; x < node_number-2 ; x ++)
        {
            temp = temp->Next;
        }
    // swap addresses
    temp_1 = temp->Next;
    temp->Next = temp_1->Next;
    //free the deleted node
    free(temp_1);
}

void print_search(int node_number,int id)
{
    char x = 0 ;
    Data* temp   = (Data*) malloc(sizeof(Data));
    temp = Head;
    if( id == PRINT)
        {
            for(x ; x < node_number ; ++x)
            {
                temp = temp->Next;
            }
        }
    else if (id == Id)
        {

            for(x ; x < employee_no ; ++x)
            {
                if(node_number == temp->ID)break;
                temp = temp->Next;
            }
            if(x==employee_no && node_number != temp->ID )
            {
                printf("\n ID not Exist");
                return;
            }
        }
            printf("\nEmployee \"%d\" Please Enter your ID : %d",x+1,temp->ID);
            printf("\nEmployee \"%d\" Please Enter your Age : %d",x+1,temp->age);
            printf("\nEmployee \"%d\" Please Enter your Salary : %d",x+1,temp->salary);
            printf("\nEmployee \"%d\" Please Enter your Experience : %d",x+1,temp->experience);
            printf("\nEmployee \"%d\" Please Enter your Name : %s",x+1,temp->name);
            printf("\n--------------------------------------------------------------");
}
