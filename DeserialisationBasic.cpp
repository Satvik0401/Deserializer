#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

struct TransactionIP 
{
    string add;
    uint64_t val;
};

struct TransactionOP
{
    string add;
    uint64_t val;
};


void deserialiseTransaction(const vector<uint8_t>& Arr) 
{
    vector<TransactionIP> IP;
    vector<TransactionOP> OP;
    for (int i=0;i<Arr.size();i+=64) 
    {
        TransactionIP I;
        I.add = "Input address " + to_string(i / 64);
        I.val = Arr[i];  
        IP.push_back(I);
        TransactionOP O;
        O.add = "Output address "+to_string(i / 64);
        O.val = Arr[i + 32];  
        OP.push_back(O);
    }
    cout<<"Transaction Inputs:\n";
    for (const auto I : IP) 
    {
        cout<<I.add<<endl<<"Value:"<<I.val<<endl;
    }
    cout<<"\nTransaction Outputs:\n";
    for (const auto O : OP) {
        cout<<O.add<<endl<<"Value:"<<O.val<<endl;
    }
}

int main() 
{
    vector<uint8_t> testIP = {
        10, 1, 1, 1, 1, 1, 1, 1,   
        0, 0, 0, 0, 0, 0, 0, 0,    //the first 16 bytes represent the input
        0, 0, 0, 0, 0, 0, 0, 0,     
        20, 0, 0, 0, 0, 0, 0, 0,   //the second represent the output
    };
    deserialiseTransaction(testIP);
    return 0;
}
