#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    while(cin >> num) {
        numbers.push_back(num);
        int i = numbers.size()-1;
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    
        int size = numbers.size();
        double median;
        if(size % 2 == 1) {
            median = numbers[size / 2];
        } else {
            median = (double)(numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
        }

        cout<<"[";
        for(int i = 0; i < size-1; i++) {
            cout << numbers[i] <<",";
        }
        cout<<numbers[size-1];
        cout <<"] median:"<< fixed << setprecision(1) << median << endl;
    }

    return 0;
}
