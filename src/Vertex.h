#ifndef VERTEX2_H
#define VERTEX2_H

#include <string>
#include <map>
using namespace std;
//__HEADERS__
#include <DynamicArray.h>
//__HEADERS__


class Vertex
{
  public:
    static void* Constructor();
    Vertex();
    Vertex(const Vertex& other);
    Vertex& operator=(const Vertex& other);
    ~Vertex();
    void copy(const Vertex& other);
    Vertex(string name, string debugName, DynamicArray* streamIndices);
//__CUSTOM_METHODS__
    void addMultiple(int count, int index);
    bool hasIndex(int streamIndex, int vertIndex);
//__CUSTOM_METHODS__
    void mergeName(const string& otherName);
    void mergeDebugName(const string& otherDebugName);
    void mergeStreamIndices(const DynamicArray& otherStreamIndices);
    void clearName();
    void clearDebugName();
    void clearStreamIndices();
    string getName();
    const string getName() const;

    void setName(string value);

    string getDebugName();
    const string getDebugName() const;

    void setDebugName(string value);

    DynamicArray& getStreamIndices();
    const DynamicArray& getStreamIndices() const;

    const unsigned int getStreamIndicesElement(unsigned int index) const;
    unsigned int getStreamIndicesElement(unsigned int index);
    unsigned int getStreamIndicesCount() const;

    void setStreamIndices(const DynamicArray& array);
    void setStreamIndicesElement(unsigned int index, unsigned int element);
    void appendStreamIndices(unsigned int element);
    void cache();
    void uncache();
    virtual void deepCopy(const Vertex* copyable);
    virtual void destroy();
    void merge(const Vertex& other);
    void clear();
private:
    string m_Name;
    string m_DebugName;
    DynamicArray m_StreamIndices;
//__CUSTOM_MEMBERS__
//__CUSTOM_MEMBERS__
};
#endif
