#ifndef POLYCOLLECTION2_H
#define POLYCOLLECTION2_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
#include <DynamicArray.h>
class Vertex;
#include <vector>
//__HEADERS__

class Polygon;

class PolyCollection
{
  public:
    static void* Constructor();
    PolyCollection();
    PolyCollection(const PolyCollection& other);
    PolyCollection& operator=(const PolyCollection& other);
    ~PolyCollection();
    void copy(const PolyCollection& other);
    PolyCollection(string name, DynamicArray* polygons);
//__CUSTOM_METHODS__
    void appendStreamIndexToVertices(unsigned int streamIndex);
    void reverseWindingOrder();
    void reinitPolygons(unsigned int polyCount);
    void findVerticesWithIndex(unsigned int streamIndex, 
				       unsigned int vertIndex, 
			  vector<Vertex*>& foundVertices);
//__CUSTOM_METHODS__
    void mergeName(const string& otherName);
    void mergePolygons(const DynamicArray& otherPolygons);
    void clearName();
    void clearPolygons();
    string getName();
    const string getName() const;

    void setName(string value);

    DynamicArray& getPolygons();
    const DynamicArray& getPolygons() const;

    const Polygon* getPolygonsElement(unsigned int index) const;
    Polygon* getPolygonsElement(unsigned int index);
    unsigned int getPolygonsCount() const;

    void setPolygons(const DynamicArray& array);
    void setPolygonsElement(unsigned int index, Polygon* element);
    void appendPolygons(Polygon* element);
    void cache();
    void uncache();
    virtual void deepCopy(const PolyCollection* copyable);
    virtual void destroy();
    void merge(const PolyCollection& other);
    void clear();
private:
    string m_Name;
    DynamicArray m_Polygons;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
