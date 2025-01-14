/*
What is Book Allocation Problem
Given an integer array called ‘pages’, where each ‘pages[i]’ represents the number of pages in the ‘i-th’ book, and a total of ‘m’ students, the objective is to allocate all the books among the students.
Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
The task is to distribute the books among ‘m’ students in such a way that the maximum number of pages assigned to any student is minimized.

Analysis

The objective is to minimize the maximum number of pages assigned to any student during the allocation process.
If the maximum number of pages assigned to a student is denoted by ‘x’, then the number of pages assigned to each student must be less than or equal to ‘x’.
It is necessary to assign at least one book to every student, meaning that no student should be left without any assigned books.
Furthermore, all books must be allocated, ensuring that no book is left unassigned.
The allocation should be done in a contiguous manner. For instance, if three books need to be allocated to a student from the ‘pages[]’ array, such as {10, 20, 30, 40}, valid allocations could be {10, 20, 30} and {20, 30, 40}. However, an allocation like {10, 30, 40} would not be valid since it is not contiguous.



*/



#include <iostream>
using namespace std;
 
 bool ifSolutionPossible(int books[],int noOfstudents,int size,int mid){
    int count=1,partition=0;
    for(int i=0;i<size;i++){
        if((partition+books[i])<=mid){
         partition+=books[i];
        }else{
            count++;
             if(count>noOfstudents || books[i]>mid){
            return false;
        }
        partition=books[i];
        }
       
    }
    return true;
}

 int bookMinAlloc(int books[],int noOfstudents,int size){
   int start=0,end=0,ans;

   for(int i=0;i<size;i++)
    end+=books[i];


   while(start<=end){
    int mid=start+(end-start)/2;
    // cout<<mid<<endl;
   
    if(ifSolutionPossible(books,noOfstudents,size,mid)){
        if(ans>mid){ans= mid;}
        end=mid-1;
    }else{
        start=mid+1;
    }
   }
   return ans;
 }



int main(){
   int books[]={10,20,30,40},size=4;
   int numberOfstudents=2;
  cout<<bookMinAlloc(books,numberOfstudents,size);
   
  return 0;
}