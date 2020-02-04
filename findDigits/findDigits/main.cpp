//
//  main.cpp
//  findDigits
//
//  Created by Redouane Bouzekri on 2/4/20.
//  Copyright © 2020 Redouane Bouzekri. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int power(int base, int oss){
    
    if(oss == 0){
        return 1;
    }else{
        return base * power(base, oss-1);
    }
}


int findDigits(int n) {
int counter = 0;
int result = 0;
    while(power(10,counter) <= n){

        if(n / power(10,counter) % 10 != 0 && n % (n / power(10,counter) % 10) == 0)
        {
        result++;
        }
        counter++;

    }
return result;
}

int main(int argc, const char * argv[]) {
   
    
    ofstream fout("output00.txt");


    ifstream input;
    input.open("input00.txt");
    int n;
    int counter = 0;
    while(input >> n)
    {
        if(counter > 0){
            int result = findDigits(n);
                   cout << result << "\n";
                   fout << result << "\n";
        
        }
        
        counter++;
    }
    
    fout.close();

    
    
    return 0;
}
