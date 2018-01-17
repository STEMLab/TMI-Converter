
#ifndef Surface_h
#define Surface_h

#include <vector>
#include <string>
#include <climits>
#include <cassert>

#include "features/Triangle.h"
#include "logic/check.hpp"
#include "util.h"
#include "features/Segment.h"
#include "predefine.h"

#include "cgal/Types.h"

class Surface{
public:
    ull sf_id;
    std::vector<Vertex*> v_list;
    std::vector<std::vector<Vertex*> > inner_ring;
    std::vector<Triangle*> tri_list;
    Vector_3 av_normal = CGAL::NULL_VECTOR;

    double min_coords[3];
    double max_coords[3];
    double area = 0.0;

    Surface(){
    }
    Surface(Triangle& pl);
    Surface(Triangle* pl) : Surface(*pl) {}
    Surface(Surface* cp);
    Surface(std::vector<Vertex*>& pVertices);

    ull getLength(){
        return v_list.size();
    }

    void setZ(double value);

    std::string toJSONString();

    bool isInMBB(Vertex* vt);
    bool isAdjacent(Surface* sf);
    bool isOpposite(Surface* sf);

    void setMBB(Triangle* pl);
    void setMBB(Surface* pl);
    void updateMBB();
    bool isExistSameVertexInRange(ll si, ll ei, Vertex* add_id);
    int getSegmentsNumber(ll start_index, ll end_index);

    //compare vector size
    static bool compareLength(Surface* i, Surface* j);
    static bool compareArea(Surface* i, Surface* j);

    void translate(double diff[]);
    bool checkDuplicate(Checker* ch);

    void removeConsecutiveDuplication(Checker* ch);
    void removeStraight(double degree);
    void removeHole(Checker* ch);

    Vector_3 getSimpleNormal();
    bool updateNormal(Checker* ch);
    void updateRectArea();

    bool isValid();
    void tagVerticesUsed();

    bool hasSameNormalwith(int axis);
    bool hasOppositeNormalwith(int axis);

    void makePlanar(Plane_3 plane);
    Point_3 findLowestPoint();
    Plane_3 getPlaneWithLowest();

    void changeToRectangle();
    Segment* makeSegmentUpperZ(Checker* ch);
    Segment* makeSegmentLowerZ(Checker* ch);

    void snapping(Surface* p_surface, double p_diff);
    void clipping(Surface* p_surface,Checker* ch);
private:
    Point_3 getCenterPoint();
    Point_3 getCenterPointInFartest();
    int findNormalTypeForTri();
    std::vector<std::pair<double, double>> project_to_Plane18();
    std::vector<Point_2> get2DPoints(Plane_3 plane);
};



#endif /* Surface_h */