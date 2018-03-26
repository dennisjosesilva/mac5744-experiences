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
    _viewMatrix = std::make_shared<QMatrix4x4>(camera.viewMatrix());
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
          _height = 2.0 * _focalDistance * tanf(qDegreesToRadians(_fovy / 2.0f));
        else {
          auto direction = (*_orientation) * QVector3D{0.0f, 0.0f, -1.0f};
          auto focalPoint = (*_position) + _focalDistance * direction;
          _focalDistance = (_height / 2.0f) / qTan(qDegreesToRadians(_fovy / 2.0f));
          (*_position) = focalPoint - _focalDistance * direction;
        }
      }
      _lens = plens;
    }
  }

  /* ========================  Point At ============================================================== */
  void Camera::pointAt(const QVector3D &target, const QVector3D &up)
  {
    _focalDistance = (target - (*_position)).length();
    auto direction = (target - (*_position)).normalized();
    lookAt(direction, up.normalized());
  }

  /* ===================== LookAt ====================================================================== */
  void Camera::lookAt(const QVector3D& direction, const QVector3D &up)
  {
    auto z = -direction;
    auto x = QVector3D::crossProduct(up, z);
    auto y = QVector3D::crossProduct(z, x);
    _orientation = std::make_shared<QMatrix4x4>(
      x[0], x[1], x[2], 0.0f,
      y[0], y[1], y[2], 0.0f,
      z[0], z[1], z[2], 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f);
  }

  /* ===================== Camera Matrix Original ========================================================= */
  QMatrix4x4 Camera::cameraMatrixOriginal()
  {
    QMatrix4x4 cameraMatrix;
    cameraMatrix *= (*_orientation);
    cameraMatrix.translate(*_position);
    return cameraMatrix;
  }


  /* ========================= Camera Matrix ============================================================== */
  QMatrix4x4 Camera::cameraMatrix()
  {
    QMatrix4x4 cameraMatrix;
    cameraMatrix *= (*_orientation);
    cameraMatrix.rotate(*_rotation);
    cameraMatrix.translate(*_position);
    return cameraMatrix;
  }

  /* =============================== View Matrix ========================================================== */
  QMatrix4x4 Camera::viewMatrix()
  {
    return cameraMatrix().inverted();
  }

  /* =================================== Projection Matrxi ================================================ */
  std::shared_ptr<QMatrix4x4> Camera::projectionMatrix()
  {
    _projectionMatrix->setToIdentity();
    if (_lens == Orthographic) {
      auto xradius = 0.5 * _height * _aspectRatio;
      auto yradius = 0.5 * _height;
      _projectionMatrix->ortho(-xradius, xradius, -yradius, yradius, _nearDistance, _farDistance);
    } 
    else
      _projectionMatrix->perspective(_fovy, _aspectRatio, _nearDistance, _farDistance);
    
    return _projectionMatrix;
  }
}