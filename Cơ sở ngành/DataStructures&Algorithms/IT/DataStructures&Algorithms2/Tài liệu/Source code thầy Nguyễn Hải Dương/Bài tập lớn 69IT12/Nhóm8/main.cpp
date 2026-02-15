#include <iostream>
using namespace std;

// ================= Merge Sort ( sap xep tron )=================
void tron(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm đệ quy chia mảng và gọi tron để sắp xếp trộn
void sapxepTron(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        sapxepTron(arr, left, mid);
        sapxepTron(arr, mid + 1, right);
        tron(arr, left, mid, right);
    }
}

// ================= Selection Sort ( sap xep chon ) =================
void sapXepchon(int A[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int VT_GTNN=i;
        for(int j=i+1; j<n; j++)
        {
            if(A[j]<A[VT_GTNN])
                VT_GTNN=j;
        }
        if(VT_GTNN!=i)
        {
            int temp=A[i];
            A[i]=A[VT_GTNN];
            A[VT_GTNN]=temp;
        }
    }
}

// ================= In mảng =================
void inMang(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

// ================= Main =================
int main()
{
    int n;
    cout<<"Nhap so phan tu: ";
    cin>>n;

    int *A = new int[n];
    cout<<"Nhap "<<n<<" phan tu:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Phan tu thu "<<i+1<<": ";
        cin>>A[i];
    }

    int choice;
    do
    {
        cout<<"\n==== MENU SAP XEP ====\n";
        cout<<"1. Sap xep TRON (Merge Sort)\n";
        cout<<"2. Sap xep CHON (Selection Sort)\n";
        cout<<"0. Thoat\n";
        cout<<"Nhap lua chon: ";
        cin>>choice;

        int *B = new int[n];
        for(int i=0; i<n; i++) B[i]=A[i];

        if(choice==1)
        {
            sapxepTron(B, 0, n-1);
            cout<<"Mang sau khi sap xep TRON: ";
            inMang(B,n);
        }
        else if(choice==2)
        {
            sapXepchon(B, n);
            cout<<"Mang sau khi sap xep CHON: ";
            inMang(B,n);
        }
        else if(choice!=0)
        {
            cout<<"Lua chon khong hop le!\n";
        }

        delete[] B;
    }
    while(choice!=0);

    delete[] A;
    cout<<"Da thoat chuong trinh.\n";
    return 0;
}


