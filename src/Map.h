/* -*- c-basic-offset: 4; indent-tabs-mode: nil; -*- */
#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <boost/utility.hpp>
#include "TmxMap.h"
#include "Math.h"

class Engine;
class Layer;

/** Map object but in game coords */
class MapObject
{
 public:
    std::string name;
    std::string type;
    unsigned gid; //< 0 is no gid
    float x;
    float y;
    float width;
    float height;
    bool visible;
    std::string shape;   //< ellipse, polygon, polyline or null
    std::vector<std::pair<float, float> > points; //< polygon or polyline points
};

//------------------------------------------------------------------------------

/** Interface to game map in game coords */
class Map : boost::noncopyable
{
    friend Layer;

 public:
    Map();
    ~Map();
    bool loadFromFile(const std::string& filename);

    Vector2<float> size() const;

    void draw(Engine *e, float xFrom, float xTo, float yFrom, float yTo) const;
    void drawLayer(Engine *e, const std::string& layer,
                   float xFrom, float xTo, float yFrom, float yTo) const;

    /** Get map objects */
    void getObjects(std::vector<MapObject>& v);

    std::vector<std::string> externalImages() const;

    std::string imageForTile(unsigned globalId) const;
    Rect<int> rectForTile(unsigned globalId) const;

 private:
    Vector2<int> pixelSize() const;
    Vector2<int> tileSize() const;

    int tileWidth() const { return m_tmxMap.tileWidth; }
    int tileHeight() const { return m_tmxMap.tileHeight; }

    tmx::Map m_tmxMap;  
    std::vector<Layer *> m_layers;
};

#endif
