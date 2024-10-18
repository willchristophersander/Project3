#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
#include "Movie.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>
#include <sys/stat.h>


using namespace std;

int main() {
    // Ensure the "data" directory exists
    struct stat info;
    if (stat("data", &info) != 0) {
        // Directory does not exist, create it
        mkdir("data", 0777);
    }
    // Create vectors of movies and integers
    std::string filename = "imdb_top_1000.csv";  // Path to the file. Change as needed.
    std::vector<Movie> movies = Movie::parseCSV(filename);
    vector<int> integers;

    for (int i = 1; i <= 100; ++i) {
        integers.push_back(i);
    }

    // Create tree objects
    BinarySearchTree<int> bst;
    AVLTree<int> avl;
    SplayTree<int> splay;

    // Insert integers in order into all trees
    for (int i : integers) {
        bst.add(i);
        avl.add(i);
        splay.add(i);
    }

    // Step 4: Find each integer in order and record depths to file
    ofstream depthFile("data/depth_in_order.csv");
    depthFile << "Value,BST Depth,AVL Depth,Splay Depth\n";
    for (int i : integers) {
        int depthBST = 0;
        int depthAVL = 0;
        int depthSplay = 0;

        bst.find(i, depthBST);
        avl.find(i, depthAVL);
        splay.find(i, depthSplay);

        depthFile << i << "," << depthBST << "," << depthAVL << "," << depthSplay << "\n";
    }
    depthFile.close();

    // Shuffle integers
    std::random_device rd;
    std::mt19937 generator(rd());
    shuffle(integers.begin(), integers.end(), generator);

    // Insert shuffled integers into new trees
    BinarySearchTree<int> bstShuffled;
    AVLTree<int> avlShuffled;
    SplayTree<int> splayShuffled;

    for (int i : integers) {
        bstShuffled.add(i);
        avlShuffled.add(i);
        splayShuffled.add(i);
    }

    // Find each integer in order and record depths to file
    ofstream depthFileShuffled("data/depth_shuffled.csv");
    depthFileShuffled << "Value,BST Depth (Shuffled),AVL Depth (Shuffled),Splay Depth (Shuffled)\n";
    sort(integers.begin(), integers.end());
    for (int i : integers) {
        int depthBST = 0;
        int depthAVL = 0;
        int depthSplay = 0;

        bstShuffled.find(i, depthBST);
        avlShuffled.find(i, depthAVL);
        splayShuffled.find(i, depthSplay);

        depthFileShuffled << i << "," << depthBST << "," << depthAVL << "," << depthSplay << "\n";
    }
    depthFileShuffled.close();

    // Insert movie objects into new trees and record depths
    BinarySearchTree<Movie> movieBST;
    AVLTree<Movie> movieAVL;
    SplayTree<Movie> movieSplay;

    for (const auto& movie : movies) {
        movieBST.add(movie);
        movieAVL.add(movie);
        movieSplay.add(movie);
    }

    ofstream movieDepthFile("data/movie_depths.csv");
    movieDepthFile << "Movie Title,BST Depth,AVL Depth,Splay Depth\n";
    for (const auto& movie : movies) {
        int depthBST = 0;
        int depthAVL = 0;
        int depthSplay = 0;

        movieBST.find(movie, depthBST);
        movieAVL.find(movie, depthAVL);
        movieSplay.find(movie, depthSplay);

        movieDepthFile << movie.getTitle() << "," << depthBST << "," << depthAVL << "," << depthSplay << "\n";
    }
    movieDepthFile.close();

    // Splay Tree - Find each object 5 times in a row
    SplayTree<Movie> splayFive;
    for (const auto& movie : movies) {
        splayFive.add(movie);
    }

    ofstream splayFiveDepthFile("data/splay_five_depths.csv");
    splayFiveDepthFile << "Movie Title,Find Attempt,Splay Depth\n";
    for (const auto& movie : movies) {
        for (int i = 0; i < 5; ++i) {
            int depth = 0;
            splayFive.find(movie, depth);
            splayFiveDepthFile << movie.getTitle() << "," << (i + 1) << "," << depth << "\n";
        }
    }
    splayFiveDepthFile.close();

    return 0;
}
