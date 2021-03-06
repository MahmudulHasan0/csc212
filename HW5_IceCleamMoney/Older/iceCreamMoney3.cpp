/*
Queue Applications: Scheduling/Resource allocatioN
Check if Xavier can give change to every person in the queue

Customers are standing in a queue waiting to buy an ice-cream from Xavier which costs 2. 
The possible currencies are $1, $5, $10, and $20. 
Initially, Xavier has no money. 
Check if Xavier will be able to provide change to every person waiting to buy an ice-cream.

queue of customers, each buying one $2 ice cream
queue stores how much the customer pays
print out:
    - the index of the customer Xavier can't refund and Xavier's revenue
    - "Every customer refunded" + Xavier's revenue, did he make and money
Modification: also let customers buy more than one ice cream, Xavier has 100 in stock
    - the index of the customer Xavier is sold out at
    - how many Xavier has left after there are no more customers
Modification two: average
    - ice creames sold
    - revenue
*/
#include <string>
#include <iostream>
#include <queue>
#include <cstdlib> 
#include <map>
using namespace std;
struct money{       //didnt use clas to not overload + operator. structs are light weight clases (we dont have any functions)
    int value;      //1,5,10,20
    string name;   //one,five,ten,twenty dollar bill 
};







//ned to create bils which ar eonly one dollar, 5,10,20




















int main()
{
    queue<int> client;  //clients in the line
    int money = 0;      //starting out with no money
    // int* clientIndex;
    // clientIndex = new int(50); 
    int clientIndex[50]; 
    for (int i=0;i<10;i++)
    {
        //SET UP THE LINE
        money cash;
        cash.value = rand() % 20+ 1;   //generate a random number from $1 to $20
        client.push(clientMoney);             //makeing a line with everyones money on hand  
        clientIndex[i] = client.front();
        cout << "client: "<< i <<"   $"<<clientMoney<< endl;  
    }
    int i=0;
    while (!client.empty())
    {
        //CHECK IF YOU CAN PAY THE GUY OR NOT
        int change = client.front()-2;
        money = money + change;
        if (change > money)//if i dont have change  
        {
            cout<<"cant pay client #"<<i<<endl;
            client.pop();
        }
        else if (change <= money)   //if i do have change,  
        {
            money = money + 2;
            cout<<"paid client #"<<i<<endl;
            client.pop();
        }
        i++;
    }
}

    //     //cout << "client: "<< i <<"   $"<<clientMoney<< endl; 
    //     //do a map of client number and money#****************************************
    //     line[i] = clientMoney;
    //     client.push(clientMoney);
    // }
    // for(int i = 0; i<=100; i++){
    //     int cashBack = 2-client.front(); //client buys one icecream. 
    //     client.pop();
    // }
// }


/*
#include <string>
#include <iterator>
 

map<int, int>::iterator serachByValue(map<int, int> &mapN, int val)
{
    // Iterate through all elements in std::map and search for the passed element
    map<int, int>::iterator key = client.begin();
    while(key) != mapN.end())
    {
        if(key->second == val)
        return key;
        key++;
    }
}

  


int main()
{
    
      map<int,int> m;
      m[1] = 2;
      m[3] = 4;
      m[5] = 6;
       map<int, int>::iterator it = serachByValue(m, 3);
    if(it != m.end())
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
 

      
    return 0;
}
*/