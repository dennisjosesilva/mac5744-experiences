#ifndef LIGHT_HPP_INCLUDED
#define LIGHT_HPP_INCLUDED

#include <memory>
#include <QVector3D>
#include <QVector4D>
#include <QObject>

namespace mac5744
{
  class Light: public QObject
  {
  public:
    Light(bool pheadLight = false,
      bool pdirectional = true,
      std::shared_ptr<QVector3D> pposition = std::make_shared<QVector3D>(0.0f, 0.0f, 0.0f),
      std::shared_ptr<QVector3D> pambientColor = std::make_shared<QVector3D>(0.2f, 0.2f, 0.2f),
      std::shared_ptr<QVector3D> pdiffuseColor = std::make_shared<QVector3D>(0.8f, 0.8f, 0.8f),
      std::shared_ptr<QVector3D> pspecularColor = std::make_shared<QVector3D>(0.0f, 0.0f, 0.0f),
      std::shared_ptr<QVector3D> pattenuation = std::make_shared<QVector3D>(1.0f, 0.02f, 0.002f)
    );

    inline void headLight(bool pheadLight) { _headLight = pheadLight; }
    inline bool headLight() const { return _headLight; }

    inline void directional(bool pdirectional) { _directional = pdirectional; }
    inline bool directional() const { return _directional; }

    inline std::shared_ptr<QVector3D> ambientColor() { return _ambientColor; }
    inline const std::shared_ptr<QVector3D> ambientColor() const { return _ambientColor; }

    inline std::shared_ptr<QVector3D> diffuseColor() { return _diffuseColor; }
    inline const std::shared_ptr<QVector3D> diffuseColor() const { return _diffuseColor; }

    inline std::shared_ptr<QVector3D> specularColor() { return _specularColor; }
    inline const std::shared_ptr<QVector3D> specularColor() const { return _specularColor; }

    inline std::shared_ptr<QVector3D> attenuation() { return _attenuation; }
    inline const std::shared_ptr<QVector3D> attenuation() const { return _attenuation; }
    
    QVector4D position() const;
    
  private:
    bool _headLight;
    bool _directional;
    std::shared_ptr<QVector3D> _position;
    std::shared_ptr<QVector3D> _ambientColor;
    std::shared_ptr<QVector3D> _diffuseColor;
    std::shared_ptr<QVector3D> _specularColor;
    std::shared_ptr<QVector3D> _attenuation;
  };
}

#endif