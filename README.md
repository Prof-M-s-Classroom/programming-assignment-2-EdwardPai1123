[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Edward Pai`
### **Student ID:** `826766636`

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

--- This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, while players will start at the root to choose either go 1.Left or 2.Right. The storyline is loaded from an external file (story.txt) and is parsed to build the decision tree. After the root it got split into two ways and both ways can lead to finding the treasure to win the game, during the game there will be more than just winning the game, there will be some bad endings, and twist endings.

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function]`
- **`GameDecisionTree.h`** → `[Explain what this file contains]`
- **`Node.h`** → `[Explain what this file contains]`
- **`Story.h`** → `[Explain what this file contains]`
- **`story.txt`** → `[Explain how the game loads story events from this file]`

--- **`main.cpp`** → 'This loads the story data, starts and runs the game, and contains the main function that initializes the game.'
**`GameDecisionTree.h`** → 'This contains the GameDecisionTree class, where it is the place that I put all my code in.'
**`Node.h`** → 'This contains the templated Node<T> class, also defines a binary tree node that stores story data and pointers towards the left and right child nodes.'
**`Story.h`** → 'This represents a single event in the story, which means it represents the description and links to the left or right child event numbers, it also declares the story class.'
**`story.txt`** → 'This is where I put all the story details in, while formating as eventNumber, description, leftEventNumber, and rightEventNumber, with this order the code will run and print out the context with this order.'

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?
- How are nodes linked based on left and right event numbers?
- What happens if an event has `-1` as left or right children?

--- The objects are created by parsing each line from story.txt while extracting the event number and description.
Nodes linked based on left and right event numbers might due to the eventNumber to Node<Story>*.
It will be treated as a leaf node which means there will be no path connected after it.

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?
- What happens when the player reaches a leaf node?
- Explain the special case where multiple events lead to the same outcome.

--- The player will be choosing either 1 or 2 as the path.
When the player reaches a leaf node it will make sure you choose 1 or 2 again, and it will bring the player to end game.
In my game I tried to make every leaf node that have different endings, but some story paths might lead to shared nodes.

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?
- How do you ensure nodes are properly linked?
- Any challenges faced while handling file input?

--- The file is reading line by line while using getline() with a | as delimiter.
with the help of atoi() function it can be treated as converting the event numbers and child IDs from strings to integers.
A hash map is used to store and link the nodes, the challenge for handling file input was handling malformed lines.

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

--- At first I was trying to test out the story, and it gave me an error said that undefined reference to `Story::Story(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, int, int)` after doing some research and discussing with my friend. I decide to add 'CXX = g++ CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic' on top of the make file and changed all int fields to be parsed from string before converting in the game decision tree.

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

--- So at first player will enter the game and story will pop out saying that You wake up in a forest clearing. There are two paths. Then player can choose either going left or right which means player is going to put 1 or 2 in the terminal to able to continue the game.
For here I choose 1, and it will bring me down to 'You follow the path to the left and encounter a river' and here comes another split of either going left ot right. And then I choose 2 because I want to see what is going on for the right side and it will bring me to 'You accidentally find a hidden passageway next to the river that leads to a secret room'. Another split for us to make decisions I choose to put 1 to go on the left side and found out it was a trap, now player is surrounded with College Student's homework, and player decide to end his/her adventure.
And I choose 1, that brings the player finished the homework and go for a job hunt. And then the final pick of left and right will both lead to end game.

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`
- **Searching for an event in the tree** → `O(?)`
- **Game traversal efficiency** → `O(?)`

--- **Loading the tree from the file** → `O(n)`
**Searching for an event in the tree** → `O(1)`
**Game traversal efficiency** → `O(h)` which I think the h is 5, since there is an at least 5 levels minimum.

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

--- I tested multiple scenarios to find that if my player will have the same ending either player are going left or right. The main goal of me to test them out is that I do not want player to have the same ending to make the play feel bored, I want for each path the player choose will bring them a whole new feeling.

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

--- I added humorous and creative endings to encourage player to replay and seek for different endings, and making detailed ending detection for avoiding showing invaild choices after reaching a leaf.

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`
- **Code must compile and run** → `(Code that does not run will receive a 0).`
- **Do not modify provided skeleton code** → `(You may only add to it).`

---
