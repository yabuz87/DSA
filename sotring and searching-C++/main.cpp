#include <iostream>
#include <vector>
using namespace std;

// Function declarations
void bubbleSort(int num[], int n);
void simpleSort(int num[],int n);
void insertionSort(int num[],int n);
void displayArray(int num[],int n);
void selectionSort(int num[],int n);
int linearSearch(int num[],int n,int target);
int binarySearch(int num[],int n, int target);
void searching(int num[],int n);
void sorting(int num[],int n);
void menu(int num[],int n);
void binaryInsertion(int num[],int n);

int binary(int num[],int n,int tar)
    {
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=high+low/2;
            if(num[mid]>tar)
                high=mid-1;
            if(num[mid]<tar)
                low=mid+1;
           //if(num[mid]==tar)
               // return mid;
        }
        return low;
    }
void searching(int num[],int n) {
    int searchingOption;
    cout << "The following are the Searching algorithms of Array:\n\n";
    cout << "1. Simple Searching \n2. Binary Searching\n\n0.back\n ";
    cin >> searchingOption;
    if (searchingOption == 1) {
        int target;
        cout << "Enter the number to search: ";
        cin >> target;
        int result = linearSearch(num,n, target);
        if(result != -1)
            cout << "Element found at index " << result << endl;
        else
            cout << "Element not found\n";
            displayArray(num,n);


            cout<<"\n\n 0. back";
            int i;
            cin>>i;
               if(i==0)
            {
                system("CLS");
                searching(num,n);

            }
            else
                return;
    }
    else if (searchingOption == 2) {
        int target;
        cout << "Enter the number to search: ";
        cin >> target;
        int result = binarySearch(num,n, target);

        if(result != -1)
            cout << "Element found at index " << result << endl;

        else
            cout << "Element not found\n";

            cout<<"\n\n 0. back";
            int i;
            cin>>i;
            if(i==0)
            {
                system("CLS");
                searching(num,n);
            }

            else
                return;

    }
    else if(searchingOption==0)
    {   system("CLS");
        menu(num,n);
    }
     else {
        cout << "Invalid option.\n";
    }
}

void sorting(int num[],int n) {
    int option;

    cout << "The following are typical sorting algorithms of an array:\n";
    cout << "1. Simple Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Selection Sort\n5. binarryInsertion\n0. Back\n";
    cin >> option;
    switch (option) {
        case 1:
            system("CLS");
            simpleSort(num,n);
            break;
        case 2:
            system("CLS");
            bubbleSort(num,n);
            break;
        case 3:
            system("CLS");
            insertionSort(num,n);
            break;
        case 4:
            system("CLS");
            selectionSort(num,n);
            {cout<<"\n0.back\n";

    int i;
    cin>>i;
    if(i==0)
        {
            system("CLS");
            sorting(num,n);
        }

    else
        return;}
            break;


            case 5:
            binaryInsertion(num,n);
            displayArray(num,n);
            {cout<<"\n0.back\n";

    int i;
    cin>>i;
    if(i==0)
        {
            system("CLS");
            sorting(num,n);
        }

    else
        return;}
            break;
        case 0:
            system("CLS");
            menu(num,n);
            break;

        

        default:
            cout << "Invalid option.\n";
            break;
    }
}

void menu(int num[],int n) {
    int menuOption;
    cout << "Welcome to Basics of DSA\n Here we will try to see some important algorithms\n that can be implemented on an array.\n";
    cout << "\n1. Searching\n2. Sorting\n0. Exit\n";
    cin >> menuOption;
    switch (menuOption) {
        case 1:
            system("CLS");
            searching(num,n);
            break;
        case 2:
            system("CLS");
            sorting(num,n);
            break;
        case 0:
            system("CLS");
            cout << "Thank you!\n";
            break;
        default:
            system("CLS");
            cout << "Invalid option.\n";
            break;
    }
}

int main() {
    cout << "Please give me the size of your array: ";
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the number (" << n - i << " numbers left): ";
        cin >> num[i];
    }
    system("CLS");
    menu(num,n);
    return 0;
}

void bubbleSort(int num[],int n) {
   // int n = num.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
            }
        }
    }
    displayArray(num,n);

    cout<<"\n0.back\n";
    int i;
    cin>>i;
    if(i==0)
        {
            system("CLS");
            sorting(num,n);
        }

    else
        return;
}

void selectionSort(int num[],int n) {
   // int n = num.sizeof(n;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (num[j] < num[minIdx]) {
                minIdx = j;
            }
        }
        swap(num[i], num[minIdx]);
    }
    displayArray(num,n);
    /*cout<<"\n0.back\n";
    int i;
    cin>>i;
    if(i==0)
        {
            system("CLS");
            sorting(num);
        }

    else
        return;*/

}

void simpleSort(int num[],int n) {
    //int n = num.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (num[j] < num[i]) {
                swap(num[i], num[j]);
            }
        }
    }
    displayArray(num,n);

    cout<<"\n0.back\n";
    int i;
    cin>>i;
    if(i==0)
        {
            system("CLS");
            sorting(num,n);
        }
    else
        return;

}

void insertionSort(int num[],int n) {
   // int n = num.size();[6,4,0,-1,9]
   // {4,6,0,-1,9} 1st pass
   // {}
    for (int i = 1; i < n; i++) {
        int current = num[i];
        int j = i - 1;
        while (j >= 0 && num[j] > current) {
            num[j + 1] = num[j];
            j = j - 1;
        }
        num[j + 1] = current;
    }
    displayArray(num,n);
    cout<<"\n0.back\n";
    int i;
    cin>>i;
    if(i==0)
        {
            system("CLS");
            sorting(num,n);
        }
    else
        return;
}
void binaryInsertion(int num[],int n)
{

    for(int i=1;i<n;i++)
    {

        int current=num[i];
        int j=i-1;
        int pos=binary(num,i,current);
        while(j>=pos)
        {
            num[j+1]=num[j];
            j--;

        }
        num[j+1]=current;

    }


}


int linearSearch( int num[],int n, int target) {
    //int n = num.size();
    for (int i = 0; i < n; i++) {
        if (num[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int num[],int n, int target) {

     selectionSort(num,n);
    int lower = 0;
    int upper =n - 1;
    while (lower <= upper) {
        int middle = lower + (upper - lower) / 2;
        if (num[middle] == target) {
            return middle;
        }
        if (num[middle] < target) {
            lower = middle + 1;
        } else {
            upper = middle - 1;
        }
    }
    return -1;
}




void displayArray(int num[],int n) {
    //int n = num.size();
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << "]\n";

}



