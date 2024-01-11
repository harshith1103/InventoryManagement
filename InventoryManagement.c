#include <stdio.h>
struct Inventory{
    int prod_Id;
    char prod_Name[100];
    char prod_Desc[100];
    float prod_Price;
    int prod_Quantity;
};
/* Functions declaration */
void welcome(struct Inventory products[], int n);
void add_items(struct Inventory products[], int n);
void display_Items(struct Inventory products[], int n);
void update_Menu(struct Inventory products[], int n);
void update_List(struct Inventory products[], int n, int searchProd_Id);
void update_Name(struct Inventory products[], int n, int searchProd_Id);
void update_Desc(struct Inventory products[], int n, int searchProd_Id);
void update_Price(struct Inventory products[], int n, int searchProd_Id);
void update_Stock(struct Inventory products[], int n, int searchProd_Id);
// update_Stock Function used to update the Stock of the product
void update_Stock(struct Inventory products[], int n, int searchProd_Id){
    int updatedProd_Stock;
    printf("Enter Updated Stock: ");
    scanf("%d", &updatedProd_Stock);
    for (int i = 0; i < n; i++) {
        if (searchProd_Id == products[i].prod_Id) {
            products[i].prod_Quantity = updatedProd_Stock;
            printf("\n\n Quantity Updated Successfully \n\n");
            update_List(products, n, searchProd_Id);
        }
    }
}
// update_Price Function used to update the Price of the product
void update_Price(struct Inventory products[], int n, int searchProd_Id){
    float updatedProd_Price;
    printf("Enter Updated Price: ");
    scanf("%f", &updatedProd_Price);
    for (int i = 0; i < n; i++) {
        if (searchProd_Id == products[i].prod_Id) {
            products[i].prod_Price = updatedProd_Price;
            printf("\n\n Price Updated Successfully \n\n");
            update_List(products, n, searchProd_Id);
        }
    }
}
// update_desc Function used to Update the Description of the product
void update_Desc(struct Inventory products[], int n, int searchProd_Id){
    for (int i = 0; i < n; i++) {
        if (searchProd_Id == products[i].prod_Id) {
            printf("Enter Updated Description: ");
            scanf("%s", products[i].prod_Desc);
            printf("\n\n Description Updated Successfully \n\n");
            update_List(products, n, searchProd_Id);
        }
    }
}
// update_Name Function used to Update the Name of the product
void update_Name(struct Inventory products[], int n, int searchProd_Id){
    for (int i = 0; i < n; i++) {
        if (searchProd_Id == products[i].prod_Id) {
            printf("Enter Updated Name: ");
            scanf("%s", products[i].prod_Name);
            printf("\n\n Name Updated Successfully \n\n");
            update_List(products, n, searchProd_Id);
        }
    }
}
// update_List Function used to select What to update
void update_List(struct Inventory products[], int n, int searchProd_Id){
    int opt;
    printf("1. Update Name\n2. Update Description\n3. Update Price\n4. Update Stock\n5. Back\n");
    printf("Enter an Option: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            update_Name(products, n, searchProd_Id);
            break;
        case 2:
            update_Desc(products, n, searchProd_Id);
            break;
        case 3:
            update_Price(products, n, searchProd_Id);
            break;
        case 4:
            update_Stock(products, n, searchProd_Id);
            break;
        case 5:
            welcome(products, n);
            break;
        default:
            printf("Invalid Argument! Try Again");
            break;
    }
}
// update_Menu Function used to show the menu of update item
void update_Menu(struct Inventory products[], int n){
    int searchProd_Id;
    int count = 0;
    printf("Enter Product Id: ");
    scanf("%d", &searchProd_Id);
    for (int i = 0; i < n; i++) {
        if(searchProd_Id == products[i].prod_Id){
            count++;
        }
    }
    if (count != 0) {
        update_List(products, n, searchProd_Id);
    }else{
        printf("Couldn't find the product Id! Try Again\n");
        update_Menu(products, n);
    }
    
}
// display_Items function used to display Items in Inventory
void display_Items(struct Inventory products[], int n){
    printf("\n*Product Details*\n");
    printf("Total Items in Inventory: %d\n", n);
    for (int i = 0; i < n; i++) {
        printf("Product Id: %d\n", products[i].prod_Id);
        printf("Product Name: %s\n", products[i].prod_Name);
        printf("Product Description: %s\n", products[i].prod_Desc);
        printf("Product price: $ %f\n", products[i].prod_Price);
        printf("Product Quantity: %d\n\n", products[i].prod_Quantity);
    }
    welcome(products, n);
}
// Add_Items Function Used to add Items to Inventory
void add_Items(struct Inventory products[], int n){
    printf("*Add Items*\n");
    printf("Enter Product Id: ");
    scanf("%d", &products[n].prod_Id);
    printf("Enter Product Name: ");
    scanf("%s", products[n].prod_Name);
    printf("Enter Product Description: ");
    scanf("%s", products[n].prod_Desc);
    printf("Enter Product Price: ");
    scanf("%f", &products[n].prod_Price);
    printf("Enter Product Quantity: ");
    scanf("%d", &products[n].prod_Quantity);
    printf("\n\n Item Added successfully\n\n");
    welcome(products, n+1);
}
// Starting Function called in the start and a process about to begin
void welcome(struct Inventory products[], int n){
    int options;
    printf("*Menu*\n");
    printf("1. Add Items\n2. Update Items\n3. Display Items\n4. Remove Items\n5. Exit Application\n");
    printf("Enter an Option: ");
    scanf("%d", &options);
    switch (options) {
        case 1:
            add_Items(products, n);
            break;
        case 2:
            if (n == 0) {
                printf("0 Items to Update!");
                welcome(products, n);
            }else{
                update_Menu(products, n);
            }
            break;
        case 3:
            if (n == 0) {
                printf("0 Items Added\n");
                welcome(products, n);
            }else{
                display_Items(products, n);
            }
            break;
        case 4:
            printf("Remove Item is called");
            break;
        case 5:
            printf("Exiting the Application! ThankYou for Using the Application\n");
            /*return 0*/;
            break;
        default:
            printf("Invalid Operator! try again\n");
            welcome(products, n);
            break;
    }
}
// main Function Used to start the program
int main(void){
    int n = 0;
    struct Inventory products[n];
    printf("\n------------Welcome to Store-------------\n");
    welcome(products, n);
}
