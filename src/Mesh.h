#ifndef MESH_H
#define MESH_H

#include <string>
#include <map>
#include <vector>
#include <DynamicArray.h>
using namespace std;

class StructSizeDescription;
class Stream;
class Polygon;
class Vertex;
class NamedStream;
class PolyCollection;

//is it possible to make the interface for working with meshes
//be opaque in terms of Streams
//In otherwords, do I need to know about streams?
//No, but you do need to know about StructDescription
//
//The StructDescription should be reworked to use paths
//so I could say what is the offset of position.y
//and then the dynamic struct would get it

//I think I should rethink the interface here so that the meshes
//are created with an structdescription

//Think of a mesh as a collection of graphs
//that have the same topology but are colored differently
  
//In other words
//I should be able to run graph algorithms over it

class Mesh
{
  public:
    static void* Constructor();
    Mesh();
    Mesh(const Mesh& other);
    Mesh& operator=(const Mesh& other);
    ~Mesh();
    void copy(const Mesh& other);
    Mesh(DynamicArray* streams, PolyCollection* polyCollection);

    void reverseWindingOrder();
    const Stream* getStreamsElement(string name) const;
    Stream* getStreamsElement(string name);
    bool hasStream(string name) const;
    void addStream(string name, StructSizeDescription* ssd);

    void reinitPolyCount(unsigned int polyCount);
    Polygon* getPolygon(unsigned int index);
    void setPolygon(unsigned int index, Polygon* polygon);

    void findVerticesWithPositionIndex(unsigned int vertIndex, 
	   	       vector<Vertex*>& foundVertices);

    void appendStreamIndexToVertices(unsigned int streamIndex);

    void mergeStreams(const DynamicArray& otherStreams);
    void mergePolyCollection(PolyCollection* const otherPolyCollection);
    void clearName();
    void clearStreams();
    void clearPolyCollection();

    DynamicArray& getStreams();
    const DynamicArray& getStreams() const;

    const NamedStream* getStreamsElement(unsigned int index) const;
    NamedStream* getStreamsElement(unsigned int index);
    unsigned int getStreamsCount() const;

    void setStreams(const DynamicArray& array);
    void setStreamsElement(unsigned int index, NamedStream* element);
    void appendStreams(NamedStream* element);
    PolyCollection* getPolyCollection();
    const PolyCollection* getPolyCollection() const;

    void setPolyCollection(PolyCollection* value);

    void deepCopy(const Mesh* copyable);
    void destroy();
    void merge(const Mesh& other);
    void clear();
private:
    DynamicArray m_Streams;
    PolyCollection* m_PolyCollection;

};

#endif
