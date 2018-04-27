#ifndef SURFACESLISTCALCULATION_H_INCLUDED
#define SURFACESLISTCALCULATION_H_INCLUDED

#include "predefine.h"
#include "features/Surface.h"
#include "SurfacesListComputation.h"

using namespace std;

class SurfacesListComputation{
public:
    static int findFirstSurfaceIndexSimilarWithAxis(vector<Surface*>& surfacesList, int axis);
    static void tagID(vector<Surface*>& surfacesList);
    static ull countTriangles(vector<TriangleMesh*> tm);

};

namespace TMIC{
    bool mergeSurfaces(vector<Surface*>& surfacesList, vector<Surface*>& result);
    bool mergeSurfaces(vector<Triangle*>& triangleList, vector<Surface*>& result);

    double getAverageSize(const vector<Surface*>& surfacesList);
    CGAL::Bbox_3 getMBB(vector<Surface *> &surfacesList);
}

#endif // SURFACESLISTCALCULATION_H_INCLUDED
