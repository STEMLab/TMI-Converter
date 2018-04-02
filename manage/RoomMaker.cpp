#include <fileio/JSONMaker.h>
#include "manage/RoomMaker.h"


int RoomMaker::importMesh() {
    string filePath = paths["resourceDir"] + paths["filename"] + "." + paths["filetype"];
    this->mesh_list = di->import(filePath.c_str());
    if (this->mesh_list.size() == 0) return -1;
    else return 0;
}

int RoomMaker::convertTriangleMeshToSpace() {
    for (int space_id = 0 ; space_id < this->mesh_list.size() ; space_id++){
        Space* space = new Space();
        space->setName(this->mesh_list[space_id]->name);
        if (space->convertTrianglesToSurfaces(this->mesh_list[space_id]->triangles)){
            cout << "make Surfaces error" << endl;
            return -1;
        }
        space->vertices = this->mesh_list[space_id]->vertices;
        // this->mesh_list[space_id]->clear();
        this->spaceList.push_back(space);
    }
    this->mesh_list.clear();
    return 0;
}

int RoomMaker::convertSpaceToTriangleMesh(){
    this->mesh_list.clear();
    for (int spaceID = 0 ; spaceID < this->spaceList.size() ; spaceID++){
        Space* space = this->spaceList[spaceID];
        vector<Triangle*> triangleList = space->getTriangleListOfAllSurfaces();

        TriangleMesh* mesh = new TriangleMesh();
        mesh->triangles = triangleList;
        mesh->vertices = space->vertices;
        mesh->name = space->name;
        this->mesh_list.push_back(mesh);
    }
    return 0;
}

int RoomMaker::exportSpace() {
    string filePath = paths["versionDir"] + "surfaces.json";
    if (de->exportSpace(this->spaceList, filePath.c_str())) return 1;
    return 0;
}

void RoomMaker::setPaths(map<string, string> _paths) {
    this->paths = _paths;
}
