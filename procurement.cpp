#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include "datastructure.h"
using namespace std;

void procurement(string shopid){
  time_t tt;
  struct tm*ti;
  int number_insert;
  ofstream sfout;
  ofstream tfout;
  bool bye = false;
  string back;
  string statusfilename=shopid+"_status.txt";
  string tranfilename=shopid+"_transaction.txt";

  //Open shop status file
  sfout.open(statusfilename.c_str(), ios::app);
  if (sfout.fail()){
    cout<< "Unable to open commodity status file\n";
    exit(1);
  }
  //Open shop transaction file
  tfout.open(tranfilename.c_str(), ios::app);
  if (tfout.fail()){
    cout<< "Unable to open transaction file\n";
    exit(1);
  }



  string itemexist;
  string productid,productname,categoryname,price,manufacturer;
  int amount,sellingprice;
  while(!bye){
    system("clear");
    //allowing users to insert items information
    cout<<"Enter the number of items that you would like to insert: ";
    cin>>number_insert;
    cout << endl;
    for (int i=0;i<number_insert;++i){
      cout<<"Has the item been procured before? (Yes/No)";
      cin>>itemexist;
      cout << endl;
      cout<<"Enter Product ID (begin with ID) : ";
      cin>>productid;
      cout << endl;
      while(productid.find("ID")){            //ensure the input product ID is valid
        cout << "Please enter a vaild ID (e.g. ID00001): ";
        cin >> productid;
        cout << endl;
      }
      cout<<endl;
      cout<<"Enter Product Name: ";
      cin>>productname;
      cout<<endl;
      cout<<"Enter Category Name: ";
      cin>>categoryname;
      cout<<endl;
      cout<<"Enter Unit Price: ";
      cin>>price;
      cout<<endl;
      cout<<"Enter Amount: ";
      cin>>amount;
      cout<<endl;
      cout<<"Enter Manufacturer: ";
      cin>>manufacturer;
      cout<<endl;
      cout<<"Enter Selling Price: ";
      cin>>sellingprice;
      cout<<endl;

      if (itemexist=="No"){       //if the item has not been bought before
        //append into status file
        sfout<<productid<<"|"<<productname<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<sellingprice<<"|"<<amount<<"|IN-STOCK\n";
        time(&tt);
        ti=localtime(&tt);
        //append the procurement record into transaction file
        tfout<<productid<<"|"<<productname<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<price<<"|"<<amount<<"|"<<asctime(ti)<<'\n';
      }
      
      if (itemexist=="Yes"){     //if the item has been bought before
        time(&tt);
        ti=localtime(&tt);
        //append the procurement record into transaction file
        tfout<<productid<<"|"<<productname<<"|"<<categoryname<<"|"<<manufacturer<<"|"<<price<<"|"<<amount<<"|"<<asctime(ti)<<'\n';
        //change item amount in status.txt
        updatestatus(statusfilename,6,to_string(amount),productid);
      }
      cout << "Product is added to the inventory.\n";

    }
    cout << "Go back to main screen? (Y/N) :";
    cin >> back;
    if(back=="Y")
      bye =true;
  }

  delete ti;
  sfout.close();
  tfout.close();
}
