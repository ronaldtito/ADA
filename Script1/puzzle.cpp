#include <iostream>
#include <vector>
#include "puzzle_1.h"
#include "puzzle_2.h"
#include "puzzle_3.h"

using namespace std;

int main()
{
    int grupos = 3;
    int test = 3;
    int n = 8;
    int x = 2;
    int y = 3;
    try{
        vector<double > tiempo;
        double avg = 0;
        for(int i = 0; i < test; i++){
            avg += (puzzle_1(n,x,y));
        }
        avg = avg/test;
        tiempo.push_back(avg);
        
        avg=0;
        for(int i = 0; i < test; i++){
            avg += (puzzle_2(n,x,y));
        }
        avg = avg/test;
        tiempo.push_back(avg);
        
        avg = 0;
        for(int i = 0; i < test; i++){
            avg += (puzzle_3(n,x,y));
        }
        avg = avg/test;
        tiempo.push_back(avg);

        for(vector<double>::iterator it=tiempo.begin(); it!= tiempo.end(); it++){
            cout<<*it<<'\t';
        }
        return 0;
    }
    catch(exception & excep){   
        cout<<"Error";
    }


    return 0;
}