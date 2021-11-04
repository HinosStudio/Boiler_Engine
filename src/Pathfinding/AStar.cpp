//
// Created by sjors on 11/1/2021.
//

#include <algorithm>
#include "Pathfinding/AStar.hpp"

AStar::AStar() {}

std::vector<const INode*>& AStar::GetPath(const INode &src, const INode &dest) {
    _closed.clear(); _open.clear();
    _open.push_back(&src);

    _link.clear(); _gScore.clear(); _hScore.clear(); _fScore.clear();

    _gScore[&src] = 0;
    _hScore[&src] = src.EstimatedCostTo(dest);
    _fScore[&src] = _hScore[&src];

    const INode * current, * from;
    float tentativeGScore;
    bool tentativeIsBetter;
    auto path = new std::vector<const INode *>;
    while(!_open.empty()){
        current = _open[0];
        if(current == &dest) return ReconstructPath(*path, _link, dest);
        _open.erase(_open.begin());
        _closed.push_back(current);
        if(current != &src) from = _link[current];
        for(const auto* next : current->Neighbours()){
            if(from != next && std::find(_closed.begin(), _closed.end(), next) == _closed.end()){
                tentativeGScore = _gScore[current] + current->CostTo(*next);
                tentativeIsBetter = true;
                if(std::find(_open.begin(), _open.end(), next) == _open.end()) _open.push_back(next);
                else if(tentativeGScore >= _gScore[next]) tentativeIsBetter = false;
                if(tentativeIsBetter){
                    _link[next] = current;
                    _gScore[next] = tentativeGScore;
                    _hScore[next] = next->EstimatedCostTo(dest);
                    _fScore[next] = _gScore[next] + _hScore[next];
                }
            }
        }
        //TODO: sort _open by comparing the fScore of the elements;
        std::sort(_open.begin(), _open.end(), [&](auto a, auto b){
            return _fScore[a] > _fScore[b];
        });
    }
    return *path;
}

std::vector<const INode*>&
AStar::ReconstructPath(std::vector<const INode*> &path, std::map<const INode*, const INode*> &link, const INode &currentNode) {
    if(link.count(&currentNode)) ReconstructPath(path, link, *link[&currentNode]);
    path.push_back(&currentNode);
    return path;
}