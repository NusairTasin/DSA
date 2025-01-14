#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *head = nullptr;
void insertAtBeginning(int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void removeDuplicates()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *curr = temp;
        while (curr->next != nullptr)
        {
            if (curr->next->data == temp->data)
            {
                Node *nudair = curr->next;
                curr->next = curr->next->next;
                delete nudair;
            }
            else
            {
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
}
void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(30);
    insertAtBeginning(20);
    removeDuplicates();
    print();
}