#ifndef BOILER_ENGINE_GRID_HPP
#define BOILER_ENGINE_GRID_HPP

struct Grid {
    V2 size;
    V2 cellSize;
};

struct GridPosition {
    Uint32 gridId;
};

struct Vector {
    V2 vector
    Color color;
};

class DrawGrid {
public:
    void Draw(){
        UInt32[] gridEnts;
        for (auto e : gridEnts) {
            Grid grid = GetComponent<Grid>(e);
            Transform gridTransform = GetComponent<Transform>(e);
            for(auto x = 0; x < grid.size.x; ++x){
                for(auto y =0; y < grid.size.y; ++y){
                    V2 point = gridTransform.position - ((grid.size * grid.cellSize) / 2);
                    Renderer::DrawPoint(point, Color::BLUE);
                }
            }
        }
    }
};

class DrawVectorOnGrid {
public:
    void Draw(){
        Uint32[] vectorEnts; //Get all Entities with Vectors
        for(auto e : vectorEnts){
            GridPosition gp = GetComponent<GridPosition>(e);
            Transform gridTransform = GetComponent<Transform>(gp.gridId);
            Transform vectorTransform = GetComponent<Transform(e);
            V2 point1 = gridTransform.position;
            V2 point2 = gridTransform.position + vectorTransform.position;
            Renderer::DrawLine(point1, point2, Color::RED);
        }
    }
};

#endif //BOILER_ENGINE_GRID_HPP
