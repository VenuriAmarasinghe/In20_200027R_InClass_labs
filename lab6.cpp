#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;
#include <algorithm>


int stack_arr[100],n=100,top=-1; // take the array size as 100. size of stack is 100

// pop function to remove an element from the stack using array
int pop_arr(){
    if(top==-1)
        cout<<"Stack Underflow"<<endl;
    else
        top--;
        return(stack_arr[top+1]);
}

// push function to insert an element in the stack using array
void push_arr(int val){
    if(top==n-1)
        cout<<"Stack Overflow"<<endl;
    else{
        top++;
        stack_arr[top]=val;
    }
}

// display function to display the elements of the stack using array

void display_arr(){
    if(top==-1)
        cout<<"Stack is empty"<<endl;
    else{
        
        for(int i=top;i>=0;i--)
            cout<<stack_arr[i]<<" ";
        cout<<endl;
    }
}


struct Node{
    int data;
    Node *link;
};

struct linked_list{
    Node *top;
    linked_list(){
        top=NULL;
    }
    void push_link(int x){
        if (top == NULL){
            top = new Node;
            top->data = x;
            top->link = NULL;
        }
        else{
            Node *temp = new Node;
            temp->data = x;
            temp->link = top;
            top = temp;
        }
    }   

    void pop_link(){
        if (top == NULL){
            cout << "Stack is empty" << endl;
        }
        else{
            Node *temp = top;
            top = top->link;
            delete temp;
        }
    }

    void display_link(){
        if (top == NULL){
            cout << "Stack is empty" << endl;
        }
        else{
            Node *temp = top;
            while (temp != NULL){
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << endl;
        }
    }

};

   



int main(){



//measure the time taken by the array implementation of stack

int push_data_arr[30];  
for (int j = 0; j < 10; j++) {
            push_data_arr[j] = rand() % 100;
            
        }

cout<<"using array"<<endl;

//measure the time taken by the array implementation of stack in nanoseconds

auto start = std::chrono::high_resolution_clock::now();




for (int j = 0; j < 10; j++) {
            
            push_arr(push_data_arr[j]);
        }
display_arr();
for (int j = 0; j < 5; j++) {
            pop_arr();
        }
   
display_arr();
for (int j = 0; j < 20; j++) {
            push_arr(push_data_arr[j]);
            
        }

display_arr();
for (int j = 0; j < 3; j++) {
            pop_arr();
        }
display_arr();
 auto end = std::chrono::high_resolution_clock::now();
    
 std::chrono::duration<double> elapsed = end - start;
 std::cout << " time taken using array implementation: " << elapsed.count() << " seconds" << std::endl;
cout<<endl;
cout<<endl;
   



cout<<"using linked list"<<endl;


linked_list l1;
//measure the time taken by the linked list implementation of stack in nanoseconds

auto start_link = std::chrono::high_resolution_clock::now();

for (int j = 0; j < 10; j++) {
            l1.push_link(push_data_arr[j]);
        }
l1.display_link();
for (int j = 0; j < 5; j++) {
            l1.pop_link();
        }
l1.display_link();
for (int j = 0; j < 20; j++) {
            l1.push_link(push_data_arr[j]);
        }
l1.display_link();
for (int j = 0; j < 3; j++) {
            l1.pop_link();
        }
l1.display_link();
auto end_link = std::chrono::high_resolution_clock::now();
    
 std::chrono::duration<double> elapsed_link = end_link - start_link;
 std::cout << " time taken using linked list implementation: " << elapsed_link.count() << " seconds" << std::endl;






 

    
}