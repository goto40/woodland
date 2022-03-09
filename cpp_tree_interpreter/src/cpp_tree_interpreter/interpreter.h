#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <cassert>
#include <variant>
#include <memory>
#include <nlohmann/json.hpp>

namespace cpp_tree_interpreter {

    struct LeafNode {
        size_t class_idx={};
        std::vector<double> probs={};
    };
    struct DecisionNode {
        using Node = std::variant<DecisionNode, LeafNode>;
        std::string name={};
        size_t idx={};
        double threshold={};
        std::unique_ptr<Node> left = nullptr;
        std::unique_ptr<Node> right = nullptr;
    };

    DecisionNode::Node build_tree(const nlohmann::json& j);
    DecisionNode::Node build_tree_from_file(std::string filename);
    LeafNode execute(const DecisionNode::Node& tree, const std::vector<double> &feature);
}