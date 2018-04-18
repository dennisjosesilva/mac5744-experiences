#ifndef SCENE_HPP_INCLUDED
#define SCENE_HPP_INCLUDED

#include <memory>
#include <string>

#include <QObject>
#include <GL/gl.h>

namespace mac5744
{
  enum DrawStyle { 
    Point = GL_POINT,
    Wireframe = GL_LINE,
    SolidWithEdges = GL_FILL + 1    
  };

  enum Shading {
    Flat = GL_FLAT,
    Smooth = GL_SMOOTH,
  };

  class Scene : public QObject
  {
  public:

  private:
    std::string _name;
    std::shared_ptr<QWidget> _viewer;
    DrawStyle _drawStyle;
    
  };
}
#endif