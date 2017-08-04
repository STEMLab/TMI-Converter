//
//  check.cpp
//  TriMeshToGeom
//
//  Created by Dong's MacBook Pro on 2017. 6. 9..
//  Copyright © 2017년 Dong's MacBook Pro. All rights reserved.
//

#include "logic/check.hpp"
#include <algorithm>
#include <cmath>


using namespace std;

bool Checker::compare_vertex(Vertex* a, Vertex* b){
    if (a->x() < b->x()){
        return true;
    }
    else if (a->x() > b->x()){
        return false;
    }
    else{
        if (a->y() < b->y())
        {
            return true;
        }
        else if (a->y() > b->y())
        {
            return false;
        }
        else{
            if (a->z() < b->z())
            {
                return true;
            }
            else
                return false;

        }
    }
}

bool Checker::isExistDuplication(vector<Vertex*> vertex){
//    sort(vertex.begin(), vertex.end(), this->compare_vertex);
//    for (int i = 0 ; i < vertex.size() - 1 ; i++)
//    {
//        int j = i + 1;
//        if (isSameVertex(vertex[i],vertex[j]))
//        {
//            cout << i << ", " << j << endl;
//            Printer::printVertex(vertex[i]);
//            Printer::printVertex(vertex[j]);
//            return true;
//        }
//    }
    return false;
}

bool Checker::isSameVertex(Vertex* v1, Vertex* v2){
    double thres = this->threshold_vertex;
    if (fabs(v1->z() - v2->z()) <= thres && fabs(v1->x() - v2->x()) <= thres && fabs(v1->y() - v2->y()) <=thres){
        return true;
    }
    else
        return false;
}

bool Checker::isSameVertex(Vertex& v1, Vertex& v2){
    double thres = this->threshold_vertex;
    if (fabs(v1.z() - v2.z()) <= thres && fabs(v1.x() - v2.x()) <= thres && fabs(v1.y() - v2.y()) <=thres){
        return true;
    }
    else
        return false;
}

bool Checker::isSameOrientation(Vector_3& nv1, Vector_3& nv2){
    double thres = this->ori_degree;
    double angle = CGALCalculation::getAngle(nv1, nv2);
    return (angle <= thres) ;
}

bool Checker::isSamePlanar(Vector_3& big, Vector_3& small){
    double thres = this->ori_degree;
    double angle = CGALCalculation::getAngle(big, small);
    Vector_3 added = big + small;
    if (angle <= 45.0){
        return (CGALCalculation::getAngle(added, big) <= thres);
    }
    return false;
}

bool Checker::isSimilarOrientation(Vector_3& nv1, Vector_3& nv2){
    double thres = this->ori_degree;
    double angle = CGALCalculation::getAngle(nv1, nv2);
    return (angle <= thres * 2) ;
}



