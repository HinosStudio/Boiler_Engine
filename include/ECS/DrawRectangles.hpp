#ifndef BOILER_ENGINE_DRAWRECTANGLES_HPP
#define BOILER_ENGINE_DRAWRECTANGLES_HPP

class DrawRectangles{
public:
    void Draw(){
        auto entities;
        for(auto entity: entities){
            Transform t;
            Rectangle r;

            Renderer::DrawRect(t.position, r.Size * r.scale, r.color);
        }
    }
};

#endif //BOILER_ENGINE_DRAWRECTANGLES_HPP
