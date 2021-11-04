#ifndef BOILER_ENGINE_NODE_HPP
#define BOILER_ENGINE_NODE_HPP

class INode {
public:
    virtual std::vector<const INode*> Neighbours() const = 0;
    virtual float CostTo(const INode &neighbour) const = 0;
    virtual float EstimatedCostTo(const INode &goal) const = 0;
};

#endif //BOILER_ENGINE_NODE_HPP
