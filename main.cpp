#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
string to_bin(int a){
    string temp="";
    if(!a)
        return string("0");
    int d;
    while(a){
        d=a%2;
        if(d){
            temp="1"+temp;
        }else{
            temp="0"+temp;
        }
        a/=2;
    }
    return temp;
}
class object{
public:
    int value;
    int volumne;
    object(){}
    object(int val,int vol) : value(val),volumne(vol){}
    void SetValue(int v){
        this->value=v;
    }
    void SetVolumne(int v){
        this->volumne=v;
    }
    int GetValue(){
        return this->value;
    }
    int GetVolumne(){
        return this->volumne;
    }
};
int main(){
    const int size=4;
    object objs[size];
    //new
    int minimum_vol=0;
    //end new
    for(int i=0;i<size;i++){
        cout<<"Enter value for "<<i<<" th object : ";
        cin>>objs[i].value;
        cout<<"Enter volumne for "<<i<<" th object : ";
        cin>>objs[i].volumne;
        if(objs[i].volumne < minimum_vol)
            minimum_vol = objs[i].volumne;
    }
    int knapsack_vol;
    int total_vol,total_val;
    string BinaryEquivalent,best="";
    int best_val=0;
    cout<<"Enter knapsack volumne : ";
    cin>>knapsack_vol;
    for(int i=/*ceil(log2(knapsack_vol))*/pow(2,size)-1;i>=0;i--){
        total_val=0;
        total_vol=0;
        BinaryEquivalent=to_bin(i);
        //new
        size_t n = std::count(BinaryEquivalent.begin(),BinaryEquivalent.end(),'1');
        if(n==1)
            continue;
        //end new
        for(int j=0;j<(int)BinaryEquivalent.size();j++){
            if(BinaryEquivalent[j]=='1'){
                total_val+=objs[j].value;
                total_vol+=objs[j].volumne;
            }
        }
        if(total_vol > knapsack_vol)
            continue;
        if(best == ""){
            best = BinaryEquivalent;
            best_val = total_val;
            continue;
        }
        if(total_val > best_val){
            best = BinaryEquivalent;
            best_val = total_val;
        }
    }
    cout<<best<<endl;
    return 0;
}
