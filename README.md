# CS 2240 Project 2
Create a Queue class and explore big-Oh complexities!

For this project, you will write a C++ program that uses Stack and Queue data structures to store objects of varying data types.

## Requirements
It is recommended that you use the data and program from Project 1 as a starting point.

### Stack Class
The Stack class from lecture is included in the starter code for this project.

### Queue Class
Create a Queue class that uses the Node class (also included in the starter code) to create a functioning queue data structure.
* Your Queue should keep track of where the front and back Nodes are.
* Your Queue should be able to:
  * `enqueue` (push Objects onto its back),
  * `dequeue` (pop and return Objects off its front),
  * `search` (determine if an Object is in the Queue or not), and
  * `print` (list all of the items in the Queue object, ordered from front to back).
* Your Queue must be able to be used with any data type.
* Your Nodes must be stored in heap memory.
* Your program must not have any memory leaks.

### Main function
Create two Queue objects: one of integers and one of strings. Demonstrate that the Queue methods work correctly by calling methods on the integer and string Queues and printing out to the console when appropriate.

Perform the following operations:
* Create a third Queue object and a Stack object, both of the type you created in Project 1.
* Use a loop to print and enqueue the first 10 objects from your vector (from Project 1) onto the Queue.
* Use a second loop to dequeue the 10 objects off the Queue and push them onto the Stack.
* Use a third loop to pop the 10 objects off the Stack and print them.

What is the order of the objects before and after adding them to the Queue and Stack? When and why did it change?

### Design
Consider the following questions:
* Using the Node class, will the links point from the front to the back of the Queue or from the back to the front? Which way will make the enqueue and dequeue methods more time efficient?
* How will you make sure there are no memory leaks?
* How will you print the objects in the main function? Should you overload an operator?

### Test
How can you demonstrate in your code that your Queue class works correctly? How can you use the integer and string Queue objects to show this?

Here are a couple hints to help you with testing:
* Make sure you call each of the `enqueue`, `dequeue`, `search`, and `print` methods at least once.
* Consider edge cases, like searching in a one-node queue (for when the search should succeed and when it should fail) and calling `dequeue` on an empty queue.

## Report
You must write a report about your project. Answer the prompts in the Report.md file.

## Submit

You must include your source files, your data file(s), CMakeLists.txt, and your updated Report.md file that contains your report to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Grading
The project is out of 60 points.

| Points Possible | Description of requirement |
|------------------- | ----------------------------- |
| 5 pts | Program compiles and runs. |
| 5 pts | Code style. Readable, naming style is consistent, comments where appropriate. |
| 20 pts | Queue class satisfies requirements. |
| 10 pts | You create integer and string Queue objects and use them to test your code. |
| 10 pts | You perform the operations with the Stack and the Queue as described above. |
| 10 pts | Report satisfies requirements, is easily readable, and is professional. |
