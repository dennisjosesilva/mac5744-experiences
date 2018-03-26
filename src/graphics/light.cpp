#include <graphics/light.hpp>

namespace mac5744
{
  Light::Light(bool pheadLight = false,
      bool pdirectional = true,
      std::shared_ptr<QVector3D> pposition = std::make_shared<QVector3D>(0.0f, 0.0f, 0.0f),
      std::shared_ptr<QVector3D> pambientColor = std::make_shared<QVector3D>(0.2f, 0.2f, 0.2f),
      std::shared_ptr<QVector3D> pdiffuseColor = std::make_shared<QVector3D>(0.8f, 0.8f, 0.8f),
      std::shared_ptr<QVector3D> pspecularColor = std::make_shared<QVector3D>(0.0f, 0.0f, 0.0f),
      std::shared_ptr<QVector3D> pattenuation = std::make_shared<QVector3D>(1.0f, 0.02f, 0.002f)
  )
  : _headLight{pheadLight},
    _directional{pdirectional},
    _position{pposition},
    _ambientColor{pambientColor},
    _diffuseColor{pdiffuseColor},
    _specularColor{pspecularColor},
    _attenuation{pattenuation}
  {}
}