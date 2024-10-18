# Project 3 Report

Answer the following questions directly in this file:
* You will have a different grader again, so make sure your report includes information about your dataset.
* How do the depths of the random-ordered integers compare to the depths of the ordered integers for each tree? Why?
## The AVL tree has similiar depths regardless of whether the integers are random or ordered, at around 4.8 depth for any integer.
## The binary search tree has significantly worse performance with ordered integers, at an average of 49.5 depth for any integer. This is because the tree does not rebalance after each addition of an element. Since the numbers are subsequent the tree never gets a chance, at each operation, to find a lesser value to put on the left node, leading to a tree with just right nodes all the way to 100. 
## The splay tree has better performance with random numbers. 
* How do the depths of each custom-data-type tree compare to each other?
## The splay tree has the best performance with both random and ordered integers, with an average depth of 4.8 for random integers and 5.0 for ordered integers. The AVL tree has the second best performance with an average depth of 4.8 for random integers and 4.8 for ordered integers. The binary search tree has the worst performance with an average depth of 49.5 for ordered integers and 5.76 for random integers.
* Why do the depths of the second custom-data-type Splay Tree make sense?
## The depths of the second custom-data-type Splay Tree make sense because the tree is splayed after each search, meaning that the most recently searched element is moved to the root of the tree. This means that the tree is always balanced and the depth is always 0 for the last accessed element.
* Graph the Binary Search Tree, AVL Tree, and Splay Tree depths for the custom data type trees. Do not use C++ to graph, you can use whatever spreadsheet application or graphical programming language you prefer. You can use whatever graph is most readable to you (e.g. scatter plot, histogram, etc.).
    * Your graphs should have clear labels for both x and y axes.
    * Save your graph files in the graphs folder.
    * You do not need to graph the depths of the integer type trees or the Splay Tree that finds each object 5 times in a row, but you can if you feel it helps you analyze the data.
    * An example graph spreadsheet and an example graph image have been included in the starter code.
    * Here is how you include an image in your Report.md file: ![example graph](graphs/example-graph.png)
* Compare and contrast the graphs and explain the differences based on what you know about the structure and behavior of the trees. Justify the time complexity of searching the trees based on the results.
## Looking at the graphs, we see the following:
## 1: Binary search can grow unwieldy as the tree is not self balancing. In worst case scenarios the tree can grow to O(n) complexity
## 2: AVL trees are strictly self balancing and have great control of their height and possess log(n) complexity. The AVL graph is the least chaotic. 
## 3: Splay trees are self balancing, but do so by moving recently accesed elements to the top, and have a depth of log(n) complexity. This is why the graph is relatively flat but still fairly chaotic.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**