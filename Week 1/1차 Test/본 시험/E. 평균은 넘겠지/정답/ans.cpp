#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    int C;
    int array[1000];
    int sum;
    int N;
    
    cin >> C;
    
    for(int j = 0; j < C; j++)
    {
        cin >> N;
        sum = 0;
        
        for(int i = 0; i < N; i++)
        {
            cin >> array[i];
            sum = sum + array[i];
        }
        
        float average = sum / N;
        int count = 0;
        
        for(int i = 0; i < N; i++)
        {
           if(average < array[i])
           {
               count++;
           }
        }
        
        float rate = (float)count / N * 100;
        cout << rate << "%" << "\n";
    }
    
}