#include "datastructure.h"
#include <iostream>
#include <fstream>
#include <string>
void alert(string id,int threshold){
  if(id!="0"){
    //cout << "alert is working\n";
    string filename,line,amountstr,productid,productname;
    int count=1,amount;
    filename=id+"_status.txt";
    //cout << filename <<endl;
    ifstream file;
    file.open(filename.c_str());
    while(getline(file,line)){
      //cout << line <<endl;
      count=1;
      amount=0;
      amountstr.clear();
      productid.clear();
      productname.clear();
      for(int i=0;i<line.length();++i){
        if(line[i]=='|')
          count++;
        if(count==1)
          productid+=line[i];
        else if(count==2 && line[i]!='|')
          productname+=line[i];
        else if(count==6 && line[i]!='|')
          amountstr+=line[i];

      }
      //cout <<amountstr;
      amount=stoi(amountstr);
      if(amount<=threshold && amount!=0)
        cout<<"Product " <<productid <<'|'<<productname<<" is running out of stock with " << amount <<" left!" <<endl;
      else if (amount==0)
        cout<<"Product " <<productid <<'|'<<productname<<" ran out of stock !!"  <<endl;
    }
    file.close();
  }
}