#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> vec;

    vec.push_back(25);
    vec.push_back(5);
    vec.push_back(15);
    vec.push_back(25);
    vec.push_back(5);
    // vec.push_back(20);
    // vec.pop_back();
    cout<<"Size = "<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    // for(int val:vec){
    //     cout<<val<<" ";
    // }

    cout << vec.front()<<endl ;
    cout << vec.at(2) ;
    return 0;
}
