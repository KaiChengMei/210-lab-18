// COMSC-210 | Lab 18 | Kai-Cheng Mei
#include <iostream>
#include <string>
using namespace std;

struct Review {
    float rating;
    string comments;
    Review *next;

    Review(float r, string c) : rating(r), comments(c), next(nullptr) {}
};

void addToFront(Review *&head, float rating, string comments);
void addToTail(Review *&head, float rating, string comments);
void Output(Review *head);


int main() {
    Review *head = nullptr;
    int enter;
    char yn;
    float rating;
    string comments;
    float sum = 0;  
    int reviewCount = 0;  

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    cin >> enter;

    do {
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();  
        cout << "Enter review comments: ";
        getline(cin, comments);
        if (enter == 1) {
            addToFront(head, rating, comments);
        } else if (enter == 2) {
            addToTail(head, rating, comments);
        }

        sum += rating;
        reviewCount++;


        cout << "Enter another review? Y/N: ";
        cin >> yn;

    } while (yn == 'y' || yn == 'Y');

    // output
    cout << "Outputting all reviews:\n";
    Output(head);
    // claculate avg
    if (reviewCount > 0) {
        float average = sum / reviewCount;
        cout << "    > Average: " << average << endl;
    } 
    else {
        cout << "    > No reviews to calculate average." << endl;
    }

    return 0;
}



void addToFront(Review *&head, float rating, string comments) {
    Review *new_node = new Review(rating, comments);  

    new_node->next = head;
    head = new_node;
}

void addToTail(Review *&head, float rating, string comments) {
    Review *new_node = new Review(rating, comments);  

    if (!head) {  // if empty
        head = new_node;
    } else {
        Review *temp = head;
        while (temp->next) {  
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void Output(Review *head) {
    int count = 1;
    while (head) {
        cout << "    > Review #" << count++ << ": " << head->rating << ": " << head->comments << endl;
        head = head->next;
    }
}