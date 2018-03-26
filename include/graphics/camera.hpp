#ifndef CAMERA_HPP_INCLUDED
#define CAMERA_HPP_INCLUDED

#include <string>
#include <memory>

#include <QVector3D>
#include <QMatrix4x4>
#include <QQuaternion>

namespace mac5744
{
  class Camera : public QObject
  {
  public:
    enum Lens { 
      Perspective,
      Orthographic
    };

  public:
    Camera(const std::string &pname = "main", 
           Lens plens = Perspective,
           std::shared_ptr<QVector3D> pposition = std::make_shared<QVector3D>(),
           float pfovy = 45.0f,
           float pheight = 2.0f,
           float pnearDistance = 0.1f,
           float pfarDistance= 100.0f,
           std::shared_ptr<QQuaternion> protation = std::make_shared<QQuaternion>());

    void copyFrom(Camera& camera);
    void store();
    void recall(float aspect=1.0f);
    
    inline void name(const std::string& pname) { _name = pname; }
    inline const std::string& name() const { return _name; }

    inline Lens lens() const { return _lens; }
    void lens(Lens plens, bool adjust=false);

    inline void position(const std::shared_ptr<QVector3D> pposition) { _position = pposition; }
    inline const std::shared_ptr<QVector3D> position() const { return _position; }
    inline std::shared_ptr<QVector3D> position() { return _position; }

    inline void aspectRatio(float paspectRatio) { _aspectRatio = paspectRatio; }
    inline float aspectRatio() const { return _aspectRatio; }

    inline void focalDistance(float pfocalDistance) { _focalDistance = pfocalDistance; }
    inline float focalDistance() const { return _focalDistance; }

    inline void height(float pheight) { _height = pheight; }
    inline float height() const { return _height; }
    void scaleHeight(float scaleFactor);

    inline void heightAngle(float fov) { _fovy = fov; }
    inline float heightAngle() const { return _fovy; }

    inline void nearDistance(float pnearDistance) { _nearDistance = pnearDistance; }
    inline float nearDistance() const { return _nearDistance; }

    inline void farDistance(float pfarDistance) { _farDistance = pfarDistance; }
    inline float farDistance() const { return _farDistance; }

    inline void rotation(const std::shared_ptr<QQuaternion> protation) { _rotation = protation; }
    inline const std::shared_ptr<QQuaternion> rotation() const { return _rotation; }
    inline std::shared_ptr<QQuaternion> rotation() { return _rotation; }

    inline void orientation(const std::shared_ptr<QMatrix4x4> porientation) { _orientation = porientation; }
    inline const std::shared_ptr<QMatrix4x4> orientation() const { return _orientation; }
    inline std::shared_ptr<QMatrix4x4> orientation() { return _orientation; }

    void pointAt(const QVector3D& target, const QVector3D &up = QVector3D{0.0f, 1.0f, 0.0f});
    void lookAt(const QVector3D& direction, const QVector3D &up);
    
    QMatrix4x4 cameraMatrixOriginal();
    QMatrix4x4 cameraMatrix();

    QMatrix4x4 viewMatrix();
    std::shared_ptr<QMatrix4x4> projectionMatrix();

  private:
    std::string _name;
    Lens _lens;
    std::shared_ptr<QVector3D> _position;
    
    float _fovy;
    float _height;
    float _nearDistance;
    float _farDistance;

    std::shared_ptr<QMatrix4x4> _projectionMatrix;
    std::shared_ptr<QMatrix4x4> _viewMatrix;
    std::shared_ptr<QMatrix4x4> _orientation;
    std::shared_ptr<QQuaternion> _rotation;

    float _focalDistance;
    float _aspectRatio;

    std::shared_ptr<Camera> _stored;
  };
}

#endif