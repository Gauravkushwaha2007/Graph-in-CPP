#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> check(10, 5);
    for(int val: check){
        cout<< val << " ";
    }
    return 0;
}