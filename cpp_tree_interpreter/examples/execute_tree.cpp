#include <iostream>
#include "cpp_tree_interpreter/version.h"
#include "cpp_tree_interpreter/interpreter.h"

int main(int argc, const char** argv) {
    try {
        if (argc<2) {
            std::cout << "cpp_tree_interpreter " << cpp_tree_interpreter::VERSION << "\n";
            std::cout << "usage " << argv[0] << " <filename> <probs>\n";
            std::cout << "e.g. " << argv[0] << " example/hello.json 5 3 1 0.2\n";
            std::cout << "e.g. " << argv[0] << " example/hello.json 6 1 4 1.5\n";
        }
        else {
            auto tree = cpp_tree_interpreter::build_tree_from_file(argv[1]);
            std::vector<double> feature={};
            for (size_t i=0;i<argc-2;i++) {
                feature.push_back( std::stod(argv[2+i]) );
            }
            auto res = cpp_tree_interpreter::execute(tree, feature);
            std::cout << "result: " << res.class_idx << "\n";
        }
    }
    catch(std::exception &e) {
        std::cerr << e.what() << "\n";
    }
}
