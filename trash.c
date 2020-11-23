#include <stdio.h>

void swap(int *a, int *b)
{
    int v = *a;
    *a = *b;
    *b = v;
}

int partition(int a[],int low,int high)
{
    int pivot = a[high];
    int i = low-1;
    
    for(int j=low; j<high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap( &a[i], &a[j] );
        }
    }
    swap(&a[++i], &a[high]);
    return i;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(a, low, high);
        quicksort(a, low, pi-1);
        quicksort(a, pi+1, high);

    }
}

const char *meanVSmedian (int *a, int n)
{
    float avr=0;
    
    for(int i=0; i<n; i++) avr += a[i];
    avr /= n;
    if( avr > a[n/2] ) return "mean";
    else if(avr < a[n/2]) return "medium";
    else return "same";
    
}

int main() {
    int a[100], i,n;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    
    quicksort( a, 0, n-1);
    
    printf("%s \n",meanVSmedian(a,n));
    return 0;
}
