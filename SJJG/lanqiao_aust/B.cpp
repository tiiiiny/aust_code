#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// int two(int x){
//     while(x/2){
        
//     }
// }
// int eight(int x){

// }
int main(){
    int x[40]={393353,901440 ,123481 ,850930 ,423154 ,240461,373746 ,232926 ,396677, 486579 ,744860 ,468782,941389 ,777714, 992588 ,343292, 385198, 876426,483857 ,241899, 544851 ,647930 ,772403 ,109929,882745 ,372491, 877710 ,340000, 659788 ,658675,296521 ,491295 ,609764, 718967, 842000 ,670302};
    for(int i=0;i<36;i++){
        int count=0;
        for(int j= 1;j*j<x[i];j++)
            if(x[i]%j==0)   count++;
        
        cout<<count<<endl;
    }

    return 0;
}