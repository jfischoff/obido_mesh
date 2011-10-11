#ifndef NAMEDSTREAM_H
#define NAMEDSTREAM_H

#include <string>
#include <map>
using namespace std;

class Stream;

class NamedStream
{
  public:
    static void* Constructor();
    NamedStream();
    NamedStream(const NamedStream& other);
    NamedStream& operator=(const NamedStream& other);
    ~NamedStream();
    void copy(const NamedStream& other);
    NamedStream(Stream* stream, string name);

    void mergeStream(Stream* const otherStream);
    void mergeName(const string& otherName);
    void clearStream();
    void clearName();
    Stream* getStream();
    const Stream* getStream() const;

    void setStream(Stream* value);

    string getName();
    const string getName() const;

    void setName(string value);

    void cache();
    void uncache();
    void merge(const NamedStream& other);
    void clear();
private:
    Stream* m_Stream;
    string m_Name;
};



#endif
