//function.c
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Item{
    int ID;
    char name[100];
    int quantity;
    float price;

};

struct Employee{
    int ID;
    char name[100];
    char Class[100];
    float salary;
};

struct Item warehouse[100];
struct Employee employees[100];
int itemcount=0;
int employeecount=0;

void menudesign()
{
    printf("------------------------------------------------\n");
    printf("|                                              |\n");
    printf("|                                              |\n");
    printf("|        Welcome To Warehouse Management       |\n");
    printf("|                                              |\n");
    printf("|                                              |\n");
    printf("------------------------------------------------\n");

}
void saveToFile() {
    FILE *wfile, *efile;
    wfile = fopen("warehouse_data.txt", "w");
    efile = fopen("employee_data.txt", "w");
    if (wfile == NULL || efile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < itemcount; i++) {
        fprintf(wfile, "%d  \t%s  \t%d  \t%.2f\n",
                warehouse[i].ID, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
      fclose(wfile);
    for (int i = 0; i < employeecount; i++) {
        fprintf(efile, "%d  \t%s  \t%s \t%.2f\n",
                employees[i].ID, employees[i].name, employees[i].Class, employees[i].salary);
    }
    //fclose(wfile);
    fclose(efile);
}
void addItem()
{
    if(itemcount>=100)
    {
        printf("OPSS !! Warehouse is full\n");
        return;
    }
    int id;
    printf("Enter Product ID: ");
    scanf("%d",&id);
    warehouse[itemcount].ID=id;
    printf("Enter Product Name: ");
    scanf("%s",warehouse[itemcount].name);
    printf("Enter item quantity: ");
    scanf("%d",&warehouse[itemcount].quantity);
    printf("Enter item price: ");
    scanf("%f",&warehouse[itemcount].price);
    itemcount++;

    printf("Item added successfully\n");
    saveToFile();
}
void editItem()
{
    int id,i,found = 0;
    printf("Enter item ID to edit: ");
    scanf("%d",&id);
    for(i=0;i<itemcount;i++)
    {
        if(warehouse[i].ID==id)
        {
            printf("Enter new name: ");
            scanf("%s",warehouse[i].name);
            printf("Enter new quantity: ");
            scanf("%d",&warehouse[i].quantity);
            printf("Enter new price: ");
            scanf("%f",&warehouse[i].price);
            found=1;
            printf("Item edited successfully");
            break;
        }
    }
    if(found==0) printf("Sorry . Item not found\n");
    saveToFile();
}
void displayStock()
{
    if(itemcount==0)
    {
        printf("OPSS !! No items in the warehouse to show.\n");
        return;
    }
    for(int i=0;i<itemcount-1;i++)
    {
        for(int j=0;j<itemcount-i-1;j++)
        {
            float value1=warehouse[j].quantity*warehouse[j].price;
            float value2=warehouse[j+1].quantity*warehouse[j+1].price;
            if(value1<value2)
            {
                struct Item temp=warehouse[j];
                warehouse[j]=warehouse[j+1];
                warehouse[j+1]=temp;
            }
        }
    }
    printf("\nID\t\tName\t\tQuantity\tPrice\t\tValue\n");
    for(int i=0;i<itemcount;i++)
    {
        float value=warehouse[i].quantity*warehouse[i].price;
        printf("%d %17s %17d %13.2f\t%13.2f\n", warehouse[i].ID, warehouse[i].name, warehouse[i].quantity, warehouse[i].price, value);
    }
}

void deleteItem()
{
    int id,i,j,found=0;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    for(i=0;i<itemcount;i++)
    {
        if(warehouse[i].ID==id)
        {
            for(j=i;j<itemcount-1;j++){
                warehouse[j]=warehouse[j+1];
            }

            itemcount--;
            found=1;
            printf("Item Deleted Successfully\n");
            break;
        }
    }
    if(found==0) printf("Item not found\n");
        saveToFile();
}

void updateStock(){

    int id,qty,found=0;
    printf("Enter item ID to update stock: ");
    scanf("%d",&id);

    for(int i=0;i<itemcount;i++) {

        if(warehouse[i].ID==id) {

            printf("Enter quantity to add/remove (use negative for removal): ");
            scanf("%d",&qty);
            warehouse[i].quantity+=qty;
            printf("Stock updated successfully!\n");
            found=1;
            break;

        }
    }

    if(found==0) printf("Item not found!\n");

    saveToFile();
}

void addEmployeeinfo(){

    if(employeecount>=100){

        printf("OPSS! Employee list is full. \n");
        return;

    }

    printf("Enter employee ID: ");
    scanf("%d", &employees[employeecount].ID);

    getchar();
    printf("Enter employee name: ");
    gets(employees[employeecount].name);
    printf("Enter employee position: ");
    gets(employees[employeecount].Class);
    printf("Enter employee salary: ");
    scanf("%f",&employees[employeecount].salary);

    employeecount++;
    printf("Employee added successfully!\n");

    saveToFile();
}

void editEmployeeinfo(){
    int id,i,found=0;

    printf("Enter employee ID to edit: ");
    scanf("%d",&id);
    getchar();

    for (i=0;i<employeecount;i++) {

        if(employees[i].ID==id) {

            printf("Enter new name:");
            gets(employees[i].name);
            printf("Enter new class: ");
            gets(employees[i].Class);
            printf("Enter new salary: ");
            scanf("%f",&employees[i].salary);
            found=1;

            printf("Employee updated successfully!\n");
            break;
        }
    }


    if (found==0) printf("OPSS! Employee not found.\n");

    saveToFile();
}

void deleteEmployee() {
    int id,i,j,found = 0;
    printf("Enter employee ID to delete: ");
    scanf("%d",&id);

    for(i=0;i<employeecount;i++) {
        if (employees[i].ID==id) {
            for (j=i;j<employeecount-1;j++) {
                employees[j]=employees[j+1];
            }
            employeecount--;
            found=1;
            printf("Employee deleted successfully!\n");
            break;

        }

    }

    if(found==0) printf("OPSS! Employee not found.\n");

    saveToFile();
}

void displayEmployeesinfo() {

    if(employeecount==0){

        printf("Sorry! No employee to show.");
        return;

    }

    printf("\nID\t\tName\t\tPosition\tSalary\n");
    for(int i=0;i<employeecount;i++){

        printf("\n%d %17s %17s %13.2f\n",employees[i].ID,employees[i].name,employees[i].Class,employees[i].salary);
    }

}


void searchItem()
{
    char name[100];
    int found=0;
    int n;
    printf("Search by \n1.Name \n2.ID \n");
    printf("Enter your choice : ");
    scanf("%d",&n);
    if(n==1)
    {
        printf("Enter item name :");
        scanf("%s",name);
        for(int i=0;i<itemcount;i++)
        {
            if(strcmp(warehouse[i].name, name)==0)
            {
                printf("Item found\nID: %d  Name: %s  Quantity: %d  Price: %.2f\n",warehouse[i].ID,warehouse[i].name,warehouse[i].quantity,warehouse[i].price);
                found = 1;
                //break;
            }
        }
    }
    else if(n==2){

        int id;
        printf("Enter item ID to search: ");
        scanf("%d",&id);

        for (int i=0;i<itemcount;i++)
        {
            if (warehouse[i].ID==id)
            {
                printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",warehouse[i].ID,warehouse[i].name,warehouse[i].quantity,warehouse[i].price);
                found = 1;
                break;
            }
        }
    }

    if(found==0)
        printf("OPSS! Item not found!\n");
}

void recordSale(){

    int id, qty, found = 0;
    FILE *file = fopen("sales.txt", "a");

    if (file==NULL){

        printf("Error opening sales record file!\n");
        return;
    }

    printf("Enter item ID to sell: ");
    scanf("%d",&id);

    for(int i=0;i<itemcount;i++){

        if(warehouse[i].ID==id){

            printf("Enter quantity sold: ");
            scanf("%d", &qty);

            if(qty>warehouse[i].quantity){
                printf("Insufficient stock!\n");
            }else{

                warehouse[i].quantity -= qty;
                fprintf(file, "\nID: %d, Name: %s, Quantity: %d",
                        warehouse[i].ID, warehouse[i].name, qty);
                printf("Sale recorded successfully!\n");
            }
            found=1;
            break;
        }
    }

    fclose(file);
    if(found==0) printf("Sorry! Item not found.\n");

    saveToFile();
}

void generateReport(){
    FILE *file = fopen("sales.txt","r");
    if(file==NULL){
        printf("Error opening file!\n");
        return;
    }

    char line[200];
    printf("\nSales Report:\n");
    while (fgets(line, sizeof(line),file)) {
        printf("%s",line);
    }

    fclose(file);
}
void getfromfile()
{
    FILE *wfile, *efile;
    wfile=fopen("warehouse_data.txt", "r");
    efile=fopen("employee_data.txt", "r");
    int i=0,j=0;
    if(wfile==NULL||efile==NULL)
    {
        printf("Error opening file");
        return;
    }
    while (fscanf(wfile, "%d %s %d %f", &warehouse[itemcount].ID, warehouse[itemcount].name, &warehouse[itemcount].quantity, &warehouse[itemcount].price) == 4) {
        itemcount++;
        if (itemcount >= 100) break;
    }
while (fscanf(efile, "%d %s %s %f", &employees[employeecount].ID, employees[employeecount].name, employees[employeecount].Class, &employees[employeecount].salary) == 4) {
        employeecount++;
        if (employeecount >= 100) break;
    }
    fclose(wfile);
    fclose(efile);
}
