# My Algorithm
This is my algorithm

## OVERVIEW
Initially, the goal of this algorithm was to make it possible to
fill a binary tree with ordered data and keep a balance structure.
This goal led to discovering and replicating a sequence that can map
the process of creating a balanced binary tree. 

## THE WAY IT WORKS
We all know how to create a binary tree using a two-node data structure with a left or right, up or down, less or greater, etc.
However, the process usualy requires novice coders to map the entire tree first to plan how they will construct it.
But, when given a large amount of ordered data of variable quantity, the task becomes nearly impossible to visualize.

My first step towards a solution was to manually write out a peusdo-code of each step one-by-one of how to go down an ordered list an build the tree, preserving it with balance and validity.
These steps can be seen in 'Notes.txt'. As I painfully reach the limit of my attention-span, it looked like I had enough iterations to start an analysis.

My next step was to weed out any repetition in the peusdo-code being very careful not to overlook any patterns that encompassed more than one step. 
That is the tricky part with sequences in mathematics and I like to call it *thinking outside of the initial scope*.
This also led to the fear of not having a large enough sample size to see the big picture.
Something about sampling frequency can probably be used as a metaphor but lets move on.
Look at 'Notes2.txt', I eliminated any constants in the iterations and found a few interesting things.

1. The iterations repeated their structure every two steps.
2. The \'less than\' nodes were unchanged.
3. The \'greater than\' nodes were changing in node iterations.

With these three characteristics, I was able to start simplifying the challenge to a simple mathematician stunt.

## THE SEQUENCE
After realizing the pattern in the pseudo-code, I decided to make a numeric sequence that would represent the levels of node iteration down the \'greater than\' path to see if I could strike gold. 
Any 'root' with an absence of '->greater' would equate to a '0', any 'root->greater' would equate to a '1', and so on. 
Compiling, executing, and exploring the 'rodriguez-algorithm.c' will take you the rest of the way of my journey to my first, full-fledged, self-made research project in the world of coding.
 
Thank you for stopping by!