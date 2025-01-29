
//main.c
#include <stdio.h>
#include<stdlib.h>
#include"func.h"
struct Item{
    int ID;
    char name[100];
    int quantity;
    float price;

};
struct Employee{
    int ID;
    char name[100];
    char position[100];
    float salary;
};
extern struct Item warehouse[100];
extern struct Employee employees[100];
extern int itemcount;
extern int employeecount;

// Main function
int main() {
    menudesign();

    //Menu Choice
    int choice;
    do {
        itemcount=0;
        employeecount=0;
        getfromfile();
        printf("\nWarehouse Management System\n");
        printf("1.  Add Item\n");
        printf("2.  Edit Item\n");
        printf("3.  Delete Item\n");
        printf("4.  Display Stock\n");
        printf("5.  Search Item\n");
        printf("6.  Update Stock\n");
        printf("7.  Record Sale\n");
        printf("8.  Generate Report\n");
        printf("9.  Add Employeeinfo\n");
        printf("10. Edit Employeeinfo\n");
        printf("11. Delete Employee\n");
        printf("12. Display Employeesinfo\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
         system("cls");

        switch (choice) {
            case 1: {addItem();
                    break;
                    }
            case 2: {editItem();
                    break;
                    }
            case 3: {deleteItem();
                    break;
                    }
            case 4: {displayStock();
                    break;
                    }
            case 5: {searchItem();
                     break;
                     }
            case 6: {updateStock();
                     break;
                     }
            case 7: {recordSale();
                     break;
                     }
            case 8: {generateReport();
                     break;
                     }
            case 9: {addEmployeeinfo();
                     break;
                     }
            case 10: {editEmployeeinfo();
                     break;
                     }
            case 11: {deleteEmployee();
                     break;
                     }
            case 12: {displayEmployeesinfo();
                     break;
                     }
            case 13: {printf("Thank you for staying with us.\nExiting...\n");
                     break;
                     }
            default: {printf("Invalid choice!\n");
                        }
        }
    } while (choice!=13);
    return 0;
}