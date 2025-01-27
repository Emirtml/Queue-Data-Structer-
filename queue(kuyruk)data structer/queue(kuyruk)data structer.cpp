
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node* prev;
};
struct node* root;
struct node* back;


void push(int x) {
    if (root == NULL) { // kuyruk boş ise (queue is empty)
        struct node* temp = new struct node();
        temp->data = x;
        temp->prev = NULL;
        root = back = temp;
    }

    else{ // kuyruk dolu ise eleman ekleme (queue isnt empty)
        struct node* temp = new struct node();
        temp->data = x;
        back->prev = temp;
        back = temp;
    }
}

// queue is list (kuyruğu listeleme)
int showQue() {
    struct node* index;
    index = root;

    if (root == NULL) { // kuyruk boşmu kontrolu yapılabilir.
        printf("queue is empty");
        return 1;
    }

    while (index ) {
        printf("%d\n", index->data);
        index = index->prev;
    }
    return 1;
}

int  pop() {
   
    if (root == NULL) { // kuyruğun boş dolu kontrolü;
        printf("queue is empty");
        return 1;
    }

    // kuyrukta ilk giren ilk çıkar(FIFO) ve eleman silme bu şekil yazılır.
    struct node* t = root;
    root = root->prev;
    free(t);

    return 1;
}

int main() {

    push(15);
    push(16);
    push(17);
    push(18);
    push(19);

   
    pop();
    pop();

    showQue();

    return 0;
}