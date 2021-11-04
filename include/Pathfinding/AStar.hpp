//
// Created by sjors on 11/1/2021.
//

#ifndef BOILER_ENGINE_ASTAR_HPP
#define BOILER_ENGINE_ASTAR_HPP

#include <vector>
#include <map>
#include "node.hpp"

class AStar {
private:
    std::vector<const INode*> _closed;
    std::vector<const INode*> _open;
    std::map<const INode*, const INode*> _link;
    std::map<const INode*, float> _gScore;
    std::map<const INode*, float> _hScore;
    std::map<const INode*, float> _fScore;

public:
    AStar();

    std::vector<const INode*>& GetPath(const INode &src, const INode &dest);

    std::vector<const INode*>&
    ReconstructPath(std::vector<const INode*> &path, std::map<const INode*, const INode*> &link, const INode &currentNode);
};

#endif //BOILER_ENGINE_ASTAR_HPP
