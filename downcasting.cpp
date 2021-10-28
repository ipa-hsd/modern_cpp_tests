#include <memory>
#include <iostream>


class Geometry {
public:
    enum {BOX, MESH} type;
    std::string name;
};

class Mesh : public Geometry {
public:
    std::string filename;
};

class GeometryDerived : public Geometry, std::enable_shared_from_this<GeometryDerived> {
public:
    void consumeGeometry() {
        std::shared_ptr<Geometry> geom = std::static_pointer_cast<Geometry>(shared_from_this());
        // Geometry geom = static_cast<Geometry>(*this);
        // std::cout << geom->name << std::endl;
        // if(geom.type == Geometry::MESH) {
        //     Mesh *mesh = static_cast<Mesh*>(&geom);
        //     std::cout << mesh->filename << std::endl;
        // }
    }
};

class MeshDerived : public Mesh {
public:
    std::string get_output() {
        return this->filename;        
    }
};

std::shared_ptr<Geometry> getGeometry() {
    std::shared_ptr<Geometry> geom = std::make_shared<Geometry>();
    geom->name = "geometry";

    Mesh *mesh = new Mesh();
    mesh->name = "name";
    mesh->filename = "filename";
    mesh->type = Geometry::MESH;
    geom.reset(mesh);

    return geom;
}

class GeometryHandler {
public:
    void consumeGeometry(std::shared_ptr<Geometry> geom) {
        if(geom->type == Geometry::MESH) {
            std::shared_ptr<MeshDerived> meshDerived = std::static_pointer_cast<MeshDerived>(geom);
            std::cout << meshDerived->filename << std::endl;
        }
    }    
};


int main(int argc, char** argv)
{
    std::shared_ptr<Geometry> geom = getGeometry();
    GeometryHandler handler;

    std::shared_ptr<GeometryDerived> geomDerived = std::static_pointer_cast<GeometryDerived>(geom);
    handler.consumeGeometry(geomDerived);
    // geomDerived->consumeGeometry();

    return 0;
}

