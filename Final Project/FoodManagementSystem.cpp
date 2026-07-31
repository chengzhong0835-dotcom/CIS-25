#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Food
{
    int id;
    string name;
    string category;
    int quantity;
};
int binarySearch(Food foods[],int size,int searchID)
{
    int left=0;
    int right=size-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(foods[middle].id==searchID)
        {
            return middle;
        }
        if(foods[middle].id<searchID)
        {
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }
    return-1;
}
void addFood(Food foods[],int& count)
{
    if(count>=100)
    {
        cout<<"Food list is full."<<endl;
        return;
    }
    cout<<"Enter Food ID: ";
    cin>>foods[count].id;
    cout<<"Enter Food Name: ";
    cin>>foods[count].name;
    cout<<"Enter Food Category: ";
    cin>>foods[count].category;
    cout<<"Enter Food Quantity: ";
    cin>>foods[count].quantity;
    count++;
    cout<<"Food added successfully."<<endl;
}
void viewFoods(Food foods[],int count)
{
    if(count==0)
    {
        cout<<"No foods found."<<endl;
        return;
    }
    for(int i=0;i<count;i++)
    {
        cout<<"Food "<<i+1<<endl;
        cout<<"ID: "<<foods[i].id<<endl;
        cout<<"Name: "<<foods[i].name<<endl;
        cout<<"Category: "<<foods[i].category<<endl;
        cout<<"Quantity: "<<foods[i].quantity<<endl;
    }
}
void searchFood(Food foods[],int count)
{
    if(count==0)
    {
        cout<<"No foods found."<<endl;
        return;
    }
    int searchID;
    cout<<"Enter Food ID to search: ";
    cin>>searchID;
    int result=binarySearch(foods,count,searchID);
    if(result!=-1)
    {
        cout<<"Food Found"<<endl;
        cout<<"ID: "<<foods[result].id<<endl;
        cout<<"Name: "<<foods[result].name<<endl;
        cout<<"Category: "<<foods[result].category<<endl;
        cout<<"Quantity: "<<foods[result].quantity<<endl;
    }
    else
    {
        cout<<"Food not found."<<endl;
    }
}
void updateFood(Food foods[],int count)
{
    if(count==0)
    {
        cout<<"No foods found."<<endl;
        return;
    }
    int searchID;
    cout<<"Enter Food ID to update: ";
    cin>>searchID;
    int result=binarySearch(foods,count,searchID);
    if(result!=-1)
    {
        cout<<"Enter New Name: ";
        cin>>foods[result].name;
        cout<<"Enter New Category: ";
        cin>>foods[result].category;
        cout<<"Enter New Quantity: ";
        cin>>foods[result].quantity;
        cout<<"Food updated successfully."<<endl;
    }
    else
    {
        cout<<"Food not found."<<endl;
    }
}
void deleteFood(Food foods[],int& count)
{
    if(count==0)
    {
        cout<<"No foods found."<<endl;
        return;
    }
    int searchID;
    cout<<"Enter Food ID to delete: ";
    cin>>searchID;
    int result=binarySearch(foods,count,searchID);
    if(result!=-1)
    {
        for(int i=result;i<count-1;i++)
        {
            foods[i]=foods[i+1];
        }
        count--;
        cout<<"Food deleted successfully."<<endl;
    }
    else
    {
        cout<<"Food not found."<<endl;
    }
}
void viewFoodsByCategory(Food foods[], int count)
{
    string category;
    cout << "Enter Category: ";
    cin >> category;

    for(int i = 0; i < count; i++)
    {
        if(foods[i].category == category)
        {
            cout << "ID: " << foods[i].id << endl;
            cout << "Name: " << foods[i].name << endl;
            cout << "Category: " << foods[i].category << endl;
            cout << "Quantity: " << foods[i].quantity << endl;
            cout << endl;
        }
    }
}
void saveFoods(Food foods[],int count)
{
    ofstream outputFile;
    outputFile.open("final/foods.txt");
    for(int i=0;i<count;i++)
    {
        outputFile<<foods[i].id<<" "
        <<foods[i].name<<" "
        <<foods[i].category<<" "
        <<foods[i].quantity<<endl;
    }
    outputFile.close();
}
void loadFoods(Food foods[],int& count)
{
    ifstream inputFile;
    inputFile.open("final/foods.txt");
    count=0;
    while(inputFile>>foods[count].id
    >>foods[count].name
    >>foods[count].category
    >>foods[count].quantity)
    {
        count++;
        if(count==100)
        {
            break;
        }
    }
    inputFile.close();
}
int main()
{
    Food foods[100];
    int count=0;
    int choice;
    loadFoods(foods,count);
    do
    {
        cout<<endl;
        cout<<"Food Management System"<<endl;
        cout<<"1. Add Food"<<endl;
        cout<<"2. View Foods"<<endl;
        cout<<"3. Search Food"<<endl;
        cout<<"4. Update Food"<<endl;
        cout<<"5. Delete Food"<<endl;
        cout<<"6. View Foods by Category"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1)
        {
            addFood(foods,count);
            saveFoods(foods,count);
        }
        else if(choice==2)
        {
            viewFoods(foods,count);
        }
        else if(choice==3)
        {
            searchFood(foods,count);
        }
        else if(choice==4)
        {
            updateFood(foods,count);
            saveFoods(foods,count);
        }
        else if(choice==5)
        {
            deleteFood(foods,count);
            saveFoods(foods,count);
        }
        else if(choice==6)
        {
            viewFoodsByCategory(foods,count);
        }
        else if(choice==7)
        {
            saveFoods(foods,count);
            cout<<"Program ended."<<endl;
        }
        else
        {
            cout<<"Invalid choice."<<endl;
        }
    }
    while(choice!=7);
    return 0;
}