# Just a hack...

## Python
 * I use `sklearn.tree.DecisionTreeClassifier` to train a tree.
 * Then I dump the tree to JSON (see `decision_trees.ipynb` in this repo...).

## C++
 * Then I parse the JSON via the nlohmann library into C++.
 * and classify an example feature vector and output the leaf tree.

The trained tree is stored in [examples/hello.json](examples/hello.json).

Evaluated examples (from the training set - to test the interpreter not to evaluate the quality of the trained tree):
```
# class 0 examples
./build/execute_tree examples/hello.json 5.1 3.5 1.4 0.2
./build/execute_tree examples/hello.json 4.9 3.1 1.5 0.1
./build/execute_tree examples/hello.json 5.4 3.7 1.5 0.2

# class 1 examples
./build/execute_tree examples/hello.json 6.2 2.9 4.3 1.3
./build/execute_tree examples/hello.json 5.1 2.5 3.  1.1
./build/execute_tree examples/hello.json 5.7 2.8 4.1 1.3

# class 2 examples
./build/execute_tree examples/hello.json 6.5 3.  5.2 2. 
./build/execute_tree examples/hello.json 6.2 3.4 5.4 2.3
./build/execute_tree examples/hello.json 5.9 3.  5.1 1.8
```

All examples yield the exepcted class index.

The Iris data is given as follows (examples):
```
5.1 3.5 1.4 0.2 0.
4.9 3.1 1.5 0.1 0.
5.4 3.7 1.5 0.2 0.
...
6.2 2.9 4.3 1.3 1.
5.1 2.5 3.  1.1 1.
5.7 2.8 4.1 1.3 1.
...
6.5 3.  5.2 2.  2.
6.2 3.4 5.4 2.3 2.
5.9 3.  5.1 1.8 2.
```