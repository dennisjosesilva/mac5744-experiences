#ifndef ACTOR_HPP_INCLUDED
#define ACTOR_HPP_INCLUDED

#include <memory>

#include <QObject>
#include <GL/gl.h>

namespace mac5744
{
  /* Forward Declararion */
  class Scene;

  enum RenderType {
    NoType = 0,
    Solid = 1,
    Transparent = 2,
    Overlay = 3,
  };

  enum RenderMode  {
    Points = GL_POINTS,
    Lines = GL_LINES,
    LineLoop = GL_LINE_LOOP,
    LineStrip = GL_LINE_STRIP,
    Triangles = GL_TRIANGLES,
    TriangleStrip = GL_TRIANGLE_STRIP,
    TriangleFan = GL_TRIANGLE_FAN
  };

  class Actor : public QObject
  {
  private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<QMatrix4x4> _transform;
    RenderMode _renderMode;
    
  };
}

#endif