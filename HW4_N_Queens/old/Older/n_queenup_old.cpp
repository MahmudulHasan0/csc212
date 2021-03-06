//N Queens on N-N board Algorithm
//Have to put all N queens in a NxN grid in a way that no two queens occupy the same column
//No two Queen can be diagonal from each other
//Bascially put Queens so that no queen can kill each other in chess




/*
checkViolation(stackName, isinColArray, diagonal)
//r1: start first row in 1...pushed
    prev = 1
    next = 1


//r2
    CHECK VIOLATIONS:
        next to 1 - violation go next (same row)
        next to 2 - violation go next (diagonal)
        next to 3 - ok........pushed
    PUSHED: r2
        prev = r2_pos
        next = 1
/r3:
    CHECK VIOLATIONS:
        next to 1 - violation(same row as r1)
        next to 2 - violation go next (diagonal of r2)
        next to 3 - violation go next (same row of r2)
        next to 4 - violation go next (diagonal of r2)
    need to pop r2.
//back to r2:
    POPPED: r2
        prev = r1_pos
        next = r2_pos


*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//void int_to_row
void print(stack<int> s, const int size)
{
    cout<<endl;
    int arr [size];
    int i = size;
    while(!s.empty())
    {    
        arr[i] = s.top();
        s.pop();   
        
        for (int j = 1; j<=size; j++)
        {
            if (j==arr[i])
                cout<<"x";
            else
                cout<<".";
            cout<<" ";
        }cout<<"                     ..."<<arr[i]<<endl; 
        cout<<endl;
    }
}











int main()
{ 
    //Possible Positions: 1,2,3,4. Out Of Zones: 0 and 5
    stack <int> queenPos;  
    const int QUEEN = 5;    //QUEEN is the number of queens. Board is also QUEENxQUEEN  
    int N = QUEEN;          //Number of queens left to do in board
    int nextPos = 1;
    int prevPos = 1; 
    

    //Setting column Array to avoid putting 2 queens in same column
    bool usedCol [QUEEN+6]; //0,1,2,3,4,5. 0 and 5 are outofzone columns
    for (int i = 0; i<=QUEEN+1; i++)
        usedCol[i] = false;

    queenPos.push(nextPos);
    usedCol[nextPos] = true;

    cout<<"\nN: "<<N<<"    pn: "<<prevPos<<"  "<<nextPos<<"        tst: "<<(prevPos==nextPos)<<"   "<<(prevPos==nextPos+1)<<"   "<<(prevPos==nextPos-1)<<"   "<< (usedCol[nextPos])<<"       ";
        cout<<"        true: "<<(prevPos==nextPos || prevPos==nextPos+1 || prevPos==nextPos-1 || usedCol[prevPos])<<"       nextPos: "<<nextPos<<"\nBEGIN:"<<endl;
    
    prevPos = nextPos;
    nextPos = 1;
    N--;
    
    int counter = 0; //to know that the next queen been through all positions and couldnt find a good one so need to chage last queen
    while(N>=0)  //Already did one queen. 3 queens left. stop when N=0 because all quens are in board
    { 
        // if (nextPos > QUEEN)
        //     //cout<<"\nactivated QUEEN to 1\n";
        //     nextPos = 1; 
        
        // if (nextPos == 0)
        //     //cout<<"\nactivated o to 1\n";
        //     nextPos = 1;
        
        cout<<"\nN: "<<N<<"    pn: "<<prevPos<<"  "<<nextPos<<"        tst: "<<(prevPos==nextPos)<<"   "<<(prevPos==nextPos+1)<<"   "<<(prevPos==nextPos-1)<<"   "<< (usedCol[prevPos])<<"       ";
        cout<<"        true: "<<(prevPos==nextPos || prevPos==nextPos+1 || prevPos==nextPos-1 || usedCol[prevPos]);
     
     //IF NEXT POS VIOLATE RULES, SHIFT IT BY 1
        if (prevPos==nextPos || prevPos==nextPos+1 || prevPos==nextPos-1 || usedCol[nextPos]) 
        {
            nextPos++;
            counter++;
            cout<<"    counter: "<<counter;
        
        //IF U CANT DO ANYTHING, SHIFT THE LAST QUEEN
            if (counter >= 4)
            { //ex: [1,4,2,cantdo]
                int lastQueen = queenPos.top(); 
                queenPos.pop();             //[1,4]
                int secLastQueen = queenPos.top();
                N--;
                usedCol[lastQueen] = false; //resetting the column (popped)
                lastQueen++;                //moving up the 1nd queen to 2th position  
                usedCol[lastQueen] = true;  //pretendign as if this postion is filled for testing, will be false if it cant work

                cout<<"\nmain_usedCol: ";
                for (int i = 1; i<=QUEEN; i++)
                    cout<<usedCol[i]<<" ";
                cout<<"     "<<lastQueen;
                
            //CAN I SHIFT THE LAST QUEEN WITHOUT ISSE?: (3)
            //(1) TEST TO SEE IF ITS NEAR ANY OTHER QUEENS OR IS IN THE SAME COLUMN OR IS IN THE FORBIDEN ZONE
                cout<<"\nTest: "<< (secLastQueen!=lastQueen && secLastQueen+1!=lastQueen && secLastQueen-1!=lastQueen && !usedCol[lastQueen] && lastQueen!=0 && lastQueen!=QUEEN+1);
                if (secLastQueen!=lastQueen && secLastQueen+1!=lastQueen && secLastQueen-1!=lastQueen && !usedCol[lastQueen] && lastQueen!=0 && lastQueen!=QUEEN+1)
                {   //ex: Original: [1,3, cant do] --> pop: [1] --> increment: 3-->4 
                    cout<<"\nSHIFTED LAST QUEEN: "<<QUEEN-queenPos.size()<<" from position "<<lastQueen-1<<" to "<<lastQueen<< "   :)"<<endl;
                    queenPos.push(lastQueen); //now stack is: [1,4] now can search for 3rd queen
                    N++;
                    prevPos = lastQueen;
                    nextPos = 1; //resettinG search 
                    counter = 0;
                }
            //(2) TEST EASY PASS: ONLY ONE QUEEN IS LEFT:  no need to test, just shift:
                else if (queenPos.size()==0) 
                {   //ex: Original: [2] --> pop: [] --> increment: 2-->3 
                    cout<<"\nSHIFTED LAST QUEEN: "<<QUEEN-queenPos.size()+1<<" from position "<<lastQueen<<" to "<<lastQueen<< "    elseif"<<endl;
                    queenPos.push(lastQueen); //now stack is: [2] now cna search for 3rd queen
                    prevPos = lastQueen;
                    nextPos = 1; //resettinG search 
                    counter = 0;
                }
            //(30 CANT MOVE THE LAST QUEEN, POP THE QUEEN BEFORE THAT
                //do nothing because it will redo the loop  
                else
                    cout<<"\nelsed stack: ";
                    usedCol[lastQueen] = false; //since i used this for test an didnt push anythign to this location, put this back to 0;   
                    lastQueen = queenPos.top();
                    queenPos.pop();
                    usedCol[lastQueen]=false;
                    lastQueen++;
                    queenPos.push(lastQueen);
                    usedCol[lastQueen] = true;
                    N++;
                    prevPos = lastQueen;
                    nextPos = 1; //resettinG search 
                    counter = 0;    
            } 
        }
        else
        {
            cout<<"       "<<QUEEN-queenPos.size()<<" nextPos: "<<nextPos<<endl;
            queenPos.push(nextPos);
            usedCol[nextPos] = true;

            cout<<"usedCol: ";
            for (int i = 1; i<=QUEEN; i++)
                cout<<usedCol[i]<<" ";
            cout<<"     ";

            prevPos = nextPos;
            nextPos = 1;
            N--;
            counter = 0;
        }        
    }
    cout<<endl;
    print(queenPos, QUEEN);
    return 0;
}




