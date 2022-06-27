#include<iostream>
using namespace std;


void find_max_min(int *ary, int start, int end, int *min, int *max){

 ///ary contains 1 element
   if(start == end){
    *max = ary[start];
    *min = ary[start];
   }


   else if(end - start == 1){ ///array contains 2 elements.
       if(ary[start] < ary[end]){
           *max = ary[end];
           *min = ary[start];
       }
       else{
           *max = ary[start];
           *min = ary[end];
       }
   }



   else{

       int mid, max1, min1;
       max1 = ary[0]; ///considering the first value as max
       min1 = ary[0]; ///considering the first value as min

       ///calculating the mid of array.
       mid = (start + end)/2;
       ///left recursion.
       find_max_min(ary, start, mid, min, max);
       ///right recursion.
       find_max_min(ary, mid+1, end, &min1, &max1);

 ///comparing max min from both recustions results.
       if(max1 > *max)
            *max = max1;
       if(min1 < *min)
            *min = min1;
   }


}


int main(){
    int ary[] = {11, 9, 10, 25, 8, 15, 4, 13, 2};
    int length = sizeof(ary) / sizeof(ary[0]); ///total array size / size of first element.
    int max, min;
    max = min = ary[0];  ///considering the first value as max and min.

    ///printing the array.
    cout << "The given array: ";
    for(int n: ary)
     cout << n << " ";

    find_max_min(ary, 0, length-1, &min, &max);  ///calling function max_min()
    cout<<"\n\n Maximum element in the array is "<<max;  ///Printing max value
    cout<<"\n Minimum element in the array is "<<min;  ///Printing min value

    return 0;
}
