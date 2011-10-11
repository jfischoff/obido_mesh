#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include <map>
#include <vector>
#include <DynamicArray.h>
using namespace std;



class Vertex;

class Polygon
{
  public:
    static void* Constructor();
    Polygon();
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);
    ~Polygon();
    void copy(const Polygon& other);
    Polygon(DynamicArray* vertices);

    void appendStreamIndexToVertices(int streamIndex);
    void reverseWindingOrder();
    void reinit(int polygonCount);
    void findVerticesWithIndex(int streamIndex,
					     int vertIndex,
					     vector<Vertex*>&
				       foundVertices);

    void mergeVertices(const DynamicArray& otherVertices);
    void clearName();
    void clearVertices();

    DynamicArray& getVertices();
    const DynamicArray& getVertices() const;

    const Vertex* getVerticesElement(unsigned int index) const;
    Vertex* getVerticesElement(unsigned int index);
    unsigned int getVerticesCount() const;

    void setVertices(const DynamicArray& array);
    void setVerticesElement(unsigned int index, Vertex* element);
    void appendVertices(Vertex* element);

    void deepCopy(const Polygon* copyable);
    void destroy();
    void merge(const Polygon& other);
    void clear();
private:
    DynamicArray m_Vertices;
};
#endif
