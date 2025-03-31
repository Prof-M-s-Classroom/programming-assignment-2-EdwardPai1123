#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream myfile(filename);
        if (!myfile.is_open()) {
            cout << "Not able to open file " << filename << endl;
            return;
        }

        unordered_map<int,Node<T>*> nodes;
        int firstEvent = -1;

        string line;
        while (getline(myfile, line)) {
            // Take in strings line by line
            stringstream ss(line);
            // String variables for each event, and one for description
            string eventNumber;
            string leftEventNumber;
            string rightEventNumber;
            string description;

            // Getting the first string variable of event number and converting it to an integer
            getline(ss, eventNumber, delimiter);
            int eventNum = atoi(eventNumber.c_str());

            // Getting the second string variable which is the description
            getline(ss, description, delimiter);

            // Getting the third string variable of choice left and converting it to an integer
            getline(ss, leftEventNumber, delimiter);
            int leftEvent = atoi(leftEventNumber.c_str());

            // Getting the fourth string variable of choice right and converting it to an integer
            getline(ss, rightEventNumber, delimiter);
            int rightEvent = atoi(rightEventNumber.c_str());

            // Capturing the event it is currently at
            if (firstEvent == -1) {
                firstEvent = eventNum;
            }

            nodes[eventNum] = new Node<T>(Story(description, eventNum, leftEvent, rightEvent));
        }

        myfile.close();

        for (auto& pair : nodes) {
            Node<T> * node = pair.second;
            if (nodes.count(node -> data.leftEventNumber)) {
                node -> left = nodes[node -> data.leftEventNumber];
            }
            if (nodes.count(node -> data.rightEventNumber)) {
                node -> right = nodes[node -> data.rightEventNumber];
            }
        }

        // Assigning root node to the event that it is currently at
        if (nodes.count(firstEvent)) {
            root = nodes[firstEvent];
        }

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T> * current = root;
        while (current) {
            cout << current -> data.description << "\n1. Left\n2. Right\nEnter choice: ";
            int choice;
            cin >> choice;
            if (choice == 1 && current -> left) {
                current = current -> left;
            } else if (choice == 2 && current->right) {
                current = current -> right;
            } else {
                cout << "Invalid choice or end game" << endl;
                break;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H