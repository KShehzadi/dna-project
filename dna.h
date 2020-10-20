//
// dna.h
//
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

class dna {
private:
    //
    // This implementation is a doubly-linked structure.  The nodes are structs
    // called Nucleotides.  Size could keep track of how many Nucleotides are
    // currently in the list.  front should always point to the first
    // Nucleotide and back should point to the last one.
    struct Nucleotide {
        char value;
        Nucleotide* next;
        Nucleotide* prev;
    };
    int Size;
    Nucleotide* front;
    Nucleotide* back;

    //
    // findFirst: (private)
    //
    // Searches dna for the first copy of the sequence target, returning a
    // pointer to that occurrence or nullptr if the target sequence isn't
    // present.
    // Performance requirement:  this function doesn't have a set Big O target,
    // but should not time out on test cases and be reasonable.
    //
    Nucleotide* findFirst(dna target) {

        Nucleotide* node = new Nucleotide();
        if (this->Size < target.Size)
        {
            return node;
        }
        Nucleotide* parentobject = new Nucleotide();
        Nucleotide* targetpointer = new Nucleotide();

        targetpointer = target.front;
        parentobject = this->front;
        while (parentobject)
        {
            if (targetpointer->value == parentobject->value)
            {
                node = parentobject;
                while (targetpointer)
                {
                    if (!targetpointer || parentobject->value != targetpointer->value)
                    {
                        break;
                    }
                    else
                    {
                        targetpointer = targetpointer->next;
                        parentobject = parentobject->next;
                    }


                }
                if (!targetpointer)
                {
                    return node;
                }
                else
                {
                    targetpointer = target.front;
                }
            }
            parentobject = parentobject->next;
        }
        node = 0;
        return node;
    }

public:
    void mytestfunction()
    {
        cout << this->Size;
    }
    //
    // default constructor:
    //
    // Called automatically by C++ to create an empty dna object with two
    // Nucleotides, each with the value of 'X'.
    //
    dna() {
        Size = 2;
        Nucleotide* a = new Nucleotide();
        a->value = 'X';
        Nucleotide* b = new Nucleotide();
        b->value = 'X';
        a->next = b;
        a->prev = nullptr;
        b->prev = a;
        b->next = nullptr;
        front = a;
        back = b;
    }


    //
    // second constructor:
    //
    // Produces a new strand of nucleotides spelled out in the sequence given
    // by str.
    // Performance requirement: O(n)
    //
    dna(const string& str) {
        this->Size = str.length();
        Nucleotide* n = new Nucleotide();
        n->value = str[0];
        this->front = n;
        this->front->prev = nullptr;
        for (int i = 1; i < str.length(); i++)
        {
            Nucleotide* n2 = new Nucleotide();
            n2->value = str[i];
            n->next = n2;
            n2->prev = n;
            n = n->next;
        }
        n->next = nullptr;
        this->back = n;
    }


    //
    // copy constructor:
    //
    // Called automatically by C++ to create a dna object that contains a copy
    // of an existing dna object.
    // Performance requirement: O(n)
    //
    dna(dna& other) {

        this->Size = other.Size;
        Nucleotide* n = new Nucleotide();
        n = other.front;
        Nucleotide* n1 = new Nucleotide();
        n1->value = n->value;
        n1->prev = nullptr;
        this->front = n1;
        n = n->next;
        while (n)
        {
            Nucleotide* n2 = new Nucleotide();
            n2->value = n->value;
            n1->next = n2;
            n2->prev = n1;
            n1 = n1->next;
            n = n->next;
        }
        n1->next =nullptr;
        this->back = n1;

    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by
    // the dna object.
    // Performance requirement: O(n)
    //
    virtual ~dna() {

    }

    //
    // clear:
    //
    // Frees all memory in the chain of nucleotides in the dna obeject.  This
    // function should also set front, back, and Size, appropriately.
    // Performance requirement: O(n)
    //
    void clear() {

        Nucleotide* n = new Nucleotide();
        while (this->front->next)
        {
            n = this->front->next;
            delete this->front;
            this->front = n;
        }
        delete this->back;
        this->front = nullptr;
        this->back = nullptr;
        this->Size = 0;
    }

    //
    // operator=
    //
    // Called when you assign one dna object into another, i.e. this = other;
    // Performance requirement: O(n)
    //
    dna& operator=(const dna& other) {


        this->Size = other.Size;
        Nucleotide* n = new Nucleotide();
        n = other.front;
        Nucleotide* n1 = new Nucleotide();
        n1->value = n->value;
        this->front = n1;
        n = n->next;
        while (n)
        {
            Nucleotide* n2 = new Nucleotide();
            n2->value = n->value;
            n1->next = n2;
            n2->prev = n1;
            n1 = n1->next;
            n = n->next;
        }

        return *this;
    }

    //
    // size:
    //
    // Returns the # of Nucleotides currently in the dna strand.
    // Performance requirement: O(1)
    //
    int size() const {
        return this->Size;  // TO DO: update this.
    }

    //
    // at(i):
    //
    // Returns a reference to the ith Nucleotide's value, which allows
    // you to read (access) or write (modify) this value.  If i is out of
    // bounds, an exception is thrown.
    // Performance requirement: O(n)
    //
    char at(int i) {

        if (i > this->Size)
        {
            throw i;
        }
        // TO DO: write this.
        char out = '0';
        Nucleotide* n = new Nucleotide();
        n = this->front;
        for (int j = 0; j < i; j++)
        {
            n = n->next;
        }

        out = n->value;
        delete n;
        return out;
    }

    //
    // toString:
    //
    // Returns a string spelling out the contents of the dna sequence.
    // Performance requirement: O(n)
    //
    string toString() {


        // TO DO: write this.
        string value = "";
        Nucleotide* n = new Nucleotide();
        n = this->front;
        for (int i = 0; i < this->Size; i++)
        {
            value = value + n->value;
            n = n->next;
        }

        return value;
    }

    //
    // operator==
    //
    // This operator determines how you define equality between two operators.
    // In this function, you should compare other and this.  The two objects
    // should be considered equal if they have the same sequence of values and
    // in the same order.
    // Performance requirement: O(n)
    //
    bool operator==(const dna& other) {

        if (this->Size != other.Size)
        {
            return false;
        }
        else
        {
            Nucleotide* parentobject = new Nucleotide();
            Nucleotide* parameterobject = new Nucleotide();
            parentobject = this->front;
            parameterobject = other.front;
            while (parentobject->next)
            {

                if (parentobject->value != parameterobject->value)
                {
                    return false;
                }
                parentobject = parentobject->next;
                parameterobject = parameterobject->next;
            }
        }

        return true;
    }

    //
    // splice:
    //
    // Removes the first copy of the sequence in target that appears in the
    // dna sequence of current object.  This requires the linked structure to
    // be properly re-wired after removal.
    // Performance requirement: this function doesn't have a set Big O target,
    // but should not time out on test cases and be reasonable.
    //
    bool splice(dna target) {
        if (this->Size < target.Size)
        {
            return false;
        }
        Nucleotide* node = new Nucleotide();
        Nucleotide* parentobject = new Nucleotide();
        Nucleotide* targetpointer = new Nucleotide();
        targetpointer = target.front;
        parentobject = this->front;
        int i = this->Size;
        while (this->front)
        {
            if (targetpointer->value == this->front->value)
            {
                node = this->front;
                while (targetpointer)
                {
                    if (targetpointer == nullptr||this->front== nullptr 
                        || this->front->value != targetpointer->value)
                    {
                        break;
                    }
                    else
                    {
                        i--;
                        targetpointer = targetpointer->next;
                        this->front = this->front->next;
                    }
                }
                if (targetpointer == nullptr)
                {
                    break;
                }
                else
                {
                    i = this->Size;
                    targetpointer = target.front;
                }
            }
            if (this->front == nullptr && targetpointer != nullptr)
            {
                return false;
            }
            else if (this->front == nullptr && targetpointer == nullptr)
            {
                break;
            }
            else
            {
                this->front = this->front->next;
            }
        }
        this->front = parentobject;
        if (i == this->Size)
        {
            return false;
        }
        Nucleotide* n = node;
        Nucleotide* n1 = n;
        Nucleotide* n2 = target.front;
        while (n2)
        {
            n1 = n1->next;
            n2 = n2->next;
        }

        if (n->prev == nullptr && n1 == nullptr)
        {
            this->front = nullptr;
            this -> back = nullptr;
        }
        else if (n1 == nullptr)
        {
            n->prev->next = nullptr;
            
        }
        else if(n->prev== nullptr)
        {
            n1->prev = nullptr;
            this->front = n1;
        }
        else
        {
            n->prev->next = n1->prev->next;
            n1->prev = n->prev;
        }
        
        this->Size = i;
        
        return true;
    }

    //
    // isLinked()
    //
    // Checks if a strand is linked correctly.  This is provided for you.
    // You should use it to test your linked structure often.
    // Performance requirement: O(n)
    //
    bool isLinked() {
        Nucleotide* start = front;
        // If we're at the start of a strand,
        // we should not have a previous pointer.
        if (start != nullptr && start->prev != nullptr) {
            return false;
        }
        // Walk the list, ensuring at each point that the next/prev pointers
        // are consistent with one another.
        for (Nucleotide* curr = start; curr != nullptr; curr = curr->next) {
            if (curr->next != nullptr && curr->next->prev != curr) return false;
            if (curr->prev != nullptr && curr->prev->next != curr) return false;
        }
        return true;
    }
};
