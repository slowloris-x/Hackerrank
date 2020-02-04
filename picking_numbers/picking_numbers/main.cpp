//
//  main.cpp
//  picking_numbers
//
//  Created by Redouane Bouzekri on 2/3/20.
//  Copyright © 2020 Redouane Bouzekri. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <ostream>
#include <string>

using namespace std;
 


/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    sort(a.begin(), a.end());

    int result = 0;
    a.resize(6);
    for(int i = 0; i < a.size(); i++){
    cout << " " << a[i] << " " ;
    }
    cout << endl;
    for(int i = 0; i < a.size(); i++){
         int counter = 1;
        for(int j = i+1; j < a.size(); j++)
        {
            if(j != i){

                if(a[i] - a[j] == -1 || a[i] - a[j] == 0){
                    
                    counter++;
                    
                }


            }
        }
        if(counter > result){
            result = counter;
        }
    }
    return result;
}

int main()
{
   
    ofstream fout("output00.txt");

    string n_temp;
    ifstream input;
    input.open("input00.txt");
    int numbers;
    int counter = 0;
    vector<int> a;
    while(input >> numbers)
    {
        if(counter > 0){

        a.push_back(numbers);
        }
        
        counter++;
    }

    int result = pickingNumbers(a);
    fout << result << "\n";

    fout.close();

    return 0;
}
