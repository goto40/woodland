#include "interpreter.h"

namespace cpp_tree_interpreter {

    DecisionNode::Node build_tree(const nlohmann::json& j) {
        if (j.contains("name")) {
            std::unique_ptr<DecisionNode::Node> left = {};
            std::unique_ptr<DecisionNode::Node> right = {};
            if (j.contains("left")) {
                left = std::make_unique<DecisionNode::Node>( build_tree(j.at("left")) );
            }        
            if (j.contains("right")) {
                right = std::make_unique<DecisionNode::Node>( build_tree(j.at("right")) );
            }        
            assert(left!=nullptr && "unexpected nullptr left");
            assert(right!=nullptr && "unexpected nullptr right");
            return DecisionNode{
                j.at("name"),
                j.at("idx"),
                j.at("threshold"),
                std::move(left),
                std::move(right)
            };
        }
        else {
            return LeafNode{
                j.at("class_idx"),
                j.at("probs").at(0).get<std::vector<double>>() // why we have an array of arrays
            };
        }
    }

    DecisionNode::Node build_tree_from_file(std::string filename) {
        std::ifstream f(filename);
        assert(f && "problem opening file");
        std::string source((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

        nlohmann::json j = nlohmann::json::parse(source);
        return build_tree(j);
    }

    LeafNode execute(const DecisionNode::Node& tree, const std::vector<double> &feature) {
        if (std::holds_alternative<LeafNode>(tree)) {
            return std::get<LeafNode>(tree); // copy
        }
        else {
            auto& d = std::get<DecisionNode>(tree);
            assert(d.idx < feature.size() && "unexpected index");
            if (feature[d.idx]<d.threshold) {
                return execute(*d.left, feature);
            }
            else {
                return execute(*d.right, feature);
            }
        }
    }

}
