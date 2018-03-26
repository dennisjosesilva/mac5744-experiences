#include <graphics/camera.hpp>
#include <QtMath>

namespace mac5744
{
  /* ================== Camera ======================================================================== */
  Camera::Camera(const std::string &pname, 
                  Lens plens,
                  std::shared_ptr<QVector3D> pposition,
                  float pfovy,
                  float pheight,
                  float pnearDistance,
                  float pfarDistance,
                  std::shared_ptr<QQuaternion> protation)
    : QObject{},
      _name{pname},
      _lens{plens},
      _position{pposition},
      _fovy{pfovy}, 
      _height{pheight}, 
      _nearDistance{pnearDistance}, 
      _farDistance{pfarDistance}, 
      _projectionMatrix{std::make_shared<QMatrix4x4>()}, 
      _viewMatrix{std::make_shared<QMatrix4x4>()}, 
      _orientation{std::make_shared<QMatrix4x4>()}, 
      _rotation{protation}, 
      _focalDistance{5.0}, 
      _aspectRatio{1.0}
  { }

  /* ======================  Copy From ================================================================= */
  void Camera::copyFrom(Camera& camera)
  {
    _name = camera._name; 
    _lens = camera.lens();
    _position = camera.position();
    _fovy = camera.heightAngle();
    _height = camera.height();
    _nearDistance = camera.nearDistance();
    _farDistance = camera.farDistance();

    _projectionMatrix = camera.projectionMatrix();
    _viewMatrix = camera.viewMatrix();
    _orientation = camera.orientation();
    _rotation = camera.rotation();

    _focalDistance = camera.focalDistance;
    _aspectRatio = camera.aspectRatio;
  }
  
  /* ======================== Store ==================================================================== */
  void Camera::store()
  {
    if (_stored == nullptr)
      _stored = std::make_shared<Camera>();
    _stored->copyFrom(*this);
  }

  /* ===================== Recall ===================================================================== */
  void Camera::recall(float aspect)
  {
    if (_stored != nullptr) {
      copyFrom(*_stored);
      _aspectRatio = aspect;
    }
  }
    
  /* =========================== Lens ================================================================  */
  void Camera::lens(Lens plens, bool adjust)
  {
    if (_lens == plens) {
      if (adjust) {
        if (_lens == Perspective)
          _height = 2.0 * _focalDistance * tanf(radian(_fovy / 2.0f));
        else {
          _direction = _orientation * QVector3D{0.0f, 0.0f, -1.0f};
          auto focalPoint = _position + _focalDistance * _direction;
          _focalDistance = (_height / 2.0f) / tanf(randian(_fovy / 2.0f))
          _position = focalPoint - _focalDistance * _direction;
        }
      }
      _lens = plens;
    }
  }

  /* ========================  Point At ============================================================== */
  void pointAt(const QVector3D& target, const QVector3D& up)
  {}
  
}