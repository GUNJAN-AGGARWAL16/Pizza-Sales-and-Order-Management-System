#include<bits/stdc++.h>
using namespace std;
struct node{
int set;
node *next;
};
class Queue{
private:
node *front, *rear; 
double totalSales;
public:
Queue(){
front=rear=NULL;
totalSales=0;
}
void buy(int);
void track(string (*itemName) [2]) ;
void manageOrder();
void display();
void viewStock(int, int, int, int, string (*itemName) [2]); 
void sales(double);
void displaySales();
};
void Queue::buy(int x){
node *order=new node;
order->set=x;
order->next=NULL;
if(front==NULL){
front=rear=order;
}
else{
rear->next=order;
rear=order;
}
}
void Queue::track(string itemName[][2]){
cout << "\n\t>>>> TRACK ORDER <<<" << endl ;
node *order=front;
if((front==NULL)&&(rear==NULL)){
cout<<"\tDo not have any order."<<endl;
}
cout << "\n\tCurrent order: " << endl ;
while(order!=NULL){
if(order->set==1){
cout << "\n\t --------------Set 1---------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[0][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[0][1]<<"|"<<endl;
cout << "\t ----------------------------------"<<endl;
}
if(order->set==2){
cout << "\n\t -------------Set 2----------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[1][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[1][1]<<"|"<<endl;
cout << "\t ----------------------------------"<<endl;
}
if(order->set==3){
cout << "\n\t ---------------Set 3--------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[2][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[2][1]<<"|"<<endl;
cout << "\t ----------------------------------"<<endl;
}
if(order->set==4){
cout << "\n\t -------------Set 4----------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[3][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[3][1]<<"|"<<endl;
cout << "\t ----------------------------------"<<endl;
}
order = order->next;
}
}
void Queue::manageOrder(){
char decision;
if(front==NULL){
cout<<"\tAll order complete."<<endl;
}
else
{
cout<<"\n\tDo you want to remove first order? [Y/N]: ";
cin>>decision;
if(decision == 'Y' || decision == 'y')
{
cout<<"\t("<<front->set<<") is remove from queue."<<endl;
if(front==rear)
front=rear=NULL;
else
front=front->next;
Queue::display();
}
else if(decision == 'N' || decision == 'n')
{
Queue::display();
}
else
{
cout << "ERROR! Wrong input." << endl ;
Queue::display();
}
}
}
void Queue::display(){
if(front==NULL){
cout<<"\tNo order to complete."<<endl<<endl;
}
else{
cout<<"\n\tCurrent ongoing order to finish: "<<endl;
node *order=front;
while(order){
cout<< "\t[" << order->set << "] -->";
order=order->next;
}
cout<<endl;
}
}
void updateStock(int& newStock1, int& newStock2, int& newStock3, int& newStock4){
char confirmEdit;
int updateSetStock, addSet1, addSet2, addSet3, addSet4 ;
 cout << "\t------------------" << endl ;
cout << "\t| UPDATE STOCK |" << endl ;
cout << "\t------------------" << endl ;
Question1:
cout<<"\n\tWhich set are you going to update stock ? -> ";
 cin>>updateSetStock;
 if(updateSetStock==1){
cout<<"\tSet "<<updateSetStock<<endl;
 cin.ignore();
 cout<<"\tRestock : ";
 cin >> addSet1 ;
 newStock1 = addSet1+newStock1;
}
else if(updateSetStock==2){
cout<<"\tSet "<<updateSetStock<<endl;
 cin.ignore();
 cout<<"\tRestock : ";
 cin >> addSet2 ;
 newStock2 = addSet2+newStock2;
}
 else if(updateSetStock==3){
cout<<"\tSet "<<updateSetStock<<endl;
 cin.ignore();
 cout<<"\tRestock : ";
 cin >> addSet3 ;
 newStock3 = addSet3+newStock3;
}
 else if(updateSetStock==4){
cout<<"\tSet "<<updateSetStock<<endl;
 cin.ignore();
 cout<<"\tRestock : ";
 cin >> addSet4 ;
 newStock4 = addSet4+newStock4;
}
 else {
 cout<<"\tINVALID! Try again.\n";
 goto Question1;
 }
 Question2:
 cout<<"\tAre you done updating the stock? (Yes-Y / No-N) -> ";
 cin>>confirmEdit;
 if (confirmEdit=='N'||confirmEdit=='n')
 goto Question1;
 else if (confirmEdit=='Y'||confirmEdit=='y') {
 cout<<"\tMenu is updated!\n\n";
 }
 else {
 cout<<"\tINVALID! Try again.\n";
 goto Question2;
 }
 }
void Queue::viewStock(int currentStock1, int currentStock2, int currentStock3, int
currentStock4, string itemName[][2]){
cout << "\n\t>>>> VIEW STOCK <<<" << endl ;
cout << "\n\t --------------Set 1---------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[0][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[0][1]<<"|"<<endl;
cout << "\t| Stock : "<<currentStock1<<" |"<<endl;
cout << "\t ----------------------------------"<<endl;
cout << "\n\t -------------Set 2----------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[1][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[1][1]<<"|"<<endl;
cout << "\t| Stock : "<<currentStock2<<" |"<<endl;
cout << "\t ----------------------------------"<<endl;
cout << "\n\t ---------------Set 3--------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[2][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[2][1]<<"|"<<endl;
cout << "\t| Stock : "<<currentStock3<<" |"<<endl;
cout << "\t ----------------------------------"<<endl;
cout << "\n\t -------------Set 4----------------"<<endl;
cout << "\t| Pizza : "<<left<<setw(25)<<itemName[3][0]<<"|"<<endl;
cout << "\t| Drink : "<<left<<setw(25)<<itemName[3][1]<<"|"<<endl;
cout << "\t| Stock : "<<currentStock4<<" |"<<endl;
cout << "\t ----------------------------------"<<endl;
}
void Queue::sales(double s){
totalSales=totalSales+s;
}
void Queue::displaySales(){
if(totalSales!=0)
cout<<"\n\tTotal sales for the whole day is: "<<totalSales<<endl;
else
cout<<"\n\tThere is no sales for today"<<endl;
}
int main(){
Queue order;
int x,ch1,ch2,pin;
char custStaff,receipt, ans;
double sales=0;
char menuOption, confirmEdit;
 int editOption;
double payment, balance;
int currentStock1=10;
int currentStock2=20;
int currentStock3=30;
int currentStock4=40;
int qty1;
string itemName[4][2]={{"Peppy Paneer Pizza" , "Coca-cola"},
 {"Cheese N Corn Pizza", "Pepsi"},
 {"Achari Do Pyaza Pizza", "Fanta"},
 {"Spicy Pasta Pizza" , "Maaza"}};
 double setPrice[4]= {190, 149, 210, 250};
system("cls");
cout << "\n\t<<<<<<<<<< PIZZA SALES & ORDER MANAGEMENT SYSTEM >>>>>>>>>>" << endl ;
cout << "\n\t\t\t Welcome to Pizza World" << endl ;
starting:
cout << "\n\n\n\t\tLogin as : " << endl ;
cout << "\t\t\t(A) => Customer " << endl ;
cout << "\t\t\t(B) => Staff " << endl ;
cout << "\t\t\t(C) => End System " <<endl ;
cout << "\n\t\t\tChoice: " ;
cin >> custStaff ;
if(custStaff=='A'||custStaff=='a'){
system("cls");
CustomerMainMenu :
 cout << "\n\t----------------------" << endl ;
cout << "\t CUSTOMER MAIN MENU " << endl ;
cout << "\t----------------------" << endl ;
cout<<"\n\t1) View menu "<<endl;
cout<<"\t2) Buy pizza "<<endl;
cout<<"\t3) Track order "<<endl;
cout<<"\t4) Exit" <<endl;
cout<<"\n\tEnter your choice: ";
cin>>ch1;
switch(ch1){
case 1: 
system("cls");
 cout << "\n\t--------------------------------------------------------------------------"<<endl;
 cout << "\t|                             Pizza World - Menu                           |"<<endl;
 cout << "\t --------------------------------------------------------------------------"<<endl;
 cout << "\n\t --------------Set 1---------------\t -------------Set2----------------"<<endl;
 cout << "\t| Pizza : "<<left<<setw(25)<<itemName[0][0]<<" |\t|"<<" Pizza : "<<left<<setw(25)<<itemName[1][0]<<"|"<<endl;
 cout << "\t| Drink : "<<left<<setw(25)<<itemName[0][1]<<" |\t|"<<" Drink : "<<left<<setw(25)<<itemName[1][1]<<"|"<<endl;
 cout << "\t| Price : Rs. "<<left<<setw(22)<<setPrice[0]<<"|\t|"<<" Price : Rs. "<<left<<setw(22)<<setPrice[1]<<"|"<<endl;
 cout << "\t ----------------------------------\t ----------------------------------"<<endl;
 cout << "\n\t ---------------Set 3--------------\t -------------Set4----------------"<<endl;
 cout << "\t| Pizza : "<<left<<setw(25)<<itemName[2][0]<<" |\t|"<<" Pizza : "<<left<<setw(25)<<itemName[3][0]<<"|"<<endl;
 cout << "\t| Drink : "<<left<<setw(25)<<itemName[2][1]<<" |\t|"<<" Drink : "<<left<<setw(25)<<itemName[3][1]<<"|"<<endl;
 cout << "\t| Price : Rs. "<<left<<setw(22)<<setPrice[2]<<"|\t|"<<" Price : Rs. "<<left<<setw(22)<<setPrice[3]<<"|"<<endl;
 cout << "\t ----------------------------------\t ----------------------------------"<<endl;
 cout << endl ;
goto CustomerMainMenu ;
break;
case 2:
system("cls");
 cout << "\t---------------" << endl ;
cout << "\t| BUY PIZZA |" << endl ;
cout << "\t---------------" << endl ;
choose:
cout << "\n\tChoose set : " ;
cin >> x ;
order.buy(x);
if (x<=4&&x>0) {
cout << "\tQuantity : " ;
cin >> qty1 ;
cout << endl ;
cout << "\tYou pick Set => " << endl ;
cout << "\n\t --------------Set "<<x<<"---------------"<<endl;
cout << "\t| Pizza :"<<left<<setw(25)<<itemName[x-1][0]<<"|"<<endl;
cout << "\t| Drink :"<<left<<setw(25)<<itemName[x-1][1]<<"|"<<endl;
cout << "\t| Price :"<<left<<setw(22)<<setPrice[x-1]<<"|"<<endl;
cout << "\t ----------------------------------"<<endl;
cout << endl ;
cout << fixed << showpoint << setprecision(2);
cout << "\tQuantity : " << qty1 << endl ;
currentStock1 = currentStock1 - qty1 ;
cout << "\tTotal price : Rs. " << (setPrice[x-1]*qty1) <<
endl ;
 sales=(setPrice[x-1]*qty1);
order.sales(sales);
do {
cout << "\n\tPlease make your payment : Rs. " ;
cin >> payment ;
if(payment >= (setPrice[x-1]*qty1))
{
balance = payment - (setPrice[x-1]*qty1) ;
cout << fixed << showpoint <<
setprecision(2) ;
cout << "\tYour balance is : Rs. " <<
balance << endl << endl ;
}
else
{
cout << "\tPayment not enough! " << endl ;
}
}
while (payment < (setPrice[x-1]*qty1)) ;
p :
cout << "\tDo you want to print receipt [Y/N] ?: ";
cin >> receipt ;
if (receipt == 'Y' || receipt == 'y'){
system("cls") ;
cout << "\n\t\t\t-------------------------------------------------"<<endl;
cout << "\t\t\t| Pizza World|"<<endl;
cout << "\t\t\t-------------------------------------------------"<<endl;
cout << endl;
cout << "\t\t\t Tel : 03-4961289 Fax :012-3456789" << endl;
cout << "\t\t\t Bill : R2402 Order :M43851259" << endl;
cout << endl;
cout << "\t\t\t Cashier : Gunjan Aggarwal" << endl;
cout << "\t\t\t Shift : SHIFT-01" << endl;
cout << "\n\t\t\t----------------------------------------------------"<<endl;
cout << "\t\t\t| Description Qty Price Amount (Rs.) |"<<endl;
cout << "\t\t\t----------------------------------------------------"<<endl;
cout << "\t\t\t Set "<< x << " " <<
qty1 << " " << setPrice[x-1] << " " << setPrice[x-1]*qty1 << " " << endl;
cout << " " <<
endl;
cout << "\t\t\t Total " <<"" << setPrice[x-1]*qty1 << endl;
cout << "\t\t\t Cash " << "" << payment << endl;
cout << "\t\t\t Balance " << "" << balance << endl;
cout << "\t\t\t----------------------------------------------------" << endl;
}
else if (receipt == 'N' || receipt == 'n')
{
goto submenu ;
}
else
{
cout << "\tERROR! You enter wrong input."
<< endl ;
goto p ;
} }
else {
cout << "\tSORRY. Set Not Available!" << endl ;
goto choose ;
}
submenu :
cout << endl ;
cout << "\tDo you want order again ? [Y/N]: ";
cin >> ans ;
switch (ans)
{
case 'Y' :
case 'y' :
goto choose;
break ;
case 'N' :
case 'n' :
cout << endl ;
cout << "\t>>Thank you for ordering! <<" << endl ;
cout << endl ;
goto
CustomerMainMenu;
break;
default :
cout <<"\n\tERROR! Wrong input. " << endl ;
goto submenu;
break ;
}
break;
case 3:
order.track(itemName);
goto CustomerMainMenu ;
break;
case 4: 
goto starting;
break;
default:
return 0;
}
}
else if(custStaff=='B'||custStaff=='b'){
system("cls");
PinNum:
cout<<"\n\tEnter pin: ";
cin>>pin;
if(pin==2022){
StaffMenu:
cout<<"\n\n\t-------------------"<<endl;
cout<<"\t STAFF MAIN MENU "<<endl;
cout<<"\t-------------------"<<endl;
cout<<"\n\t1) Edit Menu"<<endl;
cout<<"\t2) Manage Order"<<endl;
cout<<"\t3) Track Order"<<endl;
cout<<"\t4) View Stock"<<endl;
cout<<"\t5) Update Stock"<<endl;
cout<<"\t6) View sales"<<endl;
cout<<"\t7) Exit"<<endl;
cout<<"\n\tEnter your choice: ";
cin>>ch2;
switch(ch2){
case 1:
staffWorkOnMenu:
 cout << "\t-----------------" << endl ;
 cout << "\t| EDIT MENU |" << endl ;
 cout << "\t-----------------" << endl ;
 cout<<"\tEdit item => (E)\n";
 cout<<"\tView current menu => (V)\n";
 cout<<"\tBack to main => (B)\n";
 cout<<"\n\tWhat are you going to do? -> ";
 cin>>menuOption;
 cout<<endl;
 if (menuOption=='e'||menuOption=='E') {
 system("cls");
 cout << "\t---------------" << endl ;
 cout << "\t| EDIT ITEM |" << endl ;
 cout << "\t---------------" << endl ;
 Question1:
 cout<<"\n\tWhich set are you going to edit? -> ";
 cin>>editOption;
 if (editOption<=4&&editOption>0) {
 cout<<"\tSet "<<editOption<<endl;
 cin.ignore();
 cout<<"\tPizza : ";
 getline(cin, itemName[editOption-1][0]);
 cout<<"\tDrink : ";
 getline(cin, itemName[editOption-1][1]);
 cout<<"\tPrice : Rs. "; cin>>setPrice[editOption-1];
 cout<<endl;
 }
 else {
 cout<<"\tINVALID! Try again.\n";
 goto Question1;
 }
 Question2:
 cout<<"\tAre you done editing the menu? (Yes-Y / No-N) -> ";
 cin>>confirmEdit;
 if (confirmEdit=='N'||confirmEdit=='n')
 goto Question1;
 else if (confirmEdit=='Y'||confirmEdit=='y') {
 cout<<"\tMenu is updated!\n\n";
 goto staffWorkOnMenu;
 }
 else {
 cout<<"\tINVALID! Try again.\n";
 goto Question2;
 }
 }
 else if (menuOption=='v'||menuOption=='V') {
 system("cls");
 cout << "\t-----------------------" << endl ;
 cout << "\t| VIEW CURRENT MENU |" << endl ;
 cout << "\t-----------------------" << endl ;
 for(int i=0; i<4; i++) {
 cout<<"\tSet "<<i+1<<endl;
 cout<<"\tPizza : "<<itemName[i][0]<<endl;
 cout<<"\tDrink : "<<itemName[i][1]<<endl;
 cout<<"\tPrice : "<<setPrice[i]<<endl;
 cout<<endl;
 }
 goto staffWorkOnMenu;
 }
 else if (menuOption=='b'||menuOption=='B') {
goto StaffMenu;
 }
 else {
 cout<<"\tINVALID! Try again.\n";
 goto staffWorkOnMenu;
 }
goto StaffMenu;
break;
case 2:
order.display();
order.manageOrder();
goto StaffMenu;
break;
case 3:
order.track(itemName);
goto StaffMenu;
case 4:
order.viewStock(currentStock1, currentStock2, currentStock3,
currentStock4, itemName);
goto StaffMenu ;
break;
case 5:
updateStock(currentStock1, currentStock2, currentStock3,
currentStock4);
goto StaffMenu;
break;
case 6:
order.displaySales(); 
goto StaffMenu;
break;
case 7:
cout << "\tThank you! Happy working." << endl ;
goto starting;
break;
default:
return 0;
}
}
else
{
cout << "\tERROR! Wrong pin. "<< endl ;
goto PinNum ;
}
}
else if(custStaff=='C'||custStaff=='c'){
return 0;
}
else
{
cout << "\n\tERROR! Wrong input." << endl << endl ;
goto starting;
}
}
