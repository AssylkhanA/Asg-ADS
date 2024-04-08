#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//complexity O(n) , task num 1
int findMinRecursive(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int restMin = findMinRecursive(arr, n - 1);
    return (arr[n - 1] < restMin) ? arr[n - 1] : restMin;
}
//complexity O(n) task #2
double sumRecursive(int arr[], int n) {
    if (n <= 0)
        return 0;
    return arr[n - 1] + sumRecursive(arr, n - 1);
}
double findAverageRecursive(int arr[], int n) {
    double totalSum = sumRecursive(arr, n);
    return totalSum / n;
}
// Complexity O(sqrt(n)) task #3
bool isPrimeHelper(int n, int i) {
    if (n <= 2)
        return (n == 2);
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;
    return isPrimeHelper(n, i + 1);
}
bool isPrime(int n) {
    return isPrimeHelper(n, 2);
}
//complexity O(n) task #4
long long factorial(int n) { 
    if (n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 
//Complexity O(2^n) , task #5 
long long fibonacci(int n) { 
    if (n == 0) return 0; 
    if (n == 1) return 1; 
    return fibonacci(n - 1) + fibonacci(n - 2); 
} 
//Complexity O(n), task #6
long long power(int a, int n) {
    if (n == 0)
        return 1;
    // Recursive case: a^n = a * a^(n-1)
    return a * power(a, n - 1);
}
// Complexity O(n!), task #7
void swap(char &x, char &y) {
    char temp = x;
    x = y;
    y = temp;
}
void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        // Permutations made by swapping
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]);
        }
    }
}
//Complexity O(n), task #8
bool areAllDigits(const string &s, int index = 0) {
    if (index == s.size()) return true;
    if (!isdigit(s[index])) return false;
    return areAllDigits(s, index + 1);
}
//Complexity O(2^n), task #9
int binomialCoeff(int n, int a) {
    if (a == 0 || a == n)
        return 1;
    return binomialCoeff(n - 1, a - 1) + binomialCoeff(n - 1, a);
}
//Complexity O(log(min(a, b))), task #10
int gcd(int a, int n) {
    if (n == 0)
        return a;
    return gcd(n, a % n);
}

int main()
{   int taskNum = 0;
    int a,n;
    cout<<"Which task you want to check?";
    cin>>taskNum;
    if(taskNum == 1){
        cout << "Enter the number of elements: ";
        cin >> n;
        int* arr = new int[n];
        cout << "Enter " << n << " elements: ";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "The minimum element is " << findMinRecursive(arr, n) << endl;
        delete[] arr;
        return 0;
    }else if(taskNum == 2){
        cout << "Enter the number of elements: ";
        cin >> n;
        int* arr = new int[n]; 
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        double average = findAverageRecursive(arr, n);
        cout << "The average of the elements is: " << average << endl;
        delete[] arr;
        return 0;
    }else if(taskNum == 3){
        cout << "Enter the number to check: ";
        cin >> n;
        if (isPrime(n))
            cout << n << " is Prime." << endl;
        else
            cout << n << " is Composite." << endl;
        return 0;
    }else if(taskNum == 4){
        cout << "Enter a number: "; 
        cin >> n; 
        cout << "The factorial is " << factorial(n) << endl; 
        return 0; 
    }else if(taskNum == 5){
        cout << "Enter the value of n: "; 
        cin >> n; 
        cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << endl; 
        return 0;   
    }else if(taskNum == 6){
        cout << "Enter the base 'a': ";
        cin >> a;
        cout << "Enter the exponent 'n': ";
        cin >> n;
        cout << a << " raised to the power " << n << " is: " << power(a, n) << endl;
        return 0;
    }else if(taskNum == 7){
        string str;
        cout << "Enter string: ";
        cin >> str;
        permute(str, 0, str.size() - 1);
        return 0;
    }else if(taskNum == 8){
        string s;
        cout << "Enter the string: ";
        cin >> s;
        if (areAllDigits(s))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;    
    }else if(taskNum == 9){
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter a: ";
        cin >> a;
        cout << binomialCoeff(n, a) << endl;
        return 0;    
    }else if(taskNum == 10){
        cout << "Enter two numbers: ";
        cin >> a >> n;
        cout << gcd(a, n) << endl;
        return 0;
    }
    
}
