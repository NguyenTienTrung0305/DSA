#include <bits/stdc++.h>
using namespace std;

map<int , pair<string , string>> student;

void insert(int id , string Name , string Class){
    student[id] = {Name , Class};
}

void deleteID(int id){
    student[id].first = "\0";
    student[id].second = "\0";
}

void infor(int id){
    if (!student.count(id)){
        cout << "NA,NA";
    }else{
        cout << student[id].first << "," << student[id].second;
    }
}

int main(){
    insert(1 , "Trung" ,"CACLC1");
    infor(1);
}