#include<bits/stdc++.h>
using namespace std;

#include<iostream>
using namespace std;

// print out the actual weights and their no. of instances used
// to fill the knapsack
void instancesUsed(int items[],int weights[],int capacity,int size) {
   int k = capacity;
   int instances[size];
   int i;
   for(i=0;i<size;i++)
      instances[i] = 0;
   // compute the no. of instances used for each selected item(weight)
   while(k >= 0) {
      int x = items[k];
      if(x == -1) break;
      instances[x] += 1;
      k -= weights[items[k]];
   }
   cout<<"\nInstances used :-\n";
   for(i=0;i<size;i++)
      cout<<weights[i]<<" "<<instances[i]<<endl;
}

int findMaxValue(int weight[],int values[],int items[],int n,int capacity) {
   // temporary array where index 'j' denotes max value that can be fitted
   // in a knapsack of weight 'j'
   int knapsack[capacity+1];
   knapsack[0] = 0;
   items[0] = -1;
   int i,j;
   for(j=1;j<=capacity;j++) {
      items[j] = items[j-1];
      // as per our recursive formula,
      // iterate over all weights w(0)...w(n-1)
      // and find max value that can be fitted in knapsack of weight 'j'
      int max = knapsack[j-1];
      for(i=0;i<n;i++) {
         int x = j-weight[i];
         if(x >= 0 && (knapsack[x] + values[i]) > max) {
            max = knapsack[x] + values[i];
            items[j] = i;
         }
         knapsack[j] = max;
      }
   }
   return knapsack[capacity];
}

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int l;
        scanf("%d", &l);
        int weight[l+1];
       int values[l+1];
       int capacity = l; // capacity of the knapsack
        for(int i=0; i<l; ++i)
            scanf("%d", &values[i]), weight[i] = i+1;

       int size = sizeof(weight)/sizeof(weight[0]);
       // stores the items and the no. of instances of each item
       // used to fill the knapsack
       int items[capacity+1];
       int val = findMaxValue(weight,values,items,size,capacity);
       cout<<"\nMaximum value that can be fitted :: "<<val;
       //instancesUsed(items,weight,capacity,size);
       cout<<endl;
    }

   return 0;
}
