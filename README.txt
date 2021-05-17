Miniprojekt_Lightbeam

This program was created as a project work at the Fachhochschule Südwestfalen for the
Grundlagen der Informatik II subject.
It is meant to be used together with the Lightbeam 3.0 add-on for the Firefox Browser.
As described on addons.mozilla.org "Lightbeam is a browser extension that uses interactive
visualizations to show you the relationships between third parties and the sites you visit."

How to use:
(1) Install the Lightbeam 3.0 add-on to your Firefox Browser.
(2) Surf the internet(Lightbeam will record all websites visited and third party sites connected to)
(3) Open the Lightbeam extension
(4) Save the data it collected(remember where you put the file and how you named it)
(5) Compile and run this program

When you run the program you will be presented with the following menu:

1- Choose a directory path
2- Read a graph-file from the directory path. Only specify the file name i.e testgraph
3- Print Adjacency Matrix of the graph
4- Find path and distance(using BFS) between two vertices(using id's)
5- Find path and distance(using BFS) between two vertices(using vertex names)
e- Exit the program


The program will set its working directory(where all JSON files created by Lightbeam are)
to the directory of the runnable file you started. You can change that by choosing the first
option in the menu and selecting a new working directory.