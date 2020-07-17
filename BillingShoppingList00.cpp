/*
 * Billing Shopping List Program in C++
 * Created by M.Kamaljit Singha (B.Sc CS 2nd Semester)
 * Written on Xcode Compiler
 * Tested on UNIX/LINUX system
 */
#include<iostream>//It is an Input Output Stream Header File
#include<iomanip>//It is an Input Output Manipulator Header File
#include<string>//It is a String Header File
using namespace std;//If we don’t use this line of code, then we have to write std:: cin, std::cout, std::endl, etc.
const int arr = 50;//It is a constant integer type variable name "arr" to store the size of an array
const int set = 10;//It is a constant integer type variable name "set" to store the size of field width
//Let's create a class name "ITEMS"
class ITEMS{
private://It is a private access specifier
    //These are private member data
    int itemCode[arr];//It is an integer type array name "itemCode" to store item code input by the user
    string itemName[arr];//It is a string type array name "itemName" to store item name input by the user
    float itemPrice[arr];//It is a float type array name "itemPrice" to store item price input by the user
    int count = 0;//It is used to count each block of an array
public://It is a public access specifier
    //These are public member functions
    void getitem(void){//It is a "getitem" function whose return type is void
        cout << "-------------------------------------" <<endl;//It displays all the text between the " " on the console
        cout <<setw(set)<< "> Enter item Code to add : " <<setw(set);//It displays all the text within the " " on the console
        cin >> itemCode[count];//It reads the item code from the user console input
        cout <<setw(set)<< "> Enter item Name to add : " <<setw(set);//It displays all the text within the " " on the console
        cin >> itemName[count];//It reads the item name from the user console input
        cout <<setw(set)<< "> Enter item Cost to add : " <<setw(set);//It displays all the text within the " " on the console
        cin >> itemPrice[count];//It reads the item price from the user console input
        count++;//It increments the count value by one per loop
        displayItems();//It calls the "displayItems" function to display the items input by the user
    }
    void displaySum(void){//It is a "displaySum" function whose return type is void
        float sum = 0.0;//It is a floating type variable name "sum" to store the sum of all the items price
        for(int i=0; i<count; i++)//It is a loop to compute the sum of all the items price
            sum = sum + itemPrice[i];//It adds each item price and sums up
        displayItems();//It calls the "displayItems" function to display the items input by the user
        cout << "-------------------------------------" <<endl;//It displays all the text within the " " on the console
        cout <<setw(set)<< "Total value : " <<setw(16)<<sum<<endl;//It displays all the text within the " " on the console
    }
    void remove(void){//It is a "remove" function whose return type is void
        int del;//It is an integer type variable name "del" to store the code to delete
        cout << "-------------------------------------" <<endl;//It displays all the text within the " " on the console
        cout <<setw(set)<< "> Enter item Code to delete : " <<setw(set);//It displays all the text within the " " on the console
        cin >> del;//It reads the item code from the user input
        for(int i=0; i<count; i++)//It is a loop to check the item code input by the user
            if(itemCode[i] == del)//if the item code is found
                itemPrice[i] = 0;//it would set its price to zero
        displayItems();//It calls the "displayItems" function to display the items input by the user
    }
    void displayItems(void){//It is a "displayItems" function whose return type is void
        cout << "\n\n\n-------------------------------------" <<endl;//It displays all the text within the " " on the console
        cout <<setw(set)<< "CODE" <<setw(set)<<setw(set)<< "NAME" <<setw(set)<< "PRICE" <<setw(set)<<endl<< "-------------------------------------";//It displays all the text within the " " on the console
        for(int i=0; i<count; i++){//It is a loop to display the values respectively
            cout <<endl<<setw(set)<<itemCode[i]<<setw(set);//It displays the item code
            cout <<setw(set)<<itemName[i]<<setw(set);//It displays the item name
            cout <<setw(set)<<itemPrice[i]<<setw(set);//It displays the item price
        }
        cout <<endl;//It displays a new line on the console
    }
};//"ITEMS" class closed
//Main function starts
int main(){
    ITEMS order;//"order" is the object of the class "ITEMS"
    int input;//It is a integer type variable name "input" to store the input by the user
    cout << "WELCOME TO BILLING SHOPPING LIST PROGRAM IN C++" <<endl;//It displays all the text within the " " on the console
    cout << "                         created by M. Kamaljit" <<endl;//It displays all the text within the " " on the console
    //It is a do-while loop used to execute the code while the condition satisfy
    do{
        cout << "\n\n\n-------------------------------------" <<endl;//It displays all the text within the " " on the console
        cout << "1 : Add an item.";//It displays all the text within the " " on the console
        cout << "\n2 : Display total value.";//It displays all the text within the " " on the console
        cout << "\n3 : Delete an item.";//It displays all the text within the " " on the console
        cout << "\n4 : Quit.";//It displays all the text within the " " on the console
        cout << "\n-------------------------------------" <<endl;//It displays all the text within the " " on the console
        cout <<"> Choose from (1 to 4) only."<<endl<<"> Enter an appropriate number : ";//It displays all the text within the " " on the console
        cin >> input;//It reads the input from the user console input
        //Switch case helps to switch the cases according to the input of the user, for eg. if the input is 2, it will execute case 2
        switch(input){
            case 1 : order.getitem();//It executes the "getitem" function
                break;//It breaks the case after the execution
            case 2 : order.displaySum();//It executes the "displaySum" function
                break;//It breaks the case after the execution
            case 3 : order.remove();//It executes the "remove" function
                break;//It breaks the case after the execution
            case 4 : break;//it breaks the case after the execution
            //default executes when user input do not match the above cases
            default : cout << "-------------------------------------" <<endl<< "> Error in input. Please try again.\n";//It displays all the text within the " " on the console
        }
    }while(input != 4);//It is a do-while loop condition, it is a condition set for the loop not exit. It means that this loop will run until the input is 4
    return 0;//The program returns 0
}
