//
// Created by dongmin on 18. 4. 23.
//

#include "Triangle_Polygonizer.h"

#include "compute/Connect_halfedges.h"
#include "features/HalfEdge.h"
#include "features/TriangleMeshGraph.h"

void Triangle_Polygonizer::make(Space *space) {
    vector<Triangle*> triangleList = space->getTriangulation();
    vector<Surface*> newSurfaceList;

    for (int i = 0 ; i < triangleList.size() ; i++){
        newSurfaceList.push_back(triangleList[i]);
    }

    space->surfacesList = newSurfaceList;
}
